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

vex::directionType upwards = vex::directionType(reverse);
vex::directionType downwards = vex::directionType(forward);
vex::controller::button bL1 = Controller1.ButtonL1;
vex::controller::button bL2 = Controller1.ButtonL2;

void outakeMove(int speed, vex::percentUnits pt, vex::directionType Mdir, vex::controller::button Button) {
  leftUpwards.setVelocity(speed,pt);
  rightUpwards.setVelocity(speed,pt);
  leftUpwards.spin(Mdir);
  rightUpwards.spin(Mdir);
  waitUntil(!Button.pressing());
  leftArmMotor.stop();
  rightArmMotor.stop();
}

void outakeMove(int speed, vex::velocityUnits vel, vex::directionType Mdir, vex::controller::button Button) {
  leftUpwards.setVelocity(speed,vel);
  rightUpwards.setVelocity(speed,vel);
  leftUpwards.spin(Mdir);
  rightUpwards.spin(Mdir);
  waitUntil(!Button.pressing());
  leftUpwards.stop();
  rightUpwards.stop();
}
