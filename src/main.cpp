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
// leftArmMotor         motor         10              
// rightArmMotor        motor         18              
// leftUpwards          motor         1               
// rightUpwards         motor         19              
// LineTrackerLEFT      line          A               
// LineTrackerCENTER    line          B               
// LineTrackerRIGHT     line          C               
// Drivetrain           drivetrain    11, 17          
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "movementEvents.h"

competition Competition;

int test = 0;
int skillsAuto = 0;

void whenControllerR1Pressed() {
  intakeMove(200, rpm, forward);
  waitUntil(!Controller1.ButtonR1.pressing());
  wait(5, msec);
  intakeStop();
}

void whenControllerR2Pressed() {
  intakeMove(200, rpm, reverse);
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

void compAuto() {
  Drivetrain.setDriveVelocity(75, percent);
  // drive forward 23.5 inches
  Drivetrain.driveFor(12, inches);
  // wait 200 msec
  wait(200, msec);
  // turn 90 degrees
  Drivetrain.turnFor(left, 90, degrees);
  // wait 100 msec
  wait(100, msec);
  // drive forward for 36 inches
  Drivetrain.driveFor(forward, 31, inches);
  // wait 100 msec
  wait(100, msec);
  // turn left 90 degrees
  Drivetrain.turnFor(left, 90, degrees);
  // wait 100 msec
  wait(100, msec);
  // drive forward for 2 seconds
  Drivetrain.drive(forward);
  wait(2, sec);
  Drivetrain.stop();
  leftUpwards.spin(reverse, 600, rpm);
  rightUpwards.spin(reverse, 600, rpm);
  wait(500, msec);
  leftUpwards.stop();
  rightUpwards.stop();
  // reverse 12 inches
  Drivetrain.setDriveVelocity(50, percent);
  Drivetrain.driveFor(reverse, 10, inches);
  Drivetrain.setDriveVelocity(75, percent);
  // wait 100 mec
  wait(100, msec);
  // rturn left 90 degrees
  Drivetrain.turnFor(left, 90, degrees);
  // wait 100
  wait(100, msec);
  // drive forward 36 inches
  Drivetrain.driveFor(forward, 42, inches);
  // wait 100 msec
  wait(100, msec);
  // turn right 45 degrees
  Drivetrain.turnFor(right, 45, degrees);
  // wait 100 msec
  wait(100, msec);
  // spin the intakes and outakes
  leftUpwards.spin(reverse, 600, rpm);
  rightUpwards.spin(reverse, 600, rpm);
  rightArmMotor.spin(forward, 600, rpm);
  leftArmMotor.spin(forward, 600, rpm);
  Drivetrain.setDriveVelocity(25, percent);
  Drivetrain.drive(forward);


  
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // set the callbacks for testing mode
  Controller1.ButtonB.pressed(whenControllerButtonBPressed);
  Controller1.ButtonX.pressed(whenControllerButonXPressed);

  // set the callbacks for drivercontrol and usercontrol periods
  Competition.autonomous(compAuto);
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
