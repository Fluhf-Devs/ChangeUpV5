/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       brainScreen.cpp                                           */
/*    Author:       Liam Teale                                                */
/*    Created:      Jan 31 2021                                               */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

int customTimer = 0;

int controllerShake() {
  while(customTimer == 16) {
    controllerShake();
  }
  return 0;
  this_thread::sleep_for(500);
}

int brainScreen() {
  // draw boxes here so we dont waste cpu resources
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.drawRectangle(0, 110, 200, 110);
  Brain.Screen.drawRectangle(210, 110, 210, 110);
  Brain.Screen.drawImageFromFile("image.png", 200, 180);
  Brain.Screen.setFont(propXXL);
  Brain.Screen.setPenColor(green);
  Brain.Screen.print("10012W");
  Brain.Screen.setPenColor(white);
  thread timeWarning = thread(controllerShake);

  
  for(;;) {
    Brain.Screen.setFont(monoL);
    
    // display text in the boxes
    Brain.Screen.printAt(20, 150, "Battery:");
    Brain.Screen.printAt(20, 200, "%d percent", Brain.Battery.capacity());
    Brain.Screen.printAt(250, 175, "Time: %d ", customTimer);
    // sleep 1000 msecs
    this_thread::sleep_for(1000);
    // clear the line
    Brain.Screen.clearLine(20, 200);
    Brain.Screen.clearLine(250, 175);
    // post decrement auto Timer
    if (customTimer > 0) {
      customTimer--;
    }
  }
  return 0;
}