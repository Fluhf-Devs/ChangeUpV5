using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern line LineTracker1;
extern motor leftArmMotor;
extern motor rightArmMotor;
extern motor leftUpwards;
extern motor rightUpwards;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );