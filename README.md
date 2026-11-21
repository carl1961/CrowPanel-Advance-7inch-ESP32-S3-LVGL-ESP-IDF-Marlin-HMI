# CrowPanel-Advance-7inch-ESP32-S3-LVGL-ESP-IDF-Marlin-HMI
CrowPanel-Advance-7inch 3d printer controller
FIRST I am not a programer! I am a copy cat, do what I read and am told.
BUT what a world, with help from AI search and them spitting out code faster thay you can read it!
am most the time it even compiles.  
THIS is not a tutor of how to get EZZ Studio or ESP-IDF rolling. but any reqest and questions I will gladly answer.


Prints! Lots of work to yet do to tie things together.
Fill free to fork and Make it better for your personal use!

My goal poasting is to get a work going to optimize the printers working ability
FULL open source. 

OK first all the readme below is AI generated, it does not reflect my ability. these screen started with help from Gemini and Grok doing dark theme
in these file or lots of readme of this AI adventure. EEZ Studio Dark Theme UI.pdf alone is grew to over 300 pages.
 
## Architecture, Temperature Sync & Build Notes

### Hardware & Firmware Architecture
- **Display & Touch:** CrowPanel Advance 7.0-inch (800×480 RGB LCD) powered by an ESP32-S3 (8 MB PSRAM) with GT911 capacitive touch and an STC8H1K28 I2C extender/buzzer/backlight controller.
- **Real-Time Clock:** Onboard BM8563 RTC accessed over I2C for date/time display and synchronization.
- **UI & Firmware Stack:** Built with **ESP-IDF v5.5.4**, **LVGL**, and **EEZ Studio** (`ui.h`, `screens.h`, `actions.c`), paired with a UART1 Marlin communication task (`main.cpp`) and an LVGL worker task (`lvgl_port_task` in `esp32_s3.c`).
- **Marlin Communication:** Sends G-code commands over UART1 (`send_gcode()`) and parses incoming telemetry lines (`T:` nozzle, `B:` bed, `C:` driver/chamber temps, `M27` SD byte progress, and `//action:notification` status lines).

### Nozzle & Bed Arc Sync Fix
Previously, incoming `T:` and `B:` telemetry lines in `main.cpp` set the LVGL arcs to the **current** measured temperature (`hcur` / `bcur`) and unconditionally overwrote target temperature labels with Marlin's previous target (`hset` / `bset`), causing the arc knob to snap back right after release.

- **Sync Holdoff Guards (`hmi_ui_sync.h` & `actions.c`):** Track active touch (`LV_EVENT_PRESSED` / `LV_EVENT_PRESSING`) and a ~1500 ms post-release holdoff (`LV_EVENT_RELEASED`) using FreeRTOS ticks before sending `M104` (nozzle) or `M140` (bed) via `send_gcode()`. Expose `ui_should_ignore_nozzle_sync()` and `ui_should_ignore_bed_sync()` to C++.
- **Target vs. Current Telemetry (`main.cpp`):** Update current temperature labels from `hcur` / `bcur`, and only sync arc values and target labels from `hset` / `bset` when `!ui_should_ignore_*_sync()`.
- **C / C++ Linkage:** Include C headers from `main.cpp` inside an `extern "C"` block so C++ symbol name mangling does not cause `undefined reference` linker errors:
  ```cpp
  extern "C" {
  #include "hmi_ui_sync.h"
  }
## Troubleshooting

### Status Log Cluttered by `M20` / `M21` / `M22` During Active Prints
- **Cause:** SD card mount/list commands (`M20`, `M21`, `M22`) run on startup or screen logic and can keep firing during an active print, flooding the on-screen status log (`log_queue`) alongside `M27` byte progress.
- **Fix:** Gate `M20` / `M21` / `M22` polling so those commands are skipped whenever an SD print is actively running (`M27` byte progress active / printing state), and only push high-signal or rate-limited lines into `log_queue`.

### `X`, `Y`, and `Z` Axis Positions Not Updating After Screen Changes
- **Cause:** Widget names or screen references can change after splitting or renaming screens in EEZ Studio (`print_screen`), or `M114` position polling / coordinate parsing may not be triggered or locked with `lvgl_port_lock(100)`.
- **Fix:** Verify the exact `X`, `Y`, and `Z` label object names in `screens.h` / `main.cpp`, ensure `M114` responses (or move lines) parse `X:`, `Y:`, and `Z:` into those active `print_screen` labels, and wrap label updates in `lvgl_port_lock(100)` / `lvgl_port_unlock()`.

### Long G-Code Filename Overlapping the Clock in the Top Header
- **Cause:** Long filenames (such as `Test_calibration_cube_20x20mm.gcode`) can expand past the widget width or wrap/clip into the date/time label on `print_screen`.
- **Fix:** Constrain the filename label width in EEZ Studio (or set `LV_LABEL_LONG_DOT` with `lv_label_set_long_mode(...)`) so long filenames truncate cleanly with `...` before reaching the clock.

## Next Steps

- [ ] Guard `M20` / `M21` / `M22` polling during active prints and keep `log_queue` focused on useful status messages.
- [ ] Confirm `X`, `Y`, and `Z` coordinate labels on `print_screen` update reliably under `lvgl_port_lock(100)`.
- [ ] Truncate long filenames in the `print_screen` header so the date and clock remain clear.
- [ ] Clean up any remaining unused variable/function compiler warnings in `main.cpp` and `actions.c`.
