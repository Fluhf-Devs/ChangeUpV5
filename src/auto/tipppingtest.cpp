#include "vex.h"
#include "functions.h"


void tippingTest() {
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.drive(forward);
  wait(500, msec);
  Drivetrain.stop();
  Drivetrain.drive(reverse);
  wait(500, msec);
  Drivetrain.stop();
}