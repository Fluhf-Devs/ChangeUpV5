/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       buttonCallbacks.cpp                                       */
/*    Author:       Liam Teale                                                */
/*    Created:      March 5 2021                                              */
/*    Description:  V5 ChangeUp Robot                                         */ 
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

// variables
bool intercept = false;

void whenControllerR1Pressed() {
  intakeMove(200, rpm, forward);
  waitUntil(!Controller1.ButtonR1.pressing());
  intakeStop();
}

void whenControllerR2Pressed() {
  intakeMove(200, rpm, reverse);
  waitUntil(!Controller1.ButtonR2.pressing());
  intakeStop();
}

void whenControllerL1Pressed() {
  if (intercept) {
    leftArmMotor.spin(reverse, 600, rpm);
    rightArmMotor.spin(reverse, 600, rpm);
    waitUntil(!Controller1.ButtonL1.pressing());
    outakeStop();

  } else if (intercept == false) {
      outakeMove(600, rpm, reverse);
      waitUntil(!Controller1.ButtonL1.pressing());
      outakeStop();
    }
}

void whenControllerL2Pressed() {
  if (intercept) {
    leftArmMotor.spin(forward, 400, rpm);
    rightArmMotor.spin(forward, 400, rpm);
    waitUntil(!Controller1.ButtonL2.pressing());
    outakeStop();
  } else if (intercept == false) {
      outakeMove(400, rpm, forward);
      waitUntil(!Controller1.ButtonL2.pressing());
      outakeStop();
    }
}

void whenControllerButtonUpPressed() {
  driveTrainControl(forward, 15, percent);
  waitUntil(!Controller1.ButtonUp.pressing());
  Drivetrain.stop();
}

void whenControllerButtonRightPressed() {
  driveTrainControl(right, 15, percent);
  waitUntil(!Controller1.ButtonRight.pressing());
  Drivetrain.stop();
}

void whenControllerButtonDownPressed() {
  driveTrainControl(reverse, 15, percent);
  waitUntil(!Controller1.ButtonDown.pressing());
  Drivetrain.stop();
}

void whenControllerButtonLeftPressed() {
  driveTrainControl(left, 15, percent);
  waitUntil(!Controller1.ButtonLeft.pressing());
  Drivetrain.stop();
}

void whenController2ButtonBPressed() {
  intercept = !intercept;
}
