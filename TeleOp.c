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

//Initialize our globals
byte drive_scale = DRIVE_HIGH; 		//Used to scale down robot movements

//Declare large constants as longs
task driveControl() { //Asynchronous task for critical drive control
	while(true) {
		//Joystick 1 - Driver

		//Deadband between -DEADBAND to DEADBAND
		//Scale linearly for all other values
		float y1, y2;

		//writeDebugStream("IR sensor:\t%d\n", SensorValue[IR]);
		writeDebugStream("LeftSlide:\t%d\n", nMotorEncoder[LeftSlide]);
 		writeDebugStream("RightSlide:\t%d\n", nMotorEncoder[RightSlide]);

		//Tank Drive
		if(joystick.joy1_y1 > DEADBAND || joystick.joy1_y1 < -DEADBAND)		//Left stick controls left wheels
			y1 = joystick.joy1_y1 / 128.0;
		else
			y1 = 0;

		if(joystick.joy1_y2 > DEADBAND || joystick.joy1_y2 < -DEADBAND)		//Right stick controls right wheels
			y2 = joystick.joy1_y2 / 128.0;
		else
			y2 = 0;

		//Set the motors to scale
		motor[LeftWheels] = drive_scale * y1 * ANDYMARK_CONVERSION;
		motor[BackRight] = motor[FrontRight] = drive_scale * y2 * ANDYMARK_CONVERSION;

		//writeDebugStream("Wheels:\n\tFront Left:\t%d\n\tFront Right:\t%d\n\tBack Left:\t%d\n\tBack Right:\t%d\n", nMotorEncoder[FrontLeft], nMotorEncoder[FrontRight], nMotorEncoder[BackLeft], nMotorEncoder[BackRight]);
	}
}

task slideControl() {
	while(true) {
		//Joystick 2 - Operator

		float y1;
		//Check each axis for deadband
		if(joystick.joy2_y1 > DEADBAND || joystick.joy2_y1 < -DEADBAND){
			y1 = joystick.joy2_y1 / 128.0;
		}
		else {
			y1 = 0;
		}

		//Protect slides unless button 5 is pressed
		//if(((y1 < 0 && nMotorEncoder[LeftSlide] <= SLIDE_BOTTOM) || (y1 < 0 && nMotorEncoder[RightSlide] <= SLIDE_BOTTOM) || (y1 > 0 && nMotorEncoder[LeftSlide] >= SLIDE_TOP) || (y1 > 0 && nMotorEncoder[RightSlide] >= SLIDE_TOP)) && !joy2Btn(5))
		//	y1 = 0;

		if(((y1 < 0 && nMotorEncoder[RightSlide] <= SLIDE_BOTTOM) || (y1 > 0 && nMotorEncoder[RightSlide] >= SLIDE_TOP)) && !joy2Btn(5))
			y1 = 0;

		//writeDebugStream("Slides:\n\tLeft Slide:\t%d\n\tRight Slide:\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);

		//Set the motors to scale
		if(joystick.joy2_TopHat == 0) { //Hold the lift up
			motor[LeftSlide] = BUMP;
			motor[RightSlide] = BUMP;
		}
		else if(joy2Btn(9)){		//If button nine is pressed, only move the left side
			motor[LeftSlide] = SLIDE_HIGH * y1 * ANDYMARK_CONVERSION;
			motor[RightSlide] = 0;
		}
		else if(joy2Btn(10)){		//If button ten is pressed, only move the right side
			motor[LeftSlide] = 0;
			motor[RightSlide] = SLIDE_HIGH * y1 * ANDYMARK_CONVERSION;
		}
		else {		//Else move both
			motor[LeftSlide] = motor[RightSlide] = SLIDE_HIGH * y1 * ANDYMARK_CONVERSION;
		}
		//Preset Positions

		//Home
		if(joy2Btn(2)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((nMotorEncoder[RightSlide] > (ENCODER_PRECISION * 1.5)) && !joy2Btn(5)){ 		//nMotorEncoder[LeftSlide] > ENCODER_PRECISION ||
				motor[LeftSlide] = -SLIDE_HIGH * ANDYMARK_CONVERSION * .85;		//targetMotorSpeed(0, nMotorEncoder[LeftSlide]) *
				motor[RightSlide] = -SLIDE_HIGH * ANDYMARK_CONVERSION;			//targetMotorSpeed(0, nMotorEncoder[RightSlide]) *
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}

		//Goal Grab Position
		if(joystick.joy2_TopHat == 4) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((abs(nMotorEncoder[RightSlide] - GOAL_GRAB_LIFT) > ENCODER_PRECISION) && !joy2Btn(5)) {		//abs(nMotorEncoder[LeftSlide] - GOAL_GRAB_LIFT) > ENCODER_PRECISION ||
				motor[LeftSlide] = targetMotorSpeed(GOAL_GRAB_LIFT, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				motor[RightSlide] = targetMotorSpeed(GOAL_GRAB_LIFT, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}
		
		//Low Rolling Goal
		if(joy2Btn(1)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((abs(nMotorEncoder[RightSlide] - LOW_GOAL) > ENCODER_PRECISION) && !joy2Btn(5)) {		//abs(nMotorEncoder[LeftSlide] - LOW_GOAL) > ENCODER_PRECISION ||
				motor[LeftSlide] = targetMotorSpeed(LOW_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				motor[RightSlide] = targetMotorSpeed(LOW_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}

		//Medium Rolling Goal
		if(joy2Btn(3)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((abs(nMotorEncoder[RightSlide] - MEDIUM_GOAL) > ENCODER_PRECISION) && !joy2Btn(5)) {		//(abs(nMotorEncoder[LeftSlide] - MEDIUM_GOAL) > ENCODER_PRECISION ||
				motor[LeftSlide] = targetMotorSpeed(MEDIUM_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				motor[RightSlide] = targetMotorSpeed(MEDIUM_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}

		//High Rolling Goal
		if(joy2Btn(4)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((abs(nMotorEncoder[RightSlide] - HIGH_GOAL) > ENCODER_PRECISION) && !joy2Btn(5)) {		//(abs(nMotorEncoder[LeftSlide] - HIGH_GOAL) > ENCODER_PRECISION ||
				motor[LeftSlide] = targetMotorSpeed(HIGH_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				motor[RightSlide] = targetMotorSpeed(HIGH_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}

		//Center Goal
		if(joy2Btn(6)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((abs(nMotorEncoder[RightSlide] - CENTER_GOAL) > ENCODER_PRECISION) && !joy2Btn(5)) {		//(abs(nMotorEncoder[LeftSlide] - CENTER_GOAL) > ENCODER_PRECISION ||
				motor[LeftSlide] = targetMotorSpeed(CENTER_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				motor[RightSlide] = targetMotorSpeed(CENTER_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}
	}
}

task main() {
	//Initialize
	initialize();

	//Go time!
	waitForStart();

	StartTask(driveControl); //Go ahead and start critical drive functions in their own task
	StartTask(slideControl); //Start arm functions

	while(true) {
		//Joystick 1 - Driver

		if(joy1Btn(6)) 		//If the driver is pressing button 6, slow down movements
			drive_scale = DRIVE_LOW;
		else 		//Else be full speed
			drive_scale = DRIVE_HIGH;

		switch(joystick.joy1_TopHat) { //Play a song based on the D-pad value
			case 0:
				setSong("1Up.nms");
				play();
				break;
			case 2:
				setSong("SuperMario.nms");
				play();
				break;
			case 4:
				setSong("CastleComplete.nms");
				play();
				break;
			case 6:
				setSong("Starman.nms");
				play();
				break;
		}

		if(joy1Btn(4)) { //If the driver is pressing button 4, play the Imperial March
			setSong("ImperialMarch.nms");
			play();
		}
		if(joy1Btn(9)) { //If the driver is pressing button 9, play Still Alive
			setSong("StillAlive.nms");
			play();
		}
		if(joy1Btn(10)) { //If the driver is pressing button 10, stop song
			stop();
		}

		//Goal Grabbers
		int leftpos = 0;		//Keeps track of the position of the left servo
		int rightpos = 0;		//Keeps track of the position of the right servo

		if(joy1Btn(4)) {		//Both grabbers go into the down position
			servo[leftGrab] = LEFT_GRAB_DOWN;
			servo[rightGrab] = RIGHT_GRAB_DOWN;
			leftpos = 1;
			rightpos = 1;
		}
		if(joy1Btn(2)) {		//Both grabbers go into the up position
			servo[leftGrab] = LEFT_GRAB_UP;
			servo[rightGrab] = RIGHT_GRAB_UP;
			leftpos = 0;
			rightpos = 0;
		}
		if(joy1Btn(1) && leftpos == 0) {		//Left grabber goes into the down position
			servo[leftGrab] = LEFT_GRAB_DOWN;
			leftpos = 1;
   	}
   	if(joy1Btn(1) && leftpos == 1) {		//Left grabber goes into the up position
    	servo[leftGrab] = LEFT_GRAB_UP;
    	leftpos = 0;
  	}
  	if(joy1Btn(3) && rightpos == 0) {		//Right grabber goes into the down position
    	servo[rightGrab] = RIGHT_GRAB_DOWN;
    	rightpos = 1;
    }
  	if(joy1Btn(3) && rightpos == 1) {		//Right grabber goes into the up position
   		servo[rightGrab] = RIGHT_GRAB_UP;
   		rightpos = 0;
  	}

  	//Joystick 2 - Operator
		//Zip Ties
		if(joystick.joy2_y2 > DEADBAND || joystick.joy2_y2 < -DEADBAND)		//If the operator is putting in a value on the x-axis of the right stick
			motor[zipties] = sgn(joystick.joy2_y2) * DRIVE_HIGH;					//Make the servo spin accordingly
		else
			motor[zipties] = 0;					//If within DEADBAND, remain stopped

		writeDebugStream("IR_left:\t%d\n", SensorValue[IR_left]);
		writeDebugStream("IR_right:\t%d\n" ,SensorValue[IR_right]);
	}
}
