/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       screenShapes.cpp                                          */
/*    Author:       Liam Teale                                                */
/*    Created:      Jan 31 2021                                               */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

int brainScreen() {
  for(;;) {
    // Create transparent box which displays brain percentage
    Brain.Screen.setPenColor(white);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.drawRectangle(50, 110, 75, 110);
    Brain.Screen.printAt(135, 165, "Battery: %d percent", Brain.Battery.capacity());
    Brain.Screen.drawRectangle(125, 110, 150, 110);
    Brain.Screen.printAt(135, 185, "Time: %d ", std::chrono::system_clock::now());
    // sleep 1000 msecs
    this_thread::sleep_for(1000);
    // clear the line
    Brain.Screen.clearLine(135, 165);
  }
  return 0;
}