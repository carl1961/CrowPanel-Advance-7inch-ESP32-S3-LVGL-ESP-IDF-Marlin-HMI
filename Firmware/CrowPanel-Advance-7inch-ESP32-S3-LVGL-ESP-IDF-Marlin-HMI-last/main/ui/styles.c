#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: Deep_Dark_Canvas
//

void init_style_deep_dark_canvas_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_radius(style, 2);
    lv_style_set_bg_color(style, lv_color_hex(0x181c24));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_deep_dark_canvas_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_deep_dark_canvas_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_deep_dark_canvas(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_deep_dark_canvas_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_deep_dark_canvas(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_deep_dark_canvas_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Light_Deep_Container
//

void init_style_light_deep_container_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_radius(style, 4);
    lv_style_set_bg_opa(style, 255);
    lv_style_set_border_color(style, lv_color_darken(lv_color_hex(0x040404), 64));
    lv_style_set_border_opa(style, 255);
    lv_style_set_border_width(style, 1);
    lv_style_set_bg_color(style, lv_color_hex(0x222222));
};

lv_style_t *get_style_light_deep_container_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_light_deep_container_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_light_deep_container(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_light_deep_container_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_light_deep_container(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_light_deep_container_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Divider_Line
//

void init_style_divider_line_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0x30363d));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_divider_line_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_divider_line_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_divider_line(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_divider_line_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_divider_line(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_divider_line_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Warning
//

void init_style_warning_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xfba002));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_warning_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_warning_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_warning(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_warning_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_warning(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_warning_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Danger
//

void init_style_danger_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xeb0609));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_danger_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_danger_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_danger(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_danger_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_danger(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_danger_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Text_Mute
//

void init_style_text_mute_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0x8b949e));
    lv_style_set_text_color(style, lv_color_hex(0xe6edf3));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_text_mute_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_text_mute_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_text_mute(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_text_mute_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_text_mute(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_text_mute_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Text_Primary
//

void init_style_text_primary_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xe6edf3));
    lv_style_set_text_color(style, lv_color_hex(0xe6edf3));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_text_primary_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_text_primary_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_text_primary(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_text_primary_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_text_primary(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_text_primary_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Cyan
//

void init_style_cyan_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 255);
    lv_style_set_text_font(style, &ui_font_montserrat_bold_20);
    lv_style_set_bg_color(style, lv_color_hex(0x222222));
};

lv_style_t *get_style_cyan_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_cyan_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_cyan_MAIN_FOCUSED(lv_style_t *style) {
    lv_style_set_border_color(style, lv_color_darken(lv_color_hex(0x5c5f63), 64));
    lv_style_set_border_opa(style, 255);
    lv_style_set_bg_color(style, lv_color_lighten(lv_color_hex(0x21262d), 64));
    lv_style_set_bg_opa(style, 200);
};

lv_style_t *get_style_cyan_MAIN_FOCUSED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_cyan_MAIN_FOCUSED(style);
    }
    return style;
};

void add_style_cyan(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_cyan_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_cyan_MAIN_FOCUSED(), LV_PART_MAIN | LV_STATE_FOCUSED);
};

void remove_style_cyan(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_cyan_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_cyan_MAIN_FOCUSED(), LV_PART_MAIN | LV_STATE_FOCUSED);
};

//
// Style: Light_Deep_Text
//

void init_style_light_deep_text_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_darken(lv_color_hex(0x615f5f), 64));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_light_deep_text_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_light_deep_text_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_light_deep_text_MAIN_FOCUSED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0x595c62));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_light_deep_text_MAIN_FOCUSED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_light_deep_text_MAIN_FOCUSED(style);
    }
    return style;
};

void add_style_light_deep_text(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_light_deep_text_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_light_deep_text_MAIN_FOCUSED(), LV_PART_MAIN | LV_STATE_FOCUSED);
};

void remove_style_light_deep_text(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_light_deep_text_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_light_deep_text_MAIN_FOCUSED(), LV_PART_MAIN | LV_STATE_FOCUSED);
};

//
// Style: Cyan_2
//

void init_style_cyan_2_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_opa(style, 255);
    lv_style_set_text_color(style, lv_color_darken(lv_color_hex(0x02314d), 0));
};

lv_style_t *get_style_cyan_2_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_cyan_2_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_cyan_2(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_cyan_2_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_cyan_2(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_cyan_2_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Deep_Dark_Screen
//

void init_style_deep_dark_screen_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0x2e2e2e));
    lv_style_set_bg_color(style, lv_color_darken(lv_color_hex(0x252525), 64));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_deep_dark_screen_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_deep_dark_screen_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_deep_dark_screen(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_deep_dark_screen_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_deep_dark_screen(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_deep_dark_screen_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Orange
//

void init_style_orange_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0x545555));
};

lv_style_t *get_style_orange_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_orange_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_orange(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_orange_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_orange(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_orange_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Light_Deep_Button
//

void init_style_light_deep_button_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 255);
    lv_style_set_radius(style, 4);
    lv_style_set_opa(style, 255);
    lv_style_set_border_color(style, lv_color_darken(lv_color_hex(0xf6f4f1), 64));
    lv_style_set_border_opa(style, 255);
    lv_style_set_border_width(style, 1);
    lv_style_set_text_color(style, lv_color_darken(lv_color_hex(0xfcfaf8), 64));
    lv_style_set_text_opa(style, 255);
    lv_style_set_text_font(style, &ui_font_montserrat_bold_16);
    lv_style_set_bg_color(style, lv_color_hex(0x292828));
};

lv_style_t *get_style_light_deep_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_light_deep_button_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_light_deep_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_light_deep_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_light_deep_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_light_deep_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Deep_Dark_Panel
//

void init_style_deep_dark_panel_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0x141414));
    lv_style_set_border_color(style, lv_color_hex(0x000000));
    lv_style_set_border_width(style, 3);
    lv_style_set_text_color(style, lv_color_darken(lv_color_hex(0xfbfbfb), 64));
    lv_style_set_text_font(style, &ui_font_montserrat_bold_16);
    lv_style_set_border_opa(style, 255);
};

lv_style_t *get_style_deep_dark_panel_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_deep_dark_panel_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_deep_dark_panel(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_deep_dark_panel_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_deep_dark_panel(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_deep_dark_panel_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_deep_dark_canvas,
        add_style_light_deep_container,
        add_style_divider_line,
        add_style_warning,
        add_style_danger,
        add_style_text_mute,
        add_style_text_primary,
        add_style_cyan,
        add_style_light_deep_text,
        add_style_cyan_2,
        add_style_deep_dark_screen,
        add_style_orange,
        add_style_light_deep_button,
        add_style_deep_dark_panel,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_deep_dark_canvas,
        remove_style_light_deep_container,
        remove_style_divider_line,
        remove_style_warning,
        remove_style_danger,
        remove_style_text_mute,
        remove_style_text_primary,
        remove_style_cyan,
        remove_style_light_deep_text,
        remove_style_cyan_2,
        remove_style_deep_dark_screen,
        remove_style_orange,
        remove_style_light_deep_button,
        remove_style_deep_dark_panel,
    };
    remove_style_funcs[styleIndex](obj);
}