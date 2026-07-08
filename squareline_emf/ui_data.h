#ifndef UI_DATA_H
#define UI_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct {
    int raw;
    float voltage;
    float baseline;
    float delta;
    int nervous_level;         // 1..4
    char interpretation[64];
} ui_gsr_data_t;

typedef struct {
    int attention;
    int meditation;
    int poor_signal;
    bool receiving;
    long asic_bands[8];
} ui_eeg_data_t;

#define UI_RF_LOWMID_BAND_COUNT 7

typedef struct {
    float peak_frequency_mhz;
    float peak_power_db;
    float noise_floor_db;
    float snr_db;
    float band_power_db[UI_RF_LOWMID_BAND_COUNT];
} ui_rf_lowmid_data_t;

/* HackRF detector publishes 5G Cellular, 5G NR, WiFi 5 GHz (top to bottom). */
#define UI_RF_HIGH_BAND_COUNT 3

typedef struct {
    float peak_frequency_mhz;
    float peak_power_db;
    float noise_floor_db;
    float snr_db;
    float band_power_relative_db;
    float band_power_db[UI_RF_HIGH_BAND_COUNT];
} ui_rf_high_data_t;

void ui_data_update_gsr(const ui_gsr_data_t * d);
void ui_data_update_eeg(const ui_eeg_data_t * d);
void ui_data_update_rf_lowmid(const ui_rf_lowmid_data_t * d);
void ui_data_update_rf_high(const ui_rf_high_data_t * d);
void ui_data_refresh_gsr(void);
void ui_data_refresh_eeg(void);
void ui_data_refresh_analysis(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
