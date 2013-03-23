#pragma config(Hubs, S1, HTMotor, HTMotor, none, none)
#pragma config(Hubs, S2, HTMotor, HTMotor, none, none)
#pragma config(Sensor, S1, , sensorI2CMuxController)
#pragma config(Sensor, S2, , sensorI2CMuxController)
#pragma config(Sensor, S3, IR, sensorHiTechnicIRSeeker1200)
#pragma config(Motor, mtr_S1_C1_1, BackSideways, tmotorTetrix, PIDControl, encoder)
#pragma config(Motor, mtr_S1_C1_2, RightForward, tmotorTetrix, PIDControl, encoder)
#pragma config(Motor, mtr_S1_C2_1, LeftForward, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor, mtr_S1_C2_2, FrontSideways, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor, mtr_S2_C1_1, ShoulderLeft, tmotorTetrix, openLoop, encoder)
#pragma config(Motor, mtr_S2_C1_2, ShoulderRight, tmotorTetrix, openLoop, reversed)
#pragma config(Motor, mtr_S2_C2_1, ArmLeft, tmotorTetrix, openLoop, encoder)
#pragma config(Motor, mtr_S2_C2_2, ArmRight, tmotorTetrix, openLoop, reversed)
#pragma config(Motor, motorA, ArmHandLeft, tmotorNXT, PIDControl, encoder)
#pragma config(Motor, motorB, ArmHandRight, tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "common.c"

//Constants
#include "constants.h"

//Initialize our globals
byte joystickScale = JOYSTICKHIGH; //Used to scale down robot movements
byte armScale = ARMHIGH; //Used to scale arm movements
byte armScaleDown = ARMDOWNHIGH; //Second scale for going down since the arm will be moving much faster
byte shoulderScale = SHOULDERHIGH; //Same for shoulder
byte shoulderScaleDown = SHOULDERDOWNHIGH;

bool forwardlock = true; //Used for direction locking
bool sidelock = true;

task joystickControl() { //Asynchronous task for joystick control
	while(true) {
		//Joystick 1 - Driver

#ifdef TANKDRIVE
		if(forwardlock) { //Part of direction locking mechanism
			//Big fancy statement to set the left forward motors equal to the converted joystick's left y axis unless it is in the natural variant range.
			motor[LeftForward] = joystick.joy1_y1 > 10 || joystick.joy1_y1 < -10 ? joystick.joy1_y1 / 128.0 * joystickScale : 0;
			//Same for right and for sideways (but use the second y axis for right side and use the x axes for sideways motors)
			motor[RightForward] = joystick.joy1_y2 > 10 || joystick.joy1_y2 < -10 ? joystick.joy1_y2 / 128.0 * joystickScale : 0;
		}
		if(sidelock) {
			motor[BackSideways] = joystick.joy1_x1 > 10 || joystick.joy1_x1 < -10 ? joystick.joy1_x1 / 128.0 * joystickScale : 0;
			motor[FrontSideways] = joystick.joy1_x2 > 10 || joystick.joy1_x2 < -10 ? joystick.joy1_x2 / 128.0 * joystickScale : 0;
		}
#else
		if(forwardlock) { //Part of direction locking mechanism
			//Big fancy statement to set the left forward motors equal to the converted joystick's left y axis unless it is in the natural variant range and adds/subtracts to turn based on the joystick's right x axis.
			motor[LeftForward] = (joystick.joy1_y1 > 10 || joystick.joy1_y1 < -10 ? joystick.joy1_y1 : 0 + (int)(joystick.joy1_x2 > 10 || joystick.joy1_x2 < -10 ? joystick.joy1_x2 : 0)) / (128.0 + joystick.joy1_x2) * joystickScale;
			motor[RightForward] = (joystick.joy1_y1 > 10 || joystick.joy1_y1 < -10 ? joystick.joy1_y1 : 0 - (int)(joystick.joy1_x2 > 10 || joystick.joy1_x2 < -10 ? joystick.joy1_x2 : 0)) / (128.0 + joystick.joy1_x2) * joystickScale;
		}
  	if(sidelock) {
  		//Same for sideways wheels but using the joystick's left x axis for sideways but still the joystick's right x axis for turning.
			motor[BackSideways] = (joystick.joy1_x1 > 10 || joystick.joy1_x1 < -10 ? joystick.joy1_x1 : 0 - (int)(joystick.joy1_x2 > 10 || joystick.joy1_x2 < -10 ? joystick.joy1_x2 : 0)) / (128.0 + joystick.joy1_x2) * joystickScale;
			motor[FrontSideways] = (joystick.joy1_x1 > 10 || joystick.joy1_x1 < -10 ? joystick.joy1_x1 : 0 + (int)(joystick.joy1_x2 > 10 || joystick.joy1_x2 < -10 ? joystick.joy1_x2 : 0)) / (128.0 + joystick.joy1_x2) * joystickScale;
		}
#endif

		//Joystick 2 - Operator

		//Hand control
		if(joy2Btn(5) && (nMotorEncoder[ArmHandLeft] < HANDMAX || joy2Btn(7))) //If the operator is pressing button 5 and it isn't open, open the hand
			motor[ArmHandLeft] = motor[ArmHandRight] = armScale;
		else if(joy2Btn(6) && (nMotorEncoder[ArmHandLeft] > HANDMIN || joy2Btn(7))) //Else if the operator is pressing button 6 and it isn't closed, closed the hand
			motor[ArmHandLeft] = motor[ArmHandRight] = -armScale;
		else //Otherwise just don't move
			motor[ArmHandLeft] = motor[ArmHandRight] = 0;
	}
}

task armControl() { //Another asynchronous task to move the arm
	while(true) {
		//Joystick 2 - Operator

	/*if(joy2Btn(1)) { //If the operator is pressing button 1, set arm to lowest peg
			moveArm(SHOULDERUPRIGHT, BOTTOMPEG);
		}
		if(joy2Btn(2)) { //If the operator is pressing button 2, set arm to middle peg
			moveArm(SHOULDERUPRIGHT, MIDDLEPEG);
		}
		if(joy2Btn(3)) { //If the operator is pressing button 3, set arm to top peg
			moveArm(SHOULDERUPRIGHT, TOPPEG);
		}*/
		if(joy2Btn(4)) { //If the operator is pressing button 4, set arm to ring peg
			moveArm(RINGPEGSHOULDER, RINGPEGARM);
		}
		if(joy2Btn(9)) { //If the operator is pressing button 9, set arm to upright
			moveArm(SHOULDERUPRIGHT, ARMUPRIGHT);
		}
		if(joy2Btn(10)) { //If the operator is pressing button 10, set arm to home position
			moveArm(0, 0);
		}

		if(joystick.joy2_y2 > 10 && (nMotorEncoder[ShoulderLeft] < SHOULDERTOP || joy2Btn(7))) //If shoulder is going positive and we aren't at the top, follow the joystick.  If the operator is pressing button 7, override checks
			motor[ShoulderLeft] = motor[ShoulderRight] = joystick.joy2_y2 / 128.0 * shoulderScale;
		else if(joystick.joy2_y2 < -10 && (nMotorEncoder[ShoulderLeft] > SHOULDERBOTTOM || joy2Btn(7))) //Else if we are going down and aren't at the bottom, go negative
			motor[ShoulderLeft] = motor[ShoulderRight] = joystick.joy2_y2 / 128.0 * shoulderScaleDown;
		else
			motor[ShoulderLeft] = motor[ShoulderRight] = 0;
		if(joystick.joy2_y1 > 10 && (nMotorEncoder[ArmLeft] < ARMTOP || joy2Btn(7))) //Same thing for arm
			motor[ArmLeft] = motor[ArmRight] = joystick.joy2_y1 / 128.0 * armScale;
		else if(joystick.joy2_y1 < -10 && (nMotorEncoder[ArmLeft] > ARMBOTTOM || joy2Btn(7)))
			motor[ArmLeft] = motor[ArmRight] = joystick.joy2_y1 / 128.0 * armScaleDown;
		else
			motor[ArmLeft] = motor[ArmRight] = 0;
	}
}

task main() {
	//Initialize
	motor[LeftForward] = motor[RightForward] = motor[BackSideways] = motor[FrontSideways] = motor[ArmLeft] = motor[ArmRight] = motor[ShoulderLeft] = motor[ShoulderRight] = motor[ArmHandLeft] = motor[ArmHandRight] = 0; //Turn off the motors
	nMotorEncoder[LeftForward] = nMotorEncoder[RightForward] = nMotorEncoder[BackSideways] = nMotorEncoder[FrontSideways] = nMotorEncoder[ArmLeft] = nMotorEncoder[ShoulderLeft] = nMotorEncoder[ArmHandLeft] = 0; //Might as well reset the encoders too

	waitForStart();

	StartTask(joystickControl); //Go ahead and start critical joystick functions in their own task
	StartTask(armControl); //Start arm functions in their own task too
	while(true) {
		//Joystick 1 - Driver

		if(joy1Btn(6)) //If the driver is pressing button 6, scale down robot movements
			joystickScale = JOYSTICKLOW;
		else //Else leave at full speed
			joystickScale = JOYSTICKHIGH;
		if(joy1Btn(5)) //If the driver is pressing button 5, lock to y-axis movement
			sidelock = false;
		else
			sidelock = true;
		if(joy1Btn(7)) //If the driver is pressing button 7, lock to x-axis movement
			forwardlock = false;
		else
			forwardlock = true;

		//Joystick 2 - Operator

		if(joy2Btn(8)) { //If the operator is pressing button 8, scale down hand movements
			armScale = ARMLOW;
			armScaleDown = ARMDOWNLOW;
			shoulderScale = SHOULDERLOW;
			shoulderScaleDown = SHOULDERDOWNLOW;
		}
		else {
			armScale = ARMHIGH;
			armScaleDown = ARMDOWNHIGH;
			shoulderScale = SHOULDERHIGH;
			shoulderScaleDown = SHOULDERDOWNHIGH;
		}

		writeDebugStreamLine("%d\n%d", nMotorEncoder[ShoulderLeft], nMotorEncoder[ArmLeft]);
	}
}
