/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       preAuton.cpp                                              */
/*    Author:       Liam Teale                                                */
/*    Created:      Feb 2 2021                                                */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

bool activateHood = true;

int releaseHood() {
  while(activateHood == true) {
    rightArmMotor.spin(reverse, 200, rpm);
    leftArmMotor.spin(reverse, 200, rpm);
    wait(300, msec);
    leftArmMotor.stop();
    rightArmMotor.stop();
    leftUpwards.spin(forward, 600, rpm);
    rightUpwards.spin(forward, 600, rpm);
    wait(200, msec);
    leftUpwards.stop();
    rightUpwards.stop();
    activateHood = false;
  }
  this_thread::sleep_for(1000);
  return 0;
}