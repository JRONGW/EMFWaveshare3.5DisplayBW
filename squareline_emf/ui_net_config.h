#ifndef UI_NET_CONFIG_H
#define UI_NET_CONFIG_H

#include "arduino_secrets.h"

// =====================
// WiFi
// =====================
static const char* WIFI_SSID     = SECRET_SSID;
static const char* WIFI_PASSWORD = SECRET_PASS;

// =====================
// MQTT
// =====================
static const char* MQTT_SERVER = "mqtt.vixtorlab.org";
static const int   MQTT_PORT   = 1883;
static const char* MQTT_USER   = MQTT_USERNAME;
static const char* MQTT_PASSWD = MQTT_PASS;

// Primary topics (vixtorlab detector payloads after upgrade).
static const char* TOPIC_GSR       = "sensors/bio/gsr";
static const char* TOPIC_EEG       = "sensors/eeg";
static const char* TOPIC_RF_LOWMID = "sensors/rf/rtlsdr";
static const char* TOPIC_RF_HIGH   = "sensors/rf/hackrf";

// Alternate paths seen on the same broker (sensor_parse matches by suffix too).
static const char* TOPIC_RF_LOWMID_ALT = "rf/rtlsdr";
static const char* TOPIC_RF_HIGH_ALT   = "rf/hackrf";
static const char* TOPIC_RF_SWEEP      = "sensors/emf/rtlsdr";
static const char* TOPIC_EEG_ALT       = "eeg";

static const char* MQTT_SUB_TOPICS[] = {
    TOPIC_GSR,
    TOPIC_EEG,
    TOPIC_EEG_ALT,
    TOPIC_RF_LOWMID,
    TOPIC_RF_LOWMID_ALT,
    TOPIC_RF_SWEEP,
    TOPIC_RF_HIGH,
    TOPIC_RF_HIGH_ALT,
    nullptr
};

#endif
