static bool is_arc_drag_or_release(lv_event_code_t code) {
    return (code == LV_EVENT_VALUE_CHANGED || code == LV_EVENT_RELEASED);
}

void action_nozzle_arc_print_screen(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *arc = lv_event_get_target(e);
    if (arc == NULL) return;

    int32_t target_c = lv_arc_get_value(arc);

    if (code == LV_EVENT_VALUE_CHANGED) {
        if (objects.nozzle_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.nozzle_arc_target_print_screen, "%ld", (long)target_c);
        }
    } else if (code == LV_EVENT_RELEASED) {
        if (objects.nozzle_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.nozzle_arc_target_print_screen, "%ld", (long)target_c);
        }
        char cmd[24];
        snprintf(cmd, sizeof(cmd), "M104 S%ld\n", (long)target_c);
        send_gcode(cmd);
    }
}

void action_bed_arc_print_screen(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *arc = lv_event_get_target(e);
    if (arc == NULL) return;

    int32_t target_c = lv_arc_get_value(arc);

    if (code == LV_EVENT_VALUE_CHANGED) {
        if (objects.bed_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.bed_arc_target_print_screen, "%ld", (long)target_c);
        }
    } else if (code == LV_EVENT_RELEASED) {
        if (objects.bed_arc_target_print_screen != NULL) {
            lv_label_set_text_fmt(objects.bed_arc_target_print_screen, "%ld", (long)target_c);
        }
        char cmd[24];
        snprintf(cmd, sizeof(cmd), "M140 S%ld\n", (long)target_c);
        send_gcode(cmd);
    }
}