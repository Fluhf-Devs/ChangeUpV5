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

void configWork() {
  if (isSkills == true) {
    Competition.autonomous(skillsMainAuto);
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