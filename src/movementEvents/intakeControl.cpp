/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       intakeControl.cpp                                         */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "movementEvents.h"

/* Shorten the functions in main.cpp and in autoMain.cpp for controlling the intakes*/

void intakeMove(int speed, vex::percentUnits pt, vex::directionType Mdir) {
  leftArmMotor.setVelocity(speed, pt);
  rightArmMotor.setVelocity(speed, pt);
  leftArmMotor.spin(Mdir);
  rightArmMotor.spin(Mdir);
}

void intakeMove(int speed, vex::velocityUnits vel, vex::directionType Mdir) {
  leftArmMotor.setVelocity(speed, vel);
  rightArmMotor.setVelocity(speed, vel);
  leftArmMotor.spin(Mdir);
  rightArmMotor.spin(Mdir);
}

void intakeStop() {
  leftArmMotor.stop();
  rightArmMotor.stop();
}
