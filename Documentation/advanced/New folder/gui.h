#ifndef GUI_H
#define GUI_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// Declare your EEZ Studio UI actions here
void action_save_time_setting(lv_event_t *e);
void action_return_to_main(lv_event_t *e);
void action_save_time_button_time_date_setting_screen(lv_event_t *e);
void action_cancel_time_settings(lv_event_t *e);
void action_time_date_setting_screen(lv_event_t *e);
void update_clock_labels_timer(lv_timer_t *timer);

void action_start_calibration_clicked(lv_event_t *e);
void action_on_cancel_calibration(lv_event_t *e);
void action_on_calibration_touch(lv_event_t *e);

void action_show_gcode_popup(lv_event_t *e);
void action_hide_gcode_popup(lv_event_t *e);
void action_send_custom_gcode(lv_event_t *e);
void action_clear_custom_gcode(lv_event_t *e);
void action_show_keyboard(lv_event_t *e);

void action_setting_screen(lv_event_t *e);
void action_screen_calibrate(lv_event_t *e);
void action_main_screen(lv_event_t *e);

#ifdef __cplusplus
}
#endif

#endif // GUI_H