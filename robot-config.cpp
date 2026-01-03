#include "vex.h"

#include "arm.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors


// motor RM = motor(PORT16, ratio6_1, false);
// motor RF = motor(PORT17, ratio6_1, false);
// motor RB = motor(PORT18, ratio6_1, false);

// motor LF = motor(PORT15, ratio6_1, true);
// motor LM = motor(PORT14, ratio6_1, true);
// motor LB = motor(PORT13, ratio6_1, true);

// motor ir = motor(PORT19, ratio6_1, true);
// motor il = motor(PORT12, ratio6_1, false);


motor RM = motor(PORT13, ratio6_1, false);
motor RF = motor(PORT14, ratio6_1, false);
motor RB = motor(PORT2, ratio6_1, true);

motor LF = motor(PORT16, ratio6_1, false);
motor LM = motor(PORT17, ratio6_1, true);
motor LB = motor(PORT18, ratio6_1, true);

motor ir = motor(PORT12, ratio6_1, false);
motor il = motor(PORT19, ratio6_1, false);


rotation Rotation18 = rotation(PORT4, true);

controller Controller1 = controller(primary);

inertial imu = inertial(PORT20);

//angle_change
//doinker
digital_out mid = digital_out(Brain.ThreeWirePort.E);
digital_out doinker = digital_out(Brain.ThreeWirePort.H);
digital_out arm = digital_out(Brain.ThreeWirePort.F);
digital_out pto = digital_out(Brain.ThreeWirePort.G);

optical Optical = optical(PORT17);






// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit() {
  

}