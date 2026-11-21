#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_show_gcode_popup(lv_event_t * e);
extern void action_hide_gcode_popup(lv_event_t * e);
extern void action_send_btn_m119(lv_event_t * e);
extern void action_send_btn_m114(lv_event_t * e);
extern void action_send_btn_m122(lv_event_t * e);
extern void action_send_btn_m105(lv_event_t * e);
extern void action_send_btn_m503(lv_event_t * e);
extern void action_send_btn_m84(lv_event_t * e);
extern void action_send_btn_m112(lv_event_t * e);
extern void action_send_btn_g28(lv_event_t * e);
extern void action_send_btn_g29(lv_event_t * e);
extern void action_send_custom_gcode(lv_event_t * e);
extern void action_clear_custom_gcode(lv_event_t * e);
extern void action_show_keyboard(lv_event_t * e);
extern void action_print_button_main_screen(lv_event_t * e);
extern void action_main_screen(lv_event_t * e);
extern void action_print_screen(lv_event_t * e);
extern void action_setting_screen(lv_event_t * e);
extern void action_stepper_driver_screen(lv_event_t * e);
extern void action_motion_screen(lv_event_t * e);
extern void action_info_screen(lv_event_t * e);
extern void action_screen_calibrate(lv_event_t * e);
extern void action_back_main_print_screen_button(lv_event_t * e);
extern void action_heat_nozzle_button(lv_event_t * e);
extern void action_heat_bed_button(lv_event_t * e);
extern void action_cool_button(lv_event_t * e);
extern void action_preheat_button(lv_event_t * e);
extern void action_pid_nozzle_button(lv_event_t * e);
extern void action_pid_bed_button(lv_event_t * e);
extern void action_fan_speed_print_screen(lv_event_t * e);
extern void action_file_selected(lv_event_t * e);
extern void action_refresh_file_list(lv_event_t * e);
extern void action_sort_files(lv_event_t * e);
extern void action_go_back_folder(lv_event_t * e);
extern void action_settings_button_main_screen(lv_event_t * e);
extern void action_set_time_main_screen(lv_event_t * e);
extern void action_clear_log(lv_event_t * e);
extern void action_reboot_button_main_screen(lv_event_t * e);
extern void action_power_off_button_main_screen(lv_event_t * e);
extern void action_print_ready_main_screen(lv_event_t * e);
extern void action_drivers_temp_main_screen(lv_event_t * e);
extern void action_bed_temp_main_screen(lv_event_t * e);
extern void action_nozzle_temp_main_screen(lv_event_t * e);
extern void action_clock_date_year_label_main_screen(lv_event_t * e);
extern void action_wifi_icon_main_screen(lv_event_t * e);
extern void action_z_location_main_screen(lv_event_t * e);
extern void action_y_location_main_screen(lv_event_t * e);
extern void action_x_location_main_screen(lv_event_t * e);
extern void action_job_label_main_screen(lv_event_t * e);
extern void action_print_ready_label_main_screen(lv_event_t * e);
extern void action_files_dir_main_screen(lv_event_t * e);
extern void action_clock_date_year_label_print_screen(lv_event_t * e);
extern void action_wifi_icon_label_print_screen(lv_event_t * e);
extern void action_job_label_print_screen(lv_event_t * e);
extern void action_back_main_button_print_screen(lv_event_t * e);
extern void action_print_ready_label_print_screen(lv_event_t * e);
extern void action_nozzle_arc_temp_print_screen(lv_event_t * e);
extern void action_bed_arc_temp_print_screen(lv_event_t * e);
extern void action_nozzle_arc_target_print_screen(lv_event_t * e);
extern void action_heat_nozzle_button_print_screen(lv_event_t * e);
extern void action_cool_button_print_screen(lv_event_t * e);
extern void action_pid_nozzle_button_print_screen(lv_event_t * e);
extern void action_heat_bed_button_print_screen(lv_event_t * e);
extern void action_preheat_button_print_screen(lv_event_t * e);
extern void action_pid_bed_button_print_screen(lv_event_t * e);
extern void action_x_position_print_screen(lv_event_t * e);
extern void action_y_position_print_screen(lv_event_t * e);
extern void action_z_position_print_screen(lv_event_t * e);
extern void action_home_all_button_print_screen(lv_event_t * e);
extern void action_home_x_button_print_screen(lv_event_t * e);
extern void action_home_y_button_print_screen(lv_event_t * e);
extern void action_home_z_button_print_screen(lv_event_t * e);
extern void action_fan_speed_slider_print_screen(lv_event_t * e);
extern void action_printing_progress_slider_print_screen(lv_event_t * e);
extern void action_pause_button_print_screen(lv_event_t * e);
extern void action_stop_button_print_screen(lv_event_t * e);
extern void action_tune_button_print_screen(lv_event_t * e);
extern void action_change_filament_button_print_screen(lv_event_t * e);
extern void action_print_status_log_print_screen(lv_event_t * e);
extern void action_back_main_button_settings_screen(lv_event_t * e);
extern void action_on_calibration_target_pressed(lv_event_t * e);
extern void action_calibration_mode(lv_event_t * e);
extern void action_on_cancel_calibration(lv_event_t * e);
extern void action_on_calibration_touch(lv_event_t * e);
extern void action_start_calibration_clicked(lv_event_t * e);
extern void action_time_date_setting_screen(lv_event_t * e);
extern void action_save_time_setting(lv_event_t * e);
extern void action_cancel_time_settings(lv_event_t * e);
extern void action_return_to_main(lv_event_t * e);
extern void action_save_time_button_time_date_setting_screen(lv_event_t * e);
extern void action_file_browser_list(lv_event_t * e);
extern void action_refresh_file_list_button(lv_event_t * e);
extern void action_printing_progress_print_screen(lv_event_t * e);
extern void action_fan_speed_percentage(lv_event_t * e);
extern void action_usb_mount_button_main_screen(lv_event_t * e);
extern void action_pause_resume_button_label(lv_event_t * e);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/