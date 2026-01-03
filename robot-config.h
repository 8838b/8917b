using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor RF;
extern motor RM;
extern motor RB;
extern motor LF;
extern motor LM;
extern motor LB;
extern controller Controller1;
extern inertial imu;
extern motor ir;
extern motor il;
extern rotation Rotation18;




extern digital_out mid;
extern digital_out doinker;
extern digital_out arm;
extern digital_out pto;
extern optical Optical;



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit();