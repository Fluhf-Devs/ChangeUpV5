// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// leftArmMotor         motor         10              
// rightArmMotor        motor         18              
// leftUpwards          motor         1               
// rightUpwards         motor         19              
// Drivetrain           drivetrain    2, 11, 20, 17   
// LimitSwitchIntake    limit         A               
// Accel2GB             accelerometer B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "functions.h"

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

void usercontrol() {
  // set custom timers
  if(isSkills == true) {
    customTimer = 60;
  } else if (isSkills == false){
    customTimer = 105;
  }

  // stop everything, just to simulate comm switch when not actually using one
  leftArmMotor.stop();
  rightArmMotor.stop();
  leftUpwards.stop();
  rightUpwards.stop();
  Drivetrain.stop();
  // callbacks for driver contol functions
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
  
  // enable brain screen
  thread autobrainScreenThread = thread(brainScreen);
  // read config file
  configWork();

  // call the pre autonomous
  preAuton();

  // Set the intake and outake motors stopping mode
  leftUpwards.setStopping(coast);
  rightUpwards.setStopping(coast);
  leftArmMotor.setStopping(coast);
  rightArmMotor.setStopping(coast);
  Drivetrain.setStopping(coast);
}
