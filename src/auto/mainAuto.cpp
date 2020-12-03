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
  driveTrainControl(reverse, 30, percent);
  wait(500, msec);
  Drivetrain.stop();
  Drivetrain.turnFor(left, 180, degrees);
  intakeMove(600, rpm, reverse);
  Drivetrain.driveFor(forward, 455, mm);
  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(forward, 50, mm);
  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.drive(forward, 200, rpm);
  wait(500, msec);
  Drivetrain.stop();
  Drivetrain.drive(reverse);
  wait(350, msec);
  Drivetrain.stop();
  outakeMove(600, rpm, reverse);
  wait(2000, msec);
  outakeStop();
}