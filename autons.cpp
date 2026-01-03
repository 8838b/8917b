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
chassis.drive_max_voltage = 8;
chassis.drive_settle_error = 3;
}








//auton start








void FEIN(){

chassis.set_drive_constants(12, 1.15, 0.0004, 10.0, 6);

chassis.set_turn_constants(12, 0.64, 0.0045, 5.8, 12);
chassis.set_swing_constants(10, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I
chassis.set_heading_constants(12, 0.38, 0, 1.0, 12);


chassis.set_drive_exit_conditions(0.9, 130, 4000);
chassis.set_turn_exit_conditions(0.9, 130, 500);
chassis.set_swing_exit_conditions(0.9, 120, 2800);



chassis.set_slew_rate(0.6, 0.70);       // accel, decel
chassis.set_slow_zone(10.0, 4);         // start slowing 8" out, end ~2.5V
chassis.drive_distance(30);


}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solo_awp(){
chassis.set_drive_constants(12, 1.70, 0.0005, 15.0, 6);
chassis.set_turn_constants(12, 0.64, 0.0045, 5.8, 12);
chassis.set_swing_constants(10, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I
chassis.set_heading_constants(8, 0.38, 0, 1.0, 12);


chassis.set_drive_exit_conditions(0.9, 130, 2000);
chassis.set_turn_exit_conditions(0.9, 130, 500);
chassis.set_swing_exit_conditions(0.9, 100, 500);

il.spin(directionType::rev, 1000, velocityUnits::pct);
ir.spin(directionType::fwd, 1000, velocityUnits::pct);

//SLEW OFF
chassis.set_slew_rate(2, 2);       
chassis.set_slow_zone(0, 12);   
chassis.set_drive_exit_conditions(0.9, 130, 500);
chassis.drive_distance(5);

chassis.set_drive_exit_conditions(0.9, 130, 3000);
//SLEW ON
chassis.set_slew_rate(0.8, 0.55);       // accel, decel
chassis.set_slow_zone(40, 4);         // start slowing 8" out, end ~2.5V
chassis.set_finish_exit(0.06, 6);

chassis.drive_distance(-54);
chassis.set_turn_exit_conditions(0.5, 140, 500); 
doinker.set(true);
chassis.turn_to_angle(270);
//SLEW OFF
chassis.set_slew_rate(2, 2);       
chassis.set_slow_zone(0, 12);
chassis.set_drive_exit_conditions(0.5, 140, 800);
chassis.drive_distance(15);
chassis.set_drive_exit_conditions(0.5, 140, 1500);
//SLEW ON
chassis.set_slow_zone(20, 4); 
chassis.set_slew_rate(0.8, 0.4);       // accel, decel
chassis.set_drive_constants(8, 1.70, 0.0005, 15.0, 6);
chassis.drive_distance(-38);
pto.set(false);
doinker.set(false);
wait(2000,msec);
pto.set(true);
chassis.set_turn_exit_conditions(0.5, 140, 800); 
chassis.turn_to_angle(3);
chassis.set_slew_rate(0.3, 0.4);       // accel, decel
chassis.set_slow_zone(30, 4);         // start slowing 8" out, end ~2.5V
chassis.set_finish_exit(0.06, 6);
chassis.set_drive_constants(12, 1.70, 0.0005, 15.0, 6);
chassis.set_drive_exit_conditions(0.5, 140, 1000);
chassis.drive_distance(45);
chassis.set_turn_exit_conditions(0.5, 140, 200); 
chassis.turn_to_angle(350);
chassis.drive_distance(20);
chassis.set_turn_exit_conditions(0.5, 140, 300); 
chassis.turn_to_angle(320);
doinker.set(true);
chassis.drive_distance(-20);
mid.set(true);
wait(600,msec);

chassis.right_swing_to_angle(-90)









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

chassis.set_drive_constants(10, 1.50, 0.0005, 9.0, 6);
chassis.set_turn_constants(8, 0.64, 0.0045, 5.8, 12);
chassis.set_swing_constants(8, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I
chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);

chassis.set_drive_exit_conditions(0.9, 120, 3000);
chassis.set_turn_exit_conditions(0.9, 120, 2800);
chassis.set_swing_exit_conditions(0.9, 110, 2800);


chassis.drive_distance(40);



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



chassis.set_drive_constants(12, 1.20, 0.0005, 9.0, 6);
chassis.set_turn_constants(8, 0.64, 0.0045, 5.8, 12);
chassis.set_swing_constants(8, 0.78, 0.0030, 6.2, 6);  // ↓maxV, ↓P, ↑D, later I
chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);

chassis.set_drive_exit_conditions(0.9, 120, 3000);
chassis.set_turn_exit_conditions(0.9, 120, 2800);
chassis.set_swing_exit_conditions(0.9, 110, 2800);




chassis.set_turn_exit_conditions(0.9, 120, 500);
il.spin(directionType::rev, 200, velocityUnits::pct);
ir.spin(directionType::rev, 100, velocityUnits::pct);
chassis.set_heading_constants(0, 0.0, 0, 0, 0);
chassis.drive_distance(18);
chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);
chassis.set_swing_exit_conditions(0.9, 110, 500);

chassis.set_drive_constants(8, 1.20, 0.0005, 9.0, 6);
chassis.drive_distance(20);
chassis.drive_distance(-5);
chassis.set_turn_exit_conditions(0.9, 120, 500);
chassis.turn_to_angle(-245);
chassis.drive_distance(27);
doinker.set(true);
arm.set(true);
chassis.turn_to_angle(-180);
chassis.set_drive_exit_conditions(0.9, 120, 1200);
chassis.drive_distance(25);
chassis.drive_distance(-28);
ir.spin(directionType::fwd, 200, velocityUnits::pct);
wait(2500, msec);
doinker.set(false);
chassis.drive_distance(10);
chassis.turn_to_angle(110);
chassis.drive_distance(-12);
chassis.turn_to_angle(178);
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



il.spin(directionType::rev, 200, velocityUnits::pct);
ir.spin(directionType::rev, 100, velocityUnits::pct);
chassis.set_turn_exit_conditions(0.9, 120, 500);
chassis.set_heading_constants(0, 0.0, 0, 0, 0);
chassis.drive_distance(2);
chassis.set_heading_constants(7, 0.65, 0, 1.6, 12);
chassis.left_swing_to_angle(30);
chassis.drive_distance(8);
chassis.turn_to_angle(45);
chassis.drive_distance(32);
wait(200, msec);
chassis.set_drive_constants(10, 1.50, 0.0005, 9.0, 6);
chassis.drive_distance(-43);
chassis.set_turn_exit_conditions(0.9, 120, 700);
chassis.turn_to_angle(270);
chassis.drive_distance(-38); //was -40 now its for red right
chassis.turn_to_angle(180);
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