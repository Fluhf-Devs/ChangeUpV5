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

// variables for timers
int competitionAutoTimer = 15;
int competitionDriverControlTimer = 105;


int autoBrainScreen() {
  // draw boxes here so we dont waste cpu resources
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.drawRectangle(25, 110, 50, 110);
  Brain.Screen.drawRectangle(75, 110, 100, 110);

  
  for(;;) {
    Brain.Screen.setPenColor(white);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.drawRectangle(25, 110, 50, 110);
    Brain.Screen.drawRectangle(75, 110, 100, 110);
    // display text in the boxes
    Brain.Screen.printAt(37, 165, "Battery: %d percent", Brain.Battery.capacity());
    Brain.Screen.printAt(87, 185, "Time: %d ", competitionAutoTimer);
    // sleep 1000 msecs
    this_thread::sleep_for(1000);
    // clear the line
    Brain.Screen.clearLine(37, 165);
    Brain.Screen.clearLine(87, 185);
    // post decrement auto Timer
    if (competitionAutoTimer > 0) {
      competitionAutoTimer--;
    }
  }
  return 0;
}