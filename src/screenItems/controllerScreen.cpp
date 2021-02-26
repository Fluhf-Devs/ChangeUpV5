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

// shakes the controller
void controllerShake() {
  Controller1.rumble("---");
}


// main controller screen thread

int controllerScreen() {
  // clear lines
  Controller1.Screen.clearLine();
  Controller2.Screen.clearScreen();

  // controller 1 screen
  Controller1.Screen.print(customTimer);

  // controller 2 screen
  Controller2.Screen.print(drivetrainTemp);
  Controller2.Screen.newLine();
  Controller2.Screen.print(Brain.Battery.capacity());
  Controller2.Screen.newLine();
  Controller2.Screen.print(customTimer);
  Controller2.Screen.print(Drivetrain.efficiency());
  Controller2.Screen.newLine();


  vex::this_thread::sleep_for(20);

  return 0;
}
