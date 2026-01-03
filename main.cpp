#include "vex.h"
#include "cmath"
using namespace vex;
competition Competition;





/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/




/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/




Drive chassis(




  // Specify your drive setup below. There are seven options:
  // ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
  // For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
  ZERO_TRACKER_ODOM,




  // Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
  // You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".




  // Left Motors:
  motor_group(LF, LM, LB),




  // Right Motors:
  motor_group(RF, RM, RB),




  // Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
  PORT20,




  // Input your wheel diameter. (4" omnis are actually closer to 4.125"):
  2.75,




  // External ratio, must be in decimal, in the format of input teeth/output teeth.
  // If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
  // If the motor drives the wheel directly, this value is 1:
  1,




  // Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
  // For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
  360,




  /*---------------------------------------------------------------------------*/
  /*                                  PAUSE!                                   */
  /*                                                                           */
  /*  The rest of the drive constructor is for robots using POSITION TRACKING. */
  /*  If you are not using position tracking, leave the rest of the values as  */
  /*  they are.                                                                */
  /*---------------------------------------------------------------------------*/




  // If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.




  // FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
  // LF:      //RF:
  PORT1, -PORT2,




  // LB:      //RB:
  PORT3, -PORT4,




  // If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
  // If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
  // If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
  3,




  // Input the Forward Tracker diameter (reverse it to make the direction switch):
  2.75,




  // Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
  // For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
  // This distance is in inches:
  -2,




  // Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
  1,




  // Sideways tracker diameter (reverse to make the direction switch):
  -2.75,




  // Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
  5.5




);




// real sauce//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// Function for setting drive voltage
void driveVolts(float lspeed, float rspeed, int wt) {
  lspeed = lspeed * 127;
  rspeed = rspeed * 127;
  RF.spin(fwd, rspeed, voltageUnits::mV);
  RM.spin(fwd, rspeed, voltageUnits::mV);
  RB.spin(fwd, rspeed, voltageUnits::mV);
  LF.spin(fwd, lspeed, voltageUnits::mV);
  LM.spin(fwd, lspeed, voltageUnits::mV);
  LB.spin(fwd, lspeed, voltageUnits::mV);
  wait(100, msec);
}




// Autonomous selector setup
const int NUM_AUTONS = 8;
const char *autonNames[NUM_AUTONS] = {
  "FEIN",
  "solo_awp",
  "half_awp",
  "right_control",
  "left_control",
  "right_elims",
  "left_elims",
  "feinious",

};
int currentAuton = 0;
bool autoStarted = false;
bool arcadeControl = false;

bool midFlag = true;
bool doinkerFlag = false;
bool armFlag = false;
bool ptoFlag = false;

// Display selected autonomous mode
void displayAuton() {
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print(autonNames[currentAuton]);
}




void changeAuton(int direction) {
  currentAuton += direction;
  if (currentAuton < 0) {
      currentAuton = NUM_AUTONS - 1;
  } else if (currentAuton >= NUM_AUTONS) {
      currentAuton = 0;
  }
  displayAuton();
}




void pre_auton(void) {
  vexcodeInit();
  default_constants();

  // --- Calibrate the ONLY inertial you use ---
  Brain.Screen.clearScreen();
  Brain.Screen.print("Calibrating IMU...");
  imu.calibrate();
  while (imu.isCalibrating()) {
    wait(50, msec);
  }

  Brain.Screen.clearScreen();
  Brain.Screen.print("IMU calibrated.");

  // Known pneumatic states AFTER calibration so nothing moves during it
  mid.set(false);
  doinker.set(false);
  arm.set(false);
  pto.set(true);
  wait(50, msec);

  displayAuton();



  // --- Auton selector ---
  while (!autoStarted) {
    if (Controller1.ButtonUp.pressing()) {
      changeAuton(-1);
      while (Controller1.ButtonUp.pressing()) {}
      wait(200, msec);
    }
    if (Controller1.ButtonLeft.pressing()) {
      changeAuton(1);
      while (Controller1.ButtonLeft.pressing()) {}
      wait(200, msec);
    }
    // Use A to CONFIRM selection
    if (Controller1.ButtonX.pressing()) {
      Brain.Screen.clearScreen();
      Brain.Screen.print("Autonomous %s selected", autonNames[currentAuton]);
      while (Controller1.ButtonX.pressing()) {}
      autoStarted = true;


    }
    wait(10, msec);



  }
}







// Autonomous function
void autonomous(void) {
  switch (currentAuton) {
  case 0: FEIN(); break;
  case 1: solo_awp(); break;
  case 2: half_awp(); break;
  case 3: right_control(); break;
  case 4: left_control(); break;
  case 5: right_elims(); break;
  case 6: left_elims(); break;
  case 7: feinious(); break;
  default: break;

  
  }
}









// ///// Define PID constants
// double kP = 0.1;
// double kI = 0.0005;
// double kD = 0.2;

// // Define target positions
// int loadPosition = 123;
// int scorePosition = 750;
// int restPosition = 0;
// int descorePosition = 490;  // New descore position
// int twoRingPosition = 350;  // New two-ring position

// // State variables
// bool toggleDescore = false;     // Track toggle state for L2
// bool toggleTwoRing = false;     // Track toggle state for Left button
// bool toggleLoadRest = false;    // Track toggle state for Button Right
// bool toggleDescoreRest = false; // Track toggle state for Button A
// bool holdToScore = false;       // Track if the score button (L1) is being held
// int currentPosition = restPosition; // Start at rest

// // Arm control function with PID
// int armControl() {
//     Rotation18.setPosition(0, degrees); // Initialize sensor position

//     double error = 0;
//     double previousError = 0;
//     double integral = 0;
//     double derivative = 0;
//     double power = 0;
//     int targetPosition = restPosition; // Start at rest

//     while (true) {
//         // Move to score position while holding L1, return when released
//         if (Controller1.ButtonL1.pressing()) {
//             targetPosition = scorePosition;
//             holdToScore = true;
//         } else if (holdToScore) {
//             // Return to previous position when L1 is released
//             targetPosition = currentPosition;
//             holdToScore = false;
//         }

//         // Toggle to 2-ring position when Left button is pressed
//         if (Controller1.ButtonL2.pressing() && !toggleTwoRing) {
//             toggleTwoRing = true;
//             if (currentPosition == twoRingPosition) {
//                 targetPosition = restPosition;
//                 currentPosition = restPosition;
//             } else {
//                 targetPosition = twoRingPosition;
//                 currentPosition = twoRingPosition;
//             }
//         } else if (!Controller1.ButtonL2.pressing()) {
//             toggleTwoRing = false; // Reset the toggle flag when the button is released
//         }

//         // Toggle Button Right between load and rest position
//         if (Controller1.ButtonRight.pressing() && !toggleLoadRest) {
//             toggleLoadRest = true;
//             if (currentPosition == loadPosition) {
//                 targetPosition = restPosition;
//                 currentPosition = restPosition;
//             } else {
//                 targetPosition = loadPosition;
//                 currentPosition = loadPosition;
//             }
//         } else if (!Controller1.ButtonRight.pressing()) {
//             toggleLoadRest = false; // Reset the toggle flag when the button is released
//         }

//         // Toggle Button A between descore and rest position
//         if (Controller1.ButtonA.pressing() && !toggleDescoreRest) {
//             toggleDescoreRest = true;
//             if (currentPosition == descorePosition) {
//                 targetPosition = restPosition;
//                 currentPosition = restPosition;
//             } else {
//                 targetPosition = descorePosition;
//                 currentPosition = descorePosition;
//             }
//         } else if (!Controller1.ButtonA.pressing()) {
//             toggleDescoreRest = false; // Reset the toggle flag when the button is released
//         }

//         // PID calculations
//         error = targetPosition - Rotation18.position(degrees);
//         integral += error * 0.01;
//         derivative = error - previousError;
//         power = (kP * error) + (kI * integral) + (kD * derivative);

//         // Adjust power limit based on target position
//         int maxPower = (targetPosition == scorePosition || targetPosition == twoRingPosition || targetPosition == descorePosition) ? 12 : 12;
//         if (power > maxPower) power = maxPower;
//         if (power < -maxPower) power = -maxPower;

//         // Spin the arm motor with PID-calculated power
//         arm.spin(vex::directionType::fwd, power, vex::voltageUnits::volt);

//         // Update previous error for derivative calculation
//         previousError = error;

//         // Stop motor and reset integral when target position is reached
//         if (fabs(error) < 1) {
//             arm.stop(vex::brakeType::hold);
//             integral = 0; // Reset integral to prevent wind-up
//         }

//         vex::task::sleep(10); // Allow the CPU to rest
//     }
//     return 0;  // Task must return an int
// }

void usercontrol() {

  while (1) {

// drive straight nga
////////
// Inside usercontrol loop:
double LJoyPct = Controller1.Axis3.position(percent); // left stick (-100 to 100)
double RJoyPct = Controller1.Axis2.position(percent); // right stick (-100 to 100)

// If the sticks are within 10% of each other *and* roughly same direction,
// make both sides use the same power so you drive straighter.
double snapRange = 15.0;  // how close they need to be to "lock together"

if (std::fabs(LJoyPct - RJoyPct) <= snapRange && (LJoyPct * RJoyPct) > 0) {
  // Option 1: use the average of the two
  double avg = (LJoyPct + RJoyPct) / 2.0;
  LJoyPct = avg;
  RJoyPct = avg;
}

// Now drive with (possibly adjusted) values
RF.spin(forward, RJoyPct * 120, voltageUnits::mV);
RM.spin(forward, RJoyPct * 120, voltageUnits::mV);
RB.spin(forward, RJoyPct * 120, voltageUnits::mV);
LF.spin(forward, LJoyPct * 120, voltageUnits::mV);
LM.spin(forward, LJoyPct * 120, voltageUnits::mV);
LB.spin(forward, LJoyPct * 120, voltageUnits::mV);



///////////


    // =====================
    // Piston Toggles
    // =====================

    // Toggle piston with Button Y → AC
    if (Controller1.ButtonY.pressing() && midFlag) {
      midPiston();
      midFlag = false;
    } else if (!Controller1.ButtonY.pressing() && !midFlag) {
      midFlag = true;
    }

    // Toggle piston with Right Arrow → Doinker
    if (Controller1.ButtonL2.pressing() && doinkerFlag) {
      doinkerPiston();
      doinkerFlag = false;
    } else if (!Controller1.ButtonL2.pressing() && !doinkerFlag) {
      doinkerFlag = true;
    }

    // Toggle piston with L2 → Arm Left
    if (Controller1.ButtonA.pressing() && ptoFlag) {
      ptoPiston();
      ptoFlag = false;
    } else if (!Controller1.ButtonA.pressing() && !ptoFlag) {
      ptoFlag = true;
    }
        // Toggle piston with L2 → Arm Left
    if (Controller1.ButtonRight.pressing() && armFlag) {
      armPiston();
      armFlag = false;
    } else if (!Controller1.ButtonRight.pressing() && !armFlag) {
      armFlag = true;
    }
    

 
    // =====================
    // Intake Controls
    // =====================
    if (Controller1.ButtonR1.pressing() && Controller1.ButtonL1.pressing()) {
  // R1 + L1 together → half speed IR
  ir.spin(forward, 50, pct);
  il.spin(reverse, 60, pct);

} else if (Controller1.ButtonR1.pressing()) {
  // Score
  ir.spin(forward, 120, pct);
  il.spin(reverse, 120, pct);

} else if (Controller1.ButtonR2.pressing()) {
  // Reverse score
  ir.spin(reverse, 120, pct);
  il.spin(forward, 120, pct);

// } else if (Controller1.ButtonL1.pressing()) {
//   // Store
//   il.spin(reverse, 120, pct);

} else {
  // Default behavior
  ir.stop();
  il.stop();
}


    // =====================
    // IMU Calibration
    // =====================
    if (Controller1.ButtonX.pressing()) {
      driveVolts(0, 0, 0);
      Brain.Screen.clearScreen();
      Brain.Screen.print("Calibrating IMU...");
      imu.calibrate();
      while (imu.isCalibrating()) vex::task::sleep(100);
      Brain.Screen.clearScreen();
      Brain.Screen.print("IMU calibrated.");
      autonomous();
    }

    vex::task::sleep(20); // prevent CPU hogging
  }
}



// void usercontrol() {
//   int lstick, rstick;
  

   
//   while (1) {


//        if (Controller1.ButtonY.pressing() && acFlag) {
//            acPiston();
//            acFlag = false;
//        } else if (!Controller1.ButtonB.pressing() && !acFlag) {
//            acFlag = true;
//        }

//       //    if (Controller1.ButtonY.pressing() && ipFlag) {
//       //      ipPiston();
//       //      ipFlag = false;
//       //  } else if (!Controller1.ButtonY.pressing() && !ipFlag) {
//       //      ipFlag = true;
//       //  }

//       //   if (Controller1.ButtonRight.pressing() && intake_liftFlag) {
//       //      intake_liftPiston();
//       //      intake_liftFlag = false;
//       //  } else if (!Controller1.ButtonRight.pressing() && !intake_liftFlag) {
//       //      intake_liftFlag = true;
//       //  }

//     lstick = Controller1.Axis3.position();
//     rstick = Controller1.Axis2.position();

//     // Chassis stick value control
//     driveVolts(lstick, rstick, 10);



//     // Intake control (i motor)
//     if (Controller1.ButtonR1.pressing()) {
//         ir.spin(forward, 100, pct);
//         il.spin(forward, 100, pct);
//     } else if (Controller1.ButtonR2.pressing()) {
//         ir.spin(reverse, 100, pct);
//         il.spin(forward, 100, pct);
//     } else {
//         ir.stop();
//         il.stop();
//     }


    
//     // IMU calibration with Button X
//     if (Controller1.ButtonX.pressing()) {
//         driveVolts(0, 0, 0);
//         Brain.Screen.clearScreen();
//         Brain.Screen.print("Calibrating IMU...");
//         imu.calibrate();
//         while (imu.isCalibrating()) vex::task::sleep(100);
//         Brain.Screen.clearScreen();
//         Brain.Screen.print("IMU calibrated.");
//         autonomous();
//     }

//     vex::task::sleep(10);
//   }
// }



int main() {
 Competition.autonomous(autonomous);
 Competition.drivercontrol(usercontrol);
 pre_auton();
  // Calibrate IMU

}


