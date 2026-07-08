/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:/Users/58418/Documents/2026UCL/Dissertation/UI/assets/fonts/DotGothic16-Regular.ttf -o C:/Users/58418/Documents/2026UCL/Dissertation/UI/assets/fonts\ui_font_DotGothic16.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_DOTGOTHIC16
#define UI_FONT_DOTGOTHIC16 1
#endif

#if UI_FONT_DOTGOTHIC16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xd8,

    /* U+0022 "\"" */
    0xb6, 0xda,

    /* U+0023 "#" */
    0x24, 0x48, 0x91, 0x27, 0xe4, 0x89, 0x24, 0x49,
    0xf9, 0x22, 0x44, 0x80,

    /* U+0024 "$" */
    0x10, 0x21, 0xf4, 0x99, 0x32, 0x24, 0x78, 0x1c,
    0x24, 0x4c, 0x99, 0x32, 0x5f, 0x8,

    /* U+0025 "%" */
    0x61, 0x92, 0x92, 0x94, 0x94, 0x98, 0x6e, 0x19,
    0x29, 0x29, 0x49, 0x49, 0x86,

    /* U+0026 "&" */
    0x3c, 0x42, 0x42, 0x42, 0x44, 0x28, 0x30, 0x50,
    0x89, 0x85, 0x82, 0x82, 0x7d,

    /* U+0027 "'" */
    0xf8,

    /* U+0028 "(" */
    0x29, 0x25, 0x24, 0x92, 0x44, 0x91,

    /* U+0029 ")" */
    0x91, 0x24, 0x49, 0x24, 0x94, 0x94,

    /* U+002A "*" */
    0x92, 0xa8, 0xe1, 0xc5, 0x52, 0x40,

    /* U+002B "+" */
    0x10, 0x20, 0x40, 0x8f, 0xe2, 0x4, 0x8, 0x10,

    /* U+002C "," */
    0xf6,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x2, 0x4, 0x10, 0x20, 0x41, 0x2, 0x8, 0x10,
    0x40, 0x82, 0x4, 0x10, 0x20, 0x0,

    /* U+0030 "0" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+0031 "1" */
    0xe4, 0x92, 0x49, 0x24, 0x92,

    /* U+0032 "2" */
    0x38, 0x8a, 0xc, 0x18, 0x20, 0x82, 0x18, 0x41,
    0x2, 0x4, 0xf, 0xe0,

    /* U+0033 "3" */
    0x38, 0x8a, 0xc, 0x10, 0x20, 0x8e, 0x2, 0x3,
    0x6, 0xa, 0x23, 0x80,

    /* U+0034 "4" */
    0x2, 0x6, 0x6, 0xa, 0xa, 0x12, 0x12, 0x22,
    0x22, 0x42, 0xff, 0x2, 0x2,

    /* U+0035 "5" */
    0xfd, 0x2, 0x4, 0x8, 0x17, 0x31, 0xc1, 0x2,
    0x6, 0xa, 0x23, 0x80,

    /* U+0036 "6" */
    0x38, 0x8a, 0xc, 0x18, 0x17, 0x31, 0xc1, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+0037 "7" */
    0xfe, 0x4, 0x10, 0x20, 0x81, 0x2, 0x8, 0x10,
    0x20, 0x81, 0x2, 0x0,

    /* U+0038 "8" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0x8e, 0x22, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+0039 "9" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xa3, 0x3a,
    0x6, 0xa, 0x23, 0x80,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0xf0, 0xf, 0x60,

    /* U+003C "<" */
    0x2, 0x18, 0x43, 0x8, 0xc, 0x4, 0x6, 0x2,

    /* U+003D "=" */
    0xfc, 0x0, 0x0, 0xfc,

    /* U+003E ">" */
    0x80, 0xc0, 0x40, 0x60, 0x21, 0x84, 0x30, 0x80,

    /* U+003F "?" */
    0x3c, 0x42, 0x81, 0x81, 0x1, 0x2, 0xc, 0x10,
    0x10, 0x10, 0x0, 0x18, 0x18,

    /* U+0040 "@" */
    0x1c, 0x22, 0x41, 0x5b, 0xa5, 0xa5, 0xa5, 0xa5,
    0xa5, 0x9a, 0x80, 0x40, 0x3e,

    /* U+0041 "A" */
    0x10, 0x20, 0x41, 0x42, 0x85, 0x11, 0x22, 0x44,
    0xfa, 0xc, 0x18, 0x20,

    /* U+0042 "B" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x42, 0x83,
    0x6, 0xc, 0x2f, 0x80,

    /* U+0043 "C" */
    0x38, 0x8a, 0xc, 0x18, 0x10, 0x20, 0x40, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+0044 "D" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xc, 0x2f, 0x80,

    /* U+0045 "E" */
    0xff, 0x2, 0x4, 0x8, 0x10, 0x3f, 0x40, 0x81,
    0x2, 0x4, 0xf, 0xe0,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x10, 0x3f, 0x40, 0x81,
    0x2, 0x4, 0x8, 0x0,

    /* U+0047 "G" */
    0x38, 0x8a, 0xc, 0x18, 0x10, 0x27, 0xc1, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+0048 "H" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+0049 "I" */
    0xff, 0xf8,

    /* U+004A "J" */
    0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+004B "K" */
    0x83, 0xa, 0x24, 0x8a, 0x18, 0x30, 0x50, 0x91,
    0x12, 0x24, 0x28, 0x20,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x2, 0x4, 0xf, 0xe0,

    /* U+004D "M" */
    0x83, 0x7, 0x1e, 0x3e, 0xf5, 0x6a, 0xd5, 0xab,
    0x26, 0x4c, 0x98, 0x20,

    /* U+004E "N" */
    0x83, 0x7, 0xe, 0x1a, 0x34, 0x64, 0xc9, 0x8b,
    0x16, 0x1c, 0x38, 0x20,

    /* U+004F "O" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+0050 "P" */
    0xf9, 0xe, 0xc, 0x18, 0x30, 0x61, 0x7c, 0x81,
    0x2, 0x4, 0x8, 0x0,

    /* U+0051 "Q" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x26, 0x4a, 0x63, 0xc0, 0xc0,

    /* U+0052 "R" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x42, 0x85,
    0xa, 0xc, 0x18, 0x20,

    /* U+0053 "S" */
    0x38, 0x8a, 0xc, 0x18, 0x8, 0xe, 0x2, 0x3,
    0x6, 0xa, 0x23, 0x80,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40, 0x80,

    /* U+0055 "U" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+0056 "V" */
    0x83, 0x6, 0xc, 0x1c, 0x68, 0x91, 0x22, 0x6c,
    0x50, 0xa0, 0x81, 0x0,

    /* U+0057 "W" */
    0x83, 0x26, 0x4c, 0x9b, 0xb7, 0x6a, 0xd5, 0xee,
    0x89, 0x12, 0x24, 0x40,

    /* U+0058 "X" */
    0x83, 0x5, 0x12, 0x22, 0x85, 0x4, 0x14, 0x28,
    0x89, 0x14, 0x18, 0x20,

    /* U+0059 "Y" */
    0x83, 0x6, 0xa, 0x24, 0x45, 0xa, 0x8, 0x10,
    0x20, 0x40, 0x81, 0x0,

    /* U+005A "Z" */
    0xfe, 0x8, 0x10, 0x40, 0x82, 0x4, 0x10, 0x20,
    0x81, 0x4, 0xf, 0xe0,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0x27,

    /* U+005C "\\" */
    0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10,
    0x80,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x92, 0x4f,

    /* U+005E "^" */
    0x30, 0xc4, 0x92, 0x86, 0x10,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0x99, 0x10,

    /* U+0061 "a" */
    0x79, 0xa, 0x10, 0x27, 0xd0, 0xa1, 0x46, 0x72,

    /* U+0062 "b" */
    0x81, 0x2, 0x5, 0xcc, 0x50, 0x60, 0xc1, 0x83,
    0x7, 0x15, 0xc0,

    /* U+0063 "c" */
    0x38, 0x8a, 0xc, 0x8, 0x10, 0x20, 0xa2, 0x38,

    /* U+0064 "d" */
    0x2, 0x4, 0x9, 0xd4, 0x70, 0x60, 0xc1, 0x83,
    0x5, 0x19, 0xd0,

    /* U+0065 "e" */
    0x38, 0x8a, 0xc, 0x1f, 0xf0, 0x20, 0xa2, 0x38,

    /* U+0066 "f" */
    0x1c, 0x82, 0x8, 0xfc, 0x82, 0x8, 0x20, 0x82,
    0x8, 0x20,

    /* U+0067 "g" */
    0x7b, 0xa, 0x14, 0x27, 0x90, 0x1f, 0x41, 0x82,
    0xf8,

    /* U+0068 "h" */
    0x81, 0x2, 0x5, 0xcc, 0x50, 0x60, 0xc1, 0x83,
    0x6, 0xc, 0x10,

    /* U+0069 "i" */
    0xdf, 0xf0,

    /* U+006A "j" */
    0x24, 0x12, 0x49, 0x24, 0x9c,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x18, 0x53, 0x28, 0x60, 0xa1,
    0x32, 0x14, 0x10,

    /* U+006C "l" */
    0xff, 0xf0,

    /* U+006D "m" */
    0xa5, 0xb6, 0x4c, 0x99, 0x32, 0x64, 0xc9, 0x92,

    /* U+006E "n" */
    0xb9, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x82,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xa2, 0x38,

    /* U+0070 "p" */
    0xb9, 0x8e, 0xc, 0x18, 0x30, 0x71, 0x5c, 0x81,
    0x0,

    /* U+0071 "q" */
    0x3b, 0x8e, 0xc, 0x18, 0x30, 0x51, 0x9d, 0x2,
    0x4,

    /* U+0072 "r" */
    0xbe, 0x21, 0x8, 0x42, 0x10, 0x80,

    /* U+0073 "s" */
    0x7d, 0x6, 0xc, 0x7, 0xc0, 0x60, 0xc1, 0x7c,

    /* U+0074 "t" */
    0x20, 0x82, 0x3f, 0x20, 0x82, 0x8, 0x20, 0x82,
    0x7,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xa3, 0x3a,

    /* U+0076 "v" */
    0x83, 0x6, 0xa, 0x24, 0x45, 0xa, 0x8, 0x10,

    /* U+0077 "w" */
    0x93, 0x26, 0x4d, 0x5a, 0xb5, 0x51, 0x22, 0x44,

    /* U+0078 "x" */
    0x82, 0x89, 0x11, 0x41, 0x5, 0x11, 0x22, 0x82,

    /* U+0079 "y" */
    0x83, 0x5, 0x12, 0x24, 0x45, 0xa, 0x8, 0x11,
    0xc0,

    /* U+007A "z" */
    0xfe, 0x4, 0x10, 0x41, 0x4, 0x10, 0x40, 0xfe,

    /* U+007B "{" */
    0x34, 0x44, 0x44, 0x44, 0x84, 0x44, 0x44, 0x43,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xc4, 0x22, 0x22, 0x22, 0x12, 0x22, 0x22, 0x2c,

    /* U+007E "~" */
    0x66, 0x60
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 1, .box_h = 13, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 128, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 5, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 128, .box_w = 7, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 31, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 128, .box_w = 1, .box_h = 5, .ofs_x = 3, .ofs_y = 10},
    {.bitmap_index = 58, .adv_w = 128, .box_w = 3, .box_h = 16, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 64, .adv_w = 128, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 70, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 76, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 128, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 85, .adv_w = 128, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 86, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 87, .adv_w = 128, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 128, .box_w = 3, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 128, .box_w = 2, .box_h = 8, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 217, .adv_w = 128, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 220, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 228, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 232, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 128, .box_w = 1, .box_h = 13, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 448, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 461, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 544, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 128, .box_w = 3, .box_h = 16, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 574, .adv_w = 128, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 128, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 589, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 594, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 595, .adv_w = 128, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 597, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 605, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 616, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 624, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 635, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 643, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 653, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 662, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 128, .box_w = 1, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 675, .adv_w = 128, .box_w = 3, .box_h = 13, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 680, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 691, .adv_w = 128, .box_w = 1, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 701, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 709, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 717, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 726, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 735, .adv_w = 128, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 741, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 749, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 758, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 766, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 774, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 782, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 790, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 799, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 807, .adv_w = 128, .box_w = 4, .box_h = 16, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 815, .adv_w = 128, .box_w = 1, .box_h = 14, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 817, .adv_w = 128, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 825, .adv_w = 128, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4}
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
const lv_font_t ui_font_DotGothic16 = {
#else
lv_font_t ui_font_DotGothic16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_DOTGOTHIC16*/

