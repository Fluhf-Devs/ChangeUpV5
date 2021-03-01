/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       PID.cpp                                                   */
/*    Author:       Liam Teale                                                */
/*    Created:      Feb 17 2021                                               */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

// settings
double kP = 0.01;
double kI = 0.0;
double kD = 0.0;

double turnKP = 0.0001;
double turnKI = 0.0;
double turnKD = 0.0001;

int error; // sensorValues - desiredValue = Position
int prevError = 0; // Position 20 milliseconds ago
int derivative; // error - prevError = speed
int totalError = 0; // totalError = totalError + error

int turnError; // sensorValues - desiredValue = Position
int turnPrevError = 0; // Position 20 milliseconds ago
int turnDerivative; // error - prevError = speed
int turnTotalError = 0; // totalError = totalError + error

//Autonomous settings
int desiredValue = 0; // motor ticks I think, bot 200rpm about 900 ticks / rev, 
int desiredTurnValue = 0; // should work same as above

// variables used in slew
bool startSlew = false;

// variable that is part of stopping the PID
bool resetDriveSensors = false;

// variables modified for use
bool enableDrivePID = true;

// variables that have to be created outside thread
double lateralMotorPower = 0.0;
double turnMotorPower = 0.0;
double slew = 0.0;



int drivePID() {
  while(enableDrivePID) {

    if(resetDriveSensors) {
      resetDriveSensors = false;

      leftMotorA.setPosition(0, degrees);
      leftMotorB.setPosition(0, degrees);
      rightMotorA.setPosition(0, degrees);
      rightMotorB.setPosition(0, degrees);

    }

    // get the position of the motors
    int leftMotorAPosition = leftMotorA.position(degrees);
    int leftMotorBPosition = leftMotorB.position(degrees);
    int rightMotorAPosition = rightMotorA.position(degrees);
    int rightMotorBPosition = rightMotorB.position(degrees);

    /////////////////////////////////////////////////////////
    // Lateral Movement PID
    ////////////////////////////////////////////////////////////////////////////////
    
    // get average of the four motors
    int averagePosition = (leftMotorAPosition + leftMotorBPosition + rightMotorAPosition + rightMotorBPosition)/4;

    // Potential
    error = desiredValue - averagePosition;

    // Derivative
    derivative = error - prevError;

    // velocity
    totalError += error;

    // calculate motor power
    lateralMotorPower = error * kP + derivative * kD;



    /////////////////////////////////////////////////////////
    // Turning Movement PID
    ////////////////////////////////////////////////////////////////////////////////



    // get average of the four motors
    int turnDifference = ((leftMotorAPosition + leftMotorBPosition) - (rightMotorAPosition + rightMotorBPosition))/2;

    // Potential
    turnError = turnError = desiredTurnValue - turnDifference;

    // Derivative
    turnDerivative = turnError - turnPrevError;

    // velocity
    turnTotalError += turnError;

    // calculate power for turning
    turnMotorPower = turnError * turnKP + turnDerivative * turnKD;

    /////////////////////////////////////////////////////////////////////////////////


    // spin the motors
    leftMotorA.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    leftMotorB.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    rightMotorA.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    rightMotorB.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);


    // set errors
    prevError = error;
    turnPrevError = turnError;

    // sleep
    vex::task::sleep(20);
  }


  return 0;
}

int slewWorker() {

  while(startSlew) {
    slew = (lateralMotorPower / 100) * 5;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 10;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 15;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 20;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 25;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 30;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 35;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 40;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 45;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 50;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 55;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 60;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 65;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 70;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 75;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 80;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 85;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 90;
    wait(10, msec);
    slew = (lateralMotorPower / 100) * 95;
    wait(10, msec);
    slew = lateralMotorPower;
    startSlew = false;

  }
  return 0;
}