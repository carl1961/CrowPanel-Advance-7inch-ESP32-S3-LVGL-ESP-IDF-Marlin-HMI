#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: Deep_Dark_Canvas
lv_style_t *get_style_deep_dark_canvas_MAIN_DEFAULT();
void add_style_deep_dark_canvas(lv_obj_t *obj);
void remove_style_deep_dark_canvas(lv_obj_t *obj);

// Style: Light_Deep_Container
lv_style_t *get_style_light_deep_container_MAIN_DEFAULT();
void add_style_light_deep_container(lv_obj_t *obj);
void remove_style_light_deep_container(lv_obj_t *obj);

// Style: Divider_Line
lv_style_t *get_style_divider_line_MAIN_DEFAULT();
void add_style_divider_line(lv_obj_t *obj);
void remove_style_divider_line(lv_obj_t *obj);

// Style: Warning
lv_style_t *get_style_warning_MAIN_DEFAULT();
void add_style_warning(lv_obj_t *obj);
void remove_style_warning(lv_obj_t *obj);

// Style: Danger
lv_style_t *get_style_danger_MAIN_DEFAULT();
void add_style_danger(lv_obj_t *obj);
void remove_style_danger(lv_obj_t *obj);

// Style: Text_Mute
lv_style_t *get_style_text_mute_MAIN_DEFAULT();
void add_style_text_mute(lv_obj_t *obj);
void remove_style_text_mute(lv_obj_t *obj);

// Style: Text_Primary
lv_style_t *get_style_text_primary_MAIN_DEFAULT();
void add_style_text_primary(lv_obj_t *obj);
void remove_style_text_primary(lv_obj_t *obj);

// Style: Cyan
lv_style_t *get_style_cyan_MAIN_DEFAULT();
lv_style_t *get_style_cyan_MAIN_FOCUSED();
void add_style_cyan(lv_obj_t *obj);
void remove_style_cyan(lv_obj_t *obj);

// Style: Light_Deep_Text
lv_style_t *get_style_light_deep_text_MAIN_DEFAULT();
lv_style_t *get_style_light_deep_text_MAIN_FOCUSED();
void add_style_light_deep_text(lv_obj_t *obj);
void remove_style_light_deep_text(lv_obj_t *obj);

// Style: Cyan_2
lv_style_t *get_style_cyan_2_MAIN_DEFAULT();
void add_style_cyan_2(lv_obj_t *obj);
void remove_style_cyan_2(lv_obj_t *obj);

// Style: Deep_Dark_Screen
lv_style_t *get_style_deep_dark_screen_MAIN_DEFAULT();
void add_style_deep_dark_screen(lv_obj_t *obj);
void remove_style_deep_dark_screen(lv_obj_t *obj);

// Style: Orange
lv_style_t *get_style_orange_MAIN_DEFAULT();
void add_style_orange(lv_obj_t *obj);
void remove_style_orange(lv_obj_t *obj);

// Style: Light_Deep_Button
lv_style_t *get_style_light_deep_button_MAIN_DEFAULT();
void add_style_light_deep_button(lv_obj_t *obj);
void remove_style_light_deep_button(lv_obj_t *obj);

// Style: Deep_Dark_Panel
lv_style_t *get_style_deep_dark_panel_MAIN_DEFAULT();
void add_style_deep_dark_panel(lv_obj_t *obj);
void remove_style_deep_dark_panel(lv_obj_t *obj);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/