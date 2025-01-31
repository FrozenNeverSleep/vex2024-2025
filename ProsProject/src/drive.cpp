#include "main.h"
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_mg({18, 19, 20});
pros::MotorGroup right_mg({-15, -16, -17});

void drive() {
    int left_stick = controller.get_analog(ANALOG_LEFT_Y);
	int right_stick = controller.get_analog(ANALOG_RIGHT_X);
    left_mg.move(left_stick);
	right_mg.move(right_stick);
}