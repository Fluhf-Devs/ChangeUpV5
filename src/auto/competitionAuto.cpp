/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       competitionAuto.cpp                                       */
/*    Author:       Liam Teale                                                */
/*    Created:      Thu Nov 26 2020                                           */
/*    Description:  V5 ChangeUp Robot                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

/* competition autonomous code */

void competitionMainAuto() {
  // set custom timer to 15
  customTimer = 15;
  // set drivetrain velocity to 50% for accurate disctance
  Drivetrain.setDriveVelocity(50, percent);
  thread releaseAHood = thread(releaseHood);

  // checks if it should score 1 or 2 or 3 goals
  if (goals == 2) {
    Drivetrain.driveFor(12, inches);
    // turn 90 degrees
    wait(100, msec);
    Drivetrain.turnFor(dir1, 90, degrees);
    // drive forward for 36 inches
    Drivetrain.driveFor(forward, 25, inches);
    // turn left 90 degrees
    Drivetrain.turnFor(dir1, 90, degrees);
    // wait 100 msec
    // drive forward to goal
    Drivetrain.drive(forward);
    wait(700, msec);
    Drivetrain.stop();
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    wait(700, msec);
    leftUpwards.stop();
    rightUpwards.stop();
    // reverse 11 inches
    wait(100, msec);
    Drivetrain.setDriveVelocity(50, percent);
    Drivetrain.driveFor(reverse, 11, inches);
    Drivetrain.setDriveVelocity(75, percent);
    // rturn left 90 degrees
    Drivetrain.turnFor(dir1, 90, degrees);
    // drive forward 36 inches
    Drivetrain.driveFor(forward, 41, inches);
    // turn right 45 degrees
    Drivetrain.turnFor(dir2, 45, degrees);
    // wait 100 msec
    // spin the intakes and outakes
    rightArmMotor.spin(forward, 200, rpm);
    leftArmMotor.spin(forward, 200, rpm);
    Drivetrain.setDriveVelocity(30, percent);
    Drivetrain.drive(forward);
    wait(2200, msec);
    Drivetrain.setDriveVelocity(100, percent);
    leftArmMotor.stop();
    rightArmMotor.stop();
    wait(100, msec);
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    wait(700, msec);
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.drive(reverse);

  } else if (goals == 1) {
    Drivetrain.driveFor(12, inches);
    // turn to outer goal
    Drivetrain.turnFor(dir2, 90, degrees);
    // drive forward 20 inches
    Drivetrain.driveFor(forward, 16, inches);
    // turn 45 degrees
    Drivetrain.turnFor(dir2, 45, degrees);
    // spin the intakes and outakes
    rightArmMotor.spin(forward, 200, rpm);
    leftArmMotor.spin(forward, 200, rpm);
    Drivetrain.setDriveVelocity(30, percent);
    Drivetrain.drive(forward);
    waitUntil(LimitSwitchIntake.pressing());
    Drivetrain.setDriveVelocity(100, percent);
    leftArmMotor.stop();
    rightArmMotor.stop();
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    // detect collision, then wait 500 msec, then stop
    wait(2, sec);
    Drivetrain.stop();
    wait(500, msec);
    leftUpwards.stop();
    rightUpwards.stop();



////////////////////////////////////////////////////////////////////////
// DO NOT USE 3 GOALS IT DOES NOT WORK WITH CURRENT ROBOT
///////////////////////////////////////////////////////////////////////

  } else if (goals == 3) {
    // currently start s
    // release hood and score ball into center by yeeting it
    rightArmMotor.spin(reverse, 600, rpm);
    wait(200, msec);
    rightArmMotor.stop();
    // drive forward 6 inches
    Drivetrain.setDriveVelocity(100, percent);
    // wait 200 msec
    wait(200, msec);
    // set drivetrain velocity back to 50 percent
    Drivetrain.setDriveVelocity(50, percent);
    // spin 180 degrees 
    Drivetrain.turnFor(dir1, 180, degrees);
    // drive forward for 500 msec
    Drivetrain.drive(forward);
    wait(500, msec);
    Drivetrain.stop();
    // take out the red ball
    leftArmMotor.spin(forward, 200, rpm);
    rightArmMotor.spin(forward, 200, rpm);
    wait(700, msec);
    Drivetrain.driveFor(reverse, 4, inches);
    waitUntil(LimitSwitchIntake.pressing());
    // get the ball into the outake
    leftUpwards.spin(reverse, 200, rpm);
    rightUpwards.spin(reverse, 200, rpm);
    // wait 200 msec
    wait(200, msec);
    // stop everything
    leftArmMotor.stop();
    rightArmMotor.stop();
    leftUpwards.stop();
    rightUpwards.stop();
    // turn 180 degrees
    Drivetrain.turnFor(dir1, 180, degrees);
    // drive forward until the limit switch clicks
    leftArmMotor.spin(forward, 200, rpm);
    rightArmMotor.spin(forward, 200, rpm);
    Drivetrain.drive(forward);
    waitUntil(LimitSwitchIntake.pressing());
    // get the ball into the outake
    leftUpwards.spin(reverse, 200, rpm);
    rightUpwards.spin(reverse, 200, rpm);
    // wait 200 msec
    wait(200, msec);
    // stop everything
    Drivetrain.stop();
    rightArmMotor.stop();
    leftArmMotor.stop();
    leftUpwards.stop();
    rightUpwards.stop();
    // yeet the red ball into the center goal
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    wait(400, msec);
    // stop the outakes
    leftUpwards.stop();
    rightUpwards.stop();
    // reverse 14 inches
    Drivetrain.driveFor(reverse, 14, inches);
    // wait 100 msec
    wait(100, msec);
    // turn 170 degrees
    Drivetrain.turnFor(dir1, 170, degrees);
    // slowly push the blue ball out
    leftUpwards.spin(forward, 600, rpm);
    rightUpwards.spin(forward, 600, rpm);
    leftArmMotor.spin(reverse, 200, rpm);
    rightArmMotor.spin(reverse, 200, rpm);
    wait(500, msec);
    leftUpwards.stop();
    rightUpwards.stop();
    leftArmMotor.stop();
    rightArmMotor.stop();
    // turn so you are facing the side goal
    Drivetrain.turnFor(dir2, 12.5, degrees);
    // drive forward until the limit switch is triggeed
    Drivetrain.drive(forward);
    leftArmMotor.spin(forward, 200, rpm);
    rightArmMotor.spin(forward, 200, rpm);
    waitUntil(LimitSwitchIntake.pressing());
    Drivetrain.stop();
    // get the ball into the intake
    leftUpwards.spin(reverse, 200, rpm);
    rightUpwards.spin(reverse, 200, rpm);
    wait(200, msec);
    leftUpwards.stop();
    rightUpwards.stop();
    leftArmMotor.stop();
    rightArmMotor.stop();
    // wait 100 msec
    wait(100, msec);
    // stop the drivetrain and yeet the ball into the goal
    Drivetrain.stop();
    rightUpwards.spin(reverse, 600, rpm);
    leftUpwards.spin(reverse, 600, rpm);



////////////////////////////////////////////////////////////////////////////////
// Special auto for partnership with 1011S
///////////////////////////////////////////////////////////////////////////////




  }else if (goals == 1011) {
    Drivetrain.driveFor(forward, 10, inches);
    wait(100, msec);
    Drivetrain.turnFor(left, 90, degrees);
    wait(100, msec);
    Drivetrain.driveFor(forward, 14, inches);
    wait(100, msec);
    Drivetrain.turnFor(left, 45, degrees);
    leftArmMotor.spin(forward, 200, rpm);
    rightArmMotor.spin(forward, 200, rpm);
    Drivetrain.setDriveVelocity(30, percent);
    Drivetrain.drive(forward);
    wait(1500, msec);
    Drivetrain.setDriveVelocity(100, percent);
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    wait(500, msec);
    leftUpwards.stop();
    rightUpwards.stop();
    Drivetrain.stop();
    rightArmMotor.stop();
    leftArmMotor.stop();
    Drivetrain.setDriveVelocity(50, percent);




    Drivetrain.driveFor(reverse, 18, inches);
    if (LimitSwitchIntake.pressing()) {
      leftUpwards.spin(reverse, 200, rpm);
      rightUpwards.spin(reverse, 200, rpm);
      wait(150, msec);
      leftUpwards.stop();
      rightUpwards.stop();
    }
    
    Drivetrain.turnFor(right, 45, degrees);
    Drivetrain.driveFor(reverse, 40, inches);
    Drivetrain.turnFor(right, 90, degrees);

    leftArmMotor.spin(forward, 200, rpm);
    rightArmMotor.spin(forward, 200, rpm);
    Drivetrain.driveFor(forward, 28, inches);
    waitUntil(LimitSwitchIntake.pressing());
    leftArmMotor.stop();
    rightArmMotor.stop();
    Drivetrain.stop();
    leftUpwards.spin(reverse, 600, rpm);
    rightUpwards.spin(reverse, 600, rpm);
    wait(150, msec);
    leftUpwards.stop();
    rightUpwards.stop();









  }
}
