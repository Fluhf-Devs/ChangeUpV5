void intakeMove(int speed, vex::percentUnits pt, vex::directionType Mdir);
void intakeMove(int speed, vex::velocityUnits vel, vex::directionType Mdir);
void intakeStop();
void outakeMove(int speed, vex::percentUnits pt, vex::directionType Mdir);
void outakeMove(int speed, vex::velocityUnits vel, vex::directionType Mdir);
void outakeStop();
void driveTrainControl(vex::directionType dir, int speed, vex::percentUnits pt);
void driveTrainControl(vex::turnType dir, int speed, vex::percentUnits pt);
void driveTrainControl(vex::directionType dir, int speed, vex::velocityUnits vel);
void driveTrainControl(vex::turnType dir, int speed, vex::velocityUnits vel);
void driveTrainControl(vex::directionType dir, double dis, vex::distanceUnits units);
void driveTrainControl(vex::directionType dir, double dis, vex::distanceUnits units, double speed, vex::velocityUnits vel);
void driveTrainControl(double dis, vex::distanceUnits units);
void driveTrainControl(double dis, vex::distanceUnits units, double speed, vex::velocityUnits vel);
void skillsMainAuto();
void competitionMainAuto();
int brainScreen();
extern bool isSkills;
extern std::string startingPosition;
extern int goals;
extern vex::turnType dir1;
extern vex::turnType dir2;
void usercontrol();
void configWork();
extern int customTimer;
void preAuton();
extern bool activateHood;
int releaseHood();
void centerSpecial();
void hoodtest();
int drivePID();
extern bool enableDrivePID;
extern int desiredValue;
extern int desiredTurnValue;
extern bool resetDriveSensors;
void skillsAdvancedAuto();
extern double drivetrainTemp;
void controllerShake();
int controllerScreen();
extern bool startSlew;
extern bool turning;
extern double turnSlew;
extern double slewTurnPercent;
extern double turnMotorPower;
extern double slewPercent;
extern double turnKP;
extern double kP;
extern double kD;
void whenControllerR1Pressed();
void whenControllerR2Pressed();
void whenControllerL1Pressed();
void whenControllerL2Pressed();
void whenControllerButtonUpPressed();
void whenControllerButtonRightPressed();
void whenControllerButtonDownPressed();
void whenControllerButtonLeftPressed();
