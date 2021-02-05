/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       1011Special.cpp                                            */
/*    Author:       Liam Teale                                                */
/*    Created:      Feb 2 2021                                                */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

void centerSpecial() {
  // set custom timer to 15
  customTimer = 15;
  // set drivetrain velocity to 50% for accurate disctance
  Drivetrain.setDriveVelocity(50, percent);
  thread releaseAHood = thread(releaseHood);


  if(goals == 1011) {
    Drivetrain.driveFor(forward, 10, inches);
    wait(100, msec);
    Drivetrain.turnFor(left, 90, degrees);
    wait(100, msec);
    Drivetrain.driveFor(30, inches);
    wait(100, msec);
    Drivetrain.turnFor(left, 45, degrees);
    leftArmMotor.spin(forward, 200, rpm);
    rightArmMotor.spin(forward, 200, rpm);
    wait(100, msec);
    Drivetrain.drive(forward);
    waitUntil(LimitSwitchIntake.pressing());
    Drivetrain.stop();
    rightArmMotor.stop();
    leftArmMotor.stop();
    Drivetrain.setDriveVelocity(100, percent);
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    wait(150, msec);
    Drivetrain.stop();
    leftArmMotor.stop();
    rightArmMotor.stop();
    wait(100, msec);
    Drivetrain.driveFor(reverse, 30, inches);
    wait(100, msec);
    Drivetrain.turnFor(right, 135, degrees);
    wait(100, msec);
    leftArmMotor.spin(forward, 200, rpm);
    rightArmMotor.spin(forward, 200, rpm);
    Drivetrain.driveFor(forward, 40, inches);
    waitUntil(LimitSwitchIntake.pressing());
    leftArmMotor.stop();
    rightArmMotor.stop();
    Drivetrain.driveFor(reverse, 30, inches);
    Drivetrain.turnFor(right, 90, degrees);
    wait(100, msec);
    Drivetrain.driveFor(forward, 40, inches);
    wait(100, msec);
    Drivetrain.turnFor(left, 90, degrees);
    leftArmMotor.spin(forward, 200, rpm);
    rightArmMotor.spin(forward, 200, rpm);
    Drivetrain.driveFor(forward, 14, inches);
    waitUntil(LimitSwitchIntake.pressing());
    leftArmMotor.stop();
    rightArmMotor.stop();
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    wait(300, msec);
    leftUpwards.stop();
    rightUpwards.stop();
    Drivetrain.driveFor(reverse, 14, inches);









    





    
  }
}