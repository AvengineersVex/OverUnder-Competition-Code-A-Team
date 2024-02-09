#include "vex.h"
using namespace vex;

bool flywheelSpinning = false;

void intake() {
    Arm.spinToPosition(60, rotationUnits::deg);
    flywheelSpinning = true;
    Flywheel.setVelocity(50, velocityUnits::pct);
    Flywheel.spin(directionType::rev);
    wait(2000, msec);
    Flywheel.stop();
    flywheelSpinning = false;
    Arm.spinToPosition(45, rotationUnits::deg);
}

void outtake() {
    flywheelSpinning = true;
    Flywheel.setVelocity(50, velocityUnits::pct);
    Flywheel.spin(directionType::rev);
    Arm.spinToPosition(45, rotationUnits::deg);
}

void manualIntake() {
    Intake.setVelocity(50, velocityUnits::pct);
    Intake.spin(directionType::rev);
}

void manualOuttake() {
    Intake.setVelocity(50, velocityUnits::pct);
    Intake.spin(directionType::fwd);
}

void flywheel() {
    if (flywheelSpinning) {
        flywheelSpinning = false;
        Flywheel.setVelocity(0, velocityUnits::pct);
        Flywheel.stop();
    } else {
        flywheelSpinning = true;
        Flywheel.setVelocity(100, velocityUnits::pct);
        Flywheel.spin(directionType::rev, 12.0, voltageUnits::volt);
    }
}

void setupFlywheel(controller::button Button) {
    Flywheel.setVelocity(0, velocityUnits::pct);
    Flywheel.stop();
    Button.pressed(flywheel);
}
