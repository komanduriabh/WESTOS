#include "osfunctions.h"


static lv_res_t osAction(lv_obj_t * btn)
{
	lv_scr_load(lockScreen);
	return LV_RES_OK; /*Return OK if the button is not deleted*/
}
static lv_res_t compAction(lv_obj_t * btn)
{
	lv_scr_load(compScreen);
	return LV_RES_OK; /*Return OK if the button is not deleted*/
}
static lv_res_t settingsAction(lv_obj_t * btn)
{
	lv_scr_load(settingsScreen);
	return LV_RES_OK; /*Return OK if the button is not deleted*/
}
 static lv_res_t filesAction(lv_obj_t * btn)
{
	lv_scr_load(filesScreen);
	return LV_RES_OK; /*Return OK if the button is not deleted*/
}
 static lv_res_t exitAction(lv_obj_t * btn)
{
	lv_scr_load(lockScreen);
	return LV_RES_OK; /*Return OK if the button is not deleted*/
}
 static lv_res_t changeTheme(lv_obj_t * btn)
{
	static const char * btns[] ={"Apply", "Close", ""};

    lv_obj_t * mbox1 = lv_mbox_create(lv_scr_act(), NULL);
	 lv_mbox_set_text(mbox1, "Change Theme");
	lv_obj_t * ddlist = lv_ddlist_create(mbox1, NULL);
    lv_ddlist_set_options(ddlist, "Light\n"
            "Dark\n"
			"West Spirit");

    lv_obj_align(ddlist, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_mbox_add_btns(mbox1, btns, NULL);
    lv_obj_set_width(mbox1, 400);
    lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0); /*Align to the corner*/

	//Implement button functionality//

	return LV_RES_OK; /*Return OK if the button is not deleted*/
}

