#include "main.h"
#include "gdlib/util/display/ImageButton.h"
#include "gdlib/util/display/Button.h"
//Global Screen Variables
#include "osfunctions.h"
 
 

void initialize() {
	//Basic Init
	lv_scr_load(lockScreen);
	LV_IMG_DECLARE(settings);
	LV_IMG_DECLARE(files);
	LV_IMG_DECLARE(profile);
	LV_IMG_DECLARE(controller);
	LV_IMG_DECLARE(auton);
	LV_IMG_DECLARE(debug);

	//Load WEST Operating System Button
	Button* osLoadButton = new Button(LV_ALIGN_IN_TOP_LEFT, -175, 0, 470, 50, "Boot WESTOS", osAction, lockScreen);
	//Load Competition Operating System Button
	Button* compLoadButton = new Button(LV_ALIGN_IN_TOP_LEFT, -175, 0, 470, 50, "Boot COMPOS", osAction, lockScreen);

	//Settings Button
	ImageButton* settingsIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &settings, 25, 25, "Settings", settingsAction, Home);
	//Files System
	ImageButton* filesIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &files, 175, 25, "Files", filesAction, Home);
	//Profile
	ImageButton* debugIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &debug, 325, 25, "Debugging", filesAction, Home);
	//Controller Config Button
	ImageButton* controllerIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &controller, 25, 125, "Controller Configuration", settingsAction, Home);
	//Auton Button
	ImageButton* autonIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &auton, 175, 125, "Autonomous", filesAction, Home);
	//Debugging Icon
	ImageButton* debugIcon = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &debug, 325, 125, "Debugging", filesAction, Home);
	//Exit
	ImageButton* exit = new ImageButton(LV_ALIGN_IN_TOP_LEFT, &debug, 325, 125, "Debugging", exitAction, Home);
	//Enable Theme Toggling
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
