#include "main.h"
#include "gdlib/util/display/ImageButton.h"

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
