/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       mainAuto.cpp                                              */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "movementEvents.h"

/* main autonomous code */

void autoMain() {
  // descore ball at starting point
  intakeMove(600, rpm, forward);
  wait(500, msec);
  intakeStop();
  wait(1000, msec);
  // go backwards
  driveTrainControl(reverse, 30, percent);
  wait(500, msec);
  Drivetrain.stop();
  wait(1000, msec);
  // turn 180 degrees
  Drivetrain.turnFor(left, 180, degrees);
  wait(1000, msec);
  // get the ball out
  intakeMove(600, rpm, reverse);
  wait(1000, msec);
  // move close to center goal
  Drivetrain.driveFor(forward, 455, mm);
  wait(1000, msec);
  // turn 90 degrees to the right 
  Drivetrain.turnFor(right, 90, degrees);
  wait(1000, msec);
  // go forward a bit so it can descore the middle balls
  Drivetrain.driveFor(forward, 50, mm);
  wait(1000, msec);
  // turn so it faces the center goal
  Drivetrain.turnFor(left, 90, degrees);
  wait(1000, msec);
  // ram to descore a ball at the center goal
  Drivetrain.drive(forward, 200, rpm);
  wait(500, msec);
  Drivetrain.stop();
  wait(1000, msec);
  // score the middle with the preload
  outakeMove(600, rpm, reverse);
  wait(2000, msec);
  outakeStop();
  wait(1000, msec);
  // back out of the goal
  Drivetrain.driveFor(reverse, 300, mm);
  Drivetrain.stop();
  wait(1000, msec);
  // turn right
  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.stop();
}