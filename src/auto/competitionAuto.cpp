/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       competitionAuto.cpp                                       */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

/* competition autonomous code */

void competitionMainAuto() {
  // set custom timer to 15
  customTimer = 15;
  // set drivetrain velocity to 50% for accurate disctance
  Drivetrain.setDriveVelocity(50, percent);
  // drive forward 12 inches
  Drivetrain.driveFor(12, inches);

  // checks if it should score 1 or 2 goals
  if (goals == 2) {
    // turn 90 degrees
    Drivetrain.turnFor(dir1, 90, degrees);
    // drive forward for 36 inches
    Drivetrain.driveFor(forward, 25, inches);
    // turn left 90 degrees
    Drivetrain.turnFor(dir1, 90, degrees);
    // wait 100 msec
    wait(100, msec);
    // drive forward to goal
    Drivetrain.drive(forward);
    wait(700, msec);
    Drivetrain.stop();
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    wait(700, msec);
    leftUpwards.stop();
    rightUpwards.stop();
    // reverse 11 inches
    Drivetrain.setDriveVelocity(50, percent);
    Drivetrain.driveFor(reverse, 11, inches);
    Drivetrain.setDriveVelocity(75, percent);
    // wait 100 mec
    wait(100, msec);
    // rturn left 80 degrees
    Drivetrain.turnFor(dir1, 90, degrees);
    // wait 100
    wait(100, msec);
    // drive forward 36 inches
    Drivetrain.driveFor(forward, 41, inches);
    // wait 100 msec
    wait(100, msec);
    // turn right 45 degrees
    Drivetrain.turnFor(dir2, 45, degrees);
    // wait 100 msec
    wait(100, msec);
    // spin the intakes and outakes
    rightArmMotor.spin(forward, 600, rpm);
    leftArmMotor.spin(forward, 600, rpm);
    Drivetrain.setDriveVelocity(30, percent);
    Drivetrain.drive(forward);
    waitUntil(LimitSwitchIntake.pressing());
    Drivetrain.setDriveVelocity(100, percent);
    leftArmMotor.stop();
    rightArmMotor.stop();
    wait(100, msec);
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);

  } else if (goals == 1) {
    // turn to outer goal
    Drivetrain.turnFor(dir2, 90, degrees);
    // drive forward 20 inches
    Drivetrain.driveFor(forward, 20, inches);
    // turn 45 degrees
    Drivetrain.turnFor(dir2, 45, degrees);
    // spin the intakes and outakes
    rightArmMotor.spin(forward, 600, rpm);
    leftArmMotor.spin(forward, 600, rpm);
    Drivetrain.setDriveVelocity(30, percent);
    Drivetrain.drive(forward);
    waitUntil(LimitSwitchIntake.pressing());
    Drivetrain.setDriveVelocity(100, percent);
    leftArmMotor.stop();
    rightArmMotor.stop();
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    // detect collision, then wait 500 msec, then stop
    waitUntil(Accel2GB.acceleration() > 2 );
    Drivetrain.stop();
    wait(500, msec);
    leftUpwards.stop();
    rightUpwards.stop();

  }
}
