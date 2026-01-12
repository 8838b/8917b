#include "vex.h"
#include "arm.h"

#include <iostream>
#include "vex.h"


bool midVal = true;
bool doinkerVal = true;
bool armVal = true;
bool ptoVal = true;



void midPiston(){
midVal = !midVal;
if (midVal == true){
  mid.set(true);
}
if (midVal == false){
  mid.set(false);
}
}
void doinkerPiston(){
doinkerVal = !doinkerVal;
if (doinkerVal == true){
  doinker.set(true);
}
if (doinkerVal == false){
  doinker.set(false);
}
}
void armPiston(){
armVal = !armVal;
if (armVal == true){
  arm.set(true);
}
if (armVal == false){
  arm.set(false);
}
}

void ptoPiston(){
ptoVal = !ptoVal;
if (ptoVal == true){
  pto.set(true);
}
if (ptoVal == false){
  pto.set(false);




}
}












// const int RED_HUE = 5;    
// const int BLUE_HUE = 200;
// const int HUE_TOLERANCE = 10;

// // Task for detecting red
// int detectRedTask() {
//     Optical.setLight(vex::ledState::on); // Turn on the optical light

//     while (true) {
//         int detectedHue = Optical.hue();
        
//         // Check if the intake is spinning forward
//         if (i.velocity(percent) > 0 && detectedHue >= RED_HUE - HUE_TOLERANCE && detectedHue <= RED_HUE + HUE_TOLERANCE) {
//             i.stop(); // Stop the intake
//             wait(120, msec); // Wait for 500ms (0.5 seconds)
//             i.spin(forward, 100, percent); // Resume spinning intake forward
//         }

//         wait(500, msec); // Small delay to prevent excessive checking
//     }
//     return 0;
// }

// // Task for detecting blue
// int detectBlueTask() {
//     Optical.setLight(vex::ledState::on); // Turn on the optical light

//     while (true) {
//         int detectedHue = Optical.hue();
        
//         // Check if the intake is spinning forward
//         if (i.velocity(percent) > 0 && detectedHue >= BLUE_HUE - HUE_TOLERANCE && detectedHue <= BLUE_HUE + HUE_TOLERANCE) {
//             i.stop(); // Stop the intake
//             wait(120, msec); // Wait for 500ms (0.5 seconds)
//             i.spin(forward, 100, percent); // Resume spinning intake forward
//         }

//         wait(500, msec); // Small delay to prevent excessive checking
//     }
//     return 0;
// }







//(float turn_max_voltage, float turn_kp, float turn_ki, float turn_kd, float turn_starti);
//void set_drive_exit_conditions(float drive_settle_error, float drive_settle_time, float drive_timeout);




//   // Emidh constant set is in the form of (maxVoltage, kP, kI, kD, startI).
//   chassis.set_drive_constants(10, 1.5, 0, 10, 0);
//   chassis.set_heading_constants(6, .4, 0, 1, 0);
//   chassis.set_turn_constants(12, .35, .03, 2.7, 15);
//   chassis.set_swing_constants(12, .3, .001, 2, 15);

//   // Eh exit condition set is in the form of (settle_error, settle_time, timeout).
//   chassis.set_drive_exit_conditions(1.5, 300, 5000);
//   chassis.set_turn_exit_conditions(1, 300, 3000);
//   chassis.set_swing_exit_conditions(1, 300, 3000);
// }

void default_constants(){
chassis.set_drive_constants(12, 1.5, 0, 10, 0);
chassis.set_heading_constants(12, .4, 0, 1, 0);
chassis.set_turn_constants(12, .4, .03, 3, 15);
chassis.set_swing_constants(12, .7, .001, 3.5, 15);
chassis.set_drive_exit_conditions(1.5, 250, 0);
chassis.set_turn_exit_conditions(1, 250, 0);
chassis.set_swing_exit_conditions(1, 250, 850);
}




void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 6;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}








//auton start



//is this good try it later
// chassis.set_drive_constants(12, 1.15, 0.0004, 10.0, 6);

// chassis.set_turn_constants(12, 0.64, 0.0045, 5.8, 12);
// chassis.set_swing_constants(10, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I
// chassis.set_heading_constants(12, 0.38, 0, 1.0, 12);


//try the skills values nganganganganganga



void FEIN(){



chassis.set_drive_constants(8, 1, 0, 10, 0); //big
chassis.set_heading_constants(6, .4, 0, 1, 0);
chassis.set_turn_constants(8, .38, .03, 3, 15);
chassis.set_swing_constants(12, .2, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 100, 5000);
  chassis.set_turn_exit_conditions(1, 100, 3000);
  chassis.set_swing_exit_conditions(1, 100, 3000);




// //intake 4 
// chassis.drive_distance(10);
// chassis.turn_to_angle(-60);
// il.spin(directionType::rev, 1000, velocityUnits::pct);
// ir.spin(directionType::fwd, 1000, velocityUnits::pct);
// chassis.set_drive_constants(8, 1, 0, 10, 0);
// chassis.drive_distance(20); 
// chassis.drive_distance(10); 

// //going to mid goal and score
// chassis.turn_to_angle(-130);
// chassis.drive_distance(-20); 
// il.stop();
// ir.stop();
// pto.set(false);
// il.spin(directionType::rev, 80, velocityUnits::pct);
// ir.spin(directionType::fwd, 80, velocityUnits::pct);
// mid.set(true);
// wait(500,msec);
// mid.set(false);
// pto.set(true);
// wait(100,msec);
// il.stop();
// ir.stop();

// //driving to goal and score
// chassis.drive_distance(50); 
// chassis.turn_to_angle(180);
// chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
// chassis.set_drive_exit_conditions(1, 100, 800);
// chassis.drive_distance(-20); 
// pto.set(false);
// doinker.set(true);
// il.spin(directionType::rev, 1000, velocityUnits::pct);
// ir.spin(directionType::fwd, 1000, velocityUnits::pct);
// wait(800,msec);
// pto.set(true);
// chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
// chassis.turn_to_angle(178);

// //driving to loader
// chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
// chassis.set_drive_exit_conditions(1, 100, 2500);
// chassis.set_drive_constants(7, 1, 0, 10, 0); //big
// chassis.drive_distance(38); 
// chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
// chassis.set_drive_constants(8, 1, 0, 10, 0); //big

// //going to the alley
// chassis.drive_distance(-20); 
// chassis.turn_to_angle(135);
// chassis.drive_distance(-18); 
// chassis.turn_to_angle(180);
// doinker.set(false);
// chassis.set_drive_exit_conditions(1, 100, 5000);
// chassis.drive_distance(-70); 

// //turn and drive onto the goal and intkae
// chassis.turn_to_angle(-90);
// chassis.drive_distance(-12);
// chassis.turn_to_angle(0);
//   chassis.set_drive_exit_conditions(1, 100, 800);
// chassis.drive_distance(-17);
// ir.stop();
// il.stop();
// doinker.set(true);
// pto.set(false);
// il.spin(directionType::rev, 1000, velocityUnits::pct);
// ir.spin(directionType::fwd, 1000, velocityUnits::pct);
// wait(2000, msec);
// pto.set(true);
// chassis.turn_to_angle(-2);

// //driving to second loader
// chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
// chassis.set_drive_exit_conditions(1, 100, 2500);
// chassis.set_drive_constants(7, 1, 0, 10, 0); //big
// chassis.drive_distance(38); 
// chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
// chassis.set_drive_constants(8, 1, 0, 10, 0); //big

// //driving to the goal again and score
// chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
// chassis.set_drive_exit_conditions(1, 100, 2500);
// chassis.drive_distance(-35); 
// chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
// ir.stop();
// il.stop();
// doinker.set(true);
// pto.set(false);
// il.spin(directionType::rev, 1000, velocityUnits::pct);
// ir.spin(directionType::fwd, 1000, velocityUnits::pct);
// wait(2000, msec);

//going to the park
chassis.drive_distance(20); 
chassis.turn_to_angle(50);
chassis.drive_distance(25); 
chassis.turn_to_angle(75);

//driving over park
il.spin(directionType::rev, 1000, velocityUnits::pct);
ir.spin(directionType::fwd, 1000, velocityUnits::pct);
chassis.set_drive_constants(8, 1, 0, 10, 0); //big
chassis.drive_distance(40);
chassis.turn_to_angle(90);
chassis.set_drive_constants(8, 1, 0, 10, 0); //big
chassis.drive_distance(50); 

//reset on wall and goal
chassis.set_drive_constants(3, 1, 0, 10, 0); //big
 chassis.set_drive_exit_conditions(1, 100, 1500);
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.drive_distance(-60); 
chassis.drive_distance(5); 
chassis.turn_to_angle(110);
chassis.drive_distance(5); 
chassis.turn_to_angle(180);
chassis.drive_distance(-10); 
chassis.drive_stop(brake);
wait(200, msec);

// 2) back off so wall can't force your angle
chassis.drive_distance(5);
wait(100, msec);

// 3) NOW lock heading with IMU
chassis.set_heading_constants(6, .4, 0, 1, 0);
chassis.turn_to_angle(185);






 


//driving to the mid and scoring
chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
 chassis.set_drive_exit_conditions(1, 100, 3000);
chassis.set_drive_constants(8, 1, 0, 10, 0); //big
chassis.drive_distance(40);
chassis.turn_to_angle(40);
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.set_drive_exit_conditions(1, 100, 1000);
chassis.drive_distance(-18);
il.spin(directionType::rev, 80, velocityUnits::pct);
ir.spin(directionType::fwd, 80, velocityUnits::pct);
mid.set(true);
wait(2000,msec);
mid.set(false);
wait(100,msec);
il.stop();
ir.stop();
chassis.turn_to_angle(45);










// //mirrored second half

//driving to goal and score
chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
chassis.set_drive_exit_conditions(1, 100, 2000);
chassis.drive_distance(50); 
chassis.turn_to_angle(0);          // was 180
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.set_drive_exit_conditions(1, 100, 2000);
chassis.drive_distance(-30); 
wait(700, msec);
chassis.set_heading(0);
doinker.set(true);
chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
chassis.turn_to_angle(-2);         // was 178

//driving to loader
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.set_drive_exit_conditions(1, 100, 2500);
chassis.set_drive_constants(7, 1, 0, 10, 0); //big
chassis.drive_distance(38); 
chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
chassis.set_drive_constants(8, 1, 0, 10, 0); //big

//going to the alley
chassis.drive_distance(-20); 
chassis.turn_to_angle(-45);        // was 135
chassis.drive_distance(-18); 
chassis.turn_to_angle(0);          // was 180
doinker.set(false);
chassis.set_drive_exit_conditions(1, 100, 5000);
chassis.drive_distance(-70); 

//turn and drive onto the goal and intkae
chassis.turn_to_angle(90);         // was -90
chassis.drive_distance(-12);
chassis.turn_to_angle(-180);       // was 0
chassis.set_drive_exit_conditions(1, 100, 800);
chassis.drive_distance(-17);
ir.stop();
il.stop();
doinker.set(true);
pto.set(false);
il.spin(directionType::rev, 1000, velocityUnits::pct);
ir.spin(directionType::fwd, 1000, velocityUnits::pct);
wait(2000, msec);
pto.set(true);
chassis.turn_to_angle(178);        // was -2

//driving to second loader
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.set_drive_exit_conditions(1, 100, 2500);
chassis.set_drive_constants(7, 1, 0, 10, 0); //big
chassis.drive_distance(38); 
chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
chassis.set_drive_constants(8, 1, 0, 10, 0); //big

//driving to the goal again and score
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.set_drive_exit_conditions(1, 100, 2500);
chassis.drive_distance(-35); 
chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on
ir.stop();
il.stop();
doinker.set(true);
pto.set(false);
il.spin(directionType::rev, 1000, velocityUnits::pct);
ir.spin(directionType::fwd, 1000, velocityUnits::pct);
wait(2000, msec);

//going to the park
chassis.drive_distance(20); 
chassis.turn_to_angle(-130);       // was 50
chassis.drive_distance(25); 
chassis.turn_to_angle(-105);       // was 75

//driving over park
il.spin(directionType::rev, 1000, velocityUnits::pct);
ir.spin(directionType::fwd, 1000, velocityUnits::pct);
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.set_drive_constants(7, 1, 0, 10, 0); //big
chassis.drive_distance(40); 
}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solo_awp(){


chassis.set_drive_constants(12, 1, 0, 10, 0); //big
chassis.set_heading_constants(6, .4, 0, 1, 0);
// chassis.set_turn_constants(12, .38, .03, 3, 15);
chassis.set_turn_constants(8, 0.64, 0.0045, 5.8, 12);
chassis.set_swing_constants(12, .2, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 100, 5000);
  chassis.set_turn_exit_conditions(1, 200, 3000);
  chassis.set_swing_exit_conditions(1, 200, 3000);




il.spin(directionType::rev, 1000, velocityUnits::pct);
ir.spin(directionType::fwd, 1000, velocityUnits::pct);

//drive back and turn to loader
chassis.set_drive_constants(12, 1, 0, 10, 0); 
chassis.set_drive_exit_conditions(0.8, 300, 1200);
chassis.drive_distance(-42);
chassis.set_turn_exit_conditions(0.8, 300, 600); 
doinker.set(true);
chassis.turn_to_angle(270);

//drive into loader
chassis.set_drive_constants(6, 1, 0, 10, 0); 
chassis.set_drive_exit_conditions(1.2, 140, 1000);
chassis.drive_distance(18);

//drive back into goal and intake
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.set_drive_constants(7, 1, 0, 10, 0); 
chassis.drive_distance(-38);
il.stop();
ir.stop();
pto.set(false);
il.spin(directionType::rev, 1000, velocityUnits::pct);
ir.spin(directionType::fwd, 1000, velocityUnits::pct);
doinker.set(false);
wait(800,msec);
pto.set(true);
chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on

//turning on the goal
chassis.set_turn_exit_conditions(1, 200, 1000);
chassis.set_turn_constants(10, .28, .03, 3, 15); //this is for the goal turn 
chassis.turn_to_angle(10);

//after goal
chassis.set_turn_exit_conditions(1, 200, 2000);
chassis.set_turn_constants(12, .28, .03, 3, 15);
chassis.turn_to_angle(0);
chassis.set_turn_constants(12, .38, .03, 3, 15);

//intaking the 6 balls
chassis.set_drive_exit_conditions(1.2, 200, 1800);
chassis.set_drive_constants(10, 1, 0, 10, 0); 
chassis.drive_distance(55);
chassis.set_drive_constants(12, 1, 0, 10, 0); 
doinker.set(true);
chassis.set_drive_exit_conditions(1.2, 200, 1000);
chassis.drive_distance(10);

//turn to mid goal and score
chassis.set_turn_exit_conditions(1.2, 200, 600); 
chassis.turn_to_angle(315);
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.set_drive_constants(12, 1, 0, 10, 0); 
chassis.set_drive_exit_conditions(1.2, 200, 900);
chassis.drive_distance(-25);
chassis.set_heading_constants(6, .4, 0, 1, 0);  // heading back on

//intaking into the goal
il.stop();
ir.stop();
pto.set(false);
il.spin(directionType::rev, 1000, velocityUnits::pct);
ir.spin(directionType::fwd, 1000, velocityUnits::pct);
mid.set(true);
wait(200,msec);
mid.set(false);
pto.set(true);
wait(200,msec);

//drive forward the loader and turn and drive into the loader
chassis.set_drive_constants(12, 1, 0, 10, 0); //big
chassis.set_drive_exit_conditions(1.2, 200, 1400);
chassis.drive_distance(55);
chassis.set_turn_exit_conditions(1.2, 300, 600);
chassis.turn_to_angle(270);
chassis.set_drive_exit_conditions(1.2, 300, 800);
chassis.drive_distance(22);
chassis.set_drive_exit_conditions(1.2, 300, 1000);

//drive into the goal and score
chassis.set_heading_constants(0, 0, 0, 0, 0); //backing into the goal heading
chassis.set_drive_constants(10, 1, 0, 10, 0); //big
chassis.drive_distance(-38);
il.stop();
ir.stop();
pto.set(false);
il.spin(directionType::rev, 1000, velocityUnits::pct);
ir.spin(directionType::fwd, 1000, velocityUnits::pct);
doinker.set(true);
wait(800,msec);




// chassis.set_drive_constants(12, 0.40, 0.0, 1.4, 12);
// chassis.set_drive_exit_conditions(0.5, 140, 2000);
// chassis.set_turn_exit_conditions(0.5, 140, 2000); 
// chassis.right_swing_to_angle(0);
// chassis.drive_distance(65);
// chassis.set_drive_constants(12, 0.40, 0.0, 1.4, 12);
// chassis.set_drive_constants(12, 1.5, 0, 10, 0);
// chassis.drive_distance(-12);
// doinker.set(true);
// chassis.turn_to_angle(320);
// chassis.drive_distance(-10);
// mid.set(true);
// wait(500, msec);
// chassis.drive_distance(50);

// chassis.set_turn_exit_conditions(0.5, 140, 200); 
// chassis.turn_to_angle(350);
// chassis.drive_distance(20);
// chassis.set_turn_exit_conditions(0.5, 140, 300); 
// chassis.turn_to_angle(320);
// doinker.set(true);
// chassis.drive_distance(-20);
// mid.set(true);
// wait(600,msec);









// chassis.set_drive_exit_conditions(0.9, 130, 2000);
// chassis.drive_distance(41);
// chassis.set_turn_exit_conditions(0.9, 130, 500); //90 degree timeout
// doinker.set(true);
// chassis.turn_to_angle(90);
// il.spin(directionType::rev, 200, velocityUnits::pct);
// doinker.set(true);
// chassis.set_drive_exit_conditions(0.9, 130, 1000);
// chassis.drive_distance(16);
// chassis.set_drive_exit_conditions(0.9, 130, 800);
// chassis.drive_distance(-30);
// doinker.set(false);
// ir.spin(directionType::fwd, 200, velocityUnits::pct);
// wait(1100, msec);
// chassis.set_turn_exit_conditions(0.9, 130, 800);
// chassis.turn_to_angle(224);
// ir.spin(directionType::rev, 200, velocityUnits::pct);
// chassis.set_drive_constants(6, 1.70, 0.0005, 15.0, 6);
// chassis.drive_distance(15);
// chassis.set_turn_exit_conditions(0.9, 130, 300);
// chassis.turn_to_angle(183);
// il.spin(directionType::rev, 200, velocityUnits::pct);
// chassis.set_drive_constants(8, 1.70, 0.0005, 15.0, 6);
// chassis.set_drive_exit_conditions(0.9, 130, 2000);
// chassis.drive_distance(51);
// doinker.set(true);
// chassis.set_drive_constants(12, 1.70, 0.0005, 15.0, 6);
// chassis.set_turn_exit_conditions(0.9, 130, 400);
// chassis.turn_to_angle(137);
// chassis.drive_distance(-14);
// mid.set(false);
// wait(200, msec);
// ir.spin(directionType::fwd, 50, velocityUnits::pct);
// wait(800, msec);
// ir.spin(directionType::rev, 200, velocityUnits::pct);
// mid.set(true);
// wait(200, msec);
// chassis.drive_distance(46);
// chassis.turn_to_angle(90);
// chassis.set_drive_exit_conditions(0.9, 130, 1000);
// chassis.drive_distance(20);
// chassis.drive_distance(-30);
// doinker.set(false);
// ir.spin(directionType::fwd, 200, velocityUnits::pct);
// LF.setBrake(brakeType::coast);
// LM.setBrake(brakeType::coast);
// LB.setBrake(brakeType::coast);
// RF.setBrake(brakeType::coast);
// RM.setBrake(brakeType::coast);
// RB.setBrake(brakeType::coast);
// wait(5000, msec);





}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void half_awp(){



chassis.set_drive_constants(12, 1, 0, 10, 0); //big

chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(10, .28, .03, 3, 15);
chassis.set_swing_constants(12, .2, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 100, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);




// chassis.drive_distance(-50);
chassis.turn_to_angle(100);
chassis.drive_distance(20);







// chassis.set_track_width(10);


// chassis.set_arc_constants(5, 1.0, 0.0, 12.0, 6);
// chassis.set_arc_exit_conditions(0.9, 110, 2800);
// chassis.set_arc_heading_kp(0.05);
// chassis.set_arc_max_correction(0.8);
// chassis.set_arc_slow_zone(12);

// chassis.drive_arc_left(90, 20);

// // chassis.set_track_width(8.2);

// // Arc PID (maxV, kP, kI, kD, startI)
// chassis.set_arc_constants(12, 0.11, 0.0000, 0.85, 6);

// // Exit (settle_error, settle_time_ms, timeout_ms)
// chassis.set_arc_exit_conditions(0.8, 70, 1500);

// // Heading correction
// chassis.set_arc_heading_kp(0.095);     // less aggressive to prevent end whip
// chassis.set_arc_max_correction(1);   // cap correction harder

// // Drive shaping
// // chassis.set_slew_rate(1.05, 0.45);     // faster accel, stronger decel
// // chassis.set_slow_zone(7.0, 2.0);       // start slowing earlier, lower end power


// // chassis.drive_arc_left(90, 30);
// // chassis.turn_to_angle(270);
// // chassis.drive_arc_right(90, 30);
// // chassis.turn_to_angle(0);

// chassis.set_track_width(12);
// chassis.drive_arc_left(90, 30);


// il.spin(directionType::rev, 200, velocityUnits::pct);
// ir.spin(directionType::rev, 100, velocityUnits::pct);
// chassis.drive_distance(18);
// chassis.right_swing_to_angle(330);
// chassis.drive_distance(8);
// chassis.turn_to_angle(315);
// chassis.drive_distance(30);
// wait(200, msec);
// chassis.set_drive_constants(8, 1.50, 0.0005, 9.0, 6);
// chassis.drive_distance(-28);
// chassis.turn_to_angle(223);
// mid.set(false);
// chassis.drive_distance(-15);
// ir.spin(directionType::fwd, 50, velocityUnits::pct);
// il.spin(directionType::rev, 100, velocityUnits::pct);
// wait(1000, msec);
// il.spin(directionType::rev, 200, velocityUnits::pct);
// ir.spin(directionType::rev, 100, velocityUnits::pct);
// mid.set(true);
// wait(500, msec);
// chassis.drive_distance(51);
// chassis.turn_to_angle(180);
// chassis.drive_distance(-5);
// doinker.set(true);
// wait(400, msec);
// chassis.set_drive_exit_conditions(0.9, 130, 900);
// chassis.set_drive_constants(6, 1.50, 0.0005, 9.0, 6);
// chassis.drive_distance(21);
// wait(400, msec);
// chassis.set_drive_constants(10, 1.50, 0.0005, 9.0, 6);
// chassis.drive_distance(-32);
// il.spin(directionType::rev, 200, velocityUnits::pct);
// ir.spin(directionType::fwd, 200, velocityUnits::pct);
// LF.setBrake(brakeType::coast);
// LM.setBrake(brakeType::coast);
// LB.setBrake(brakeType::coast);
// RF.setBrake(brakeType::coast);
// RM.setBrake(brakeType::coast);
// RB.setBrake(brakeType::coast);
// wait(10000, msec);

 


}


void right_control(){



chassis.set_drive_constants(12, 0.40, 0.0, 1.4, 12);


chassis.set_turn_constants(6, .4, .03, 3, 15);



chassis.set_swing_constants(8, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I
chassis.set_heading_constants(3.5, 0.45, 0, 0.9, 12);


chassis.set_drive_exit_conditions(0.9, 120, 3000);
chassis.set_turn_exit_conditions(0.9, 120, 2800);
chassis.set_swing_exit_conditions(0.9, 110, 2800);

chassis.turn_to_angle(90);


// chassis.set_turn_exit_conditions(0.9, 120, 500);
// il.spin(directionType::rev, 200, velocityUnits::pct);
// ir.spin(directionType::rev, 100, velocityUnits::pct);
// chassis.set_heading_constants(0, 0.0, 0, 0, 0);
// chassis.drive_distance(18);
// chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);
// chassis.set_swing_exit_conditions(0.9, 110, 500);

// chassis.set_drive_constants(8, 1.20, 0.0005, 9.0, 6);
// chassis.drive_distance(20);
// chassis.drive_distance(-5);
// chassis.set_turn_exit_conditions(0.9, 120, 500);
// chassis.turn_to_angle(-245);
// chassis.drive_distance(27);
// doinker.set(true);
// arm.set(true);
// chassis.turn_to_angle(-180);
// chassis.set_drive_exit_conditions(0.9, 120, 1200);
// chassis.drive_distance(25);
// chassis.drive_distance(-28);
// ir.spin(directionType::fwd, 200, velocityUnits::pct);
// wait(2500, msec);
// doinker.set(false);
// chassis.drive_distance(10);
// chassis.turn_to_angle(110);
// chassis.drive_distance(-12);
// chassis.turn_to_angle(178);
// chassis.set_drive_constants(6, 1.20, 0.0005, 9.0, 6);
// LF.setBrake(brakeType::coast);
// LM.setBrake(brakeType::coast);
// LB.setBrake(brakeType::coast);
// RF.setBrake(brakeType::coast);
// RM.setBrake(brakeType::coast);
// RB.setBrake(brakeType::coast);
// chassis.drive_distance(-25);







 
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void left_control(){

chassis.set_drive_constants(12, 1.20, 0.0005, 9.0, 6);
chassis.set_turn_constants(8, 0.64, 0.0045, 5.8, 12);
chassis.set_swing_constants(8, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I
chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);

chassis.set_drive_exit_conditions(0.9, 120, 3000);
chassis.set_turn_exit_conditions(0.9, 120, 2800);
chassis.set_swing_exit_conditions(0.9, 110, 2800);




chassis.set_turn_exit_conditions(0.9, 120, 400);
il.spin(directionType::rev, 200, velocityUnits::pct);
ir.spin(directionType::rev, 100, velocityUnits::pct);
chassis.set_heading_constants(0, 0.0, 0, 0, 0);
chassis.drive_distance(18);
arm.set(true);
chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);
chassis.set_swing_exit_conditions(0.9, 110, 500);
chassis.right_swing_to_angle(-30);
chassis.set_drive_constants(8, 1.20, 0.0005, 9.0, 6);
chassis.drive_distance(20);
chassis.drive_distance(-5);
chassis.set_turn_exit_conditions(0.9, 120, 500);
chassis.turn_to_angle(245);
chassis.drive_distance(27);
doinker.set(true);
chassis.turn_to_angle(180);
chassis.set_drive_exit_conditions(0.9, 120, 1200);
chassis.drive_distance(25);
chassis.drive_distance(-28);
ir.spin(directionType::fwd, 200, velocityUnits::pct);
wait(2500, msec);
doinker.set(false);
chassis.drive_distance(10);
chassis.turn_to_angle(110);
chassis.drive_distance(-12);
chassis.turn_to_angle(180);
chassis.set_drive_constants(6, 1.20, 0.0005, 9.0, 6);
LF.setBrake(brakeType::coast);
LM.setBrake(brakeType::coast);
LB.setBrake(brakeType::coast);
RF.setBrake(brakeType::coast);
RM.setBrake(brakeType::coast);
RB.setBrake(brakeType::coast);
chassis.drive_distance(-25);




}







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//NOT USING
void right_elims(){
chassis.set_drive_constants(12, 1.20, 0.0005, 9.0, 6);
chassis.set_turn_constants(8, 0.64, 0.0045, 5.8, 12);
chassis.set_swing_constants(8, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I
chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);

chassis.set_drive_exit_conditions(0.9, 120, 3000);
chassis.set_turn_exit_conditions(0.9, 120, 2800);
chassis.set_swing_exit_conditions(0.9, 110, 300);


chassis.turn_to_angle(50);




// il.spin(directionType::rev, 200, velocityUnits::pct);
// ir.spin(directionType::rev, 100, velocityUnits::pct);
// chassis.set_turn_exit_conditions(0.9, 120, 500);
// chassis.set_heading_constants(0, 0.0, 0, 0, 0);
// chassis.drive_distance(2);
// chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);
// chassis.left_swing_to_angle(30);
// chassis.drive_distance(8);
// chassis.turn_to_angle(45);
// chassis.drive_distance(32);
// wait(200, msec);
// chassis.set_drive_constants(10, 1.50, 0.0005, 9.0, 6);
// chassis.drive_distance(-43);
// chassis.set_turn_exit_conditions(0.9, 120, 700);
// chassis.turn_to_angle(270);
// chassis.drive_distance(-38); //was -40 now its for red right
// chassis.turn_to_angle(180);
// ir.stop();
// chassis.set_drive_exit_conditions(0.9, 130, 800);
// chassis.drive_distance(-8);
// chassis.set_drive_exit_conditions(0.9, 130, 3000);
// ir.spin(directionType::fwd, 200, velocityUnits::pct);
// wait(2000, msec);
// doinker.set(true);
// ir.stop();
// chassis.set_drive_exit_conditions(0.9, 130, 2000);
// chassis.set_drive_constants(8, 1.50, 0.0005, 9.0, 6);


// chassis.set_drive_exit_conditions(0.9, 130, 1300);
// chassis.drive_distance(40);//into wall
// chassis.set_drive_constants(10, 1.50, 0.0005, 9.0, 6);
// ir.spin(directionType::rev, 100, velocityUnits::pct);
// chassis.drive_distance(-30);
// ir.stop();
// ir.spin(directionType::fwd, 100, velocityUnits::pct);
// LF.setBrake(brakeType::coast);
// LM.setBrake(brakeType::coast);
// LB.setBrake(brakeType::coast);
// RF.setBrake(brakeType::coast);
// RM.setBrake(brakeType::coast);
// RB.setBrake(brakeType::coast);
// wait(1200, msec);


}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void left_elims(){

chassis.set_drive_constants(12, 1.20, 0.0005, 9.0, 6);
chassis.set_turn_constants(8, 0.64, 0.0045, 5.8, 12);
chassis.set_swing_constants(8, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I
chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);

chassis.set_drive_exit_conditions(0.9, 120, 3000);
chassis.set_turn_exit_conditions(0.9, 120, 2800);
chassis.set_swing_exit_conditions(0.9, 110, 300);



il.spin(directionType::rev, 200, velocityUnits::pct);
ir.spin(directionType::rev, 100, velocityUnits::pct);
chassis.set_turn_exit_conditions(0.9, 120, 500);
chassis.set_heading_constants(0, 0.0, 0, 0, 0);
chassis.drive_distance(18);
chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);
chassis.right_swing_to_angle(-30);
chassis.drive_distance(8);
chassis.turn_to_angle(45);
chassis.drive_distance(32);
wait(200, msec);
chassis.set_drive_constants(10, 1.50, 0.0005, 9.0, 6);
chassis.drive_distance(-43);
chassis.set_turn_exit_conditions(0.9, 120, 700);
chassis.turn_to_angle(-270);
chassis.drive_distance(-38); //was -40 now its for red right
chassis.turn_to_angle(-180);
ir.stop();
chassis.set_drive_exit_conditions(0.9, 130, 800);
chassis.drive_distance(-8);
chassis.set_drive_exit_conditions(0.9, 130, 3000);
ir.spin(directionType::fwd, 200, velocityUnits::pct);
wait(2000, msec);
doinker.set(true);
ir.stop();
chassis.set_drive_exit_conditions(0.9, 130, 2000);
chassis.set_drive_constants(8, 1.50, 0.0005, 9.0, 6);


chassis.set_drive_exit_conditions(0.9, 130, 1300);
chassis.drive_distance(40);//into wall
chassis.set_drive_constants(10, 1.50, 0.0005, 9.0, 6);
ir.spin(directionType::rev, 100, velocityUnits::pct);
chassis.drive_distance(-30);
ir.stop();
ir.spin(directionType::fwd, 100, velocityUnits::pct);
LF.setBrake(brakeType::coast);
LM.setBrake(brakeType::coast);
LB.setBrake(brakeType::coast);
RF.setBrake(brakeType::coast);
RM.setBrake(brakeType::coast);
RB.setBrake(brakeType::coast);
wait(1200, msec);


}













//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void feinious(){





chassis.set_drive_constants(8, 1.5, 0.0005, 9.0, 6);
chassis.set_turn_constants(8, 0.64, 0.0045, 5.8, 12);
chassis.set_turn_constants(8, 0.64, 0.0045, 5.8, 12);
chassis.set_swing_constants(10, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I


chassis.set_drive_exit_conditions(0.9, 130, 3000);
chassis.set_turn_exit_conditions(0.9, 130, 2800);
chassis.set_swing_exit_conditions(0.9, 120, 800);







chassis.drive_distance(40);
chassis.set_drive_constants(8, 1.20, 0.0005, 9.0, 6);
doinker.set(true);
chassis.turn_to_angle(90);
ir.spin(directionType::rev, 200, velocityUnits::pct);
il.spin(directionType::rev, 200, velocityUnits::pct);
chassis.set_drive_exit_conditions(0.9, 130, 1000);
chassis.drive_distance(12);
wait(1000, msec);
chassis.drive_distance(-8);
doinker.set(false);
chassis.turn_to_angle(120);
chassis.drive_distance(-25);
chassis.turn_to_angle(90);
chassis.set_drive_exit_conditions(0.9, 130, 6000);
chassis.drive_distance(-70);
chassis.turn_to_angle(0);
chassis.drive_distance(-12);
chassis.turn_to_angle(270);
chassis.set_drive_exit_conditions(0.9, 130, 700);
chassis.drive_distance(-18);
chassis.set_drive_exit_conditions(0.9, 130, 3000);
ir.spin(directionType::fwd, 200, velocityUnits::pct);
wait(3000, msec);
ir.spin(directionType::rev, 200, velocityUnits::pct);
doinker.set(true);
wait(500, msec);
chassis.set_drive_exit_conditions(0.9, 130, 1500);
chassis.set_drive_constants(6, 1.70, 0.0005, 15.0, 6);
chassis.drive_distance(33);
wait(1000, msec);
chassis.set_drive_constants(8, 1.70, 0.0005, 15.0, 6);
chassis.drive_distance(-30);
chassis.set_drive_exit_conditions(0.9, 130, 3000);
ir.spin(directionType::fwd, 200, velocityUnits::pct);
wait(3000, msec);
ir.spin(directionType::rev, 200, velocityUnits::pct);
chassis.drive_distance(5);
chassis.drive_distance(-5);
doinker.set(false);
chassis.drive_distance(10);
chassis.turn_to_angle(180);
chassis.set_drive_exit_conditions(0.9, 130, 6000);
chassis.drive_distance(98);
doinker.set(true);
chassis.turn_to_angle(270);
chassis.set_drive_exit_conditions(0.9, 130, 1000);
chassis.drive_distance(20);
wait(3000, msec);
chassis.drive_distance(-8);
doinker.set(false);
chassis.turn_to_angle(-60);
chassis.drive_distance(-25);
chassis.turn_to_angle(-90);
chassis.set_drive_exit_conditions(0.9, 130, 6000);
chassis.drive_distance(-70);
chassis.turn_to_angle(-180);
chassis.drive_distance(-12);
chassis.turn_to_angle(90);
chassis.set_drive_exit_conditions(0.9, 130, 700);
chassis.drive_distance(-18);
chassis.set_drive_exit_conditions(0.9, 130, 3000);
ir.spin(directionType::fwd, 200, velocityUnits::pct);
wait(3000, msec);
ir.spin(directionType::rev, 200, velocityUnits::pct);
doinker.set(true);
wait(500, msec);
chassis.set_drive_exit_conditions(0.9, 130, 1500);
chassis.set_drive_constants(6, 1.70, 0.0005, 15.0, 6);
chassis.drive_distance(35);
wait(1000, msec);
chassis.set_drive_constants(8, 1.70, 0.0005, 15.0, 6);
chassis.drive_distance(-30);
chassis.set_drive_exit_conditions(0.9, 130, 3000);
ir.spin(directionType::fwd, 200, velocityUnits::pct);
wait(3000, msec);
ir.spin(directionType::rev, 200, velocityUnits::pct);
chassis.drive_distance(5);
chassis.drive_distance(-5);

doinker.set(false);
wait(500, msec);
arm.set(true);
chassis.drive_distance(20);
chassis.turn_to_angle(210);        // 240 - 90
chassis.drive_distance(-22);
chassis.left_swing_to_angle(180); // 270 - 90
chassis.drive_distance(-3);

chassis.right_swing_to_angle(200);  // 250 - 90
chassis.set_drive_constants(12, 1.70, 0.0005, 15.0, 6);
chassis.drive_distance(-30);
chassis.set_swing_exit_conditions(0.9, 120, 500);
chassis.left_swing_to_angle(180); // 270 - 90
chassis.drive_distance(-10);




}
