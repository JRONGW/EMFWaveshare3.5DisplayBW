# EMFWaveshare3.5Display

SquareLine LVGL UI for the **Waveshare ESP32-S3-Touch-LCD-3.5** (ST7796 320×480), with live MQTT sensor binding for an EMF / bio-sensing dissertation UI.

Screens: **homepage**, **detect** (4-quadrant overview), **EEG**, **GSR**, **low-mid RF**, **high RF**, and **analysis**.

## Files

### SquareLine UI
- **`ui.c/h`**, **`ui_helpers.c/h`**, **`ui_events.h`**
- **`screens/`** — 7 screens
- **`images/`** — embedded flash assets (+ stubs for oversized icons)
- **`fonts/`** — DotGothic 8/12/16/24/32/64
- **`components/ui_comp_hook.c`**

### Integration layer
- **`ui_data.h/.c`** — binds parsed sensor values onto SquareLine widgets
- **`sensor_parse.h/.cpp`** — MQTT JSON → structs for `ui_data.c`
- **`ui_net_config.h`** + **`arduino_secrets.h`** — WiFi/MQTT/topic config
- **`squareline_emf.ino`** — display/touch bring-up with WiFi + MQTT

## Before it builds

1. **Copy `arduino_secrets.h.example` to `arduino_secrets.h`** and fill in WiFi/MQTT credentials.
2. **Check `TOPIC_EEG` in `ui_net_config.h`** against your MQTT broker tree.
3. **Libraries** (Library Manager): `PubSubClient`, `ArduinoJson` (v7), plus the Waveshare/LVGL stack from the original demo.

## Live data wiring

| Screen | Widgets updated | MQTT source |
|--------|-----------------|-------------|
| GSR | 4 arousal panels (#FAAEC2 fill from `nervous_level` / `delta`) | `sensors/bio/gsr` |
| EEG | 5 band panels (delta/theta/alpha/beta/gamma) | `sensors/eeg` |
| High RF | 4 bars (Wi-Fi 5 + Cellular wired) | `sensors/rf/hackrf` |
| Low-mid RF | 7 bars mirror peak power until per-band bins exist | `sensors/rf/rtlsdr` |
| Analysis | RF strength arc + calmness arc | cached from high RF + EEG |

## SquareLine re-export

After exporting from SquareLine Studio to `EXPORTUI`, run:

```powershell
.\sync_squareline_export.ps1
```

That copies updated UI files and fixes background image pixel format for LVGL 16-bit color.

## Known gaps

- **Low-mid RF**: bars show `peak_power_dB` on every row until the RTL-SDR payload includes per-band power.
- **High RF**: Wi-Fi 2.4 GHz and Bluetooth bars stay at 0% until matching fields are added to the HackRF MQTT payload.
