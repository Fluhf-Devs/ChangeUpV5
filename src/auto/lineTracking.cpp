/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       lineTracking.cpp                                          */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

int threshold;

void lineTracking() {
  // set the threshold value
  threshold = 30;
  while (true) {
    // left sensor sees dark
    if(LineTrackerLEFT.reflectivity() > threshold) {
      // counter steer left
      Drivetrain.turn(left);
    }
    // center sensor sees dark
    if(LineTrackerCENTER.reflectivity() > threshold) {
      // go forward
      Drivetrain.drive(forward);
    }
    // right sensor sees dark
    if(LineTrackerRIGHT.reflectivity() > threshold) {
      // counter steer right
      Drivetrain.turn(right);
    }
  }
}