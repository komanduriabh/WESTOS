#include "display/lvgl.h"

class Button{
private:
    lv_obj_t * btn;
    static int freeNumber;
public:
    Button(lv_align_t align,lv_coord_t x_ofs, lv_coord_t y_ofs, lv_coord_t width, lv_coord_t height, const char *text, lv_action_t action, lv_obj_t *par);
};