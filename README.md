# CrowPanel-Advance-7inch-ESP32-S3-LVGL-ESP-IDF-Marlin-HMI
CrowPanel-Advance-7inch 3d printer controller
FIRST I am not a programer! I am a copy cat, do what I read and am told to do.
BUT what a world, with help from AI search and them spitting out code faster than you can read it!
and most the time it even compiles. 

THIS is not a tutor of how to get EZZ Studio or ESP-IDF rolling. but any reqest and questions I will gladly answer.


********************************************************************************************************************************
11-28-2026

## Recent Firmware Updates

### 1. Homing Status Persistence & Jog Safety (`main.cpp` & `actions.c`)
* **Persistent Homing Status:** Tracked `G28` commands via `s_homing_active` and `s_homing_started_tick` in `main.cpp` so `"Homing All (G28)..."` (and X/Y/Z homing prompts) stay displayed on `status_log_jog_screen` until homing completes after the minimum elapsed window (`1500 ms`+) or reports a homing/error state.
* **Removed Premature Coordinate Overrides:** Removed duplicate `strncmp` homing-completion checks above the `X:`/`Y:`/`Z:` coordinate parser in `parse_marlin_line()` so position updates refresh axis labels without prematurely flipping the homing status message.
* **Z-Homed Guard:** Kept `jog_mark_z_homed(true)` on Z and All homing actions (`action_z_home_button_jog_screen`, `action_all_home_button_jog_screen`) while leaving X-only and Y-only homes from falsely marking Z homed, and preserved `lift_z_before_home()` on Print screen home actions.

### 2. EEPROM Save (`M500`) Long Buzzer Beep (`main.cpp`)
* **Centralized `M500` Tracking:** Flagged outbound `M500` commands in `send_gcode()` with `s_m500_pending` so save buttons across screens (Jog, Tune popup, and the EEPROM save prompt) trigger a single notification path.
* **Non-Blocking Long Beep:** When Marlin confirms `M500` (`Settings Stored` or `ok` without error), `trigger_m500_success_beep()` spawns a short-lived FreeRTOS task (`buzzer_long_beep_task`) to sound the STC8H1K28 buzzer for `600 ms` via `stc8h1k28_buzzer_on()` / `stc8h1k28_buzzer_off()` without blocking LVGL or UART RX.

### 3. Console Telemetry Filtering & Log Stability (`actions.c` & `main.cpp`)
* **Telemetry Filter:** Filtered routine `M105`, `ok T:`, `T:`, and `BD:` (`//action:notification BD:...mm`) lines out of `ui_report_marlin_status()` via `is_routine_telemetry_line()` so BDsensor distance streaming and temperature polls do not flood the UI logs.
* **Bounded Log Textareas:** Capped `print_status_log` and `print_status_log_print_screen` (`LOG_TEXTAREA_MAX_CHARS = 2500`, `LOG_TEXTAREA_TRIM_BATCH = 500`), trimming old text on newline boundaries and auto-scrolling to the latest line.
* **G-Code Popup & Code Cleanup:** Added `-` support on the G-code keypad map (`gcode_map`) for negative coordinates/offsets and removed duplicate declarations and unused/commented stubs in `main.cpp` and `actions.c`.

### 4. SFM-27 3-24v
* Added external buzzer, Onboard buzzer hard to hear whe display is in 3D Printer case



11-23-2026  Gemini Finished FILAMENT MANAGEMENT Screen

<img width="743" height="452" alt="image" src="https://github.com/user-attachments/assets/ae5f052f-5c1c-4231-8c24-3fb3e1467281" />






11-22-2026   Progess

Grok, Fixed temperture arcs on PRINTER SCREEN been weeks at getting this thing working, then I asked grok! you can read his comment below.

<img width="744" height="452" alt="image" src="https://github.com/user-attachments/assets/389eb0cb-4b40-4e72-8431-b250ba48bb5a" />


Gemini, Fixed Cool  button and Preheat for PetG, this gets temps up without having to spin arcs and you can then fine tune
Personally I quit using PLA after learning after a year no matter what you make breaks down and starts bio degrading.

Gemini fixed and wired in the POPUP tune screen

<img width="743" height="458" alt="image" src="https://github.com/user-attachments/assets/f311a8b6-225c-401d-8e3b-93ee0179a769" />

every button worked!





Prints! Lots of work to yet do to tie things together.
Fill free to fork and Make it better for your personal use!

My goal posting is to get a work going to optimize the printers working ability
FULL open source. 

OK first all the readme below is AI generated, it does not reflect my ability. 

These screens started with help from Gemini and Grok doing dark theme.

In these files or lots of readme of this AI adventure. EEZ Studio Dark Theme UI.pdf alone has grew to over 300 pages.

I was hoping AI, Gemini could read my files like a doctor, anylyize and spit out the cure.

QUOTE from Gemini 11-21-2026  "—I don't have a tool to pull or browse files directly from GitHub repositories, so I can't open the whole repo on my own to do a full-repo diagnostic.
What works just as well when you want a full "doctor's checkup" on the code is pasting the key files or sections directly here—especially main.cpp, actions.c, hmi_ui_sync.h, and the print_tools parts of screens.h and screens.c."

Groks Answer:

Yes — your GitHub repo is fully public and open.

Anyone can view, clone, and fork it right now.It is extremely current.

Last commit was today (November 21, 2026) — multiple updates in the last few hours, including “remove build folder”, README improvements, and “updated current running”. This is live, active work.Doctor’s Report: Project Health CheckPatient: CrowPanel-Advance-7inch-ESP32-S3-LVGL-ESP-IDF-Marlin-HMI

Owner: carl1961 (Carl Shelton)

Status: Work-in-progress 3D printer HMI for Marlin firmware on the Elecrow CrowPanel Advance 7" (800×480 RGB IPS + GT911 touch + ESP32-S3).Overall DiagnosisHealthy but still growing.

This is a real, functional HMI that already talks to Marlin over UART, shows live temperatures, progress, coordinates, file browser, and has a proper dark-theme UI from EEZ Studio. It is not a toy demo — it has actual print control logic, progress estimation, and sync safeguards.You openly say “FIRST I am not a programer! I am a copy cat…” and credit AI (Grok + Gemini) heavily. That’s fine and honest. The code shows the classic AI-assisted pattern: solid structure in places, some repetition, and a few remaining rough edges that you’re already documenting in the README.Strengths (What’s Working Well)
Architecture is sensible.

FreeRTOS tasks for UART TX/RX, command queue, log queue, LVGL lock protection, watchdog that polls M105 if Marlin goes quiet. This is proper embedded practice.
Temperature arc sync fix is smart.

You added hmi_ui_sync.h + holdoff logic so the arcs don’t snap back while the user is dragging them. That was a real pain point and you fixed it properly with ui_should_ignore_nozzle_sync() / bed equivalent.
Live data parsing is already quite complete:
T: / B: temps + targets
M27 byte progress
M20 file list
Coordinates (X: Y: Z:)
Print start/end detection
Fan PWM

UI side is advanced. EEZ Studio project + generated screens, dark theme, multiple screens (main, print, file browser, etc.).
Hardware support is solid. BM8563 RTC, STC8H1K28 IO expander/buzzer/backlight, GT911 touch, proper ESP-IDF 5.5.4 + LVGL setup.
Weaknesses / Areas That Need Attention (the “symptoms”)
Still unfinished (you already know this).

README lists clear next steps:
Guard M20/M21/M22 during active prints (status log gets flooded)
Make sure X/Y/Z labels update reliably after screen changes
Truncate long filenames so they don’t overlap the clock
Clean remaining unused variable warnings

Code quality is mixed (normal for AI-assisted + solo work).
main.cpp is ~28 KB and does a lot — parsing, queues, timers, UI updates all in one place.
Some C/C++ mixing (you already fixed the extern "C" linkage, good).
UART is set to 115200 in the code I saw (common, but confirm it matches your Marlin baud).

Documentation is honest but scattered.

Top-level README is short + personal. The detailed architecture notes are good. There’s a huge “EEZ Studio Dark Theme UI.pdf” (300+ pages of the AI adventure) and a project tree. It’s more “working notes” than polished project docs.
Repo hygiene.

You just cleaned the build folder (good). There are still zip files of the project inside Firmware/. EEZ project file is large (~4 MB).
PrognosisVery good.

This is already more advanced than many public CrowPanel + Marlin HMI attempts. The core loop (UART ↔ LVGL ↔ Marlin) works, prints can be started from the screen, and the temperature interaction problem is solved. The remaining items are polish and robustness, not fundamental redesign.You are actively iterating (commits today), which is the healthiest sign.Recommendations (Doctor’s Orders)
Keep the honest README style — it’s refreshing.
Finish the three items already listed in “Next Steps”.
Consider splitting main.cpp a bit more (parser vs. UI update helpers) when you have time.
Add a simple CHANGELOG.md or keep updating the README with what works right now.
Once the log flooding and coordinate updates are solid, this becomes a very usable open-source CrowPanel Marlin controller.
Would you like me to dig deeper into any specific part (the temperature sync logic, the parser, the EEZ screens, the UART tasks, etc.) and give more targeted feedback or suggestions? Just say the word.





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
