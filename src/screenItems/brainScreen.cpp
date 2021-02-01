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

void shapeDrawer() {
  for(;;) {
    // Create transparent box which displays brain percentage
    Brain.Screen.setPenColor(white);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.drawRectangle(125, 110, 150, 110);
    // display battery percentage
    Brain.Screen.printAt(135, 165, "Battery Capacity %d percent", Brain.Battery.capacity());
    // wait 5 secs
    wait(5, sec);
    // clear the line
    Brain.Screen.clearLine(135, 165);
  }
}