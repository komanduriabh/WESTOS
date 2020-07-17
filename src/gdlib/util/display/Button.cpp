#include "Button.h"

Button::Button(lv_align_t align,lv_coord_t x_ofs, lv_coord_t y_ofs, lv_coord_t width, lv_coord_t height, const char *text, lv_action_t action, lv_obj_t *par){
    lv_obj_t * btn1 = lv_btn_create(par, NULL);
    lv_obj_align(btn1, NULL, LV_ALIGN_CENTER, x_ofs, y_ofs);
    lv_obj_set_size(btn1, width, height);
    lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, action);

    lv_obj_t * label = lv_label_create(btn1, NULL);
    lv_label_set_text(label, text);
}