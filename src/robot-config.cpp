#include "vex.h"
#include "drive.h"
#include "robot-config.h"
#include <array>

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

// 8 motor 4 WHEEL mechanum drive
// A front, B back
//brain is Front, batt back

//15inch
// motor LeftMotorA(PORT11, gearSetting::ratio18_1, true);//
// motor LeftMotorB(PORT12, gearSetting::ratio18_1, false);//    // because of gearing, middle one is opposite
// motor LeftMotorC(PORT13, gearSetting::ratio18_1, true);//

// motor RightMotorA(PORT18, gearSetting::ratio18_1, false); ///
// motor RightMotorB(PORT19, gearSetting::ratio18_1, true);
// motor RightMotorC(PORT20, gearSetting::ratio18_1, false);


// //snow
// motor LeftMotorA(PORT17, gearSetting::ratio18_1, true);
// motor LeftMotorB(PORT18, gearSetting::ratio18_1, false);// left
// motor LeftMotorC(PORT15, gearSetting::ratio18_1, true);


// motor RightMotorA(PORT13, gearSetting::ratio18_1, true);
// motor RightMotorB(PORT12, gearSetting::ratio18_1, false);
// motor RightMotorC(PORT14, gearSetting::ratio18_1, false);

// //18 actual ,  stake front
// motor LeftMotorA(PORT1, gearSetting::ratio18_1, false);//
// motor LeftMotorB(PORT2, gearSetting::ratio18_1, true);//    // because of gearing, middle one is opposite
// motor LeftMotorC(PORT3, gearSetting::ratio18_1, false);//

// motor RightMotorA(PORT8, gearSetting::ratio18_1, true); 
// motor RightMotorB(PORT9, gearSetting::ratio18_1, false);//
// motor RightMotorC(PORT10, gearSetting::ratio18_1, true);


//18 actual, reverse front back//   -> rollor wheels front
motor LeftMotorA(PORT1, gearSetting::ratio18_1, true);//
motor LeftMotorB(PORT2, gearSetting::ratio18_1, false);//    // because of gearing, middle one is opposite
motor LeftMotorC(PORT3, gearSetting::ratio18_1, true);//

motor RightMotorA(PORT8, gearSetting::ratio18_1, false); 
motor RightMotorB(PORT9, gearSetting::ratio18_1, true);//
motor RightMotorC(PORT10, gearSetting::ratio18_1, false);



// small 2 motors bot
// motor LeftMotorA(PORT10, gearSetting::ratio18_1, true);//
// motor LeftMotorB(PORT9, gearSetting::ratio18_1, false);//    // because of gearing, middle one is opposite
// // motor LeftMotorC(PORT8, gearSetting::ratio18_1, true);//

// motor RightMotorA(PORT1, gearSetting::ratio18_1, false); ///
// motor RightMotorB(PORT2, gearSetting::ratio18_1, true);
// // motor RightMotorC(PORT3, gearSetting::ratio18_1, false);

// motor LeftMotorC(PORT12, gearSetting::ratio18_1, true);//
//  motor RightMotorC(PORT20, gearSetting::ratio18_1, true);



motor intake(PORT12, gearSetting::ratio18_1, false);
motor intake2(PORT13,gearSetting::ratio18_1, false);

motor intakeRoller(PORT11, gearSetting::ratio18_1, true);// wheels 

motor wingL(PORT7, gearSetting::ratio18_1, false);
motor wingR(PORT14, gearSetting::ratio18_1, true);

motor catapultA(PORT19, gearSetting::ratio18_1, true); //left
motor catapultB(PORT13, gearSetting::ratio18_1, false); //right

rotation catapultRot(PORT5, false);

inertial imu(PORT13);
gps gps1(PORT20, 0, 0, distanceUnits::mm, 180); // port, x, y, distance units, angle offset, turn direction?
rotation odomLeft(PORT10, true);
rotation odomRight(PORT2, false);
rotation odomCenter(PORT3, true);

optical colorSensor(PORT20);

brain Brain;
controller Controller1(controllerType::primary);

double initialHeading = 0;//initial 

// declare object-oriented stuff here (that should be globally accessible)
Drive drive;
Wings wings;

 
//dark indoor
aivision::colordesc redRing (1,     237,      36,     98,   10.00,    0.2); 
aivision::colordesc blueRing = aivision::colordesc(2, 39, 178, 234, 10.00, 0.20);




aivision aiVision1(PORT19, redRing, blueRing);

vex::distance Distance1(PORT10);

