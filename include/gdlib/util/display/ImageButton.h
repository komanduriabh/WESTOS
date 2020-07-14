#pragma once
#include "display/lvgl.h"
#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H
class ImageButton {
private:
    lv_obj_t * imgbtn;
    lv_align_t align;
    const void *src;
    lv_coord_t x_ofs;
    lv_coord_t y_ofs;
    const char *text;

public:
    ImageButton( lv_obj_t * imgbtn, lv_align_t align, const void *src, lv_coord_t x_ofs, lv_coord_t y_ofs, const char *text);
};
#endif