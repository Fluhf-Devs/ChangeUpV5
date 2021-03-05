/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       skillsAuto2.cpp                                           */
/*    Author:       Liam Teale                                                */
/*    Created:      Feb 24 2021                                               */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

/* 
3.25 inch wheel circumference = 10.2101761242 inches (distance traveled per revolution)
track width = 13.5 inches
wheelbase = 9 inches

circumference of track width = 42.411500823462 inches

lateral movement:
900 motor ticks = 1 revolution
1 revolution = 10.2101761242 inches
1 motor tick = 0.01134464013 inches

turning movement:
to turn 360 degrees, each wheel has to go forward 42.411500823462 inches
42.411500823462 

3738.46153 motor ticks / 360 degrees

10.3846153611 motor ticks / degree */

void skillsAdvancedAuto() {
  // set custom timer to 60
  customTimer = 60;
  // release the hood
  //vex::thread releaseAHood = thread(releaseHood);
  // activate PID and slew
  vex::task driveTrainPID(drivePID);

  // autonomous
  leftArmMotor.setVelocity(200, rpm);
  rightArmMotor.setVelocity(200, rpm);
  leftArmMotor.spin(forward);
  rightArmMotor.spin(forward);
  startSlew = true;
  resetDriveSensors = true;
  turning = false;
  desiredValue = 800;

  vex::task::sleep(1000);

  leftArmMotor.stop();
  rightArmMotor.stop();
  resetDriveSensors = true;
  startSlew = true;
  turning = true;
  slewTurnPercent = 0.0;
  slewPercent = 0.0;
  desiredValue = 0;
  desiredTurnValue = -250;

  vex::task::sleep(500);

  leftUpwards.spin(reverse, 600, rpm);
  rightUpwards.spin(reverse, 600, rpm);
  wait(200, msec);
  leftUpwards.stop();
  rightUpwards.stop();
  resetDriveSensors = true;
  startSlew = true;
  turning = false;
  slewTurnPercent = 0.0;
  slewPercent = 0.0;
  desiredValue = 1300;
  desiredTurnValue = 0;

  vex::task::sleep(1500);
  
  resetDriveSensors = true;
  startSlew = true;
  turning = true;
  slewTurnPercent = 0.0;
  slewPercent = 0.0;
  desiredValue = 0;
  desiredTurnValue = -800;

  vex::task::sleep(750);

  resetDriveSensors = true;
  startSlew = true;
  turning = false;
  slewTurnPercent = 0;
  slewPercent = 0;
  kP = 0.02;
  desiredValue = 500;
  desiredTurnValue = 0;

  vex::task::sleep(500);

  kP = 0.09;
  resetDriveSensors = true;
  startSlew = true;
  turning = false;
  slewTurnPercent = 0;
  slewPercent = 0;
  desiredValue = 0;
  desiredTurnValue = 0;
  leftUpwards.spin(reverse, 600, rpm);
  rightUpwards.spin(reverse, 600, rpm);
  wait(500, msec);
  leftUpwards.stop();
  rightUpwards.stop();

  vex::task::sleep(100);

  resetDriveSensors = true;
  startSlew = true;
  turning = false;
  slewTurnPercent = 0;
  slewPercent = 0;
  desiredValue = -300;
  desiredTurnValue = 0;

  vex::task::sleep(500);

  resetDriveSensors = true;
  startSlew = true;
  turning = true;
  slewTurnPercent = 0;
  slewPercent = 0;
  desiredValue = 0;
  desiredTurnValue = 700;
  vex::task::sleep(500);

  leftArmMotor.spin(forward, 200, rpm);
  rightArmMotor.spin(forward, 200, rpm);
  resetDriveSensors = true;
  startSlew = true;
  turning = false;
  slewTurnPercent = 0;
  slewPercent = 0;
  desiredTurnValue = 0;
  desiredValue = 1900;

  vex::task::sleep(1500);

  leftArmMotor.stop();
  rightArmMotor.stop();
  resetDriveSensors = true;
  startSlew = true;
  turning = true;
  slewTurnPercent = 0;
  slewPercent = 0;
  desiredTurnValue = -600;
  desiredValue = 0;

  vex::task::sleep(500);

  resetDriveSensors = true;
  startSlew = true;
  turning = false;
  slewTurnPercent = 0;
  slewPercent = 0;
  kP = 0.02;
  desiredValue = 600;
  desiredTurnValue = 0;
  wait(400, msec);
  leftUpwards.spin(reverse, 600, rpm);
  rightUpwards.spin(reverse, 600, rpm);
  wait(700, msec);
  rightUpwards.stop();
  leftUpwards.stop();

  vex::task::sleep (900);

  resetDriveSensors = true;
  startSlew = true;
  turning = false;
  slewTurnPercent = 0;
  slewPercent = 0;
  kP = 0.09;
  desiredTurnValue = 0;
  desiredValue = -400;

  vex::task::sleep(500);

  resetDriveSensors = true;
  startSlew = true;
  turning = true;
  slewTurnPercent = 0;
  slewPercent = 0;
  desiredValue = 0;
  desiredTurnValue = 1400;










  
  



  
  











}