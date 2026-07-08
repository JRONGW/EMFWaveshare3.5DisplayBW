/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: --bpp 1 --size 12 --font C:/Users/58418/Documents/2026UCL/Dissertation/UI/assets/fonts/DotGothic16-Regular.ttf -o C:/Users/58418/Documents/2026UCL/Dissertation/UI/assets/fonts\ui_font_DotGothic12.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_DOTGOTHIC12
#define UI_FONT_DOTGOTHIC12 1
#endif

#if UI_FONT_DOTGOTHIC12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfe, 0xc0,

    /* U+0022 "\"" */
    0xff,

    /* U+0023 "#" */
    0x28, 0xa2, 0x9f, 0x29, 0x45, 0x3e, 0x51, 0x40,

    /* U+0024 "$" */
    0x23, 0xab, 0x5a, 0x78, 0xa5, 0xad, 0x5c, 0x40,

    /* U+0025 "%" */
    0x46, 0xaa, 0xac, 0xf8, 0xd5, 0x55, 0x56, 0x20,

    /* U+0026 "&" */
    0x31, 0x24, 0x94, 0x31, 0x89, 0x65, 0x89, 0xd0,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x29, 0x49, 0x24, 0x89, 0x10,

    /* U+0029 ")" */
    0x89, 0x12, 0x49, 0x29, 0x40,

    /* U+002A "*" */
    0x9b, 0xcc, 0xb9, 0x80,

    /* U+002B "+" */
    0x21, 0x9, 0xf2, 0x10, 0x80,

    /* U+002C "," */
    0xd8,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x8, 0x42, 0x32, 0x11, 0x8, 0x46, 0x20,

    /* U+0030 "0" */
    0x22, 0xa3, 0x18, 0xc6, 0x31, 0x51, 0x0,

    /* U+0031 "1" */
    0xd5, 0x55, 0x50,

    /* U+0032 "2" */
    0x26, 0xe2, 0x22, 0x11, 0x10, 0x87, 0xc0,

    /* U+0033 "3" */
    0x26, 0xe2, 0x22, 0x8, 0x31, 0xd9, 0x0,

    /* U+0034 "4" */
    0x8, 0x63, 0x8a, 0x29, 0x2c, 0xbf, 0x8, 0x20,

    /* U+0035 "5" */
    0xf4, 0x21, 0x4d, 0xc4, 0x31, 0x51, 0x0,

    /* U+0036 "6" */
    0x26, 0xe3, 0x4d, 0x46, 0x31, 0xd9, 0x0,

    /* U+0037 "7" */
    0xfc, 0x30, 0x84, 0x10, 0x41, 0x8, 0x20, 0x80,

    /* U+0038 "8" */
    0x26, 0xe2, 0xa2, 0x2a, 0x31, 0x51, 0x0,

    /* U+0039 "9" */
    0x26, 0xe3, 0x18, 0xac, 0xb1, 0x51, 0x0,

    /* U+003A ":" */
    0x88,

    /* U+003B ";" */
    0x87,

    /* U+003C "<" */
    0x1c, 0x86, 0x20, 0x60, 0x60, 0x40,

    /* U+003D "=" */
    0xf0, 0xf,

    /* U+003E ">" */
    0xe0, 0x81, 0x81, 0x19, 0x88, 0x0,

    /* U+003F "?" */
    0x73, 0x38, 0x42, 0x10, 0x82, 0x0, 0x20, 0x80,

    /* U+0040 "@" */
    0x39, 0x17, 0x73, 0xcf, 0x3c, 0xec, 0x41, 0xe0,

    /* U+0041 "A" */
    0x21, 0x14, 0xa4, 0xa5, 0x2f, 0x8c, 0x40,

    /* U+0042 "B" */
    0xe4, 0xe3, 0x2e, 0x4a, 0x31, 0x97, 0x0,

    /* U+0043 "C" */
    0x26, 0xe3, 0x8, 0x42, 0x31, 0x51, 0x0,

    /* U+0044 "D" */
    0xe4, 0xa3, 0x18, 0xc6, 0x31, 0x97, 0x0,

    /* U+0045 "E" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0x87, 0xc0,

    /* U+0046 "F" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0x84, 0x0,

    /* U+0047 "G" */
    0x26, 0xe3, 0xb, 0xc6, 0x31, 0x51, 0x0,

    /* U+0048 "H" */
    0x8c, 0x63, 0x1f, 0xc6, 0x31, 0x8c, 0x40,

    /* U+0049 "I" */
    0xff, 0xc0,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x86, 0x31, 0x51, 0x0,

    /* U+004B "K" */
    0x8c, 0xe9, 0x8c, 0x62, 0x92, 0x9c, 0x40,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x42, 0x10, 0x87, 0xc0,

    /* U+004D "M" */
    0x8d, 0xdf, 0xff, 0xfb, 0xb8,

    /* U+004E "N" */
    0x8d, 0xdd, 0xbb, 0xbb, 0x98,

    /* U+004F "O" */
    0x22, 0xa3, 0x18, 0xc6, 0x31, 0x51, 0x0,

    /* U+0050 "P" */
    0xe4, 0xe3, 0x19, 0xf2, 0x10, 0x84, 0x0,

    /* U+0051 "Q" */
    0x72, 0xa3, 0x18, 0xc6, 0x35, 0xfb, 0x86,

    /* U+0052 "R" */
    0xf4, 0x63, 0x1f, 0x46, 0x31, 0x8c, 0x40,

    /* U+0053 "S" */
    0x26, 0xe2, 0x82, 0x8, 0x31, 0xd9, 0x0,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x20,

    /* U+0055 "U" */
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0x51, 0x0,

    /* U+0056 "V" */
    0x8c, 0x63, 0x94, 0xa5, 0x6a, 0x21, 0x0,

    /* U+0057 "W" */
    0x8d, 0x6b, 0xff, 0xef, 0x69, 0x4a, 0x40,

    /* U+0058 "X" */
    0x8a, 0x52, 0xa2, 0x29, 0x49, 0xcc, 0x40,

    /* U+0059 "Y" */
    0x8c, 0x52, 0xa5, 0x10, 0x84, 0x21, 0x0,

    /* U+005A "Z" */
    0xfc, 0x21, 0x8, 0x20, 0x82, 0x10, 0xc3, 0xf0,

    /* U+005B "[" */
    0xea, 0xaa, 0xab,

    /* U+005C "\\" */
    0x84, 0x44, 0x44, 0x22, 0x11,

    /* U+005D "]" */
    0xd5, 0x55, 0x57,

    /* U+005E "^" */
    0x23, 0x14, 0xa8, 0x80,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0x94,

    /* U+0061 "a" */
    0x72, 0x20, 0x9e, 0x8a, 0x66, 0x40,

    /* U+0062 "b" */
    0x84, 0x3d, 0x18, 0xc6, 0x3a, 0xa0,

    /* U+0063 "c" */
    0x7c, 0x61, 0x8, 0xa4, 0xc0,

    /* U+0064 "d" */
    0x8, 0x5f, 0x18, 0xc6, 0x2b, 0x28,

    /* U+0065 "e" */
    0x74, 0x63, 0xf8, 0xa8, 0x80,

    /* U+0066 "f" */
    0x19, 0x9, 0xf2, 0x10, 0x84, 0x21, 0x0,

    /* U+0067 "g" */
    0x7c, 0x62, 0xe8, 0x7e, 0x2f,

    /* U+0068 "h" */
    0x84, 0x3d, 0x18, 0xc6, 0x31, 0x88,

    /* U+0069 "i" */
    0xff, 0x80,

    /* U+006A "j" */
    0x55, 0x55, 0x60,

    /* U+006B "k" */
    0x84, 0x23, 0x6c, 0x62, 0xd1, 0x88,

    /* U+006C "l" */
    0xff, 0x80,

    /* U+006D "m" */
    0xfd, 0x6b, 0x5a, 0xd6, 0xa0,

    /* U+006E "n" */
    0xf4, 0x63, 0x18, 0xc6, 0x20,

    /* U+006F "o" */
    0x74, 0x63, 0x18, 0xa8, 0x80,

    /* U+0070 "p" */
    0xa6, 0xe3, 0x18, 0xfa, 0x10,

    /* U+0071 "q" */
    0x2e, 0xe3, 0x18, 0xbc, 0x21,

    /* U+0072 "r" */
    0xf8, 0x88, 0x88, 0x80,

    /* U+0073 "s" */
    0x74, 0x60, 0xe0, 0xc5, 0xc0,

    /* U+0074 "t" */
    0x21, 0x3e, 0x42, 0x10, 0x84, 0x18,

    /* U+0075 "u" */
    0x8c, 0x63, 0x18, 0xac, 0xa0,

    /* U+0076 "v" */
    0x8c, 0x52, 0x95, 0x38, 0x80,

    /* U+0077 "w" */
    0xad, 0x77, 0xb4, 0xa5, 0x20,

    /* U+0078 "x" */
    0x85, 0x23, 0x8, 0x31, 0x28, 0x40,

    /* U+0079 "y" */
    0x8c, 0x52, 0x95, 0x38, 0x98,

    /* U+007A "z" */
    0xfc, 0x31, 0x8, 0x42, 0xf, 0xc0,

    /* U+007B "{" */
    0x29, 0x25, 0x92, 0x49, 0x10,

    /* U+007C "|" */
    0xff, 0xe0,

    /* U+007D "}" */
    0x89, 0x24, 0xd2, 0x49, 0x40,

    /* U+007E "~" */
    0xdb
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 96, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 96, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 96, .box_w = 2, .box_h = 4, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 4, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 12, .adv_w = 96, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 20, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 96, .box_w = 1, .box_h = 4, .ofs_x = 3, .ofs_y = 8},
    {.bitmap_index = 37, .adv_w = 96, .box_w = 3, .box_h = 12, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 42, .adv_w = 96, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 47, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 51, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 96, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 57, .adv_w = 96, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 58, .adv_w = 96, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 59, .adv_w = 96, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 96, .box_w = 2, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 98, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 96, .box_w = 1, .box_h = 5, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 135, .adv_w = 96, .box_w = 1, .box_h = 8, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 136, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 96, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 144, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 96, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 96, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 276, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 296, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 96, .box_w = 2, .box_h = 12, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 342, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 96, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 350, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 354, .adv_w = 96, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 355, .adv_w = 96, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 356, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 368, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 396, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 96, .box_w = 1, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 96, .box_w = 2, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 407, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 96, .box_w = 1, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 415, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 435, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 440, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 455, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 465, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 476, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 481, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 96, .box_w = 3, .box_h = 12, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 492, .adv_w = 96, .box_w = 1, .box_h = 11, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 494, .adv_w = 96, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 499, .adv_w = 96, .box_w = 4, .box_h = 2, .ofs_x = 1, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_DotGothic12 = {
#else
lv_font_t ui_font_DotGothic12 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_DOTGOTHIC12*/

