#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          LeftHand,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          RightHand,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     FrontLeft,     tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     FrontRight,    tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     BackLeft,      tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     BackRight,     tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C1_1,     LeftArmShoulder, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     LeftArmElbow,  tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C2_1,     RightArmShoulder, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S2_C2_2,     RightArmElbow, tmotorTetrix, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
//#include "common.c"

//Constants
#include "constants.h"

//Initialize our globals
byte drive_scale = DRIVE_HIGH; //Used to scale down robot movements
byte arm_scale = ARM_HIGH;

bool forwards = true; //Used for direction locking
bool sideways = true;

task driveControl() { //Asynchronous task for critical drive control
	while(true) {
		//Joystick 1 - Driver

		//Deadband between -15 to 15
		//Scale linearly for all other values
		float x1, y1, x2, y2;

		//Check each axis for deadband and direction locking
		if((joystick.joy1_x1 > 15 || joystick.joy1_x1 < -15) && sideways)
			x1 = joystick.joy1_x1 / 128.0;
		else
			x1 = 0;

		if((joystick.joy1_y1 > 15 || joystick.joy1_y1 < -15) && forwards)
			y1 = joystick.joy1_y1 / 128.0;
		else
			y1 = 0;

		if(joystick.joy1_x2 > 15 || joystick.joy1_x2 < -15)
			x2 = joystick.joy1_x2 / 128.0;
		else
			x2 = 0;

		if(joystick.joy1_y2 > 15 || joystick.joy1_y2 < -15)
			y2 = joystick.joy1_y2 / 128.0;
		else
			y2 = 0;

		//Set the motors to scale
		motor[FrontLeft] = drive_scale * (-x2 + (y1 + x1));
		motor[FrontRight] = drive_scale * (-x2 + (-y1 + x1));
		motor[BackLeft] = drive_scale * (-x2 + (y1 + -x1));
		motor[BackRight] = drive_scale * (-x2 + (-y1 + -x1));
	}
}

task armControl() {
	while(true) {
		//Joystick 2 - Operator

		float x1, y1, x2, y2;

		//Check each axis for deadband and protect arm
		if((joystick.joy2_x1 > 15 || joystick.joy2_x1 < -15) && (abs(joystick.joy2_x1) > abs(joystick.joy2_y1))) // && (nMotorEncoder[LeftArmShoulder] > ARM_SHOULDER_BOTTOM && nMotorEncoder[LeftArmShoulder] < ARM_SHOULDER_TOP) || joy2Btn(7))
			x1 = joystick.joy2_x1 / 128.0;
		else
			x1 = 0;

		if((joystick.joy2_y1 > 15 || joystick.joy2_y1 < -15) && (abs(joystick.joy2_y1) > abs(joystick.joy2_x1))) // && (nMotorEncoder[LeftArmElbow] > ARM_ELBOW_BOTTOM && nMotorEncoder[LeftArmElbow] < ARM_ELBOW_TOP) || joy2Btn(7))
			y1 = joystick.joy2_y1 / 128.0;
		else
			y1 = 0;

		if((joystick.joy2_x2 > 15 || joystick.joy2_x2 < -15) && (abs(joystick.joy2_x2) > abs(joystick.joy2_y2)))
			x2 = joystick.joy2_x2 / 128.0;
		else
			x2 = 0;

		if((joystick.joy2_y2 > 15 || joystick.joy2_y2 < -15) && (abs(joystick.joy2_y2) > abs(joystick.joy2_x2)))
			y2 = joystick.joy2_y2 / 128.0;
		else
			y2 = 0;

		//Set the motors to scale
		motor[LeftArmShoulder] = arm_scale * x1;
		motor[LeftArmElbow] = arm_scale * y1;
		motor[RightArmShoulder] = arm_scale * x2;
		motor[RightArmElbow] = arm_scale * y2;

		//If button 7 is pressed, open the left hand until it is at max
		if(joy2Btn(7) && nMotorEncoder[LeftHand] < HAND_MAX)
			motor[LeftHand] = 255;
		else if(nMotorEncoder[LeftHand] > HAND_MIN) //Else close the hand
			motor[LeftHand] = -255;
		else
			motor[LeftHand] = 0;

		//If button 8 is pressed, control the right hand
		if(joy2Btn(8) && nMotorEncoder[RightHand] < HAND_MAX)
			motor[RightHand] = 255;
		else if(nMotorEncoder[RightHand] > HAND_MIN) //Else close the hand
			motor[RightHand] = -255;
		else
			motor[RightHand] = 0;
	}
}

task main() {
	//Initialize
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = motor[LeftArmShoulder] = motor[LeftArmElbow] = motor[RightArmShoulder] = motor[RightArmElbow] = motor[LeftHand] = motor[RightHand] = 0; //Turn off the motors
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = nMotorEncoder[LeftArmShoulder] = nMotorEncoder[LeftArmElbow] = nMotorEncoder[RightArmShoulder] = nMotorEncoder[RightArmElbow] = nMotorEncoder[LeftHand] = nMotorEncoder[RightHand] = 0; // Might as well reset the encoders too

	//Display the robot's name
	nxtDisplayCenteredTextLine(0, "Codex");

	//Go time!
	waitForStart();
	StartTask(driveControl); //Go ahead and start critical drive functions in their own task
	StartTask(armControl); //Start arm functions

	while(true) {
		//Joystick 1 - Driver

		if(joy1Btn(6)) //If the driver is pressing button 6, scale down robot movements
			drive_scale = DRIVE_LOW;
		else //Else leave at full speed
			drive_scale = DRIVE_HIGH;

		if(joy1Btn(5)) //If the driver is pressing button 5, lock to y-axis movement
			sideways = false;
		else
			sideways = true;

		if(joy1Btn(7)) //If the driver is pressing button 7, lock to x-axis movement
			forwards = false;
		else
			forwards = true;

		//Joystick 2 - Operator

		if(joy2Btn(6)) //If the operator is pressing button 8, scale down the arm movements
			arm_scale = ARM_LOW;
		else
			arm_scale = ARM_HIGH;
	}
}
