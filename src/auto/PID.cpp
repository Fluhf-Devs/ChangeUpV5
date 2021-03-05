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
double kP = 0.09;
double kI = 0.0;
double kD = 0.09;

double turnKP = 0.046;
double turnKI = 0.0;
double turnKD = 0.05;

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
bool turning = false;

// variable that is part of stopping the PID
bool resetDriveSensors = false;

// variables modified for use
bool enableDrivePID = true;

// variables that have to be created outside thread
double lateralMotorPower = 0.0;
double turnMotorPower = 0.0;
double slew = 0.0;
double turnSlew = 0.0;
double slewPercent = 0.0;
double slewTurnPercent = 0.0;



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
    int turnDifference = ((leftMotorAPosition + leftMotorBPosition)/2) - ((rightMotorAPosition + rightMotorBPosition)/2);

    // Potential
    turnError = desiredTurnValue - turnDifference;

    // Derivative
    turnDerivative = turnError - turnPrevError;

    // velocity
    turnTotalError += turnError;

    // calculate power for turning
    turnMotorPower = turnError * turnKP + turnDerivative * turnKD;

    /////////////////////////////////////////////////////////////////////////////////
    // slew
    ////////////////////////////////////

    if(startSlew) {
      // lateral Slew
      if (turning == false) {
          slew = (lateralMotorPower / 100) * slewPercent;
          if(slewPercent < 100) {
             slewPercent += 10;
          }
      } else if (turning) {
          turnSlew = (turnMotorPower / 100) * slewTurnPercent;
          if(slewTurnPercent < 100) {
              slewTurnPercent += 10;
          }
      }
    }


    // spin the motors
    leftMotorA.spin(forward, slew + turnSlew, voltageUnits::volt);
    leftMotorB.spin(forward, slew + turnSlew, voltageUnits::volt);
    rightMotorA.spin(forward, ((slew - turnSlew)/100) * 96, voltageUnits::volt);
    rightMotorB.spin(forward, ((slew - turnSlew)/100) * 96, voltageUnits::volt);


    // set errors
    prevError = error;
    turnPrevError = turnError;

    // test turning logic
    std::cout << turnSlew << std::endl;
    std::cout << desiredTurnValue << std::endl;
    std::cout << turnMotorPower << std::endl;
    std::cout << slewTurnPercent << std::endl;

    // sleep
    vex::task::sleep(20);
  }


  return 0;
}
