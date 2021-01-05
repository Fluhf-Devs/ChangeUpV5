using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor leftArmMotor;
extern motor rightArmMotor;
extern motor leftUpwards;
extern motor rightUpwards;
extern line LineTrackerLEFT;
extern line LineTrackerCENTER;
extern line LineTrackerRIGHT;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );