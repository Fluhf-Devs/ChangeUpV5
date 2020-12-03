/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       outakeControl.cpp                                         */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "movementEvents.h"

/* Shorten the functions in main.cpp and in autoMain.cpp for controlling the outakes*/

void outakeMove(int speed, vex::percentUnits pt, vex::directionType Mdir) {
  // set the velocity for the motors for maximum speed
  leftUpwards.setVelocity(speed,pt);
  rightUpwards.setVelocity(speed,pt);
  // spin the motors
  leftUpwards.spin(Mdir);
  rightUpwards.spin(Mdir);

}

// Overload the functions for different combinations of parameters
void outakeMove(int speed, vex::velocityUnits vel, vex::directionType Mdir) {
  leftUpwards.setVelocity(speed,vel);
  rightUpwards.setVelocity(speed,vel);
  leftUpwards.spin(Mdir);
  rightUpwards.spin(Mdir);

}

// Function that can be called to quickly stop all motors
void outakeStop() {
  leftUpwards.stop();
  rightUpwards.stop();
}