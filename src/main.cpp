/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       AV Engineers                                              */
/*    Created:      Tue Oct 11 2023                                           */
/*    Description:  AV Engineers A Team Spin Up Competition Code Main         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// LeftDriveFront    motor           1
// LeftDriveBack     motor           2
// RightDriveFront   motor           3
// RightDriveBack    motor           4
// Flywheel          motor           5
// Arm               motor           6
// Controller        controller
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "drive.h"
#include "control.h"
#include "auton.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}

void autonomous(void) {
  Arm.spinToPosition(45, rotationUnits::deg);
  // RightDrive.setVelocity(100, velocityUnits::pct);
  // LeftDrive.setVelocity(100, velocityUnits::pct);
  // RightDrive.spin(directionType::fwd);
  // LeftDrive.spin(directionType::fwd);
  // Intake.setVelocity(50, velocityUnits::pct);
  // Intake.spin(directionType::fwd);
  // wait(250, msec);
  // Intake.setVelocity(0, velocityUnits::pct);
  // Intake.stop();
  // RightDrive.stop();
  // LeftDrive.stop();
  // RightDrive.setVelocity(100, velocityUnits::pct);
  // LeftDrive.setVelocity(100, velocityUnits::pct);
  // RightDrive.spin(directionType::fwd);
  // LeftDrive.spin(directionType::fwd);
  // wait(1000, msec);
  // RightDrive.stop();
  // LeftDrive.stop();
  // Intake.spin(directionType::fwd);
  // wait(2000, msec);
  // Intake.stop();
  // RightDrive.spin(directionType::rev);
  // LeftDrive.spin(directionType::rev);
  // wait(1975, msec);
  // RightDrive.stop();
  // LeftDrive.stop();
  // wait(500, msec);
  // RightDrive.spin(directionType::fwd);
  // LeftDrive.spin(directionType::rev);
  // wait(800, msec);
  // LeftDrive.spin(directionType::fwd);
  // wait(1000, msec);
  // Intake.setVelocity(50, velocityUnits::pct);
  // Intake.spin(directionType::fwd);
  // wait(500, msec);
  // Intake.setVelocity(0, velocityUnits::pct);
  // Intake.stop();
  // // RightDrive.setVelocity(0, velocityUnits::pct);
  // LeftDrive.setVelocity(0, velocityUnits::pct);
  // RightDrive.stop();
  // LeftDrive.stop();
}

void usercontrol(void) {
  setupFlywheel(Controller.ButtonR1);
  Controller.ButtonX.pressed(intake);
  Controller.ButtonA.pressed(outtake);
  Controller.ButtonR2.pressed(manualIntake);
  Controller.ButtonL2.pressed(manualOuttake);
  while (true) {
    mainDrive();
    wait(20, msec);
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}