/* SquareLine UI on ESP32-S3-Touch-LCD-3.5
 * Hardware init matches Waveshare 11_lvgl_arduino_v8. */

#include <lvgl.h>
#include <Arduino_GFX_Library.h>
#include "TCA9554.h"
#include "TouchDrvFT6X36.hpp"
#include <WiFi.h>
#include <PubSubClient.h>
#include "ui_net_config.h"
#include "sensor_parse.h"
#include "ui_data.h"

extern "C" void ui_init(void);

#define GFX_BL 6

#define SPI_MISO 2
#define SPI_MOSI 1
#define SPI_SCLK 5

#define LCD_CS -1
#define LCD_DC 3
#define LCD_RST -1
#define LCD_HOR_RES 320
#define LCD_VER_RES 480

#define I2C_SDA 8
#define I2C_SCL 7

#define DISPLAY_ROTATION 1

TCA9554 TCA(0x20);

Arduino_DataBus *bus = new Arduino_ESP32SPI(LCD_DC, LCD_CS, SPI_SCLK, SPI_MOSI, SPI_MISO);
Arduino_GFX *gfx = new Arduino_ST7796(
  bus, LCD_RST, DISPLAY_ROTATION, true, LCD_HOR_RES, LCD_VER_RES);

TouchDrvFT6X36 touch;

WiFiClient espClient;
PubSubClient mqttClient(espClient);
static unsigned long lastWifiRetry = 0;
static unsigned long lastAnalysisRefresh = 0;
const unsigned long WIFI_RETRY_INTERVAL = 15000;
const unsigned long ANALYSIS_REFRESH_INTERVAL = 1000;

static bool connectWiFi() {
  if (WiFi.status() == WL_CONNECTED) return true;

  Serial.print("Connecting to WiFi: ");
  Serial.println(WIFI_SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  for (int i = 0; i < 40; i++) {
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println();
      Serial.print("WiFi connected, IP: ");
      Serial.println(WiFi.localIP());
      return true;
    }
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connect failed, will retry.");
  return false;
}

static void mqttCallback(char* topic, byte* payload, unsigned int length) {
  sensor_parse_and_update(topic, payload, length);
}

static void reconnectMqtt() {
  if (WiFi.status() != WL_CONNECTED) return;
  if (mqttClient.connected()) return;

  String clientId = "esp32-lvgl-display-";
  clientId += String(random(0xffff), HEX);

  bool ok = (strlen(MQTT_USER) > 0)
              ? mqttClient.connect(clientId.c_str(), MQTT_USER, MQTT_PASSWD)
              : mqttClient.connect(clientId.c_str());

  if (ok) {
    Serial.println("MQTT connected.");
    for(const char* const * tp = MQTT_SUB_TOPICS; *tp != nullptr; ++tp) {
      mqttClient.subscribe(*tp);
      Serial.print("Subscribed: ");
      Serial.println(*tp);
    }
  } else {
    Serial.print("MQTT connect failed, rc=");
    Serial.println(mqttClient.state());
  }
}

uint32_t screenWidth;
uint32_t screenHeight;
uint32_t bufSize;
lv_disp_draw_buf_t draw_buf;
lv_color_t *disp_draw_buf1;
lv_color_t *disp_draw_buf2;
lv_disp_drv_t disp_drv;

void lcd_reset(void) {
  TCA.write1(1, 1);
  delay(10);
  TCA.write1(1, 0);
  delay(10);
  TCA.write1(1, 1);
  delay(200);
}

static void configure_touch_for_rotation(uint8_t rotation) {
  touch.setMaxCoordinates(gfx->width(), gfx->height());
  switch (rotation) {
    case 1:
      touch.setSwapXY(true);
      touch.setMirrorXY(false, true);
      break;
    case 3:
      touch.setSwapXY(true);
      touch.setMirrorXY(true, false);
      break;
    case 2:
      touch.setSwapXY(false);
      touch.setMirrorXY(true, true);
      break;
    default:
      touch.setSwapXY(false);
      touch.setMirrorXY(false, false);
      break;
  }
}

void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

  lv_disp_flush_ready(disp_drv);
}

void my_touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
  int16_t x[1], y[1];
  uint8_t touched = touch.getPoint(x, y, 1);

  if (touched) {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = x[0];
    data->point.y = y[0];
  } else {
    data->state = LV_INDEV_STATE_REL;
  }
}

void setup() {
  Serial.begin(115200);

  Wire.begin(I2C_SDA, I2C_SCL);
  TCA.begin();
  TCA.pinMode1(1, OUTPUT);
  lcd_reset();

  if (!touch.begin(Wire, FT6X36_SLAVE_ADDRESS)) {
    Serial.println("Failed to find FT6X36 - check your wiring!");
    while (1) {
      delay(1000);
    }
  }

  if (!gfx->begin()) {
    Serial.println("gfx->begin() failed!");
  }

  gfx->fillScreen(RGB565_BLACK);

#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif

  configure_touch_for_rotation(DISPLAY_ROTATION);

  lv_init();

  screenWidth = gfx->width();
  screenHeight = gfx->height();
  bufSize = screenWidth * 120;

  const size_t draw_buf_bytes = bufSize * sizeof(lv_color_t);
  disp_draw_buf1 = (lv_color_t *)heap_caps_malloc(draw_buf_bytes, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
  disp_draw_buf2 = (lv_color_t *)heap_caps_malloc(draw_buf_bytes, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
  if(!disp_draw_buf1 || !disp_draw_buf2) {
    Serial.println("LVGL draw buffer alloc failed!");
    while(1) { delay(1000); }
  }

  lv_disp_draw_buf_init(&draw_buf, disp_draw_buf1, disp_draw_buf2, bufSize);

  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();
  lv_refr_now(NULL);

  mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
  mqttClient.setBufferSize(1024);
  mqttClient.setCallback(mqttCallback);

  Serial.print("Setup done, free heap: ");
  Serial.println(ESP.getFreeHeap());
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    unsigned long now = millis();
    if (now - lastWifiRetry >= WIFI_RETRY_INTERVAL) {
      lastWifiRetry = now;
      connectWiFi();
    }
  } else if (!mqttClient.connected()) {
    reconnectMqtt();
  }
  mqttClient.loop();

  unsigned long now = millis();
  if (now - lastAnalysisRefresh >= ANALYSIS_REFRESH_INTERVAL) {
    lastAnalysisRefresh = now;
    ui_data_refresh_analysis();
    ui_data_refresh_eeg();
    ui_data_refresh_gsr();
  }

  lv_timer_handler();
  delay(1);
}
