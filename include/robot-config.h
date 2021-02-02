using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor leftArmMotor;
extern motor rightArmMotor;
extern motor leftUpwards;
extern motor rightUpwards;
extern drivetrain Drivetrain;
extern limit LimitSwitchIntake;
extern accelerometer Accel2GB;
extern gyro GyroC;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );