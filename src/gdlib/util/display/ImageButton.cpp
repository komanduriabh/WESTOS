#include "gdlib/util/display/ImageButton.h"
#if LV_USE_IMGBTN

ImageButton::ImageButton( lv_obj_t * imgbtn, lv_align_t align, const void *src, lv_coord_t x_ofs, lv_coord_t y_ofs, const char *text){
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_image_recolor_opa(&style, LV_STATE_PRESSED, LV_OPA_30);
    lv_style_set_image_recolor(&style, LV_STATE_PRESSED, LV_COLOR_BLACK);
    lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    imgbtn = lv_imgbtn_create(lv_scr_act(), NULL);
    lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_RELEASED, src);
    lv_obj_add_style(imgbtn, LV_IMGBTN_PART_MAIN, &style);
    lv_obj_align(imgbtn, NULL, align, x_ofs, y_ofs);

    lv_obj_t * label = lv_label_create(imgbtn, NULL);
    lv_label_set_text(label, text);
}
#endif