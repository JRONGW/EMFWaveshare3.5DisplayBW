// Arduino only compiles .c/.cpp in the sketch root. SquareLine exports live in
// subfolders, so pull them into one translation unit here (must be .c, not .cpp).

#include "screens/ui_homepage.c"
#include "screens/ui_detect.c"
#include "screens/ui_EEG_Screen.c"
#include "screens/ui_GSR_Screen.c"
#include "screens/ui_Analysis.c"
#include "screens/ui_High_RF.c"
#include "screens/ui_Low_mid_RF1.c"

#include "images/ui_img_backgroundpage2_png.c"
#include "images/ui_img_3_png.c"
#include "images/ui_img_stubs.c"

#include "components/ui_comp_hook.c"
