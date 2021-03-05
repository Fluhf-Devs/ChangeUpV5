// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// leftArmMotor         motor         10              
// rightArmMotor        motor         18              
// leftUpwards          motor         16              
// rightUpwards         motor         19              
// Drivetrain           drivetrain    2, 11, 12, 17   
// LimitSwitchIntake    limit         A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "functions.h"

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
  Controller2.ButtonB.pressed(whenController2ButtonBPressed);
  
  // disable drive PID
  enableDrivePID = false;
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // enable controllers and brain screen thread
  thread autobrainScreenThread = thread(brainScreen);
  task autocontrollerScreenThread = task(controllerScreen);

  // read config file
  configWork();

  // Set the intake and outake motors stopping mode
  leftUpwards.setStopping(coast);
  rightUpwards.setStopping(coast);
  leftArmMotor.setStopping(coast);
  rightArmMotor.setStopping(coast);
  Drivetrain.setStopping(coast);
}
