#include "ImageButton.h"


int ImageButton::freeNumber = 0;

ImageButton::ImageButton( lv_obj_t * imgbtn, lv_align_t align, const void *src, lv_coord_t x_ofs, lv_coord_t y_ofs, const char *text, lv_action_t action){

    imgbtn = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_fit(imgbtn, true, true);
    lv_btn_set_style(imgbtn, LV_BTN_STYLE_REL, &lv_style_transp_tight);
    lv_btn_set_style(imgbtn, LV_BTN_STYLE_PR, &lv_style_transp_tight);
    lv_btn_set_action(imgbtn, LV_BTN_ACTION_CLICK, action);
    lv_obj_align(imgbtn, NULL, align, x_ofs, y_ofs);
    lv_obj_set_free_num(imgbtn, freeNumber); /*Set a unique number for the button*/

	lv_obj_t * img = lv_img_create(imgbtn, NULL);                         /*Create the image on 'btn1'*/
    lv_obj_set_click(img, false);      
    lv_img_set_src(img, src);


    freeNumber++;

}
