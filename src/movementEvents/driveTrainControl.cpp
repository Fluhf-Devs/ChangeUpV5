/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       driveTrainControl.cpp                                     */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "movementEvents.h"

void driveTrainControl(vex::directionType dir, int speed, vex::percentUnits pt) {
  Drivetrain.setDriveVelocity(speed, pt);
  Drivetrain.drive(dir);
}

void driveTrainControl(vex::turnType dir, int speed, vex::percentUnits pt) {
  Drivetrain.setTurnVelocity(speed, pt);
  Drivetrain.turn(dir);
}

void driveTrainControl(vex::directionType dir, int speed, vex::velocityUnits vel) {
  Drivetrain.setDriveVelocity(speed, vel);
  Drivetrain.drive(dir);
}

void driveTrainControl(vex::turnType dir, int speed, vex::velocityUnits vel) {
  Drivetrain.setTurnVelocity(speed, vel);
  Drivetrain.turn(dir);
}

void driveTrainControl(vex::directionType dir, double dis, vex::distanceUnits units) {
  Drivetrain.driveFor(dir, dis, units);
}

void driveTrainControl(vex::directionType dir, double dis, vex::distanceUnits units, double speed, vex::velocityUnits vel) {
  Drivetrain.driveFor(dir, dis, units, speed, vel);
}

void driveTrainControl(double dis, vex::distanceUnits units) {
  Drivetrain.driveFor(dis, units);
}

void driveTrainControl(double dis, vex::distanceUnits units, double speed, vex::velocityUnits vel) {
  Drivetrain.driveFor(dis, units, speed, vel);
}