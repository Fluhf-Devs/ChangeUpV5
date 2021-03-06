/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       configFunctions.cpp                                       */
/*    Author:       Liam Teale                                                */
/*    Created:      Feb 1 2021                                                */
/*    Description:  V5 ChangeUp Robot                                         */ 
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

// define and assign values to these variables
vex::turnType dir1 = left;
vex::turnType dir2 = right;

void configWork() {
  // declare competition and declare usercontrol function
  competition Competition;
  // declare usercontrol
  Competition.drivercontrol(usercontrol);
  
  // now to read the config file!
  if (isSkills == true) {
    Competition.autonomous(skillsAdvancedAuto);
  } else if (isSkills == false) {
    Competition.autonomous(competitionMainAuto);
  }

  if (isSkills == false && startingPosition == "right") {
    dir1 = left;
    dir2 = right;
  }

  if (isSkills == false && startingPosition == "left") {
    dir1 = right;
    dir2 = left;
  }

}