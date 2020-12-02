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

void outakeMove(int speed, vex::percentUnits pt, vex::directionType Mdir) {
  leftUpwards.setVelocity(speed,pt);
  rightUpwards.setVelocity(speed,pt);
  leftUpwards.spin(Mdir);
  rightUpwards.spin(Mdir);

}

void outakeMove(int speed, vex::velocityUnits vel, vex::directionType Mdir) {
  leftUpwards.setVelocity(speed,vel);
  rightUpwards.setVelocity(speed,vel);
  leftUpwards.spin(Mdir);
  rightUpwards.spin(Mdir);

}

void outakeStop() {
  leftUpwards.stop();
  rightUpwards.stop();
}