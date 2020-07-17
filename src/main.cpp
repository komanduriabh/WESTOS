#include "main.h"
#include "gdlib/util/display/ImageButton.h"

//Global Screen Variables
//-----------------------------------------------//
lv_obj_t * Home = lv_obj_create(NULL, NULL);
lv_obj_t * settingsScreen = lv_obj_create(NULL, NULL);
//-----------------------------------------------//
 
 static lv_res_t btn_click_action(lv_obj_t * btn)
{
	uint8_t id = lv_obj_get_free_num(btn);
	printf("Button %d is released\n", id);
	lv_scr_load(settingsScreen);
	return LV_RES_OK; /*Return OK if the button is not deleted*/
}
 static lv_res_t btn_click_action_one(lv_obj_t * btn)
{
	uint8_t id = lv_obj_get_free_num(btn);
	printf("Button %d is released\n", id);
	lv_scr_load(Home);
	return LV_RES_OK; /*Return OK if the button is not deleted*/
}
void initialize() {
	lv_scr_load(Home);
	lv_obj_t * settingsButton;		//Basic initialization for image and button
	
	LV_IMG_DECLARE(settings);
	 lv_theme_t *th = lv_theme_alien_init(10, NULL);

	//Settings Button
	ImageButton* settingsIcon = new ImageButton(settingsButton, LV_ALIGN_IN_TOP_LEFT, &settings, 25, 50, "Settings", btn_click_action, Home);
	ImageButton* two = new ImageButton(settingsButton, LV_ALIGN_IN_TOP_LEFT, &settings, 55, 50, "Settings", btn_click_action_one, settingsScreen);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
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
