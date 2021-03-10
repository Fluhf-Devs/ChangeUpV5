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
  setPID(false, 800);

  vex::task::sleep(1000);

  leftArmMotor.stop();
  rightArmMotor.stop();
  setPID(true, -250);

  vex::task::sleep(500);

  leftUpwards.spin(reverse, 600, rpm);
  rightUpwards.spin(reverse, 600, rpm);
  wait(200, msec);
  leftUpwards.stop();
  rightUpwards.stop();
  setPID(false, 1300);

  vex::task::sleep(1500);
  
  setPID(true, -800);

  vex::task::sleep(750);

  setPID(false, 500, 0.02);

  vex::task::sleep(500);

  setPID(false, 0, 0.09);
  leftUpwards.spin(reverse, 600, rpm);
  rightUpwards.spin(reverse, 600, rpm);
  wait(500, msec);
  leftUpwards.stop();
  rightUpwards.stop();

  vex::task::sleep(100);

  setPID(false, -250);

  vex::task::sleep(500);

  setPID(true, 750);

  vex::task::sleep(500);

  leftArmMotor.spin(forward, 200, rpm);
  rightArmMotor.spin(forward, 200, rpm);
  setPID(false, 1900);

  vex::task::sleep(1500);

  leftArmMotor.stop();
  rightArmMotor.stop();
  setPID(true, -625);

  vex::task::sleep(500);

  setPID(false, 600, 0.02);
  wait(400, msec);
  leftUpwards.spin(reverse, 600, rpm);
  rightUpwards.spin(reverse, 600, rpm);
  wait(700, msec);
  rightUpwards.stop();
  leftUpwards.stop();

  vex::task::sleep (900);

  setPID(false, -600, 0.09);

  vex::task::sleep(1000);

  setPID(true, 1300);

  vex::task::sleep(750);

  leftArmMotor.spin(forward, 200, rpm);
  rightArmMotor.spin(forward, 200, rpm);
  setPID(false, 1750);

  vex::task::sleep(2000);

  leftArmMotor.stop();
  rightArmMotor.stop();
  setPID(true, -950);

  vex::task::sleep(750);

  setPID(false, 600, 0.02);

  vex::task::sleep(750);

  setPID(false, 0, 0.09);
  leftUpwards.spin(reverse, 600, rpm);
  rightUpwards.spin(reverse, 600, rpm);
  wait(600, msec);;
  leftUpwards.stop();
  rightUpwards.stop();

  vex::task::sleep(1000);

  setPID(false, -800);

  vex::task::sleep(750);

  setPID(true, 800);



  

}