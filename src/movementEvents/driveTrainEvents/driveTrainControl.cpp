/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       outakeControl.cpp                                         */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "driver-control-functions.h"

using namespace vex;

vex::controller::button bUp = Controller1.ButtonUp;
vex::controller::button bRight = Controller1.ButtonRight;
vex::controller::button bDown = Controller1.ButtonDown;
vex::controller::button bLeft = Controller1.ButtonLeft;

void driveTrainControl(vex::directionType dir, int speed, vex::percentUnits pt, vex::controller::button Button) {
  Drivetrain.setDriveVelocity(speed, pt);
  Drivetrain.drive(dir);
  waitUntil(!Button.pressing());
  Drivetrain.stop();
}

void driveTrainControl(vex::turnType dir, int speed, vex::percentUnits pt, vex::controller::button Button) {
  Drivetrain.setTurnVelocity(speed, pt);
  Drivetrain.turn(dir);
  waitUntil(!Button.pressing());
  Drivetrain.stop();
}

void driveTrainControl(vex::directionType dir, int speed, vex::velocityUnits vel, vex::controller::button Button) {
  Drivetrain.setDriveVelocity(speed, vel);
  Drivetrain.drive(dir);
  waitUntil(!Button.pressing());
  Drivetrain.stop();
}

void driveTrainControl(vex::turnType dir, int speed, vex::velocityUnits vel, vex::controller::button Button) {
  Drivetrain.setTurnVelocity(speed, vel);
  Drivetrain.turn(dir);
  waitUntil(!Button.pressing());
  Drivetrain.stop();
}
