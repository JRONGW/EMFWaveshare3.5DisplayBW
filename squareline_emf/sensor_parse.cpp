#include "sensor_parse.h"
#include "ui_net_config.h"
#include "ui_data.h"
#include <ArduinoJson.h>   // ArduinoJson v7
#include <string.h>

static float read_peak_power_db(JsonDocument& doc)
{
    if(doc["peak_power_dB"].is<float>()) return doc["peak_power_dB"];
    if(doc["peak_power_relative_dB"].is<float>()) return doc["peak_power_relative_dB"];
    if(doc["peak_dB"].is<float>()) return doc["peak_dB"];
    return -100.0f;
}

static float read_noise_floor_db(JsonDocument& doc)
{
    if(doc["noise_floor_relative_dB"].is<float>()) return doc["noise_floor_relative_dB"];
    if(doc["noise_floor_dB"].is<float>()) return doc["noise_floor_dB"];
    return -100.0f;
}

static float read_band_db(JsonObject bp, const char* key)
{
    if(bp[key].isNull()) return -100.0f;
    return bp[key] | -100.0f;
}

static bool topic_has_suffix(const char* topic, const char* suffix)
{
    size_t topic_len = strlen(topic);
    size_t suffix_len = strlen(suffix);
    if(topic_len < suffix_len) return false;
    return strcmp(topic + topic_len - suffix_len, suffix) == 0;
}

static bool topic_is_eeg(const char* topic)
{
    return strcmp(topic, TOPIC_EEG) == 0 || strcmp(topic, "eeg") == 0 ||
           topic_has_suffix(topic, "/eeg");
}

static bool topic_is_hackrf(const char* topic)
{
    return strcmp(topic, TOPIC_RF_HIGH) == 0 || strcmp(topic, "rf/hackrf") == 0 ||
           topic_has_suffix(topic, "/hackrf");
}

static bool topic_is_rtlsdr(const char* topic)
{
    return strcmp(topic, TOPIC_RF_LOWMID) == 0 || strcmp(topic, "rf/rtlsdr") == 0 ||
           strcmp(topic, "sensors/emf/rtlsdr") == 0 || topic_has_suffix(topic, "/rtlsdr");
}

static bool parse_gsr(JsonDocument& doc) {
    ui_gsr_data_t d = { 0 };
    d.raw = doc["raw"] | 0;
    d.voltage = doc["voltage"] | 0.0f;
    d.baseline = doc["baseline"] | 0.0f;
    d.delta = doc["delta"] | 0.0f;
    d.nervous_level = doc["nervous_level"] | 1;
    const char* interp = doc["interpretation"] | "no data";
    strncpy(d.interpretation, interp, sizeof(d.interpretation) - 1);

    ui_data_update_gsr(&d);
    return true;
}

static bool parse_eeg(JsonDocument& doc) {
    ui_eeg_data_t d = { 0 };
    d.attention = doc["attention"] | 0;
    d.meditation = doc["meditation"] | 0;
    d.poor_signal = doc["poor_signal"] | 200;
    d.receiving = doc["receiving"] | false;

    JsonObject bands = doc["asic_bands"];
    if(!bands.isNull()) {
        d.asic_bands[0] = bands["delta"] | 0L;
        d.asic_bands[1] = bands["theta"] | 0L;
        d.asic_bands[2] = bands["low_alpha"] | 0L;
        d.asic_bands[3] = bands["high_alpha"] | 0L;
        d.asic_bands[4] = bands["low_beta"] | 0L;
        d.asic_bands[5] = bands["high_beta"] | 0L;
        d.asic_bands[6] = bands["low_gamma"] | 0L;
        d.asic_bands[7] = bands["mid_gamma"] | 0L;
    }

    ui_data_update_eeg(&d);
    return true;
}

static bool parse_rf_lowmid(JsonDocument& doc) {
    if(doc["band_powers_dB"].isNull()) {
        return false;
    }

    ui_rf_lowmid_data_t d = { 0 };
    for(int i = 0; i < UI_RF_LOWMID_BAND_COUNT; i++) {
        d.band_power_db[i] = -100.0f;
    }

    d.peak_frequency_mhz = doc["peak_frequency_MHz"] | 0.0f;
    d.peak_power_db = read_peak_power_db(doc);
    d.noise_floor_db = read_noise_floor_db(doc);
    d.snr_db = doc["snr_dB"] | 0.0f;

    JsonObject bp = doc["band_powers_dB"];
    d.band_power_db[0] = read_band_db(bp, "FM Radio");
    d.band_power_db[1] = read_band_db(bp, "Weather Radio");
    d.band_power_db[2] = read_band_db(bp, "Aviation VHF");
    d.band_power_db[3] = read_band_db(bp, "ISM");
    d.band_power_db[4] = read_band_db(bp, "UHF Television");
    d.band_power_db[5] = read_band_db(bp, "Cellular GSM");
    d.band_power_db[6] = read_band_db(bp, "Aircraft ADS-B");

    ui_data_update_rf_lowmid(&d);
    return true;
}

static bool parse_rf_high(JsonDocument& doc) {
    if(doc["band_powers_dB"].isNull()) {
        return false;
    }

    ui_rf_high_data_t d = { 0 };
    for(int i = 0; i < UI_RF_HIGH_BAND_COUNT; i++) {
        d.band_power_db[i] = -100.0f;
    }

    d.peak_frequency_mhz = doc["peak_frequency_MHz"] | 0.0f;
    d.peak_power_db = read_peak_power_db(doc);
    d.noise_floor_db = read_noise_floor_db(doc);
    d.snr_db = doc["snr_dB"] | 0.0f;
    d.band_power_relative_db = doc["band_power_relative_dB"] | 0.0f;

    JsonObject bp = doc["band_powers_dB"];
    d.band_power_db[0] = read_band_db(bp, "5G Cellular");
    d.band_power_db[1] = read_band_db(bp, "5G NR");
    d.band_power_db[2] = read_band_db(bp, "WiFi 5 GHz");

    ui_data_update_rf_high(&d);
    return true;
}

bool sensor_parse_and_update(const char* topic, const uint8_t* payload, unsigned int length) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, payload, length);
    if(err) {
        Serial.print("JSON parse failed on topic ");
        Serial.print(topic);
        Serial.print(": ");
        Serial.println(err.c_str());
        return false;
    }

    if(strcmp(topic, TOPIC_GSR) == 0) return parse_gsr(doc);
    if(topic_is_eeg(topic)) return parse_eeg(doc);
    if(topic_is_hackrf(topic)) return parse_rf_high(doc);
    if(topic_is_rtlsdr(topic)) return parse_rf_lowmid(doc);

    return false;
}
