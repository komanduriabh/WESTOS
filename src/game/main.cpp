#include "main.h"
#include "gdlib/util/display/ImageButton.h"
#include "gdlib/util/display/Button.h"
//Global Screen Variables
//-----------------------------------------------//
lv_obj_t * Home = lv_obj_create(NULL, NULL);
lv_obj_t * settingsScreen = lv_obj_create(NULL, NULL);
lv_obj_t * filesScreen = lv_obj_create(NULL, NULL);
//-----------------------------------------------//
 
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

void initialize() {
	//Basic Init
	lv_scr_load(Home);
	LV_IMG_DECLARE(settings);
	LV_IMG_DECLARE(files);
	LV_IMG_DECLARE(profile);
	LV_IMG_DECLARE(controller);
	LV_IMG_DECLARE(auton);
	LV_IMG_DECLARE(debug);

	//Settings Button
	ImageButton* settingsIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &settings, 25, 25, "Settings", settingsAction, Home);
	//Files System
	ImageButton* filesIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &files, 175, 25, "Files", filesAction, Home);
	//Profile
	ImageButton* profileIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &profile, 325, 25, "Profile", filesAction, Home);
	//Controller Config Button
	ImageButton* controllerIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &controller, 25, 125, "Controller Configuration", settingsAction, Home);
	//Auton Button
	ImageButton* autonIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &auton, 175, 125, "Autonomous", filesAction, Home);
	//Debugging Icon
	ImageButton* debugIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &debug, 325, 125, "Debugging", filesAction, Home);


	Button* theme = new Button(LV_ALIGN_IN_TOP_LEFT, -175, -75, 470, 50, "Theme", changeTheme, settingsScreen);
}









void disabled() {}
void competition_initialize() {}
void autonomous() {}
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		left_mtr = left;
		right_mtr = right;
		pros::delay(20);
	}
}
