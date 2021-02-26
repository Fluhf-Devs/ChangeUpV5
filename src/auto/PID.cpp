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
double kP = 0.0;
double kI = 0.0;
double kD = 0.0;

double turnKP = 0.0;
double turnKI = 0.0;
double turnKD = 0.0;

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

///////////////////////////////////////////////////////////
///// wheels are 3.25 inches, therefore each revolution the robot will travel 3.25 inches, 900 motor ticks = 3.25 inches forward
////////////////////////////////////




bool resetDriveSensors = false;




// variables modified for use
bool enableDrivePID = true;



int drivePID() {

  while(enableDrivePID == true) {


    if(resetDriveSensors) {
      resetDriveSensors = false;

      leftMotorA.setPosition(0, degrees);
      leftMotorB.setPosition(0, degrees);
      rightMotorA.setPosition(0, degrees);
      rightMotorB.setPosition(0, degrees);

    }

    // get the position of the motors
    int leftMotorAPosition = leftMotorA.position(vex::rotationUnits::raw);
    int leftMotorBPosition = leftMotorB.position(vex::rotationUnits::raw);
    int rightMotorAPosition = rightMotorA.position(vex::rotationUnits::raw);
    int rightMotorBPosition = rightMotorB.position(vex::rotationUnits::raw);

    /////////////////////////////////////////////////////////
    // Lateral Movement PID
    ////////////////////////////////////////////////////////////////////////////////
    
    // get average of the four motors
    int averagePosition = (leftMotorAPosition + leftMotorBPosition + rightMotorAPosition + rightMotorBPosition)/4;


    // Potential
    error = averagePosition - desiredValue;

    // Derivative
    derivative = error - prevError;

    // velocity
    totalError += error;


    double lateralMotorPower = error * kP + derivative * kD;




    /////////////////////////////////////////////////////////
    // Turning Movement PID
    ////////////////////////////////////////////////////////////////////////////////

    // get average of the four motors
    int turnDifference = ((leftMotorAPosition + leftMotorBPosition) - (rightMotorAPosition + rightMotorBPosition))/2;


    // Potential
    turnError = turnDifference - desiredTurnValue;

    // Derivative
    turnDerivative = turnError - turnPrevError;

    // velocity
    turnTotalError += turnError;


    double turnMotorPower = turnError * turnKP + turnDerivative * turnKD;
    /////////////////////////////////////////////////////////////////////////////////

    leftMotorA.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    leftMotorB.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    rightMotorA.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    rightMotorB.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);





    prevError = error;
    turnPrevError = prevError;

    vex::task::sleep(20);
  }


  return 0;
}