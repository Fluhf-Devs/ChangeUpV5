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

// A global instance of competition
competition Competition;

void autonomous(void) {
  autoMain();
}

void usercontrol(void) {
  if (Controller1.ButtonR1.pressing()) {
    intakeMove(600, rpm, forward);
  }
  if (Controller1.ButtonR2.pressing()) {
    intakeMove(400, rpm, reverse);
  }
  if (Controller1.ButtonL1.pressing()) {
    outakeMove(600, rpm, reverse);
  }
  if (Controller1.ButtonL2.pressing()) {
    outakeMove(400, rpm, forward);
  }
  if (Controller1.ButtonUp.pressing()) {
    driveTrainControl(forward, 15, percent);
  }
  if (Controller1.ButtonRight.pressing()) {
    driveTrainControl(right, 15, percent);
  }
  if (Controller1.ButtonDown.pressing()) {
    driveTrainControl(reverse, 15, percent);
  }
  if (Controller1.ButtonLeft.pressing()) {
    driveTrainControl(left, 15, percent);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // Create callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Set the intake and outake motors stopping mode
  leftUpwards.setStopping(brake);
  rightUpwards.setStopping(brake);
  leftArmMotor.setStopping(coast);
  rightArmMotor.setStopping(coast);
  Drivetrain.setStopping(brake);
  
}
