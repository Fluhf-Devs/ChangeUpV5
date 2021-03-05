/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       controllerScreen.cpp                                      */
/*    Author:       Liam Teale                                                */
/*    Created:      26 Feb 2021                                               */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

bool firstTime = true;

// shakes the controller
void controllerShake() {
  Controller1.rumble("---");
}

// main controller screen thread
int controllerScreen() {
  while (true) {
    Controller2.Screen.clearScreen();

    // controller 2 screen
    Controller2.Screen.print(drivetrainTemp);
    Controller2.Screen.newLine();
    Controller2.Screen.print(Brain.Battery.capacity());
    Controller2.Screen.newLine();
    Controller2.Screen.print(customTimer);
    Controller2.Screen.print(Drivetrain.efficiency());
    Controller2.Screen.newLine();

    // make it say that its not the first time
    firstTime = false;
  }
  vex::this_thread::sleep_for(1000);
  return 0;
}
