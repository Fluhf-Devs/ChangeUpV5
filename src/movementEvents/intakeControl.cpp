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
#include "vex_controller.h"

using namespace vex;

//vex::directionType inwards = vex::directionType(forward);
//vex::directionType outwards = vex::directionType(reverse);
//vex::controller::button bR1 = Controller1.ButtonR1;
//vex::controller::button bR2 = Controller1.ButtonR2;

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
