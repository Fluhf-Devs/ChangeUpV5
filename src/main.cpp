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
// leftArmMotor         motor         5               
// rightArmMotor        motor         6               
// leftUpwards          motor         17              
// rightUpwards         motor         8               
// LineTrackerLEFT      line          A               
// LineTrackerCENTER    line          B               
// LineTrackerRIGHT     line          C               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "movementEvents.h"

competition Competition;

int test = 0;
int skillsAuto = 0;

void whenControllerR1Pressed() {
  intakeMove(600, rpm, forward);
  waitUntil(!Controller1.ButtonR1.pressing());
  wait(5, msec);
  intakeStop();
}

void whenControllerR2Pressed() {
  intakeMove(400, rpm, reverse);
  waitUntil(!Controller1.ButtonR2.pressing());
  wait(5, msec);
  intakeStop();
}

void whenControllerL1Pressed() {
  outakeMove(600, rpm, reverse);
  waitUntil(!Controller1.ButtonL1.pressing());
  wait(5, msec);
  outakeStop();
}

void whenControllerL2Pressed() {
  outakeMove(400, rpm, forward);
  waitUntil(!Controller1.ButtonL2.pressing());
  wait(5, msec);
  outakeStop();
}

void whenControllerButtonUpPressed() {
  driveTrainControl(forward, 15, percent);
  waitUntil(!Controller1.ButtonUp.pressing());
  wait(5, msec);
  Drivetrain.stop();
}

void whenControllerButtonRightPressed() {
  driveTrainControl(right, 15, percent);
  waitUntil(!Controller1.ButtonRight.pressing());
  wait(5, msec);
  Drivetrain.stop();
}

void whenControllerButtonDownPressed() {
  driveTrainControl(reverse, 15, percent);
  waitUntil(!Controller1.ButtonDown.pressing());
  wait(5, msec);
  Drivetrain.stop();
}

void whenControllerButtonLeftPressed() {
  driveTrainControl(left, 15, percent);
  waitUntil(!Controller1.ButtonLeft.pressing());
  wait(5, msec);
  Drivetrain.stop();
}

void whenControllerButtonBPressed() {
  skillsMainAuto();
}

void whenControllerButonXPressed() {
  ++test;
}

void autonomous() {
  competitionMainAuto();
}

void usercontrol() {
  // callbacks for the buttons here so that it does not work during the autonomous period
  Controller1.ButtonR1.pressed(whenControllerR1Pressed);
  Controller1.ButtonR2.pressed(whenControllerR2Pressed);
  Controller1.ButtonL1.pressed(whenControllerL1Pressed);
  Controller1.ButtonL2.pressed(whenControllerL2Pressed);
  Controller1.ButtonUp.pressed(whenControllerButtonUpPressed);
  Controller1.ButtonRight.pressed(whenControllerButtonRightPressed);
  Controller1.ButtonDown.pressed(whenControllerButtonDownPressed);
  Controller1.ButtonLeft.pressed(whenControllerButtonLeftPressed);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // set the callbacks for testing mode
  Controller1.ButtonB.pressed(whenControllerButtonBPressed);
  Controller1.ButtonX.pressed(whenControllerButonXPressed);

  // set the callbacks for drivercontrol and usercontrol periods
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Set the intake and outake motors stopping mode
  leftUpwards.setStopping(coast);
  rightUpwards.setStopping(coast);
  leftArmMotor.setStopping(coast);
  rightArmMotor.setStopping(coast);
  Drivetrain.setStopping(coast);

  // enter test mode
  while (test>=1) {
    Controller1.ButtonR1.pressed(whenControllerR1Pressed);
    Controller1.ButtonR2.pressed(whenControllerR2Pressed);
    Controller1.ButtonL1.pressed(whenControllerL1Pressed);
    Controller1.ButtonL2.pressed(whenControllerL2Pressed);
    Controller1.ButtonUp.pressed(whenControllerButtonUpPressed);
    Controller1.ButtonRight.pressed(whenControllerButtonRightPressed);
    Controller1.ButtonDown.pressed(whenControllerButtonDownPressed);
    Controller1.ButtonLeft.pressed(whenControllerButtonLeftPressed);
  }  
  
}
