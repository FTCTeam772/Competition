#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S3,     Compass,        sensorI2CHiTechnicCompass)
#pragma config(Sensor, S4,     Multi,          sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     FrontRight,    tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     BackRight,     tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     LeftWheels,    tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     zipties,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S2_C1_1,     LeftSlide,     tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     RightSlide,    tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S2_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_2,    leftGrab,             tServoStandard)
#pragma config(Servo,  srvo_S2_C2_3,    rightGrab,            tServoStandard)
#pragma config(Servo,  srvo_S2_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

//Constants
#include "constants.h"

//Useful functions
#include "common.h"

//Music player
#include "Player.h"

void kickCenter(bool kick, bool center){

		//Get IR Values
		int irvalue = -1;

		if ((HTIRS2readACDir(IR_left) == 5 && HTIRS2readACDir(IR_right) == 6) || (HTIRS2readACDir(IR_left) == 5 && HTIRS2readACDir(IR_right) == 0)) { //center goal is facing the box
			irvalue = 0;
		}

		if ((HTIRS2readACDir(IR_left) == 6 && HTIRS2readACDir(IR_right) == 7) || (HTIRS2readACDir(IR_left) == 0 && HTIRS2readACDir(IR_right) == 0)) { //center goal is facing at a 45 degree angle between the box and side of the ramp
			irvalue = 1;
		}

		if (HTIRS2readACDir(IR_left) == 5 && HTIRS2readACDir(IR_right) == 5) { //center goal is facing toward the side of the ramp
			irvalue = 2;
		}

		if (center == true) {
			//run kickstand method for ramp start

			if (irvalue == 0) { //center goal is facing the box
				//score in the centergoal
				turn(-2000);
				drive(-2500);
				turn(-2200);
				drive(2100);
				//liftScore(CENTER_GOAL);

				if (kick == true){
					//knock over kickstand

				}
			}

			if (irvalue == 1) { //center goal is facing at a 45 degree angle between the box and side of the ramp
				//score in the centergoal
				turn(-1200);
				drive(-5000);
				turn(-3500);
				drive(-500);
				//liftScore(CENTER_GOAL);

				if (kick == true){
					//knock over kickstand

				}
			}

			if (irvalue == 2) { //center goal is facing toward the side of the ramp
				//score in the centergoal
				turn(-1400);
				drive(-7300);
				turn(-2200);
				//liftScore(CENTER_GOAL);

				if (kick == true){
					//knock over kickstand

				}
			}
		}

		if (kick == true){		//center is false & kickstand is true

			if (irvalue == 0) { //center goal is facing the box
				//knock over kickstand
				oneSideTurn(-1800, false);
				oneSideTurn(-1800, true);
				drive(-6000);
			}

			if (irvalue == 1) { //center goal is facing at a 45 degree angle
				//knock over kickstand
				turn(3000);
				drive(3300);
				turn(-2300);
				drive(-7000);
			}

			if (irvalue == 2) { //center goal is facing toward the side of the ramp
				//knock over kickstand
				drive(-2500);
				turn(-3000);
				drive(-3000);
				drive(2000);
				drive(-4000);
		  }
		}
	}


void execute(bool ramp, bool def, bool kick, bool center, int roll) {			//I feel like this should be outside of task main()

		if (ramp == true) {			//If starting from ramp

			if (roll == 1) {
				//score in medium goal and bring it back (bring it back can be a common.h method) to parking zone
				drive(11400);
				oneSideTurn(300, false);
				setGrabbers();
				liftScore(MEDIUM_GOAL);
				grabGoal();
				turn(1100);
				drive(-10700);
				turn(5500);
				releaseGoal();
				}

			kickCenter(kick, center);
		}

		if (ramp == false) {

			if (def == true) {
				//run defense program for floor beginning
			}
			if (def == false) {

				if (roll == 0) {		//If not scoring in rolling goals
					drive(-2700);
				}

				if (roll == 1) {
					//score in medium goal and bring it back
					drive(1600);
					//turn(1050);
					turnBy(5);
					drive(11300);
					setGrabbers();
					liftScore(MEDIUM_GOAL);
					grabGoal();
					wait();
					drive(-8300);
					turn(6800);
					releaseGoal();
				}
				if (roll == 2) {
					//score in tallest goal and bring it back
					drive(1800);
					turn(1000);
					drive(8600);
					oneSideTurn(1300, true);
					drive(5000);
					setGrabbers();
					liftScore(HIGH_GOAL);
					grabGoal();
					wait();
					drive(-4500);
					oneSideTurn(-1500, true);
					drive(-7000);
					turn(9000);
					releaseGoal();
				}

				kickCenter(kick, center);
			}
		}
	}

task main() {

	//Initialize
	initialize();

	//Go time!
	waitForStart();

	//Play the Imperial March
	//setSong("ImperialMarch.nms");
	//play();

	//wait10Msec(delay * 100);

 	execute(RAMP, DEF, KICK, CENTER, ROLLING);

}
