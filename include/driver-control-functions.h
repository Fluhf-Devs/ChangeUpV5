void intakeMove(int speed, vex::percentUnits pt, vex::directionType Mdir, vex::controller::button Button);
void intakeMove(int speed, vex::velocityUnits vel, vex::directionType Mdir, vex::controller::button Button);
void outakeMove(int speed, vex::percentUnits pt, vex::directionType Mdir, vex::controller::button Button);
void outakeMove(int speed, vex::velocityUnits vel, vex::directionType Mdir, vex::controller::button Button);
void driveTrainControl(vex::directionType dir, int speed, vex::percentUnits pt, vex::controller::button Button);
void driveTrainControl(vex::turnType dir, int speed, vex::percentUnits pt, vex::controller::button Button);
void driveTrainControl(vex::directionType dir, int speed, vex::velocityUnits vel, vex::controller::button Button);
void driveTrainControl(vex::turnType dir, int speed, vex::velocityUnits vel, vex::controller::button Button);