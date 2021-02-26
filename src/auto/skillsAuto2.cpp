/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       skillsAuto2.cpp                                           */
/*    Author:       Liam Teale                                                */
/*    Created:      Feb 24 2021                                                */
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



lateral movement
900 motor ticks = 1 revolution
1 revolution = 10.2101761242 inches
1 motor tick = 0.01134464013 inches


turning movement

to turn 360 degrees, each wheel has to go forward 42.411500823462 inches

42.411500823462 


3738.46153 motor ticks / 360 degrees

10.3846153611 motor ticks / degree


*/



void skillsAdvancedAuto() {
  // set custom timer to 60
  customTimer = 60;
  // activate PID
  vex::task drivetrainPID(drivePID);
  // release the hood
  thread releaseAHood = thread(releaseHood);


  // start autonomous
  



  
  











}