#include "display/lvgl.h"

class ImageButton {
private:
    lv_obj_t * imgbtn;
    static int freeNumber;
public:
 
    ImageButton(lv_align_t align, const void *src, lv_coord_t x_ofs, lv_coord_t y_ofs, const char *text, lv_action_t action, lv_obj_t *par);
};
