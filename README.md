# CrowPanel-Advance-7inch-ESP32-S3-LVGL-ESP-IDF-Marlin-HMI
CrowPanel-Advance-7inch 3d printer controller

Prints! Lots work to tie things together.
Fill free to fork and Make it better!
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
