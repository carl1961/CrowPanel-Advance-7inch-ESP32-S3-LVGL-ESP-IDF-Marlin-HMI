#ifndef EEZ_LVGL_UI_FONTS_H
#define EEZ_LVGL_UI_FONTS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_font_t ui_font_font_awesome5_solid_14;
extern const lv_font_t ui_font_font_awesome5_solid_20;
extern const lv_font_t ui_font_font_awesome5_solid_16;
extern const lv_font_t ui_font_font_awesome5_solid_28;
extern const lv_font_t ui_font_font_awesome5_solid_32;
extern const lv_font_t ui_font_font_awesome5_solid_36;
extern const lv_font_t ui_font_montserrat_bold_20;
extern const lv_font_t ui_font_montserrat_extra_bold_20;
extern const lv_font_t ui_font_montserrat_bold_14;
extern const lv_font_t ui_font_montserrat_bold_38;
extern const lv_font_t ui_font_montserrat_bold_12;
extern const lv_font_t ui_font_montserrat_bold_16;
extern const lv_font_t ui_font_font_awesome5_solid_48;
extern const lv_font_t ui_font_montserrat_bold_22;
extern const lv_font_t ui_font_montserrat_bold_24;
extern const lv_font_t ui_font_font_awesome5_solid_60;
extern const lv_font_t ui_font_font_awesome5_solid_44;
extern const lv_font_t ui_font_font_awesome5_solid_40;

#ifndef EXT_FONT_DESC_T
#define EXT_FONT_DESC_T
typedef struct _ext_font_desc_t {
    const char *name;
    const void *font_ptr;
} ext_font_desc_t;
#endif

extern ext_font_desc_t fonts[];

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_FONTS_H*/