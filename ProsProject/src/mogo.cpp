#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut mogo_digout (1);

void mogoControl() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) 
    {
        mogo_digout.set_value(true);
    } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) 
    {
        mogo_digout.set_value(false);
    }
}