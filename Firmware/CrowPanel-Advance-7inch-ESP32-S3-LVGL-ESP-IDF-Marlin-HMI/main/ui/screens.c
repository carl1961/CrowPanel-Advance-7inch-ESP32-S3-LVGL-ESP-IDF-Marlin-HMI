#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

//
// Screens
//

void create_screen_main_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf9fafc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // PrintReadyLabelMainScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.print_ready_label_main_screen = obj;
                    lv_obj_set_pos(obj, 97, 26);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "READY");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 72, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "PRINTER STATUS:");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 316, 7);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfcfbfb), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "JOB:");
        }
        {
            // Printer_1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_1 = obj;
            lv_obj_set_pos(obj, 7, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            // JobLabelMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.job_label_main_screen = obj;
            lv_obj_set_pos(obj, 353, 7);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Project.gcode");
        }
        {
            // TimeLabelMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_label_main_screen = obj;
            lv_obj_set_pos(obj, 544, 7);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x074b5a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf3f2f2), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "2:00 PM ");
        }
        {
            // WifiIconMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.wifi_icon_main_screen = obj;
            lv_obj_set_pos(obj, 747, 5);
            lv_obj_set_size(obj, 30, 20);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf6fbfb), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF1EB");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 8, 64);
            lv_obj_set_size(obj, 388, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 403, 64);
            lv_obj_set_size(obj, 388, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 471, 73);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "SYSTEM BOOT LOG CONSOLE");
        }
        {
            // PrintStatusLog
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.print_status_log = obj;
            lv_obj_set_pos(obj, 422, 104);
            lv_obj_set_size(obj, 360, 250);
            lv_textarea_set_max_length(obj, 0);
            lv_textarea_set_text(obj, "SYSTEM BOOT LOG Information");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x1f1e1e), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfaf5f5), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf7f5f5), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 20, 73);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "FILE BROWSER:");
        }
        {
            // FilesDirMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.files_dir_main_screen = obj;
            lv_obj_set_pos(obj, 143, 73);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "/USB_DRIVE/GCODE_FILES/");
        }
        {
            // ClearLog
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.clear_log = obj;
            lv_obj_set_pos(obj, 423, 365);
            lv_obj_set_size(obj, 126, 45);
            lv_obj_add_event_cb(obj, action_clear_log, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f4f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "CLEAR LOG");
                }
            }
        }
        {
            // SettingsButtonMainScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.settings_button_main_screen = obj;
            lv_obj_set_pos(obj, 687, 366);
            lv_obj_set_size(obj, 90, 96);
            lv_obj_add_event_cb(obj, action_setting_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f3f3), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x08ed05), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj5 = obj;
                    lv_obj_set_pos(obj, -2, 25);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xece9e9), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, " SETTINGS");
                }
            }
        }
        {
            // PowerOffButtonMainScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.power_off_button_main_screen = obj;
            lv_obj_set_pos(obj, 20, 417);
            lv_obj_set_size(obj, 130, 43);
            lv_obj_add_event_cb(obj, action_power_off_button_main_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xeb0609), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "POWER OFF");
                }
            }
        }
        {
            // SendGcode
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.send_gcode = obj;
            lv_obj_set_pos(obj, 423, 417);
            lv_obj_set_size(obj, 126, 45);
            lv_obj_add_event_cb(obj, action_show_gcode_popup, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f4f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // RefreshFileListButton
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.refresh_file_list_button = obj;
            lv_obj_set_pos(obj, 188, 365);
            lv_obj_set_size(obj, 98, 45);
            lv_obj_add_event_cb(obj, action_refresh_file_list_button, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f4f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj7 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "REFRESH");
                }
            }
        }
        {
            // GoBackFolder
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.go_back_folder = obj;
            lv_obj_set_pos(obj, 19, 365);
            lv_obj_set_size(obj, 77, 45);
            lv_obj_add_event_cb(obj, action_go_back_folder, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj8 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "BACK");
                }
            }
        }
        {
            // RebootButtonMainScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.reboot_button_main_screen = obj;
            lv_obj_set_pos(obj, 158, 417);
            lv_obj_set_size(obj, 130, 45);
            lv_obj_add_event_cb(obj, action_reboot_button_main_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f4f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // PrintButtonMainScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.print_button_main_screen = obj;
            lv_obj_set_pos(obj, 298, 365);
            lv_obj_set_size(obj, 86, 96);
            lv_obj_add_event_cb(obj, action_print_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02f2fd), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj9 = obj;
                    lv_obj_set_pos(obj, -1, 22);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0x464444), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "PRINT");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 323, 376);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0x464444), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf00c");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 707, 375);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xece9e9), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf013");
        }
        {
            // SortFiles
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.sort_files = obj;
            lv_obj_set_pos(obj, 104, 365);
            lv_obj_set_size(obj, 77, 45);
            lv_obj_add_event_cb(obj, action_sort_files, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f4f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj12 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "SORT");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 202, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f9f9), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 281, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfafa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 360, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 478, 32);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Nozzle:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 597, 33);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Bed:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 672, 33);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0x08ed05), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Drivers:");
        }
        {
            // X_LocationMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.x_location_main_screen = obj;
            lv_obj_set_pos(obj, 225, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f5f5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "205.00");
        }
        {
            // Y_LocationMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.y_location_main_screen = obj;
            lv_obj_set_pos(obj, 302, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f5f5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "189.00");
        }
        {
            // Z_LocationMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.z_location_main_screen = obj;
            lv_obj_set_pos(obj, 381, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f5f5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "1.00");
        }
        {
            // NozzleTempMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.nozzle_temp_main_screen = obj;
            lv_obj_set_pos(obj, 535, 33);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f5f5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "24");
        }
        {
            // BedTempMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.bed_temp_main_screen = obj;
            lv_obj_set_pos(obj, 635, 33);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f5f5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "25");
        }
        {
            // DriversTempMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.drivers_temp_main_screen = obj;
            lv_obj_set_pos(obj, 734, 33);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f5f5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "42");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 86, 199);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "SEND GCODE");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, -180, 199);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "REBOOT");
        }
        {
            // USB_Mount_Button_Main_Screen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.usb_mount_button_main_screen = obj;
            lv_obj_set_pos(obj, 556, 365);
            lv_obj_set_size(obj, 126, 45);
            lv_obj_add_event_cb(obj, action_usb_mount_button_main_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // SetTimeMainScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.set_time_main_screen = obj;
            lv_obj_set_pos(obj, 556, 417);
            lv_obj_set_size(obj, 126, 45);
            lv_obj_add_event_cb(obj, action_time_date_setting_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj21 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "SET TIME");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 562, 379);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf9f9), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, " USB MOUNT");
        }
        {
            // FileBrowserList
            lv_obj_t *obj = lv_list_create(parent_obj);
            objects.file_browser_list = obj;
            lv_obj_set_pos(obj, 24, 105);
            lv_obj_set_size(obj, 358, 252);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
            lv_obj_set_scroll_dir(obj, LV_DIR_VER);
            lv_obj_set_style_radius(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xf1efef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfefdfd), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_post(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1f1e1e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f6f6), LV_PART_MAIN | LV_STATE_SCROLLED);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_SCROLLED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_SCROLLED);
        }
        {
            // GcodePopup
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.gcode_popup = obj;
            lv_obj_set_pos(obj, 18, 110);
            lv_obj_set_size(obj, 407, 379);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_deep_dark_panel(obj);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ButtonGrid
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.button_grid = obj;
                    lv_obj_set_pos(obj, -5, -4);
                    lv_obj_set_size(obj, 370, 334);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    add_style_light_deep_container(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0x8b8787), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Btn_M119
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_m119 = obj;
                            lv_obj_set_pos(obj, 12, 62);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_btn_m119, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj23 = obj;
                                    lv_obj_set_pos(obj, -4, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf4f6f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "M119");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj24 = obj;
                            lv_obj_set_pos(obj, 30, 64);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Endstops");
                        }
                        {
                            // Btn_M105
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_m105 = obj;
                            lv_obj_set_pos(obj, 12, 118);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_btn_m105, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj25 = obj;
                                    lv_obj_set_pos(obj, -4, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf4f6f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "M105");
                                }
                            }
                        }
                        {
                            // Btn_G28
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_g28 = obj;
                            lv_obj_set_pos(obj, 12, 174);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_btn_g28, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj26 = obj;
                                    lv_obj_set_pos(obj, -4, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "G28");
                                }
                            }
                        }
                        {
                            // Btn_Clear
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_clear = obj;
                            lv_obj_set_pos(obj, 14, 285);
                            lv_obj_set_size(obj, 170, 43);
                            lv_obj_add_event_cb(obj, action_clear_custom_gcode, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0x5a5c5c), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x717373), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf9f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj27 = obj;
                                    lv_obj_set_pos(obj, -4, 2);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf4f6f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "CLEAR");
                                }
                            }
                        }
                        {
                            // Btn_M114
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_m114 = obj;
                            lv_obj_set_pos(obj, 133, 62);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_btn_m114, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj28 = obj;
                                    lv_obj_set_pos(obj, -4, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf4f6f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "M114");
                                }
                            }
                        }
                        {
                            // Btn_M503
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_m503 = obj;
                            lv_obj_set_pos(obj, 133, 118);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_btn_m503, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj29 = obj;
                                    lv_obj_set_pos(obj, -4, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf4f6f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "M503");
                                }
                            }
                        }
                        {
                            // Btn_G29
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_g29 = obj;
                            lv_obj_set_pos(obj, 133, 174);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_btn_g29, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj30 = obj;
                                    lv_obj_set_pos(obj, -4, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "G29");
                                }
                            }
                        }
                        {
                            // Btn_M122
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_m122 = obj;
                            lv_obj_set_pos(obj, 254, 62);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_btn_m122, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj31 = obj;
                                    lv_obj_set_pos(obj, -4, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf4f6f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "M122");
                                }
                            }
                        }
                        {
                            // Btn_M84
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_m84 = obj;
                            lv_obj_set_pos(obj, 254, 118);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_btn_m84, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj32 = obj;
                                    lv_obj_set_pos(obj, -4, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf4f6f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "M84");
                                }
                            }
                        }
                        {
                            // Btn_M112
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_m112 = obj;
                            lv_obj_set_pos(obj, 254, 174);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_btn_m112, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf40f05), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj33 = obj;
                                    lv_obj_set_pos(obj, -4, 5);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xe8ecec), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "M112");
                                }
                            }
                        }
                        {
                            // Btn_SendCustom
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_send_custom = obj;
                            lv_obj_set_pos(obj, 254, 230);
                            lv_obj_set_size(obj, 110, 43);
                            lv_obj_add_event_cb(obj, action_send_custom_gcode, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj34 = obj;
                                    lv_obj_set_pos(obj, -4, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "SEND");
                                }
                            }
                        }
                        {
                            // Btn_Close
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_close = obj;
                            lv_obj_set_pos(obj, 194, 285);
                            lv_obj_set_size(obj, 170, 43);
                            lv_obj_add_event_cb(obj, action_hide_gcode_popup, LV_EVENT_PRESSED, (void *)0);
                            add_style_light_deep_button(obj);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0x5a5c5c), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x717373), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj35 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf4f6f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "CLOSE");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj36 = obj;
                            lv_obj_set_pos(obj, 152, 64);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Position");
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj37 = obj;
                            lv_obj_set_pos(obj, 271, 64);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "TMC status");
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj38 = obj;
                            lv_obj_set_pos(obj, 30, 120);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Temps");
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj39 = obj;
                            lv_obj_set_pos(obj, 152, 120);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Settings");
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj40 = obj;
                            lv_obj_set_pos(obj, 273, 120);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Motors Off");
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj41 = obj;
                            lv_obj_set_pos(obj, 30, 176);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Home All");
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj42 = obj;
                            lv_obj_set_pos(obj, 151, 176);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Bed Level");
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj43 = obj;
                            lv_obj_set_pos(obj, 260, 176);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xd1cece), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Emerg  Stop");
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj44 = obj;
                            lv_obj_set_pos(obj, 129, 21);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "SEND GCODE");
                        }
                        {
                            // CustomGcode
                            lv_obj_t *obj = lv_textarea_create(parent_obj);
                            objects.custom_gcode = obj;
                            lv_obj_set_pos(obj, 14, 230);
                            lv_obj_set_size(obj, 230, 45);
                            lv_textarea_set_max_length(obj, 128);
                            lv_textarea_set_placeholder_text(obj, "Custom command...");
                            lv_textarea_set_one_line(obj, false);
                            lv_textarea_set_password_mode(obj, false);
                            lv_obj_add_event_cb(obj, action_show_keyboard, LV_EVENT_FOCUSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e1e1e), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0x9b9999), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xbdbdbd), LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 255, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            // DateYearLabelMainScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.date_year_label_main_screen = obj;
            lv_obj_set_pos(obj, 638, 7);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf3f2f2), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Aug 14 1956");
        }
    }
    
    tick_screen_main_screen();
}

void tick_screen_main_screen() {
}

void create_screen_print_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.print_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj45 = obj;
            lv_obj_set_pos(obj, 0, 1);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x212121), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1c1c1c), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Print_ReadyLabelPrintScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.print_ready_label_print_screen = obj;
                    lv_obj_set_pos(obj, 124, 26);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "READY");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj46 = obj;
                    lv_obj_set_pos(obj, 99, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "PRINTER STATUS:");
                }
            }
        }
        {
            // JobLabelPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.job_label_print_screen = obj;
            lv_obj_set_pos(obj, 308, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
            lv_obj_set_scroll_dir(obj, LV_DIR_LEFT);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_START);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_START);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfaf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Project.gcode");
        }
        {
            // WifiIconLabelPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.wifi_icon_label_print_screen = obj;
            lv_obj_set_pos(obj, 763, 4);
            lv_obj_set_size(obj, 30, 20);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbfbfb), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF1EB");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 8, 68);
            lv_obj_set_size(obj, 300, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj47 = obj;
                    lv_obj_set_pos(obj, 383, 361);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "C");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj48 = obj;
                    lv_obj_set_pos(obj, 22, 65);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Target:");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj49 = obj;
            lv_obj_set_pos(obj, 22, 85);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "NOZZLE");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj50 = obj;
            lv_obj_set_pos(obj, 308, 34);
            lv_obj_set_size(obj, 491, 23);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x252525), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // NozzleArc
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.nozzle_arc = obj;
            lv_obj_set_pos(obj, 128, 76);
            lv_obj_set_size(obj, 170, 170);
            lv_arc_set_range(obj, 0, 300);
            lv_arc_set_value(obj, 215);
            lv_arc_set_bg_end_angle(obj, 405);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
            lv_obj_set_scroll_dir(obj, LV_DIR_ALL);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x767b7b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 12, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf51303), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0x00f4ff), 64), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // BedArc
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.bed_arc = obj;
            lv_obj_set_pos(obj, 128, 255);
            lv_obj_set_size(obj, 170, 170);
            lv_arc_set_range(obj, 0, 120);
            lv_arc_set_value(obj, 60);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
            lv_obj_set_scroll_dir(obj, LV_DIR_ALL);
            lv_obj_set_style_arc_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x767b7b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xfba002), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf32b05), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfba002), 64), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj51 = obj;
            lv_obj_set_pos(obj, 43, 271);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "BED");
        }
        {
            // NozzleArcTempPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.nozzle_arc_temp_print_screen = obj;
            lv_obj_set_pos(obj, 152, 135);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_46, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "215");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj52 = obj;
            lv_obj_set_pos(obj, 238, 152);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0x00f4ff), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj53 = obj;
            lv_obj_set_pos(obj, 245, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfba002), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "C");
        }
        {
            // BedArcTempPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.bed_arc_temp_print_screen = obj;
            lv_obj_set_pos(obj, 157, 324);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_46, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "60");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj54 = obj;
            lv_obj_set_pos(obj, 31, 317);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Target:");
        }
        {
            // BedArcTargetPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.bed_arc_target_print_screen = obj;
            lv_obj_set_pos(obj, 45, 362);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "60");
        }
        {
            // NozzleArcTargetPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.nozzle_arc_target_print_screen = obj;
            lv_obj_set_pos(obj, 45, 178);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "215");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj55 = obj;
            lv_obj_set_pos(obj, 22, 416);
            lv_obj_set_size(obj, 126, 43);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj56 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "???");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj57 = obj;
            lv_obj_set_pos(obj, 170, 416);
            lv_obj_set_size(obj, 126, 43);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj58 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "???");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 316, 43);
            lv_obj_set_size(obj, 210, 198);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj59 = obj;
            lv_obj_set_pos(obj, 328, 53);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbfafa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "AXIS POSITIONS (mm)");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj60 = obj;
            lv_obj_set_pos(obj, 409, -88);
            lv_obj_set_size(obj, 122, 45);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e1e1e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x1e1e1e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj61 = obj;
            lv_obj_set_pos(obj, 391, 125);
            lv_obj_set_size(obj, 122, 45);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Y_PositionPrintScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_position_print_screen = obj;
                    lv_obj_set_pos(obj, 11, 5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x292828), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "89.15");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj62 = obj;
                    lv_obj_set_pos(obj, -4, -50);
                    lv_obj_set_size(obj, 122, 45);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Y_PositionPrintScreen_2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.y_position_print_screen_2 = obj;
                            lv_obj_set_pos(obj, 14, -1);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "89.15");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj63 = obj;
            lv_obj_set_pos(obj, 393, 179);
            lv_obj_set_size(obj, 122, 45);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z_PositionPrintScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z_position_print_screen = obj;
                    lv_obj_set_pos(obj, 10, 6);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0x000000), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x292828), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "45.32");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj64 = obj;
            lv_obj_set_pos(obj, 340, 76);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_38, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj65 = obj;
            lv_obj_set_pos(obj, 341, 130);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_38, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj66 = obj;
            lv_obj_set_pos(obj, 341, 178);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_38, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 318, 254);
            lv_obj_set_size(obj, 206, 73);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj67 = obj;
            lv_obj_set_pos(obj, 382, 261);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfefcfc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "FAN SPEED:");
        }
        {
            // FanSpeedPercentage
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fan_speed_percentage = obj;
            lv_obj_set_pos(obj, 479, 262);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbfafa), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "50%");
        }
        {
            // FanSpeedSliderPrintScreen
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.fan_speed_slider_print_screen = obj;
            lv_obj_set_pos(obj, 372, 295);
            lv_obj_set_size(obj, 130, 10);
            lv_slider_set_value(obj, 50, LV_ANIM_OFF);
            lv_obj_add_event_cb(obj, action_fan_speed_slider_print_screen, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf1f3f5), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0x00f4ff), 64), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // Fan
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.fan = obj;
            lv_obj_set_pos(obj, 327, 260);
            lv_obj_set_size(obj, 37, 36);
            lv_img_set_src(obj, &img_fan);
            lv_img_set_zoom(obj, 34);
            lv_img_set_size_mode(obj, LV_IMG_SIZE_MODE_REAL);
            lv_obj_set_style_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // PIDBedButtonPrintScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.pid_bed_button_print_screen = obj;
            lv_obj_set_pos(obj, 318, 338);
            lv_obj_set_size(obj, 126, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj68 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "PID BED");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 535, 43);
            lv_obj_set_size(obj, 255, 133);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 535, 186);
            lv_obj_set_size(obj, 254, 138);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 318, 334);
            lv_obj_set_size(obj, 471, 138);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj69 = obj;
            lv_obj_set_pos(obj, 596, 53);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfcfafa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "JOB PROGRESS");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj70 = obj;
            lv_obj_set_pos(obj, 600, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Printing:");
        }
        {
            // PrintingProgressPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.printing_progress_print_screen = obj;
            lv_obj_set_pos(obj, 677, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf5f7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "68%");
        }
        {
            // PrintingProgressSliderPrintScreen
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.printing_progress_slider_print_screen = obj;
            lv_obj_set_pos(obj, 552, 107);
            lv_obj_set_size(obj, 223, 10);
            lv_slider_set_value(obj, 68, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0x000000), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj71 = obj;
            lv_obj_set_pos(obj, 564, 126);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfaf8f8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Time Elapsed:");
        }
        {
            // TimeElapsed
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_elapsed = obj;
            lv_obj_set_pos(obj, 712, 126);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf6f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "1h 14m");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj72 = obj;
            lv_obj_set_pos(obj, 563, 149);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf7f4f4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Time Remaining:");
        }
        {
            // TimeRemaining
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_remaining = obj;
            lv_obj_set_pos(obj, 712, 152);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfcf9f9), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "0h 35m");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj73 = obj;
            lv_obj_set_pos(obj, 593, 196);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf7f4f4), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "JOB CONTROLS");
        }
        {
            // PauseButtonPrintScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.pause_button_print_screen = obj;
            lv_obj_set_pos(obj, 540, 223);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_add_event_cb(obj, action_pause_resume_button_label, LV_EVENT_CLICKED, (void *)0);
            add_style_warning(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8f4f4), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // PauseResumeButtonLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.pause_resume_button_label = obj;
                    lv_obj_set_pos(obj, 12, 4);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "PAUSE");
                }
            }
        }
        {
            // StopButtonPrintScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.stop_button_print_screen = obj;
            lv_obj_set_pos(obj, 665, 223);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_add_event_cb(obj, action_stop_button_print_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_danger(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfaf9f9), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "STOP");
                }
            }
        }
        {
            // TuneButtonPrintScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.tune_button_print_screen = obj;
            lv_obj_set_pos(obj, 540, 276);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfdfdfd), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj74 = obj;
                    lv_obj_set_pos(obj, 16, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x090909), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "TUNE");
                }
            }
        }
        {
            // ChangeFilamentButtonPrintScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.change_filament_button_print_screen = obj;
            lv_obj_set_pos(obj, 665, 276);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf5f2f2), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj75 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x0b0b0b), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_line_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "CHANGE \nFILAMENT");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj76 = obj;
            lv_obj_set_pos(obj, 490, 342);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "STATUS LOG");
        }
        {
            // PrintStatusLogPrintScreen
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.print_status_log_print_screen = obj;
            lv_obj_set_pos(obj, 328, 368);
            lv_obj_set_size(obj, 449, 95);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x292828), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfaf5f5), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf4efef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj77 = obj;
            lv_obj_set_pos(obj, 548, 233);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf5f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf04c");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 552, 283);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf013");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj78 = obj;
            lv_obj_set_pos(obj, 674, 231);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf7f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf04d");
        }
        {
            // BackMainButtonPrintScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_print_screen = obj;
            lv_obj_set_pos(obj, 10, 9);
            lv_obj_set_size(obj, 79, 39);
            lv_obj_add_event_cb(obj, action_main_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj79 = obj;
                    lv_obj_set_pos(obj, -1, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // TimeLabelPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_label_print_screen = obj;
            lv_obj_set_pos(obj, 588, 8);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xe4e3e3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_label_set_text(obj, "2:00 PM");
        }
        {
            // DateYearLabelPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.date_year_label_print_screen = obj;
            lv_obj_set_pos(obj, 663, 7);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xe4e3e3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_label_set_text(obj, "Aug 14 1956");
        }
        {
            // Printer
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer = obj;
            lv_obj_set_pos(obj, 238, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            // X_PositionPrintScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.x_position_print_screen = obj;
            lv_obj_set_pos(obj, 402, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x292828), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_post(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_label_set_text_static(obj, "152.40");
        }
    }
    
    tick_screen_print_screen();
}

void tick_screen_print_screen() {
}

void create_screen_stepper_driver_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.stepper_driver_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj80 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8fafc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj81 = obj;
                    lv_obj_set_pos(obj, 211, 11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "TMC DRIVER SETTINGS");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj82 = obj;
            lv_obj_set_pos(obj, 404, 62);
            lv_obj_set_size(obj, 384, 202);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Y_StealthchopToggle
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.y_stealthchop_toggle = obj;
                    lv_obj_set_pos(obj, 314, 101);
                    lv_obj_set_size(obj, 50, 25);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf93703), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfcfcfc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj83 = obj;
                    lv_obj_set_pos(obj, 49, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Y Axis");
                }
                {
                    // Y_RMS_Current
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_rms_current = obj;
                    lv_obj_set_pos(obj, 310, 37);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "850");
                }
                {
                    // Y_StallguardThreshold
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_stallguard_threshold = obj;
                    lv_obj_set_pos(obj, 350, 67);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "-48");
                }
                {
                    // Y_HybridThreshold
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_hybrid_threshold = obj;
                    lv_obj_set_pos(obj, 301, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "120");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj84 = obj;
                    lv_obj_set_pos(obj, 337, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mm/s");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj85 = obj;
                    lv_obj_set_pos(obj, 351, 37);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mA");
                }
                {
                    // Y_warning_icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_warning_icon = obj;
                    lv_obj_set_pos(obj, 336, 164);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x07f4f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "OK");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj86 = obj;
                    lv_obj_set_pos(obj, 8, 37);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "RMS Current");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj87 = obj;
                    lv_obj_set_pos(obj, 8, 68);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StallGuard Threshold");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj88 = obj;
                    lv_obj_set_pos(obj, 7, 100);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StealthChop enable");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj89 = obj;
                    lv_obj_set_pos(obj, 48, 166);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Status");
                }
                {
                    // Y_RMS_CurrentSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.y_rms_current_slider = obj;
                    lv_obj_set_pos(obj, 176, 39);
                    lv_obj_set_size(obj, 123, 10);
                    lv_slider_set_range(obj, 100, 2000);
                    lv_slider_set_value(obj, 750, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // Y_StallguardThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.y_stallguard_threshold_slider = obj;
                    lv_obj_set_pos(obj, 178, 71);
                    lv_obj_set_size(obj, 123, 10);
                    lv_slider_set_range(obj, -64, 64);
                    lv_slider_set_value(obj, -48, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // Y_HybridThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.y_hybrid_threshold_slider = obj;
                    lv_obj_set_pos(obj, 164, 138);
                    lv_obj_set_size(obj, 123, 10);
                    lv_slider_set_range(obj, 0, 300);
                    lv_slider_set_value(obj, 120, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj90 = obj;
                    lv_obj_set_pos(obj, 8, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Hybrid Threshold");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj91 = obj;
                    lv_obj_set_pos(obj, 6, 157);
                    lv_obj_set_size(obj, 370, 35);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xe0e0e0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Y_Status_Icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_status_icon = obj;
                    lv_obj_set_pos(obj, 8, 160);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf058");
                }
            }
        }
        {
            // BackMainButtonStepperDriverScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_stepper_driver_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj92 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_4
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_4 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj93 = obj;
            lv_obj_set_pos(obj, 15, 271);
            lv_obj_set_size(obj, 384, 202);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Z_AutoAlignButtonStepperDriverScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.z_auto_align_button_stepper_driver_screen = obj;
            lv_obj_set_pos(obj, 33, 292);
            lv_obj_set_size(obj, 100, 50);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj94 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf2f1f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Z Auto\nAlign");
                }
            }
        }
        {
            // BedLevelButtonStepperDriverScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.bed_level_button_stepper_driver_screen = obj;
            lv_obj_set_pos(obj, 33, 370);
            lv_obj_set_size(obj, 100, 50);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj95 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf2f1f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Bed Level");
                }
            }
        }
        {
            // DisableSteppersButtonStepperDriverScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.disable_steppers_button_stepper_driver_screen = obj;
            lv_obj_set_pos(obj, 273, 300);
            lv_obj_set_size(obj, 100, 50);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj96 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf2f1f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Disable\nSteppers");
                }
            }
        }
        {
            // SaveSettingsButtonStepperDriverScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_settings_button_stepper_driver_screen = obj;
            lv_obj_set_pos(obj, 273, 376);
            lv_obj_set_size(obj, 100, 50);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj97 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf2f1f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Save\nSettings");
                }
            }
        }
        {
            // Z_AxisSettingsButtonStepperDriverScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.z_axis_settings_button_stepper_driver_screen = obj;
            lv_obj_set_pos(obj, 157, 292);
            lv_obj_set_size(obj, 100, 134);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj98 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf2f1f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "      Z\n   Axis \n\nSettings");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj99 = obj;
            lv_obj_set_pos(obj, 10, 62);
            lv_obj_set_size(obj, 384, 202);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // X_StealthchopToggle
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.x_stealthchop_toggle = obj;
                    lv_obj_set_pos(obj, 314, 101);
                    lv_obj_set_size(obj, 50, 25);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf93703), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfcfcfc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj100 = obj;
                    lv_obj_set_pos(obj, 49, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "X Axis");
                }
                {
                    // X_RMS_Current
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_rms_current = obj;
                    lv_obj_set_pos(obj, 310, 37);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "850");
                }
                {
                    // X_StallguardThreshold
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_stallguard_threshold = obj;
                    lv_obj_set_pos(obj, 350, 67);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "-64");
                }
                {
                    // X_HybridThreshold
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_hybrid_threshold = obj;
                    lv_obj_set_pos(obj, 301, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "120");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj101 = obj;
                    lv_obj_set_pos(obj, 337, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mm/s");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj102 = obj;
                    lv_obj_set_pos(obj, 351, 37);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mA");
                }
                {
                    // X_warning_icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_warning_icon = obj;
                    lv_obj_set_pos(obj, 336, 164);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x07f4f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "OK");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj103 = obj;
                    lv_obj_set_pos(obj, 8, 37);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "RMS Current");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj104 = obj;
                    lv_obj_set_pos(obj, 8, 68);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StallGuard Threshold");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj105 = obj;
                    lv_obj_set_pos(obj, 7, 100);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StealthChop enable");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj106 = obj;
                    lv_obj_set_pos(obj, 48, 166);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Status");
                }
                {
                    // X_RMS_CurrentSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.x_rms_current_slider = obj;
                    lv_obj_set_pos(obj, 176, 39);
                    lv_obj_set_size(obj, 123, 10);
                    lv_slider_set_range(obj, 100, 2000);
                    lv_slider_set_value(obj, 850, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // X_StallguardThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.x_stallguard_threshold_slider = obj;
                    lv_obj_set_pos(obj, 178, 71);
                    lv_obj_set_size(obj, 123, 10);
                    lv_slider_set_range(obj, -64, 64);
                    lv_slider_set_value(obj, -64, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // X_HybridThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.x_hybrid_threshold_slider = obj;
                    lv_obj_set_pos(obj, 164, 138);
                    lv_obj_set_size(obj, 123, 10);
                    lv_slider_set_range(obj, 0, 300);
                    lv_slider_set_value(obj, 120, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj107 = obj;
                    lv_obj_set_pos(obj, 8, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Hybrid Threshold");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj108 = obj;
                    lv_obj_set_pos(obj, 6, 157);
                    lv_obj_set_size(obj, 370, 35);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xe0e0e0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // X_Status_Icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_status_icon = obj;
                    lv_obj_set_pos(obj, 8, 160);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf058");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj109 = obj;
            lv_obj_set_pos(obj, 404, 271);
            lv_obj_set_size(obj, 384, 202);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // E0_StealthchopToggle
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.e0_stealthchop_toggle = obj;
                    lv_obj_set_pos(obj, 314, 101);
                    lv_obj_set_size(obj, 50, 25);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf93703), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfcfcfc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj110 = obj;
                    lv_obj_set_pos(obj, 49, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "E0 Axis");
                }
                {
                    // E0_RMS_Current
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e0_rms_current = obj;
                    lv_obj_set_pos(obj, 310, 37);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "850");
                }
                {
                    // E0_StallguardThreshold
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e0_stallguard_threshold = obj;
                    lv_obj_set_pos(obj, 350, 67);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "-48");
                }
                {
                    // E0_HybridThreshold
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e0_hybrid_threshold = obj;
                    lv_obj_set_pos(obj, 301, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "120");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj111 = obj;
                    lv_obj_set_pos(obj, 337, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mm/s");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj112 = obj;
                    lv_obj_set_pos(obj, 351, 37);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mA");
                }
                {
                    // E0_warning_icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e0_warning_icon = obj;
                    lv_obj_set_pos(obj, 336, 164);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x07f4f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "OK");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj113 = obj;
                    lv_obj_set_pos(obj, 8, 37);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "RMS Current");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj114 = obj;
                    lv_obj_set_pos(obj, 8, 68);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StallGuard Threshold");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj115 = obj;
                    lv_obj_set_pos(obj, 7, 100);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StealthChop enable");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj116 = obj;
                    lv_obj_set_pos(obj, 48, 166);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Status");
                }
                {
                    // E0_RMS_CurrentSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.e0_rms_current_slider = obj;
                    lv_obj_set_pos(obj, 176, 39);
                    lv_obj_set_size(obj, 123, 10);
                    lv_slider_set_range(obj, 100, 2000);
                    lv_slider_set_value(obj, 850, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // E0_StallguardThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.e0_stallguard_threshold_slider = obj;
                    lv_obj_set_pos(obj, 178, 71);
                    lv_obj_set_size(obj, 123, 10);
                    lv_slider_set_range(obj, -64, 64);
                    lv_slider_set_value(obj, -48, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // E0_HybridThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.e0_hybrid_threshold_slider = obj;
                    lv_obj_set_pos(obj, 164, 138);
                    lv_obj_set_size(obj, 123, 10);
                    lv_slider_set_range(obj, 0, 300);
                    lv_slider_set_value(obj, 120, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj117 = obj;
                    lv_obj_set_pos(obj, 8, 134);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Hybrid Threshold");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj118 = obj;
                    lv_obj_set_pos(obj, 6, 157);
                    lv_obj_set_size(obj, 370, 35);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xe0e0e0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // E0_Status_Icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e0_status_icon = obj;
                    lv_obj_set_pos(obj, 8, 160);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf058");
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 413, 66);
            lv_obj_set_size(obj, 32, 34);
            lv_img_set_src(obj, &img_stepper_white);
            lv_img_set_zoom(obj, 100);
            lv_img_set_size_mode(obj, LV_IMG_SIZE_MODE_REAL);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 20, 66);
            lv_obj_set_size(obj, 32, 34);
            lv_img_set_src(obj, &img_stepper_white);
            lv_img_set_zoom(obj, 100);
            lv_img_set_size_mode(obj, LV_IMG_SIZE_MODE_REAL);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 412, 275);
            lv_obj_set_size(obj, 32, 34);
            lv_img_set_src(obj, &img_stepper_white);
            lv_img_set_zoom(obj, 100);
            lv_img_set_size_mode(obj, LV_IMG_SIZE_MODE_REAL);
        }
    }
    
    tick_screen_stepper_driver_screen();
}

void tick_screen_stepper_driver_screen() {
}

void create_screen_z_stepper_driver_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.z_stepper_driver_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj119 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj120 = obj;
                    lv_obj_set_pos(obj, 248, 11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Z DRIVER SETTINGS");
                }
            }
        }
        {
            // BackMainButtonZ_StepperDriverScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_z_stepper_driver_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj121 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_8
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_8 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj122 = obj;
            lv_obj_set_pos(obj, 8, 66);
            lv_obj_set_size(obj, 260, 389);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z1_StealthchopToggle
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.z1_stealthchop_toggle = obj;
                    lv_obj_set_pos(obj, 197, 220);
                    lv_obj_set_size(obj, 50, 25);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf93703), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfcfcfc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj123 = obj;
                    lv_obj_set_pos(obj, 13, 14);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_38, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Z 1 ");
                }
                {
                    // Z1_RMS_CurrentLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z1_rms_current_label = obj;
                    lv_obj_set_pos(obj, 179, 74);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "850");
                }
                {
                    // Z1_StallguardThresholdLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z1_stallguard_threshold_label = obj;
                    lv_obj_set_pos(obj, 214, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "-20");
                }
                {
                    // Z1_HybridThresholdLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z1_hybrid_threshold_label = obj;
                    lv_obj_set_pos(obj, 179, 258);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "120");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj124 = obj;
                    lv_obj_set_pos(obj, 205, 258);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mm/s");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj125 = obj;
                    lv_obj_set_pos(obj, 222, 74);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mA");
                }
                {
                    // Z1_warning_icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z1_warning_icon = obj;
                    lv_obj_set_pos(obj, 208, 344);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "OK");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj126 = obj;
                    lv_obj_set_pos(obj, 15, 74);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "RMS Current");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj127 = obj;
                    lv_obj_set_pos(obj, 13, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StallGuard Threshold");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj128 = obj;
                    lv_obj_set_pos(obj, 13, 225);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StealthChop enable");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj129 = obj;
                    lv_obj_set_pos(obj, 38, 348);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Status");
                }
                {
                    // Z1_RMS_CurrentSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.z1_rms_current_slider = obj;
                    lv_obj_set_pos(obj, 15, 113);
                    lv_obj_set_size(obj, 225, 10);
                    lv_slider_set_range(obj, 100, 2000);
                    lv_slider_set_value(obj, 850, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // Z1_StallguardThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.z1_stallguard_threshold_slider = obj;
                    lv_obj_set_pos(obj, 8, 184);
                    lv_obj_set_size(obj, 227, 10);
                    lv_slider_set_range(obj, -64, 64);
                    lv_slider_set_value(obj, -20, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // Z1HybridThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.z1_hybrid_threshold_slider = obj;
                    lv_obj_set_pos(obj, 15, 299);
                    lv_obj_set_size(obj, 225, 10);
                    lv_slider_set_range(obj, 0, 300);
                    lv_slider_set_value(obj, 120, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj130 = obj;
                    lv_obj_set_pos(obj, 13, 258);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Hybrid Threshold");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj131 = obj;
                    lv_obj_set_pos(obj, 5, 339);
                    lv_obj_set_size(obj, 242, 35);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xe0e0e0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Z1_Status_Icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z1_status_icon = obj;
                    lv_obj_set_pos(obj, 8, 342);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf058");
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 223, 81);
            lv_obj_set_size(obj, 32, 34);
            lv_img_set_src(obj, &img_stepper_white);
            lv_img_set_zoom(obj, 120);
            lv_img_set_size_mode(obj, LV_IMG_SIZE_MODE_REAL);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 270, 67);
            lv_obj_set_size(obj, 260, 389);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z2_StealthchopToggle
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.z2_stealthchop_toggle = obj;
                    lv_obj_set_pos(obj, 197, 220);
                    lv_obj_set_size(obj, 50, 25);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf93703), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfcfcfc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj132 = obj;
                    lv_obj_set_pos(obj, 13, 14);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_38, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Z 2 ");
                }
                {
                    // Z2_RMS_CurrentLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z2_rms_current_label = obj;
                    lv_obj_set_pos(obj, 179, 74);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "750");
                }
                {
                    // Z2_StallguardThresholdLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z2_stallguard_threshold_label = obj;
                    lv_obj_set_pos(obj, 214, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "-25");
                }
                {
                    // Z2_HybridThresholdLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z2_hybrid_threshold_label = obj;
                    lv_obj_set_pos(obj, 179, 258);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "100");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj133 = obj;
                    lv_obj_set_pos(obj, 205, 258);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mm/s");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj134 = obj;
                    lv_obj_set_pos(obj, 222, 74);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mA");
                }
                {
                    // Z2_warning_icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z2_warning_icon = obj;
                    lv_obj_set_pos(obj, 208, 344);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x07f4f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "OK");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj135 = obj;
                    lv_obj_set_pos(obj, 15, 74);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "RMS Current");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj136 = obj;
                    lv_obj_set_pos(obj, 13, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StallGuard Threshold");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj137 = obj;
                    lv_obj_set_pos(obj, 13, 225);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StealthChop enable");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj138 = obj;
                    lv_obj_set_pos(obj, 38, 348);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Status");
                }
                {
                    // Z2_RMS_CurrentSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.z2_rms_current_slider = obj;
                    lv_obj_set_pos(obj, 15, 113);
                    lv_obj_set_size(obj, 225, 10);
                    lv_slider_set_range(obj, 100, 2000);
                    lv_slider_set_value(obj, 750, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // Z2_StallguardThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.z2_stallguard_threshold_slider = obj;
                    lv_obj_set_pos(obj, 8, 184);
                    lv_obj_set_size(obj, 227, 10);
                    lv_slider_set_range(obj, -64, 64);
                    lv_slider_set_value(obj, -25, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // Z2HybridThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.z2_hybrid_threshold_slider = obj;
                    lv_obj_set_pos(obj, 15, 299);
                    lv_obj_set_size(obj, 225, 10);
                    lv_slider_set_range(obj, 0, 300);
                    lv_slider_set_value(obj, 100, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj139 = obj;
                    lv_obj_set_pos(obj, 13, 258);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Hybrid Threshold");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj140 = obj;
                    lv_obj_set_pos(obj, 5, 339);
                    lv_obj_set_size(obj, 242, 35);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xe0e0e0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Z2_Status_Icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z2_status_icon = obj;
                    lv_obj_set_pos(obj, 8, 342);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf058");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj141 = obj;
            lv_obj_set_pos(obj, 533, 63);
            lv_obj_set_size(obj, 260, 389);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z3_StealthchopToggle
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.z3_stealthchop_toggle = obj;
                    lv_obj_set_pos(obj, 197, 220);
                    lv_obj_set_size(obj, 50, 25);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf93703), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfcfcfc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj142 = obj;
                    lv_obj_set_pos(obj, 13, 14);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf8e302), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_38, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Z 3 ");
                }
                {
                    // Z3_RMS_CurrentLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z3_rms_current_label = obj;
                    lv_obj_set_pos(obj, 179, 74);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "900");
                }
                {
                    // Z3_StallguardThresholdLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z3_stallguard_threshold_label = obj;
                    lv_obj_set_pos(obj, 214, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "-10");
                }
                {
                    // Z3_HybridThresholdLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z3_hybrid_threshold_label = obj;
                    lv_obj_set_pos(obj, 179, 258);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "150");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj143 = obj;
                    lv_obj_set_pos(obj, 205, 258);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mm/s");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj144 = obj;
                    lv_obj_set_pos(obj, 222, 74);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "mA");
                }
                {
                    // Z3_warning_icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z3_warning_icon = obj;
                    lv_obj_set_pos(obj, 208, 344);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf8e302), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "OK");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj145 = obj;
                    lv_obj_set_pos(obj, 15, 74);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "RMS Current");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj146 = obj;
                    lv_obj_set_pos(obj, 13, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StallGuard Threshold");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj147 = obj;
                    lv_obj_set_pos(obj, 13, 225);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "StealthChop enable");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj148 = obj;
                    lv_obj_set_pos(obj, 38, 348);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Status");
                }
                {
                    // Z3_RMS_CurrentSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.z3_rms_current_slider = obj;
                    lv_obj_set_pos(obj, 15, 113);
                    lv_obj_set_size(obj, 225, 10);
                    lv_slider_set_range(obj, 100, 2000);
                    lv_slider_set_value(obj, 900, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf8e302), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf8e302), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf8e302), LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf8e302), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // Z3_StallguardThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.z3_stallguard_threshold_slider = obj;
                    lv_obj_set_pos(obj, 8, 184);
                    lv_obj_set_size(obj, 227, 10);
                    lv_slider_set_range(obj, -64, 64);
                    lv_slider_set_value(obj, -10, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf8e302), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf8e302), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // Z3HybridThresholdSlider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.z3_hybrid_threshold_slider = obj;
                    lv_obj_set_pos(obj, 15, 299);
                    lv_obj_set_size(obj, 225, 10);
                    lv_slider_set_range(obj, 0, 300);
                    lv_slider_set_value(obj, 150, LV_ANIM_OFF);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf8e302), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf8e302), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj149 = obj;
                    lv_obj_set_pos(obj, 13, 258);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Hybrid Threshold");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj150 = obj;
                    lv_obj_set_pos(obj, 5, 339);
                    lv_obj_set_size(obj, 242, 35);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xe0e0e0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Z3_Status_Icon
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z3_status_icon = obj;
                    lv_obj_set_pos(obj, 8, 342);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf8e302), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf058");
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 483, 81);
            lv_obj_set_size(obj, 32, 34);
            lv_img_set_src(obj, &img_stepper_white);
            lv_img_set_zoom(obj, 120);
            lv_img_set_size_mode(obj, LV_IMG_SIZE_MODE_REAL);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 746, 81);
            lv_obj_set_size(obj, 32, 34);
            lv_img_set_src(obj, &img_stepper_white);
            lv_img_set_zoom(obj, 120);
            lv_img_set_size_mode(obj, LV_IMG_SIZE_MODE_REAL);
        }
    }
    
    tick_screen_z_stepper_driver_screen();
}

void tick_screen_z_stepper_driver_screen() {
}

void create_screen_jog_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.jog_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x111518), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj151 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfbfbfc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj152 = obj;
                    lv_obj_set_pos(obj, 361, 9);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "JOG");
                }
            }
        }
        {
            // BackMainButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_jog_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj153 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_5
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_5 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj154 = obj;
            lv_obj_set_pos(obj, 183, 67);
            lv_obj_set_size(obj, 427, 70);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f1f1), 64), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f1f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj155 = obj;
            lv_obj_set_pos(obj, 244, 75);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_light_deep_text(obj);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdf9f9), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj156 = obj;
            lv_obj_set_pos(obj, 389, 75);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_light_deep_text(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbfbfb), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj157 = obj;
            lv_obj_set_pos(obj, 527, 75);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_light_deep_text(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfefefe), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z");
        }
        {
            // X_PositionLabelJogScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.x_position_label_jog_screen = obj;
            lv_obj_set_pos(obj, 204, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "123.45");
        }
        {
            // Y_PositionLabelJogScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.y_position_label_jog_screen = obj;
            lv_obj_set_pos(obj, 362, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "98.70");
        }
        {
            // Z_PositionLabelJogScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.z_position_label_jog_screen = obj;
            lv_obj_set_pos(obj, 500, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "15.20");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj158 = obj;
            lv_obj_set_pos(obj, 568, 108);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf3f1f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "mm");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj159 = obj;
            lv_obj_set_pos(obj, 431, 108);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf3f1f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "mm");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj160 = obj;
            lv_obj_set_pos(obj, 282, 107);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf3f1f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "mm");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj161 = obj;
            lv_obj_set_pos(obj, 681, 79);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "HOMING");
        }
        {
            // X_HomeButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.x_home_button_jog_screen = obj;
            lv_obj_set_pos(obj, 650, 112);
            lv_obj_set_size(obj, 131, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 22, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "X");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj162 = obj;
            lv_obj_set_pos(obj, 668, 123);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF015");
        }
        {
            // Y_HomeButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.y_home_button_jog_screen = obj;
            lv_obj_set_pos(obj, 650, 174);
            lv_obj_set_size(obj, 131, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 22, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Y");
                }
            }
        }
        {
            // Z_HomeButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.z_home_button_jog_screen = obj;
            lv_obj_set_pos(obj, 650, 235);
            lv_obj_set_size(obj, 131, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 22, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Z");
                }
            }
        }
        {
            // ALL_HomeButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.all_home_button_jog_screen = obj;
            lv_obj_set_pos(obj, 650, 297);
            lv_obj_set_size(obj, 131, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj163 = obj;
                    lv_obj_set_pos(obj, 22, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "ALL");
                }
            }
        }
        {
            // MottorOffButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.mottor_off_button_jog_screen = obj;
            lv_obj_set_pos(obj, 650, 382);
            lv_obj_set_size(obj, 131, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj164 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "MOTORS OFF");
                }
            }
        }
        {
            // Z_AutoAlignButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.z_auto_align_button_jog_screen = obj;
            lv_obj_set_pos(obj, 18, 175);
            lv_obj_set_size(obj, 143, 50);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 1, -1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Z Auto-Align");
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 250, 147);
            lv_obj_set_size(obj, 289, 200);
            lv_img_set_src(obj, &img_jog);
            lv_img_set_zoom(obj, 170);
            lv_img_set_size_mode(obj, LV_IMG_SIZE_MODE_REAL);
        }
        {
            // X_LeftButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.x_left_button_jog_screen = obj;
            lv_obj_set_pos(obj, 262, 216);
            lv_obj_set_size(obj, 80, 70);
            add_style_light_deep_button(obj);
            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x111518), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Y_UpButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.y_up_button_jog_screen = obj;
            lv_obj_set_pos(obj, 356, 155);
            lv_obj_set_size(obj, 80, 60);
            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0x111518), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0x111518), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0x111518), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x111518), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0x111518), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // X_RightButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.x_right_button_jog_screen = obj;
            lv_obj_set_pos(obj, 449, 216);
            lv_obj_set_size(obj, 80, 70);
            add_style_light_deep_button(obj);
            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj165 = obj;
                    lv_obj_set_pos(obj, 3, 16);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "X +");
                }
            }
        }
        {
            // Y_DownButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.y_down_button_jog_screen = obj;
            lv_obj_set_pos(obj, 356, 279);
            lv_obj_set_size(obj, 80, 60);
            add_style_light_deep_button(obj);
            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0x1e2126), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj166 = obj;
            lv_obj_set_pos(obj, -6, -36);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y +");
        }
        {
            // Z_UpButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.z_up_button_jog_screen = obj;
            lv_obj_set_pos(obj, 465, 322);
            lv_obj_set_size(obj, 100, 65);
            add_style_light_deep_button(obj);
        }
        {
            // Z_DownButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.z_down_button_jog_screen = obj;
            lv_obj_set_pos(obj, 223, 322);
            lv_obj_set_size(obj, 100, 65);
            add_style_light_deep_button(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj167 = obj;
            lv_obj_set_pos(obj, -6, 84);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y -");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj168 = obj;
            lv_obj_set_pos(obj, -95, 28);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X -");
        }
        {
            // AutoBedLevelButtonJogScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.auto_bed_level_button_jog_screen = obj;
            lv_obj_set_pos(obj, 18, 254);
            lv_obj_set_size(obj, 143, 50);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Auto-Bed Level");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj169 = obj;
            lv_obj_set_pos(obj, 382, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf062");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj170 = obj;
            lv_obj_set_pos(obj, 477, 218);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf061");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj171 = obj;
            lv_obj_set_pos(obj, 382, 280);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf063");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj172 = obj;
            lv_obj_set_pos(obj, 288, 218);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf060");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj173 = obj;
            lv_obj_set_pos(obj, 669, 185);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF015");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj174 = obj;
            lv_obj_set_pos(obj, 669, 246);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF015");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj175 = obj;
            lv_obj_set_pos(obj, 669, 307);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF015");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj176 = obj;
            lv_obj_set_pos(obj, 118, 129);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z +");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj177 = obj;
            lv_obj_set_pos(obj, -120, 129);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z -");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj178 = obj;
            lv_obj_set_pos(obj, 205, 408);
            lv_obj_set_size(obj, 379, 54);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x0f5bdb), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xe0e0e0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj179 = obj;
            lv_obj_set_pos(obj, 183, 402);
            lv_obj_set_size(obj, 427, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f1f1), 64), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf6f1f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1f2227), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // StepSizeButton_1mm_JogSgreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.step_size_button_1mm_jog_sgreen = obj;
            lv_obj_set_pos(obj, 289, 415);
            lv_obj_set_size(obj, 82, 34);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1f2227), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "1");
                }
            }
        }
        {
            // StepSizeButton_10mm_JogSgreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.step_size_button_10mm_jog_sgreen = obj;
            lv_obj_set_pos(obj, 384, 415);
            lv_obj_set_size(obj, 82, 34);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1f2227), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, -1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "10");
                }
            }
        }
        {
            // StepSizeButton_100mm_JogSgreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.step_size_button_100mm_jog_sgreen = obj;
            lv_obj_set_pos(obj, 478, 415);
            lv_obj_set_size(obj, 82, 34);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1f2227), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "100");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj180 = obj;
            lv_obj_set_pos(obj, 571, 435);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf3f1f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "mm");
        }
        {
            // StepSizeButton_01_JogSgreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.step_size_button_01_jog_sgreen = obj;
            lv_obj_set_pos(obj, 194, 415);
            lv_obj_set_size(obj, 82, 34);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x222121), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0x29abd6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "0.1");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj181 = obj;
            lv_obj_set_pos(obj, 55, 421);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Step Size");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj182 = obj;
            lv_obj_set_pos(obj, 262, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf063");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj183 = obj;
            lv_obj_set_pos(obj, 500, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x29abd6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf062");
        }
    }
    
    tick_screen_jog_screen();
}

void tick_screen_jog_screen() {
}

void create_screen_filament_change_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.filament_change_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj184 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj185 = obj;
                    lv_obj_set_pos(obj, 187, 10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "FILAMENT MANAGEMENT");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj186 = obj;
            lv_obj_set_pos(obj, 8, 64);
            lv_obj_set_size(obj, 388, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfefefe), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj187 = obj;
            lv_obj_set_pos(obj, 400, 64);
            lv_obj_set_size(obj, 388, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfcf8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // BackMainButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj188 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_10
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_10 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj189 = obj;
            lv_obj_set_pos(obj, 453, 77);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "FILAMENT OPERATIONS");
        }
        {
            // RetractButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.retract_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 435, 315);
            lv_obj_set_size(obj, 144, 134);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj190 = obj;
                    lv_obj_set_pos(obj, 0, -45);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf1efeb), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "RETRACT");
                }
            }
        }
        {
            // ExtrudeButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.extrude_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 612, 315);
            lv_obj_set_size(obj, 144, 134);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj191 = obj;
                    lv_obj_set_pos(obj, 0, -45);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf1eeea), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "EXTRUDE");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj192 = obj;
            lv_obj_set_pos(obj, 668, 400);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf3eeee), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "(+)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj193 = obj;
            lv_obj_set_pos(obj, 491, 346);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf3eeee), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "(-)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj194 = obj;
            lv_obj_set_pos(obj, 486, 372);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_60, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xeae6e6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf103");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj195 = obj;
            lv_obj_set_pos(obj, 665, 345);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xeeeaea), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_60, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf102");
        }
        {
            // FilamentLoadButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.filament_load_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 416, 128);
            lv_obj_set_size(obj, 170, 70);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj196 = obj;
                    lv_obj_set_pos(obj, 20, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x0e0e0e), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "   LOAD \nFILAMENT");
                }
            }
        }
        {
            // FilamentUnloadButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.filament_unload_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 605, 128);
            lv_obj_set_size(obj, 170, 70);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj197 = obj;
                    lv_obj_set_pos(obj, 20, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "UNLOAD\nFILAMENT");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj198 = obj;
            lv_obj_set_pos(obj, 616, 142);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf3e5");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj199 = obj;
            lv_obj_set_pos(obj, 424, 136);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf064");
        }
        {
            // StepsPer_1mmButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.steps_per_1mm_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 416, 238);
            lv_obj_set_size(obj, 83, 42);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj200 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf3f2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "1mm");
                }
            }
        }
        {
            // StepsPer_5mmButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.steps_per_5mm_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 507, 238);
            lv_obj_set_size(obj, 83, 43);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj201 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf3f2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "5mm");
                }
            }
        }
        {
            // StepsPer_50mmButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.steps_per_50mm_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 600, 238);
            lv_obj_set_size(obj, 83, 42);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj202 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf3f2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "50mm");
                }
            }
        }
        {
            // StepsPer_100mmButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.steps_per_100mm_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 690, 238);
            lv_obj_set_size(obj, 83, 42);
            add_style_light_deep_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj203 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf3f2f0), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "100mm");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj204 = obj;
            lv_obj_set_pos(obj, 52, 77);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "TEMPERTURE CONTROL");
        }
        {
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.obj205 = obj;
            lv_obj_set_pos(obj, 95, 110);
            lv_obj_set_size(obj, 191, 196);
            lv_arc_set_range(obj, 0, 300);
            lv_arc_set_value(obj, 215);
            lv_arc_set_bg_start_angle(obj, 160);
            lv_arc_set_bg_end_angle(obj, 20);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 18, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_darken(lv_color_hex(0xe0e0e0), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // NozzleTempLabelFilamentChangeScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.nozzle_temp_label_filament_change_screen = obj;
            lv_obj_set_pos(obj, 138, 178);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "210");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj206 = obj;
            lv_obj_set_pos(obj, 148, 152);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "NOZZLE:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj207 = obj;
            lv_obj_set_pos(obj, 211, 179);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj208 = obj;
            lv_obj_set_pos(obj, 207, 178);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "o");
        }
        {
            // ReadyLabelFilamentChangeScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ready_label_filament_change_screen = obj;
            lv_obj_set_pos(obj, 156, 228);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "READY");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj209 = obj;
            lv_obj_set_pos(obj, 17, 413);
            lv_obj_set_size(obj, 370, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x161515), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // TEMP_OkLabelFilamentChangeScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.temp_ok_label_filament_change_screen = obj;
            lv_obj_set_pos(obj, 154, 426);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x13f706), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "TEMP OK");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj210 = obj;
            lv_obj_set_pos(obj, 271, 426);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf40404), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "> 180  C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj211 = obj;
            lv_obj_set_pos(obj, 338, 422);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf40404), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "o");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj212 = obj;
            lv_obj_set_pos(obj, 28, 426);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xede7e7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "STATUS: ");
        }
        {
            // PLATempButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.pla_temp_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 69, 270);
            lv_obj_set_size(obj, 249, 36);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj213 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "PLA  (210  C)");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj214 = obj;
            lv_obj_set_pos(obj, 235, 272);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "o");
        }
        {
            // PETGTempButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.petg_temp_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 70, 320);
            lv_obj_set_size(obj, 249, 36);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj215 = obj;
                    lv_obj_set_pos(obj, 2, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "PETG  (240  C)");
                }
            }
        }
        {
            // CooldownButtonFilamentChangeScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.cooldown_button_filament_change_screen = obj;
            lv_obj_set_pos(obj, 71, 368);
            lv_obj_set_size(obj, 249, 36);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj216 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xe9ecec), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "COOLDOWN");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj217 = obj;
            lv_obj_set_pos(obj, 251, 321);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "o");
        }
    }
    
    tick_screen_filament_change_screen();
}

void tick_screen_filament_change_screen() {
}

void create_screen_motion_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.motion_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj218 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj219 = obj;
                    lv_obj_set_pos(obj, 245, 11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "MOTION SETTINGS");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj220 = obj;
            lv_obj_set_pos(obj, 10, 60);
            lv_obj_set_size(obj, 780, 82);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // BackMainButtonMotionScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_motion_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj221 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_9
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_9 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj222 = obj;
            lv_obj_set_pos(obj, 669, 74);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "E");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj223 = obj;
            lv_obj_set_pos(obj, 45, 90);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // X_StepsLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_steps_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "80.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj224 = obj;
            lv_obj_set_pos(obj, 227, 91);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Y_StepsLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_steps_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "80.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj225 = obj;
            lv_obj_set_pos(obj, 420, 92);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z_StepsLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z_steps_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "400.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj226 = obj;
            lv_obj_set_pos(obj, 610, 92);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // E_StepsLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e_steps_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "93.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj227 = obj;
            lv_obj_set_pos(obj, 482, 74);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj228 = obj;
            lv_obj_set_pos(obj, 290, 74);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj229 = obj;
            lv_obj_set_pos(obj, 110, 74);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj230 = obj;
            lv_obj_set_pos(obj, -8, -168);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Steps/mm");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj231 = obj;
            lv_obj_set_pos(obj, 10, 147);
            lv_obj_set_size(obj, 780, 82);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj232 = obj;
            lv_obj_set_pos(obj, 669, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "E");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj233 = obj;
            lv_obj_set_pos(obj, 45, 176);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // X_MaxAccelerationLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_max_acceleration_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "3000");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj234 = obj;
            lv_obj_set_pos(obj, 227, 177);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Y_MaxAccelerationLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_max_acceleration_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "3000");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj235 = obj;
            lv_obj_set_pos(obj, 420, 178);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z_MaxAccelerationLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z_max_acceleration_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "100");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj236 = obj;
            lv_obj_set_pos(obj, 610, 178);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // E_MaxAccelerationLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e_max_acceleration_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "10000");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj237 = obj;
            lv_obj_set_pos(obj, 482, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj238 = obj;
            lv_obj_set_pos(obj, 290, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj239 = obj;
            lv_obj_set_pos(obj, 110, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj240 = obj;
            lv_obj_set_pos(obj, -8, -80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Max Acceleration");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj241 = obj;
            lv_obj_set_pos(obj, 10, 235);
            lv_obj_set_size(obj, 780, 82);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj242 = obj;
            lv_obj_set_pos(obj, 669, 248);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "E");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj243 = obj;
            lv_obj_set_pos(obj, 45, 265);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // X_MaxFeedRateLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_max_feed_rate_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "500.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj244 = obj;
            lv_obj_set_pos(obj, 227, 265);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Y_MaxFeedRateLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_max_feed_rate_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "500.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj245 = obj;
            lv_obj_set_pos(obj, 420, 265);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z_MaxFeedRateLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z_max_feed_rate_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "60.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj246 = obj;
            lv_obj_set_pos(obj, 610, 265);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // E_MaxFeedRateLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e_max_feed_rate_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "45.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj247 = obj;
            lv_obj_set_pos(obj, 482, 248);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj248 = obj;
            lv_obj_set_pos(obj, 290, 248);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj249 = obj;
            lv_obj_set_pos(obj, 110, 248);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj250 = obj;
            lv_obj_set_pos(obj, -8, 8);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Max Feed Rate");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj251 = obj;
            lv_obj_set_pos(obj, 12, 323);
            lv_obj_set_size(obj, 780, 82);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj252 = obj;
            lv_obj_set_pos(obj, 671, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "E");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj253 = obj;
            lv_obj_set_pos(obj, 47, 353);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // X_JerkLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_jerk_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "10.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj254 = obj;
            lv_obj_set_pos(obj, 229, 353);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Y_JerkLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_jerk_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "10.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj255 = obj;
            lv_obj_set_pos(obj, 422, 353);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z_JerkLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z_jerk_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "0.40");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj256 = obj;
            lv_obj_set_pos(obj, 612, 353);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // E_JerkLabelMotionScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e_jerk_label_motion_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "5.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj257 = obj;
            lv_obj_set_pos(obj, 484, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj258 = obj;
            lv_obj_set_pos(obj, 292, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj259 = obj;
            lv_obj_set_pos(obj, 112, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj260 = obj;
            lv_obj_set_pos(obj, -6, 96);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Jerk");
        }
        {
            // LoadDefaultsButtonMotionScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.load_defaults_button_motion_screen = obj;
            lv_obj_set_pos(obj, 260, 416);
            lv_obj_set_size(obj, 160, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj261 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "LOAD DEFAULTS");
                }
            }
        }
        {
            // SaveButtonMotionScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_button_motion_screen = obj;
            lv_obj_set_pos(obj, 37, 415);
            lv_obj_set_size(obj, 205, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xf80b02), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf80b02), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj262 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfaf8f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "SAVE");
                }
            }
        }
        {
            // MoreSettingsButtonMotionScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.more_settings_button_motion_screen = obj;
            lv_obj_set_pos(obj, 612, 416);
            lv_obj_set_size(obj, 160, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x121212), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj263 = obj;
                    lv_obj_set_pos(obj, 0, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "MORE SETTINGS");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj264 = obj;
            lv_obj_set_pos(obj, 435, 416);
            lv_obj_set_size(obj, 160, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x121212), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj265 = obj;
                    lv_obj_set_pos(obj, 1, -15);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Junction Deviation");
                }
            }
        }
        {
            // JunctionDeviationButtonMotionScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.junction_deviation_button_motion_screen = obj;
            lv_obj_set_pos(obj, 111, 208);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf6f6f6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "0.012");
        }
    }
    
    tick_screen_motion_screen();
}

void tick_screen_motion_screen() {
}

void create_screen_setting_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.setting_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj266 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xffffff), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj267 = obj;
                    lv_obj_set_pos(obj, 319, 11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "SETTINGS");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 8, 64);
            lv_obj_set_size(obj, 388, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 400, 64);
            lv_obj_set_size(obj, 388, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, action_show_gcode_popup, LV_EVENT_PRESSED, (void *)0);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // CalibrateScreenButtonSettingsScreen
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.calibrate_screen_button_settings_screen = obj;
                    lv_obj_set_pos(obj, 253, 142);
                    lv_obj_set_size(obj, 119, 83);
                    lv_obj_add_event_cb(obj, action_screen_calibrate, LV_EVENT_CLICKED, (void *)0);
                    add_style_light_deep_button(obj);
                    lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f6f3), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // SaveLog_2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.save_log_2 = obj;
                            lv_obj_set_pos(obj, 0, 32);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "SCREEN");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj268 = obj;
            lv_obj_set_pos(obj, 404, 72);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Advanced OK");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj269 = obj;
            lv_obj_set_pos(obj, 323, 376);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0x464444), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf00c");
        }
        {
            // BackMainButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_settings_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj270 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // MotionSettingsButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.motion_settings_button_settings_screen = obj;
            lv_obj_set_pos(obj, 207, 72);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj271 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Motion Settings");
                }
            }
        }
        {
            // AccelerationButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.acceleration_button_settings_screen = obj;
            lv_obj_set_pos(obj, 208, 128);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj272 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Acceleration");
                }
            }
        }
        {
            // HomeOffsetButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_offset_button_settings_screen = obj;
            lv_obj_set_pos(obj, 209, 185);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj273 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Home Offset");
                }
            }
        }
        {
            // ProbeOffsetButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.probe_offset_button_settings_screen = obj;
            lv_obj_set_pos(obj, 18, 185);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj274 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Probe Offset");
                }
            }
        }
        {
            // JunctionDevButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.junction_dev_button_settings_screen = obj;
            lv_obj_set_pos(obj, 210, 244);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj275 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Junction Dev");
                }
            }
        }
        {
            // FirmwareRetractionButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.firmware_retraction_button_settings_screen = obj;
            lv_obj_set_pos(obj, 18, 244);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj276 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "FW Retraction");
                }
            }
        }
        {
            // DisableStepperButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.disable_stepper_button_settings_screen = obj;
            lv_obj_set_pos(obj, 210, 304);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj277 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Disable Steppers");
                }
            }
        }
        {
            // RetractionRecoverButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.retraction_recover_button_settings_screen = obj;
            lv_obj_set_pos(obj, 18, 304);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj278 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Retraction Recover");
                }
            }
        }
        {
            // AutoRetractionButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.auto_retraction_button_settings_screen = obj;
            lv_obj_set_pos(obj, 18, 363);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj279 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Auto Retraction");
                }
            }
        }
        {
            // Z_FadeHeightButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.z_fade_height_button_settings_screen = obj;
            lv_obj_set_pos(obj, 210, 363);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj280 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Z Fade Height");
                }
            }
        }
        {
            // AdvancedOkToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.advanced_ok_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 435, 93);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf90d03), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // LoadMeshBedLevelingToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.load_mesh_bed_leveling_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 435, 147);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf90d03), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8f5f5), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // AutoShutDownToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.auto_shut_down_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 435, 207);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf90303), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8f6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // FilamentMotionSensorToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.filament_motion_sensor_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 692, 97);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf90d03), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f4f4), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // PowerRecoveryToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.power_recovery_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 566, 152);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf92203), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8f5f5), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // SerialAlwaysOnToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.serial_always_on_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 566, 97);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf91803), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8f5f5), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // FilamentSensorToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.filament_sensor_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 695, 153);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf91803), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf5f1f1), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Z_AutoAlignToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.z_auto_align_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 435, 263);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf93703), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfcfcfc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Printer_2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_2 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj281 = obj;
            lv_obj_set_pos(obj, 405, 122);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Load Leveling");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj282 = obj;
            lv_obj_set_pos(obj, 404, 186);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Auto Shutdown");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj283 = obj;
            lv_obj_set_pos(obj, 665, 127);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Filament Sensor");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj284 = obj;
            lv_obj_set_pos(obj, 414, 240);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z Auto Align");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj285 = obj;
            lv_obj_set_pos(obj, 536, 127);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Power Recovery");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj286 = obj;
            lv_obj_set_pos(obj, 533, 73);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Serial Always On");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj287 = obj;
            lv_obj_set_pos(obj, 673, 73);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Motion Sensor");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj288 = obj;
            lv_obj_set_pos(obj, 20, 420);
            lv_obj_set_size(obj, 370, 45);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f4f4), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj289 = obj;
            lv_obj_set_pos(obj, 252, 447);
            lv_obj_set_size(obj, 123, 10);
            lv_slider_set_value(obj, 70, LV_ANIM_OFF);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x010101), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf8f9f9), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj290 = obj;
            lv_obj_set_pos(obj, 29, 441);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfae903), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Display Brightness");
        }
        {
            // DisplayBrightnessSettingsScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.display_brightness_settings_screen = obj;
            lv_obj_set_pos(obj, 192, 437);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_EDITED);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "70");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj291 = obj;
            lv_obj_set_pos(obj, 222, 437);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "%");
        }
        {
            // SaveSettingsButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_settings_button_settings_screen = obj;
            lv_obj_set_pos(obj, 407, 420);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj292 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Save Settings");
                }
            }
        }
        {
            // TimeSetButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.time_set_button_settings_screen = obj;
            lv_obj_set_pos(obj, 407, 363);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj293 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Set Time");
                }
            }
        }
        {
            // DefaultPrinterSettingsButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.default_printer_settings_button_settings_screen = obj;
            lv_obj_set_pos(obj, 599, 363);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj294 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Default Settings");
                }
            }
        }
        {
            // RestorePrinterSettingsButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.restore_printer_settings_button_settings_screen = obj;
            lv_obj_set_pos(obj, 599, 420);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj295 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf10505), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Restore Settings");
                }
            }
        }
        {
            // ManualHotendPIDButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.manual_hotend_pid_button_settings_screen = obj;
            lv_obj_set_pos(obj, 407, 304);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj296 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Manual Hotend  PID");
                }
            }
        }
        {
            // ManualBedPIDButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.manual_bed_pid_button_settings_screen = obj;
            lv_obj_set_pos(obj, 599, 304);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj297 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Manual Bed PID");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj298 = obj;
            lv_obj_set_pos(obj, 692, 230);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf8f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf25a");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj299 = obj;
            lv_obj_set_pos(obj, 660, 230);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfffefe), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf061");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj300 = obj;
            lv_obj_set_pos(obj, 700, 208);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfcf9f9), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf063");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj301 = obj;
            lv_obj_set_pos(obj, 742, 230);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfcfbfb), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf060");
        }
        {
            // MaxAccelerationButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.max_acceleration_button_settings_screen = obj;
            lv_obj_set_pos(obj, 19, 71);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj302 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Max Acceleration");
                }
            }
        }
        {
            // MaxFeedRateButtonSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.max_feed_rate_button_settings_screen = obj;
            lv_obj_set_pos(obj, 18, 128);
            lv_obj_set_size(obj, 180, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj303 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Max Feed Rate");
                }
            }
        }
        {
            // CommandChecksumToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.command_checksum_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 570, 207);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf92203), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8f5f5), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj304 = obj;
            lv_obj_set_pos(obj, 579, 240);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "ABL");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj305 = obj;
            lv_obj_set_pos(obj, 537, 186);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Cmd Checksum");
        }
        {
            // ABLToggleSettingsScreen
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.abl_toggle_settings_screen = obj;
            lv_obj_set_pos(obj, 571, 263);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf92203), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8f5f5), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_setting_screen();
}

void tick_screen_setting_screen() {
}

void create_screen_more_settings_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.more_settings_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj306 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj307 = obj;
                    lv_obj_set_pos(obj, 245, 11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "MORE SETTINGS");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj308 = obj;
            lv_obj_set_pos(obj, 10, 60);
            lv_obj_set_size(obj, 780, 108);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // BackMainButtonMoreSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_more_settings_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ClearLog_36
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.clear_log_36 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_11
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_11 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj309 = obj;
            lv_obj_set_pos(obj, 145, 110);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // PrintAccelerationLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.print_acceleration_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "2000");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj310 = obj;
            lv_obj_set_pos(obj, 325, 110);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // E_RetractionAccelerationLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.e_retraction_acceleration_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "1000");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj311 = obj;
            lv_obj_set_pos(obj, 520, 110);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // TravelAccelerationLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.travel_acceleration_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "2000");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj312 = obj;
            lv_obj_set_pos(obj, 564, 87);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Travel");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj313 = obj;
            lv_obj_set_pos(obj, 342, 87);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "E Retraction");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj314 = obj;
            lv_obj_set_pos(obj, 195, 87);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Print");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj315 = obj;
            lv_obj_set_pos(obj, 9, 178);
            lv_obj_set_size(obj, 780, 108);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj316 = obj;
            lv_obj_set_pos(obj, 600, 205);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z Lift on Retration");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj317 = obj;
            lv_obj_set_pos(obj, 45, 230);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // RetractLengthLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.retract_length_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "2.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj318 = obj;
            lv_obj_set_pos(obj, 227, 230);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // RetractSwapLengthLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.retract_swap_length_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "13.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj319 = obj;
            lv_obj_set_pos(obj, 420, 230);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // RetractFeedRateLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.retract_feed_rate_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "2700.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj320 = obj;
            lv_obj_set_pos(obj, 610, 230);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z_LiftOnRetractionLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z_lift_on_retraction_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, ".50");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj321 = obj;
            lv_obj_set_pos(obj, 412, 207);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Retract Feed Rate");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj322 = obj;
            lv_obj_set_pos(obj, 210, 207);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Retract Swap Length");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj323 = obj;
            lv_obj_set_pos(obj, 55, 207);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Retract Length");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj324 = obj;
            lv_obj_set_pos(obj, -8, -170);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Acceleration");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj325 = obj;
            lv_obj_set_pos(obj, -8, -50);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Filament Firmware Retraction");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj326 = obj;
            lv_obj_set_pos(obj, 12, 296);
            lv_obj_set_size(obj, 780, 108);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj327 = obj;
            lv_obj_set_pos(obj, 580, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Swap Recover Feedrate");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj328 = obj;
            lv_obj_set_pos(obj, 47, 350);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // XtraLengthLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.xtra_length_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, ".50");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj329 = obj;
            lv_obj_set_pos(obj, 229, 350);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // XtraSwapLengthLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.xtra_swap_length_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "0.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj330 = obj;
            lv_obj_set_pos(obj, 422, 350);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // RecoveryFeedrateLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.recovery_feedrate_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "480.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj331 = obj;
            lv_obj_set_pos(obj, 612, 350);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // SwapRecoveryFeedrateLabelMoreSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.swap_recovery_feedrate_label_more_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "480.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj332 = obj;
            lv_obj_set_pos(obj, 418, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Recover Feedrate");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj333 = obj;
            lv_obj_set_pos(obj, 220, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Xtra Swap Length");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj334 = obj;
            lv_obj_set_pos(obj, 66, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Xtra Length");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj335 = obj;
            lv_obj_set_pos(obj, -8, 70);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Firmware Retration Recover");
        }
        {
            // LoadDefaultsButtonMoreSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.load_defaults_button_more_settings_screen = obj;
            lv_obj_set_pos(obj, 290, 415);
            lv_obj_set_size(obj, 205, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj336 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "LOAD DEFAULTS");
                }
            }
        }
        {
            // SaveButtonMoreSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_button_more_settings_screen = obj;
            lv_obj_set_pos(obj, 37, 415);
            lv_obj_set_size(obj, 205, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xf80b02), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf80b02), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj337 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfaf8f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "SAVE");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj338 = obj;
            lv_obj_set_pos(obj, 546, 415);
            lv_obj_set_size(obj, 205, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x121212), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // JunctionDeviationButtonMotionScreen_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.junction_deviation_button_motion_screen_1 = obj;
                    lv_obj_set_pos(obj, 1, -15);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Junction Deviation");
                }
            }
        }
        {
            // SettingScreenButtonMoreSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.setting_screen_button_more_settings_screen = obj;
            lv_obj_set_pos(obj, 546, 415);
            lv_obj_set_size(obj, 205, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x121212), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj339 = obj;
                    lv_obj_set_pos(obj, 1, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "SETTING SCREEN");
                }
            }
        }
    }
    
    tick_screen_more_settings_screen();
}

void tick_screen_more_settings_screen() {
}

void create_screen_xtra_settings_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.xtra_settings_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj340 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj341 = obj;
                    lv_obj_set_pos(obj, 248, 11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "XTRA SETTINGS");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj342 = obj;
            lv_obj_set_pos(obj, 10, 60);
            lv_obj_set_size(obj, 780, 108);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // BackMainButtonXtraSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_xtra_settings_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj343 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_12
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_12 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj344 = obj;
            lv_obj_set_pos(obj, 145, 110);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // HotendKpLabelXtraSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.hotend_kp_label_xtra_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "13.60");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj345 = obj;
            lv_obj_set_pos(obj, 325, 110);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // HotendKiLabelXtraSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.hotend_ki_label_xtra_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "0.69");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj346 = obj;
            lv_obj_set_pos(obj, 520, 110);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // HotendKdLabelXtraSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.hotend_kd_label_xtra_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "67.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj347 = obj;
            lv_obj_set_pos(obj, 570, 87);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Kd");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj348 = obj;
            lv_obj_set_pos(obj, 382, 87);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Ki");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj349 = obj;
            lv_obj_set_pos(obj, 200, 87);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Kp");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj350 = obj;
            lv_obj_set_pos(obj, 9, 178);
            lv_obj_set_size(obj, 780, 108);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj351 = obj;
            lv_obj_set_pos(obj, 570, 205);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Kd");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj352 = obj;
            lv_obj_set_pos(obj, 145, 230);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // BedKpLabelXtraSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.bed_kp_label_xtra_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "29.20");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj353 = obj;
            lv_obj_set_pos(obj, 325, 230);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // BedKiLabelXtraSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.bed_ki_label_xtra_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "3.17");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj354 = obj;
            lv_obj_set_pos(obj, 520, 230);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // BedKdLabelXtraSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.bed_kd_label_xtra_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "179.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj355 = obj;
            lv_obj_set_pos(obj, 382, 205);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Ki");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj356 = obj;
            lv_obj_set_pos(obj, 204, 205);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Kp");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj357 = obj;
            lv_obj_set_pos(obj, -8, -170);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Hotend PID");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj358 = obj;
            lv_obj_set_pos(obj, -8, -50);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Bed PID");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj359 = obj;
            lv_obj_set_pos(obj, 12, 296);
            lv_obj_set_size(obj, 780, 108);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj360 = obj;
            lv_obj_set_pos(obj, 580, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj361 = obj;
            lv_obj_set_pos(obj, 145, 350);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // X-ProbeOffsetLabelXtraSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.x_probe_offset_label_xtra_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "-3.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj362 = obj;
            lv_obj_set_pos(obj, 325, 350);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Y-ProbeOffsetLabelXtraSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_probe_offset_label_xtra_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "16.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj363 = obj;
            lv_obj_set_pos(obj, 520, 350);
            lv_obj_set_size(obj, 140, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xb9b7b5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z-ProbeOffsetLabelXtraSettingsScreen
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z_probe_offset_label_xtra_settings_screen = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "0.00");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj364 = obj;
            lv_obj_set_pos(obj, 390, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj365 = obj;
            lv_obj_set_pos(obj, 210, 328);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xdedcdc), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj366 = obj;
            lv_obj_set_pos(obj, -8, 70);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Probe Offset");
        }
        {
            // LoadDefaultsButtonXtraSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.load_defaults_button_xtra_settings_screen = obj;
            lv_obj_set_pos(obj, 290, 415);
            lv_obj_set_size(obj, 205, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x222222), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj367 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "LOAD DEFAULTS");
                }
            }
        }
        {
            // SaveButtonXtraSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_button_xtra_settings_screen = obj;
            lv_obj_set_pos(obj, 37, 415);
            lv_obj_set_size(obj, 205, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xf80b02), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf80b02), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj368 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfaf8f6), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "SAVE");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj369 = obj;
            lv_obj_set_pos(obj, 546, 415);
            lv_obj_set_size(obj, 205, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x121212), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // JunctionDeviationButtonMotionScreen_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.junction_deviation_button_motion_screen_3 = obj;
                    lv_obj_set_pos(obj, 1, -15);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Junction Deviation");
                }
            }
        }
        {
            // MoreSettingsButtonXtraSettingsScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.more_settings_button_xtra_settings_screen = obj;
            lv_obj_set_pos(obj, 546, 415);
            lv_obj_set_size(obj, 205, 50);
            add_style_light_deep_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x121212), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj370 = obj;
            lv_obj_set_pos(obj, 243, 202);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfcfafa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "MORE SETTINGS");
        }
    }
    
    tick_screen_xtra_settings_screen();
}

void tick_screen_xtra_settings_screen() {
}

void create_screen_screen_calibrate() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_calibrate = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj371 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj372 = obj;
                    lv_obj_set_pos(obj, 130, 13);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "TOUCH CALIBRATION");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 5, 64);
            lv_obj_set_size(obj, 790, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, action_on_calibration_touch, LV_EVENT_CLICKED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // BackMainButtonScreenCalibrationScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_screen_calibration_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            lv_obj_add_event_cb(obj, action_main_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj373 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_7
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_7 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            // crosshair_1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.crosshair_1 = obj;
            lv_obj_set_pos(obj, -25, 22);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_crosshair);
            lv_img_set_zoom(obj, 150);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_img_recolor(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // crosshair_2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.crosshair_2 = obj;
            lv_obj_set_pos(obj, 688, 22);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_crosshair);
            lv_img_set_zoom(obj, 150);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_img_recolor(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // crosshair_4
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.crosshair_4 = obj;
            lv_obj_set_pos(obj, -25, 370);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_crosshair);
            lv_img_set_zoom(obj, 150);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // crosshair_3
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.crosshair_3 = obj;
            lv_obj_set_pos(obj, 685, 370);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_crosshair);
            lv_img_set_zoom(obj, 150);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_img_recolor(obj, lv_color_hex(0xf6f8f9), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // cal_status_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.cal_status_label = obj;
            lv_obj_set_pos(obj, 130, 202);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xe7e4e4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Tap each crosshair target as it appears. Starting \nwith top-left, top-right, bottom right,  bottom left.\nGreen accepted. Red rejected. You only need to \ntap RED rejected crosshair.  Press  [START CAL]");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj374 = obj;
            lv_obj_set_pos(obj, 296, 312);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf0ebeb), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "CALIBRATION POINT: 1/4");
        }
        {
            // on_cancel_calibration_clicked
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.on_cancel_calibration_clicked = obj;
            lv_obj_set_pos(obj, 616, 9);
            lv_obj_set_size(obj, 116, 39);
            lv_obj_add_event_cb(obj, action_main_screen, LV_EVENT_PRESSED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj375 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfa0707), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "CANCEL");
                }
            }
        }
        {
            // start_calibration_clicked
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.start_calibration_clicked = obj;
            lv_obj_set_pos(obj, 455, 9);
            lv_obj_set_size(obj, 146, 39);
            lv_obj_add_event_cb(obj, action_start_calibration_clicked, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj376 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0x55f704), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "START CAL");
                }
            }
        }
    }
    
    tick_screen_screen_calibrate();
}

void tick_screen_screen_calibrate() {
}

void create_screen_info_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.info_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj377 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf9f9fa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj378 = obj;
                    lv_obj_set_pos(obj, 281, 11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "PRINTER INFO");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 8, 64);
            lv_obj_set_size(obj, 784, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
        }
        {
            // BackMainButtonInfoScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_info_screen = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj379 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_6
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_6 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj380 = obj;
            lv_obj_set_pos(obj, 348, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "SYSTEM");
        }
        {
            // FirmwareMarlinLabelInfoScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.firmware_marlin_label_info_screen = obj;
            lv_obj_set_pos(obj, 55, 113);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfaf301), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Firmware: Marlin bugfix-2.1.x (Nov  1 2026 07:07:58)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj381 = obj;
            lv_obj_set_pos(obj, 55, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf50606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "HMI: CrowPanel DIS08070H 800x480  ESP32-S3-WROOM-1-N4R8");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj382 = obj;
            lv_obj_set_pos(obj, 55, 155);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x0af808), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Controller Board: BTT Octopus 1.1");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj383 = obj;
            lv_obj_set_pos(obj, 327, 210);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "HARDWARE");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj384 = obj;
            lv_obj_set_pos(obj, 55, 235);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfaf301), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Drivers: TMC5160 (SPI)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj385 = obj;
            lv_obj_set_pos(obj, 55, 258);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf60606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Probe: BDSensor V1.2c/Eddy Coil");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj386 = obj;
            lv_obj_set_pos(obj, 55, 280);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x0af808), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Hotend: 300  C, Bambu PS2");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj387 = obj;
            lv_obj_set_pos(obj, 190, 289);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x0af808), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "o");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj388 = obj;
            lv_obj_set_pos(obj, 328, 325);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "FIRMWARE");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj389 = obj;
            lv_obj_set_pos(obj, 55, 351);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfaf301), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "HMI Version: v3.0");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj390 = obj;
            lv_obj_set_pos(obj, 55, 372);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf70303), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "LVGL: 8.4");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj391 = obj;
            lv_obj_set_pos(obj, 55, 393);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x0af808), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "EEZ Studio Ver 0.29.0");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj392 = obj;
            lv_obj_set_pos(obj, 55, 414);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf17c02), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "ESP-IDF v4.4.6");
        }
    }
    
    tick_screen_info_screen();
}

void tick_screen_info_screen() {
}

void create_screen_template_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.template_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj393 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj394 = obj;
                    lv_obj_set_pos(obj, 319, 11);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "TEMPLATE");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 8, 64);
            lv_obj_set_size(obj, 388, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 400, 64);
            lv_obj_set_size(obj, 388, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // BackMainSettingsButton_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_settings_button_1 = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj395 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_3
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_3 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj396 = obj;
            lv_obj_set_pos(obj, 679, 74);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z Auto Align");
        }
    }
    
    tick_screen_template_screen();
}

void tick_screen_template_screen() {
}

void create_screen_time_date_setting_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.time_date_setting_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SCROLL_ONE|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj397 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj398 = obj;
                    lv_obj_set_pos(obj, 274, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "TIME SETTINGS");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 15, 64);
            lv_obj_set_size(obj, 771, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // return_to_main
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.return_to_main = obj;
            lv_obj_set_pos(obj, 17, 8);
            lv_obj_set_size(obj, 104, 39);
            lv_obj_add_event_cb(obj, action_return_to_main, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj399 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_13
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_13 = obj;
            lv_obj_set_pos(obj, 742, 3);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
        {
            // TimeLabelTimeDateSettingScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_label_time_date_setting_screen = obj;
            lv_obj_set_pos(obj, 544, 7);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x074b5a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf3f2f2), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "2:00 PM ");
        }
        {
            // DateYearLabelTimeDateSettingScreen
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.date_year_label_time_date_setting_screen = obj;
            lv_obj_set_pos(obj, 638, 7);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan_2(obj);
            lv_obj_set_style_text_color(obj, lv_color_lighten(lv_color_hex(0xf3f2f2), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Aug 14 1956");
        }
        {
            // roller_hour
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.roller_hour = obj;
            lv_obj_set_pos(obj, 167, 190);
            lv_obj_set_size(obj, 80, 100);
            lv_roller_set_options(obj, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n\n", LV_ROLLER_MODE_NORMAL);
        }
        {
            // roller_minute
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.roller_minute = obj;
            lv_obj_set_pos(obj, 259, 190);
            lv_obj_set_size(obj, 80, 100);
            lv_roller_set_options(obj, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59\n", LV_ROLLER_MODE_NORMAL);
        }
        {
            // roller_day
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.roller_day = obj;
            lv_obj_set_pos(obj, 512, 190);
            lv_obj_set_size(obj, 80, 100);
            lv_roller_set_options(obj, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31", LV_ROLLER_MODE_NORMAL);
        }
        {
            // roller_month
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.roller_month = obj;
            lv_obj_set_pos(obj, 424, 190);
            lv_obj_set_size(obj, 80, 100);
            lv_roller_set_options(obj, "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n", LV_ROLLER_MODE_NORMAL);
        }
        {
            // roller_year
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.roller_year = obj;
            lv_obj_set_pos(obj, 599, 190);
            lv_obj_set_size(obj, 80, 100);
            lv_roller_set_options(obj, "2026\n2027\n2028\n2029\n2030\n2031\n2032\n2033\n2034\n2035\n2036\n2037\n2039\n2040\n2041\n2042\n2043\n2044\n2045\n2046\n2047\n2049\n2050\n2051\n2052\n2053\n2054\n2055\n2056\n2057\n2059\n2060", LV_ROLLER_MODE_NORMAL);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj400 = obj;
            lv_obj_set_pos(obj, 175, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf3efef), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "HOUR");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj401 = obj;
            lv_obj_set_pos(obj, 278, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf3efef), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "MIN");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj402 = obj;
            lv_obj_set_pos(obj, 432, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf3efef), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Month");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj403 = obj;
            lv_obj_set_pos(obj, 530, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf3efef), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "DAY");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj404 = obj;
            lv_obj_set_pos(obj, 607, 159);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf3efef), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "YEAR");
        }
        {
            // SaveTimeButtonTimeDateSettingScreen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_time_button_time_date_setting_screen = obj;
            lv_obj_set_pos(obj, 201, 82);
            lv_obj_set_size(obj, 174, 38);
            lv_obj_add_event_cb(obj, action_return_to_main, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x292828), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj405 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "SAVE & APPLY");
                }
            }
        }
        {
            // CancelTimeSettings
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.cancel_time_settings = obj;
            lv_obj_set_pos(obj, 432, 81);
            lv_obj_set_size(obj, 174, 39);
            lv_obj_add_event_cb(obj, action_cancel_time_settings, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x292828), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj406 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xf70303), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "CANCEL");
                }
            }
        }
    }
    
    tick_screen_time_date_setting_screen();
}

void tick_screen_time_date_setting_screen() {
}

void create_screen_print_tools_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.print_tools_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    add_style_deep_dark_screen(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj407 = obj;
            lv_obj_set_pos(obj, 3, 0);
            lv_obj_set_size(obj, 790, 56);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf7f8f8), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Print_ReadyLabelPrintScreen_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.print_ready_label_print_screen_1 = obj;
                    lv_obj_set_pos(obj, 124, 26);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "READY");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj408 = obj;
                    lv_obj_set_pos(obj, 288, 10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan_2(obj);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf9f7f7), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "PRINTER TOOLS");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 8, 64);
            lv_obj_set_size(obj, 300, 408);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj409 = obj;
                    lv_obj_set_pos(obj, 383, 361);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_cyan(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "C");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj410 = obj;
                    lv_obj_set_pos(obj, 18, 183);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Target:");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj411 = obj;
            lv_obj_set_pos(obj, 40, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "NOZZLE");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj412 = obj;
            lv_obj_set_pos(obj, 308, 34);
            lv_obj_set_size(obj, 492, 22);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(0x252525), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // NozzleArc_1
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.nozzle_arc_1 = obj;
            lv_obj_set_pos(obj, 18, 117);
            lv_obj_set_size(obj, 130, 130);
            lv_arc_set_range(obj, 0, 300);
            lv_arc_set_value(obj, 215);
            lv_arc_set_bg_end_angle(obj, 405);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x767b7b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 12, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // BedArc_1
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.bed_arc_1 = obj;
            lv_obj_set_pos(obj, 165, 117);
            lv_obj_set_size(obj, 130, 130);
            lv_arc_set_value(obj, 60);
            lv_obj_set_style_arc_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x767b7b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xfba002), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj413 = obj;
            lv_obj_set_pos(obj, 209, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_bold_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "BED");
        }
        {
            // NozzleArcTempPrintScreen_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.nozzle_arc_temp_print_screen_1 = obj;
            lv_obj_set_pos(obj, 45, 167);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "215");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj414 = obj;
            lv_obj_set_pos(obj, 97, 169);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0x00f4ff), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj415 = obj;
            lv_obj_set_pos(obj, 114, 167);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0x00f4ff), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "0");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj416 = obj;
            lv_obj_set_pos(obj, 245, 170);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfba002), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj417 = obj;
            lv_obj_set_pos(obj, 263, 171);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "0");
        }
        {
            // BedArcTempPrintScreen_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.bed_arc_temp_print_screen_1 = obj;
            lv_obj_set_pos(obj, 195, 168);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            add_style_cyan(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "60");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj418 = obj;
            lv_obj_set_pos(obj, 174, 247);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Target:");
        }
        {
            // BedArcTargetPrintScreen_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.bed_arc_target_print_screen_1 = obj;
            lv_obj_set_pos(obj, 254, 248);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "60");
        }
        {
            // NozzleArcTargetPrintScreen_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.nozzle_arc_target_print_screen_1 = obj;
            lv_obj_set_pos(obj, 104, 248);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf9f7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "215");
        }
        {
            // HeatNozzleButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.heat_nozzle_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 20, 295);
            lv_obj_set_size(obj, 126, 43);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj419 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "HEAT NOZZLE");
                }
            }
        }
        {
            // HeatBedButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.heat_bed_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 168, 295);
            lv_obj_set_size(obj, 126, 43);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj420 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "HEAT BED");
                }
            }
        }
        {
            // PreheatButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.preheat_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 165, 359);
            lv_obj_set_size(obj, 126, 43);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj421 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "PREHEAT ");
                }
            }
        }
        {
            // CoolButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.cool_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 21, 359);
            lv_obj_set_size(obj, 126, 43);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj422 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "COOL");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 316, 43);
            lv_obj_set_size(obj, 210, 229);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj423 = obj;
            lv_obj_set_pos(obj, 328, 53);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbfafa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "AXIS POSITIONS (mm)");
        }
        {
            // X_PositionPrintScreen_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.x_position_print_screen_1 = obj;
            lv_obj_set_pos(obj, 403, 86);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_label_set_text_static(obj, "152.40");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj424 = obj;
            lv_obj_set_pos(obj, 393, 141);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e1e1e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Y_PositionPrintScreen_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.y_position_print_screen_1 = obj;
                    lv_obj_set_pos(obj, 11, 5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "89.15");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj425 = obj;
            lv_obj_set_pos(obj, 393, 204);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1e1e1e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Z_PositionPrintScreen_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.z_position_print_screen_1 = obj;
                    lv_obj_set_pos(obj, 10, 6);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfbf7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "45.32");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj426 = obj;
            lv_obj_set_pos(obj, 340, 83);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_38, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "X");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj427 = obj;
            lv_obj_set_pos(obj, 341, 146);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_38, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Y");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj428 = obj;
            lv_obj_set_pos(obj, 339, 204);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_38, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Z");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj429 = obj;
            lv_obj_set_pos(obj, 316, 281);
            lv_obj_set_size(obj, 210, 109);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x222222), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj430 = obj;
            lv_obj_set_pos(obj, 349, 287);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbfafa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "HOMING CONTROL");
        }
        {
            // HomeAllButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_all_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 320, 314);
            lv_obj_set_size(obj, 46, 66);
            lv_obj_add_event_cb(obj, action_home_all_button_print_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj431 = obj;
                    lv_obj_set_pos(obj, 0, 16);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "HOME\n   ALL");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj432 = obj;
            lv_obj_set_pos(obj, 326, 320);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF015");
        }
        {
            // Home_X_ButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_x_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 372, 314);
            lv_obj_set_size(obj, 46, 66);
            lv_obj_add_event_cb(obj, action_home_x_button_print_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj433 = obj;
                    lv_obj_set_pos(obj, 0, 16);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "HOME\n     X");
                }
            }
        }
        {
            // Home_Y_ButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_y_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 424, 314);
            lv_obj_set_size(obj, 46, 66);
            lv_obj_add_event_cb(obj, action_home_y_button_print_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj434 = obj;
                    lv_obj_set_pos(obj, 0, 16);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "HOME\n     Y");
                }
            }
        }
        {
            // Home_Z_ButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_z_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 475, 314);
            lv_obj_set_size(obj, 46, 66);
            lv_obj_add_event_cb(obj, action_home_z_button_print_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj435 = obj;
                    lv_obj_set_pos(obj, 0, 16);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "HOME\n     Z");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj436 = obj;
            lv_obj_set_pos(obj, 482, 319);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF015");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj437 = obj;
            lv_obj_set_pos(obj, 377, 320);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF015");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj438 = obj;
            lv_obj_set_pos(obj, 430, 320);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "\uF015");
        }
        {
            // PIDBedButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.pid_bed_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 168, 416);
            lv_obj_set_size(obj, 126, 45);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj439 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "PID BED");
                }
            }
        }
        {
            // PIDNozzleButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.pid_nozzle_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 20, 417);
            lv_obj_set_size(obj, 126, 43);
            add_style_light_deep_button(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj440 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "PID NOZZLE");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 535, 43);
            lv_obj_set_size(obj, 255, 133);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 535, 186);
            lv_obj_set_size(obj, 254, 138);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 535, 334);
            lv_obj_set_size(obj, 254, 138);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            add_style_light_deep_container(obj);
            lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj441 = obj;
            lv_obj_set_pos(obj, 596, 53);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfcfafa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "JOB PROGRESS");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj442 = obj;
            lv_obj_set_pos(obj, 600, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Printing:");
        }
        {
            // PrintingProgressPrintScreen_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.printing_progress_print_screen_1 = obj;
            lv_obj_set_pos(obj, 677, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf5f7f7), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "68%");
        }
        {
            // PrintingProgressSliderPrintScreen_1
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.printing_progress_slider_print_screen_1 = obj;
            lv_obj_set_pos(obj, 552, 107);
            lv_obj_set_size(obj, 223, 10);
            lv_slider_set_value(obj, 68, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0x000000), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj443 = obj;
            lv_obj_set_pos(obj, 564, 126);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfaf8f8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Time Elapsed:");
        }
        {
            // TimeElapsed_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_elapsed_1 = obj;
            lv_obj_set_pos(obj, 712, 126);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf6f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "1h 14m");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj444 = obj;
            lv_obj_set_pos(obj, 563, 149);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf7f4f4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Time Remaining:");
        }
        {
            // TimeRemaining_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_remaining_1 = obj;
            lv_obj_set_pos(obj, 712, 152);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfcf9f9), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "0h 35m");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj445 = obj;
            lv_obj_set_pos(obj, 593, 196);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xf7f4f4), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "JOB CONTROLS");
        }
        {
            // PauseButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.pause_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 540, 223);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_add_event_cb(obj, action_pause_resume_button_label, LV_EVENT_CLICKED, (void *)0);
            add_style_warning(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf8f4f4), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfba002), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // PauseResumeButtonLabel_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.pause_resume_button_label_1 = obj;
                    lv_obj_set_pos(obj, 12, 4);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "PAUSE");
                }
            }
        }
        {
            // StopButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.stop_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 665, 223);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_add_event_cb(obj, action_stop_button_print_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_danger(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfaf9f9), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "STOP");
                }
            }
        }
        {
            // TuneButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.tune_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 540, 276);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfdfdfd), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj446 = obj;
                    lv_obj_set_pos(obj, 16, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x090909), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "TUNE");
                }
            }
        }
        {
            // ChangeFilamentButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.change_filament_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 665, 276);
            lv_obj_set_size(obj, 120, 45);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xf5f2f2), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj447 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x0b0b0b), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_line_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "CHANGE \nFILAMENT");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj448 = obj;
            lv_obj_set_pos(obj, 612, 342);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfbf6f6), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "STATUS LOG");
        }
        {
            // PrintStatusLogPrintScreen_1
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.print_status_log_print_screen_1 = obj;
            lv_obj_set_pos(obj, 546, 368);
            lv_obj_set_size(obj, 231, 95);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x292828), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_darken(lv_color_hex(0xfaf5f5), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf4efef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj449 = obj;
            lv_obj_set_pos(obj, 548, 233);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf5f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf04c");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 552, 283);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf013");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj450 = obj;
            lv_obj_set_pos(obj, 674, 231);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xf7f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "\uf04d");
        }
        {
            // BackMainButtonPrintScreen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_main_button_print_screen_1 = obj;
            lv_obj_set_pos(obj, 18, 9);
            lv_obj_set_size(obj, 79, 39);
            lv_obj_add_event_cb(obj, action_main_screen, LV_EVENT_CLICKED, (void *)0);
            add_style_light_deep_button(obj);
            lv_obj_set_style_radius(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x02314d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj451 = obj;
                    lv_obj_set_pos(obj, -1, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_darken(lv_color_hex(0xfdfcfa), 64), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_font_awesome5_solid_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "\uf060");
                }
            }
        }
        {
            // Printer_14
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.printer_14 = obj;
            lv_obj_set_pos(obj, 136, 70);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_printer);
        }
    }
    
    tick_screen_print_tools_screen();
}

void tick_screen_print_tools_screen() {
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main_screen,
    tick_screen_print_screen,
    tick_screen_stepper_driver_screen,
    tick_screen_z_stepper_driver_screen,
    tick_screen_jog_screen,
    tick_screen_filament_change_screen,
    tick_screen_motion_screen,
    tick_screen_setting_screen,
    tick_screen_more_settings_screen,
    tick_screen_xtra_settings_screen,
    tick_screen_screen_calibrate,
    tick_screen_info_screen,
    tick_screen_template_screen,
    tick_screen_time_date_setting_screen,
    tick_screen_print_tools_screen,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 15) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
    { "FontAwesome5-Solid-14", &ui_font_font_awesome5_solid_14 },
    { "FontAwesome5-Solid-20", &ui_font_font_awesome5_solid_20 },
    { "FontAwesome5-Solid-16", &ui_font_font_awesome5_solid_16 },
    { "FontAwesome5-Solid-28", &ui_font_font_awesome5_solid_28 },
    { "FontAwesome5-Solid-32", &ui_font_font_awesome5_solid_32 },
    { "FontAwesome5-Solid-36", &ui_font_font_awesome5_solid_36 },
    { "Montserrat-Bold-20", &ui_font_montserrat_bold_20 },
    { "Montserrat-Extra-Bold-20", &ui_font_montserrat_extra_bold_20 },
    { "Montserrat-Bold-14", &ui_font_montserrat_bold_14 },
    { "Montserrat-Bold-38", &ui_font_montserrat_bold_38 },
    { "Montserrat-Bold-12", &ui_font_montserrat_bold_12 },
    { "Montserrat-Bold-16", &ui_font_montserrat_bold_16 },
    { "FontAwesome5-Solid-48", &ui_font_font_awesome5_solid_48 },
    { "Montserrat-Bold-22", &ui_font_montserrat_bold_22 },
    { "Montserrat-Bold-24", &ui_font_montserrat_bold_24 },
    { "FontAwesome5-Solid-60", &ui_font_font_awesome5_solid_60 },
    { "FontAwesome5-Solid-44", &ui_font_font_awesome5_solid_44 },
    { "FontAwesome5-Solid-40", &ui_font_font_awesome5_solid_40 },
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
// Color themes
//

uint32_t active_theme_index = 0;

//
//
//

void create_screens() {

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    // Create screens
    create_screen_main_screen();
    create_screen_print_screen();
    create_screen_stepper_driver_screen();
    create_screen_z_stepper_driver_screen();
    create_screen_jog_screen();
    create_screen_filament_change_screen();
    create_screen_motion_screen();
    create_screen_setting_screen();
    create_screen_more_settings_screen();
    create_screen_xtra_settings_screen();
    create_screen_screen_calibrate();
    create_screen_info_screen();
    create_screen_template_screen();
    create_screen_time_date_setting_screen();
    create_screen_print_tools_screen();
}