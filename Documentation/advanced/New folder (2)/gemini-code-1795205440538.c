void action_pause_resume_button_label(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_PRESSED || code == LV_EVENT_CLICKED) {
        ESP_LOGI("PAUSE", "Pause/Resume triggered (code=%d), state=%d", (int)code, (int)s_is_paused);
        if (!s_is_paused) {
            send_gcode("M25\n");
            // Lift nozzle 10mm away from the part (relative move, then back to absolute)
            send_gcode("G91\n");
            send_gcode("G1 Z10 F600\n");
            send_gcode("G90\n");
            ui_set_paused_state(true);
        } else {
            // Lower nozzle back 10mm before resuming SD/USB playback
            send_gcode("G91\n");
            send_gcode("G1 Z-10 F600\n");
            send_gcode("G90\n");
            send_gcode("M24\n");
            ui_set_paused_state(false);
        }
    }
}