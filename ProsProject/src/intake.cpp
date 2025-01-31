#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup intake_mg({13, 14});
enum intake_state {
  REVERSE = 1,
  STOPPED,
  FORWARD
}; 
enum intake_state state = STOPPED;
void intakeControls() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
        switch(state) {
            case STOPPED:
                state = FORWARD;
                break;
            case FORWARD:
                state = STOPPED;
                break;
            default:
                break;
        }
    } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) 
    {
        state = REVERSE;
    }
    switch(state) {
        case FORWARD:
            intake_mg.move(127);
            break;
        case REVERSE:
            intake_mg.move(-127);
            break;
        case STOPPED:
            intake_mg.move(0);
            break;
    }
}