/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       skillsAuto.cpp                                            */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

/* skills autonomous code */

void skillsMainAuto() {
  // activate PID
  vex::task drivetrainPID(drivePID);
  // set timer for brain screen
  customTimer = 60;
  // wheelbase and track width test
  Drivetrain.turnFor(360, degrees);
  // spin the outakes
  outakeMove(600, rpm, reverse);
  wait(1000, msec);
  outakeStop();
  // spin the intakes
  intakeMove(600, rpm, forward);
  // move forward
  Drivetrain.drive(forward, 200, rpm);
  wait(500, msec);
  Drivetrain.stop();
  // descore ball at starting point
  wait(500, msec);
  Drivetrain.drive(reverse, 75, rpm);
  wait(500, msec);
  Drivetrain.stop();
  wait(1000, msec);
  // go backwards
  driveTrainControl(reverse, 50, percent);
  wait(1000, msec);
  Drivetrain.stop();
  wait(1000, msec);
  // turn 180 degrees
  Drivetrain.turnFor(left, 180, degrees);
  wait(1000, msec);
  // get the ball out
  intakeMove(600, rpm, reverse);
  wait(1000, msec);
  intakeStop();
  Drivetrain.turnFor(right, 30, degrees);
  // move close to center goal
  Drivetrain.driveFor(forward, 900, mm, 200, rpm);
  wait(1000, msec);
  // reverse
  Drivetrain.drive(reverse);
  wait(700, msec);
  Drivetrain.stop();
  // forward
  Drivetrain.drive(forward, 600, rpm);
  wait(900, msec);
  Drivetrain.stop();
  // reverse
  Drivetrain.drive(reverse);
  wait(900, msec);
  Drivetrain.stop();
  // forward
  Drivetrain.drive(forward, 600, rpm);
  wait(900, msec);
  Drivetrain.stop();
}

void preAuton() {
  
}