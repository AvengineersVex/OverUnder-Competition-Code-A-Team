#include "vex.h"
#include <cmath>
#include <math.h>
using namespace vex;

int mainDrive() { // one joystick
    RightDriveFront.setVelocity(0, velocityUnits::pct);
    RightDriveBack.setVelocity(0, velocityUnits::pct);
    LeftDriveFront.setVelocity(0, velocityUnits::pct);
    LeftDriveBack.setVelocity(0, velocityUnits::pct);
    Arm.setVelocity(0, velocityUnits::pct);
    RightDriveFront.spin(fwd);
    RightDriveBack.spin(fwd);
    LeftDriveFront.spin(fwd);
    LeftDriveBack.spin(fwd);
    Arm.spin(fwd);
    
    while (true) { // loop forever
        if (abs(Controller.Axis3.value()) < 20) { // rotating on the spot
            RightDriveFront.setVelocity(Controller.Axis4.position(), velocityUnits::pct); // right motor is negated because it needs to go in the opposite direction to turn on the spot
            RightDriveBack.setVelocity(Controller.Axis4.position(), velocityUnits::pct); // right motor is negated because it needs to go in the opposite direction to turn on the spot
            LeftDriveFront.setVelocity(-Controller.Axis4.position(), velocityUnits::pct);
            LeftDriveBack.setVelocity(-Controller.Axis4.position(), velocityUnits::pct);
        }
        else { // moving forward or back
            RightDriveFront.setVelocity(-Controller.Axis3.position(), velocityUnits::pct); // left and right motor go in the same direction
            RightDriveBack.setVelocity(-Controller.Axis3.position(), velocityUnits::pct); // left and right motor go in the same direction
            LeftDriveFront.setVelocity(-Controller.Axis3.position(), velocityUnits::pct); 
            LeftDriveBack.setVelocity(-Controller.Axis3.position(), velocityUnits::pct); 
        }

        if (Controller.Axis2.value() > 20) { // moving arm
            Arm.setVelocity(75, velocityUnits::pct);
        }
        else if (Controller.Axis2.value() < -20) { // moving arm
            Arm.setVelocity(-75, velocityUnits::pct);
        }
        else {
            Arm.setVelocity(0, velocityUnits::pct);
        }

        wait(20, msec); // some delay to prevent wasted resources
    }
    return 0;
}

// drive controls:

double inchesToDegrees(double inches) {
    return
     (inches / (4 * 3.14)) * 360;
}

// void goForward() {
//     RightDrive.setVelocity(100, velocityUnits::pct);
//     LeftDrive.setVelocity(100, velocityUnits::pct);
//     RightDrive.spin(directionType::fwd);
//     LeftDrive.spin(directionType::rev);
// }

// void goBackward() {
//     RightDrive.setVelocity(100, velocityUnits::pct);
//     LeftDrive.setVelocity(100, velocityUnits::pct);
//     RightDrive.spin(directionType::rev);
//     LeftDrive.spin(directionType::fwd);
// }

// void turnLeft() {
//     RightDrive.setVelocity(100, velocityUnits::pct);
//     LeftDrive.setVelocity(100, velocityUnits::pct);
//     RightDrive.spin(directionType::fwd);
//     LeftDrive.spin(directionType::fwd);
// }

// void turnRight() {
//     RightDrive.setVelocity(100, velocityUnits::pct);
//     LeftDrive.setVelocity(100, velocityUnits::pct);
//     RightDrive.spin(directionType::rev);
//     LeftDrive.spin(directionType::rev);
// }

// void stop() {
//     LeftDrive.stop();
//     RightDrive.stop();
// }

// void forwardInches(double inches) {
//     LeftDrive.spin(directionType::fwd);
//     RightDrive.spin(directionType::fwd);
//     LeftDrive.rotateFor(inchesToDegrees(inches), rotationUnits::deg, true);
//     RightDrive.rotateFor(inchesToDegrees(inches), rotationUnits::deg, true);
// }

// void backwardInches(double inches) {
//     LeftDrive.spin(directionType::rev);
//     RightDrive.spin(directionType::rev);
//     LeftDrive.rotateFor(inchesToDegrees(inches), rotationUnits::deg, true);
//     RightDrive.rotateFor(inchesToDegrees(inches), rotationUnits::deg, true);
// }

// void turnDegrees(double deg) {
//     const double width = 15.25;
//     const double length = 11.1;
//     const double circum = 12.5663706144;
//     double r = sqrt(pow(width, 2) + pow(length, 2)); // radius of the circle
//     double a = (deg * M_PI * r / 180) * (60) * (1 / circum);    // exact rpm to move in degrees/180 seconds
//     LeftDrive.setVelocity((a), velocityUnits::rpm);
//     RightDrive.setVelocity((-a), velocityUnits::rpm);
//     RightDrive.spin(directionType::fwd);
//     LeftDrive.spin(directionType::fwd);
//     wait((deg/180), sec);
//     RightDrive.setVelocity(0, velocityUnits::rpm);
//     LeftDrive.setVelocity(0, velocityUnits::rpm);
// }