#include "ui.h"
#include "ui_data.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

#define COL_PANEL_ACTIVE  lv_color_hex(0xFAAEC2)

/* Full scale = 1.5x the strongest category in the current MQTT message. */
#define MQTT_DISPLAY_HEADROOM  1.5f
/* GSR delta from baseline (same units as MQTT "delta" field). */
#define GSR_DELTA_HIGH    8000.0f
#define PANEL_OPA_MIN     48
#define RF_BAND_MISSING   -100.0f

static ui_gsr_data_t s_last_gsr = { 0 };
static ui_eeg_data_t s_last_eeg = { 0 };
static ui_rf_lowmid_data_t s_last_rf_lowmid = {
    .peak_power_db = RF_BAND_MISSING,
    .band_power_db = { RF_BAND_MISSING, RF_BAND_MISSING, RF_BAND_MISSING, RF_BAND_MISSING,
                       RF_BAND_MISSING, RF_BAND_MISSING, RF_BAND_MISSING }
};
static ui_rf_high_data_t s_last_rf_high = {
    .peak_power_db = RF_BAND_MISSING,
    .band_power_db = { RF_BAND_MISSING, RF_BAND_MISSING, RF_BAND_MISSING }
};
static int clampi(int v, int lo, int hi)
{
    if(v < lo) return lo;
    if(v > hi) return hi;
    return v;
}

static bool band_is_active(float db)
{
    return db > (RF_BAND_MISSING + 1.0f);
}

static int pct_of_mqtt_max(float value, float mqtt_max)
{
    if(mqtt_max <= 0.0f || value <= 0.0f) return 0;
    float full_scale = mqtt_max * MQTT_DISPLAY_HEADROOM;
    return clampi((int)((value / full_scale) * 100.0f + 0.5f), 0, 100);
}

static void mqtt_scaled_rf_bars_to_pct(const float * band_db, int count, int * out_pct)
{
    float min_db = 1e9f;
    float max_db = -1e9f;
    int active = 0;

    for(int i = 0; i < count; i++) {
        out_pct[i] = 0;
        if(!band_is_active(band_db[i])) continue;
        active++;
        if(band_db[i] < min_db) min_db = band_db[i];
        if(band_db[i] > max_db) max_db = band_db[i];
    }

    if(active == 0) return;

    if(active == 1) {
        int fill = pct_of_mqtt_max(1.0f, 1.0f);
        for(int i = 0; i < count; i++) {
            if(band_is_active(band_db[i])) out_pct[i] = fill;
        }
        return;
    }

    float span = max_db - min_db;
    if(span < 0.01f) {
        int fill = pct_of_mqtt_max(1.0f, 1.0f);
        for(int i = 0; i < count; i++) {
            if(band_is_active(band_db[i])) out_pct[i] = fill;
        }
        return;
    }

    float full_span = span * MQTT_DISPLAY_HEADROOM;
    for(int i = 0; i < count; i++) {
        if(!band_is_active(band_db[i])) continue;
        out_pct[i] = clampi((int)(((band_db[i] - min_db) / full_span) * 100.0f + 0.5f), 0, 100);
    }
}

static void apply_mqtt_scaled_rf_bars(lv_obj_t * const * bars, int count, const float * band_db)
{
    int pct[UI_RF_LOWMID_BAND_COUNT] = { 0 };
    mqtt_scaled_rf_bars_to_pct(band_db, count, pct);

    for(int i = 0; i < count; i++) {
        if(!bars[i]) continue;
        lv_bar_set_value(bars[i], pct[i], LV_ANIM_ON);
    }
}

static lv_opa_t long_to_opa(long val, long high)
{
    if(val <= 0 || high <= 0) return 0;
    int opa = (int)((val * 255L) / high);
    opa = clampi(opa, 0, 255);
    if(opa > 0 && opa < PANEL_OPA_MIN) opa = PANEL_OPA_MIN;
    return (lv_opa_t)opa;
}

static lv_opa_t float_to_opa(float val, float high)
{
    float a = fabsf(val);
    if(a <= 0.0f || high <= 0.0f) return 0;
    int opa = (int)((a * 255.0f) / high);
    opa = clampi(opa, 0, 255);
    if(opa > 0 && opa < PANEL_OPA_MIN) opa = PANEL_OPA_MIN;
    return (lv_opa_t)opa;
}

static void set_panel_fill(lv_obj_t * panel, lv_opa_t opa)
{
    if(!panel) return;
    lv_obj_set_style_bg_color(panel, COL_PANEL_ACTIVE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(panel, opa, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// ---------------------------------------------------------
// GSR - 4 panels: stable / mild / moderate / strong arousal
// ---------------------------------------------------------
void ui_data_refresh_gsr(void)
{
    if(!ui_GSR_Screen) return;

    lv_obj_t * panels[4] = {
        ui_PanellowGSR, ui_PanelMildGSR, ui_PanelModeratteGSR, ui_PanelStrongGSR
    };
    int level = clampi(s_last_gsr.nervous_level, 1, 4);
    lv_opa_t peak_opa = float_to_opa(s_last_gsr.delta, GSR_DELTA_HIGH);
    if(peak_opa == 0) {
        peak_opa = (lv_opa_t)clampi(80 + level * 35, PANEL_OPA_MIN, 255);
    }

    for(int i = 0; i < 4; i++) {
        lv_opa_t opa = 0;
        int tier = i + 1;
        if(tier < level) {
            opa = 200;
        } else if(tier == level) {
            opa = peak_opa;
        }
        set_panel_fill(panels[i], opa);
    }
}

void ui_data_update_gsr(const ui_gsr_data_t * d)
{
    s_last_gsr = *d;
    ui_data_refresh_gsr();
}

// ---------------------------------------------------------
// EEG - 5 panels: delta, theta, alpha, beta, gamma
// ---------------------------------------------------------
void ui_data_refresh_eeg(void)
{
    if(!ui_EEG_Screen) return;

    lv_obj_t * panels[5] = {
        ui_PanellowGSR1, ui_PanellowGSR2, ui_PanellowGSR3, ui_PanellowGSR4, ui_PanellowGSR5
    };
    long band_vals[5] = {
        s_last_eeg.asic_bands[0],
        s_last_eeg.asic_bands[1],
        s_last_eeg.asic_bands[2] + s_last_eeg.asic_bands[3],
        s_last_eeg.asic_bands[4] + s_last_eeg.asic_bands[5],
        s_last_eeg.asic_bands[6] + s_last_eeg.asic_bands[7]
    };

    long max_band = 0;
    for(int i = 0; i < 5; i++) {
        if(band_vals[i] > max_band) max_band = band_vals[i];
    }

    int signal_scale = 255;
    if(!s_last_eeg.receiving || s_last_eeg.poor_signal > 50) {
        signal_scale = 80;
    } else if(s_last_eeg.poor_signal > 25) {
        signal_scale = 160;
    }

    for(int i = 0; i < 5; i++) {
        int pct = pct_of_mqtt_max((float)band_vals[i], (float)max_band);
        lv_opa_t opa = (lv_opa_t)((pct * 255) / 100);
        opa = (lv_opa_t)((opa * signal_scale) / 255);
        if(pct > 0 && opa > 0 && opa < PANEL_OPA_MIN) opa = PANEL_OPA_MIN;
        set_panel_fill(panels[i], opa);
    }
}

void ui_data_update_eeg(const ui_eeg_data_t * d)
{
    s_last_eeg = *d;
    ui_data_refresh_eeg();
}

// ---------------------------------------------------------
// RF low-mid - 7 bars, top to bottom on screen
// ---------------------------------------------------------
void ui_data_update_rf_lowmid(const ui_rf_lowmid_data_t * d)
{
    s_last_rf_lowmid = *d;

    if(!ui_Low_mid_RF1) return;

    lv_obj_t * bars[UI_RF_LOWMID_BAND_COUNT] = {
        ui_Bar6, ui_Bar7, ui_Bar5, ui_Bar8, ui_Bar9, ui_Bar10, ui_Bar11
    };

    apply_mqtt_scaled_rf_bars(bars, UI_RF_LOWMID_BAND_COUNT, d->band_power_db);
}

// ---------------------------------------------------------
// RF high - 3 bars: 5G Cellular, 5G NR, WiFi 5 GHz
// ---------------------------------------------------------
void ui_data_update_rf_high(const ui_rf_high_data_t * d)
{
    s_last_rf_high = *d;

    if(!ui_High_RF) return;

    lv_obj_t * bars[4] = { ui_Bar1, ui_Bar2, ui_Bar3, ui_Bar4 };
    float band_db[4] = {
        d->band_power_db[0],
        d->band_power_db[1],
        d->band_power_db[2],
        RF_BAND_MISSING
    };
    apply_mqtt_scaled_rf_bars(bars, 4, band_db);
}

// ---------------------------------------------------------
// Analysis gauges
// ---------------------------------------------------------
void ui_data_refresh_analysis(void)
{
    if(!ui_Analysis) return;

    int rf_pct = 0;
    if(s_last_rf_high.snr_db > 0.0f) {
        rf_pct = clampi((int)s_last_rf_high.snr_db, 0, 100);
    } else if(s_last_rf_high.band_power_relative_db > 0.0f) {
        rf_pct = clampi((int)(s_last_rf_high.band_power_relative_db * 4.0f), 0, 100);
    } else {
        int band_pct[UI_RF_HIGH_BAND_COUNT] = { 0 };
        mqtt_scaled_rf_bars_to_pct(s_last_rf_high.band_power_db, UI_RF_HIGH_BAND_COUNT, band_pct);
        rf_pct = band_pct[0];
        for(int i = 1; i < UI_RF_HIGH_BAND_COUNT; i++) {
            if(band_pct[i] > rf_pct) rf_pct = band_pct[i];
        }
    }

    lv_arc_set_value(ui_AnalysisRFstrengthArc, rf_pct);
    lv_label_set_text_fmt(ui_AnalysisRFstregnthtext, "%d", rf_pct);

    int calm_pct = clampi(s_last_eeg.meditation, 0, 100);
    if(!s_last_eeg.receiving || s_last_eeg.poor_signal > 50) {
        calm_pct = 0;
    }
    lv_arc_set_value(ui_AnalysisEmotionArc, calm_pct);
    lv_label_set_text_fmt(ui_AnalysisEmotionalCalmnesstext, "%d", calm_pct);
}
