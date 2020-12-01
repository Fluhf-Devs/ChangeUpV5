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
// leftArmMotor         motor         5               
// rightArmMotor        motor         6               
// leftUpwards          motor         17              
// rightUpwards         motor         8               
// Drivetrain           drivetrain    1, 2, 3, 4      
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "driver-control-functions.h"
#include "./movementEvents/intakeEvents/intakeControl.cpp"
#include "./movementEvents/outakeEvents/outakeControl.cpp"
#include "./movementEvents/driveTrainEvents/driveTrainControl.cpp"

using namespace vex;

void whenControllerR1Pressed() {
  intakeMove(600, rpm, inwards, bR1);
}

void whenControllerR2Pressed() {
  intakeMove(400, rpm, outwards, bR2);
}

void whenControllerL1Pressed() {
  outakeMove(600, rpm, upwards, bL1);
}

void whenControllerL2Pressed() {
  outakeMove(400, rpm, downwards, bL2);
}

void whenControllerButtonUpPressed() {
  driveTrainControl(forward, 15, percent, bUp);
}

void whenControllerButtonRightPressed() {
  driveTrainControl(right, 15, percent, bRight);
}

void whenControllerButtonDownPressed() {
  driveTrainControl(reverse, 15, percent, bDown);
}

void whenControllerButtonLeftPressed() {
  driveTrainControl(left, 15, percent, bLeft);
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
