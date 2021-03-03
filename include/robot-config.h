using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern controller Controller2;
extern motor leftArmMotor;
extern motor rightArmMotor;
extern motor leftUpwards;
extern motor rightUpwards;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA;
extern motor rightMotorB;
extern drivetrain Drivetrain;
extern limit LimitSwitchIntake;
extern bumper BumperB;
extern bumper BumperC;
extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );