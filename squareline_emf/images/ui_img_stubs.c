// Tiny 1x1 placeholders replace multi-megabyte SquareLine image assets.
// Original PNGs in images/ are kept for reference but are not compiled into flash.

#include "../ui.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

static const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_stub_pixel[] = { 0xFF, 0xFF };

#define UI_DEFINE_IMG_STUB(img_name) \
    const lv_img_dsc_t img_name = { \
        .header.always_zero = 0, \
        .header.w = 1, \
        .header.h = 1, \
        .data_size = sizeof(ui_img_stub_pixel), \
        .header.cf = LV_IMG_CF_TRUE_COLOR, \
        .data = ui_img_stub_pixel \
    }

UI_DEFINE_IMG_STUB(ui_img_1_png);
UI_DEFINE_IMG_STUB(ui_img_2_png);
UI_DEFINE_IMG_STUB(ui_img_16736989);
UI_DEFINE_IMG_STUB(ui_img_1412130330);
UI_DEFINE_IMG_STUB(ui_img_1191746074);
UI_DEFINE_IMG_STUB(ui_img_2101998455);
