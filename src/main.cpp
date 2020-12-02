/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4      
// LineTracker1         line          A               
// leftArmMotor         motor         5               
// rightArmMotor        motor         6               
// leftUpwards          motor         17              
// rightUpwards         motor         8               
// LineTracker2         line          B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "movementEvents.h"

using namespace vex;

void whenControllerR1Pressed() {
  intakeMove(600, rpm, forward);
  waitUntil(!Controller1.ButtonR1.pressing());
  intakeStop();
}

void whenControllerR2Pressed() {
  intakeMove(400, rpm, reverse);
  waitUntil(!Controller1.ButtonR2.pressing());
  intakeStop();
}

void whenControllerL1Pressed() {
  outakeMove(600, rpm, reverse);
  waitUntil(!Controller1.ButtonL1.pressing());
  outakeStop();
}

void whenControllerL2Pressed() {
  outakeMove(400, rpm, forward);
  waitUntil(!Controller1.ButtonL2.pressing());
  outakeStop();
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

void autonomous() {
  autoMain();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Create Callbacks for the motors and buttons
  Controller1.ButtonR1.pressed(whenControllerR1Pressed);
  Controller1.ButtonR2.pressed(whenControllerR2Pressed);
  Controller1.ButtonL1.pressed(whenControllerL1Pressed);
  Controller1.ButtonL2.pressed(whenControllerL2Pressed);
  Controller1.ButtonUp.pressed(whenControllerButtonUpPressed);
  Controller1.ButtonRight.pressed(whenControllerButtonRightPressed);
  Controller1.ButtonDown.pressed(whenControllerButtonDownPressed);
  Controller1.ButtonLeft.pressed(whenControllerButtonLeftPressed);

  // Set the intake and outake motors stopping mode
  leftUpwards.setStopping(brake);
  rightUpwards.setStopping(brake);
  leftArmMotor.setStopping(coast);
  rightArmMotor.setStopping(coast);
  Drivetrain.setStopping(brake);
  
}
