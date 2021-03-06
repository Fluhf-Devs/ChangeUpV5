/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       config.cpp                                                */
/*    Author:       Liam Teale                                                */
/*    Created:      Feb 1 2021                                                */
/*    Description:  V5 ChangeUp Robot                                         */ 
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "functions.h"

using namespace std;

// should it use skills or competition autonomous?
bool isSkills = true;

// Where is the starting position? (left or right)
string startingPosition = "right";

// how many goals should it score?
int goals = 2;
