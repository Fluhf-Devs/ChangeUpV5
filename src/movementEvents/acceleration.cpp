/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       acceleration.cpp                                          */
/*    Author:       Liam Teale                                                */
/*    Created:      23 Feb 2021                                               */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"\


// variables
bool rWorkerDown = false;
bool rWorkerUp = false;
int fuck = 0;


int rightDriveSmartStopper() {
  if (rStopper) {

    if (drivetrainLeftSideSpeed > 0) {
      
    }




  }

  
  return 0;
}

int rightDriveSmartStopperWorker() {
  if (rWorkerDown) {
    drivetrainLeftSideSpeed - 2;
  }



  return 0;
}


int generalworker() {
  
}


void decelerator() {
  if (rWorkerDown) {
    fuck = drivetrainLeftSideSpeed / 150;

  }

}

int fucker() {

  return 0;
}