// #include "arm.h"

// // Global variables
// int globalTargetPosition = restPosition;
// bool useAutonomousControl = false;

// // State variables
// bool toggleTwoRing = false;
// bool toggleLoadRest = false;
// bool toggleDescoreRest = false;
// bool toggleStakeRest = false;  // Toggle for stake position
// bool holdToScore = false;
// int currentPosition = restPosition;

// // Arm control function (runs as a task)
// int armControl() {
//     Rotation18.setPosition(0, degrees); // Initialize sensor position

//     double error = 0, previousError = 0, integral = 0, derivative = 0, power = 0;

//     while (true) {
//         int targetPosition = globalTargetPosition; // Follow global target

//         if (!useAutonomousControl) {
//             // Score position
//             if (Controller1.ButtonL1.pressing()) {
//                 targetPosition = scorePosition;
//                 holdToScore = true;
//             } else if (holdToScore) {
//                 targetPosition = currentPosition;
//                 holdToScore = false;
//             }

//             // Two Ring toggle logic
//             if (Controller1.ButtonL2.pressing() && !toggleTwoRing) {
//                 toggleTwoRing = true;
//                 targetPosition = (currentPosition == twoRingPosition) ? restPosition : twoRingPosition;
//                 currentPosition = targetPosition;
//             } else if (!Controller1.ButtonL2.pressing()) {
//                 toggleTwoRing = false;
                
//             }

//             // Load position toggle logic
//             if (Controller1.ButtonDown.pressing() && !toggleLoadRest) {
//                 toggleLoadRest = true;
//                 targetPosition = (currentPosition == loadPosition) ? restPosition : loadPosition;
//                 currentPosition = targetPosition;
//             } else if (!Controller1.ButtonDown.pressing()) {
//                 toggleLoadRest = false;
//             }

//             // Stake position toggle (A button)
//             if (Controller1.ButtonA.pressing() && !toggleStakeRest) {
//                 toggleStakeRest = true;
//                 targetPosition = (currentPosition == stakePosition) ? restPosition : stakePosition;
//                 currentPosition = targetPosition;
//             } else if (!Controller1.ButtonA.pressing()) {
//                 toggleStakeRest = false;
//             }

//             // Descore position toggle (R1 + R2)
//             if (Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing() && !toggleDescoreRest) {
//                 toggleDescoreRest = true;
//                 targetPosition = (currentPosition == descorePosition) ? restPosition : descorePosition;
//                 currentPosition = targetPosition;
//             } else if (!(Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing())) {
//                 toggleDescoreRest = false;
//             }

//             globalTargetPosition = targetPosition;
//         }

//         // PID calculations
//         error = targetPosition - Rotation18.position(degrees);
//         integral += error * 0.01;
//         derivative = error - previousError;
//         power = (kP * error) + (kI * integral) + (kD * derivative);

//         // Limit power
//         int maxPower = 12;
//         if (power > maxPower) power = maxPower;
//         if (power < -maxPower) power = -maxPower;

//         // Apply power
//         arm.spin(vex::directionType::fwd, power, vex::voltageUnits::volt);

//         // Reset position at rest
//         if (fabs(error) < 1) {
//             if (targetPosition == restPosition) {
//                 Rotation18.setPosition(0, degrees);  // Reset position to 0 when arm is at rest
//             }
//             arm.stop(vex::brakeType::hold);  // Apply brake hold
//             integral = 0;
//         }

//         previousError = error;
//         vex::task::sleep(10);
//     }
//     return 0;
// }

// // Non-blocking function for setting arm position in autonomous
// void setArmPosition(int position) {
//      useAutonomousControl = true;
//     globalTargetPosition = position;
//     vex::task::sleep(300); // Allow time for arm to reach the position
//     useAutonomousControl = false; // Return control to driver
// }


