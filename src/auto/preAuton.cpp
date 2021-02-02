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

void preAuton() {
  // calibrate the gyro
  GyroC.calibrate();
  // end the function
  waitUntil(!GyroC.isCalibrating());
}