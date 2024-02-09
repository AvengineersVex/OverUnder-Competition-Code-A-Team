#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// VEXcode device constructors
motor LeftDriveFront = motor(PORT12, ratio18_1, false);
motor LeftDriveBack = motor(PORT11, ratio18_1, false);
motor RightDriveFront = motor(PORT14, ratio18_1, true);
motor RightDriveBack = motor(PORT13, ratio18_1, true);
motor Flywheel = motor(PORT5, ratio6_1, false);
motor Arm = motor(PORT6, ratio36_1, false);

controller Controller = controller(primary);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
