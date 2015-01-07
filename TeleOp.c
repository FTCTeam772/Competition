#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S3,     Compass,        sensorI2CHiTechnicCompass)
#pragma config(Sensor, S4,     Multi,          sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     FrontRight,    tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     BackRight,     tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     FrontLeft,     tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     BackLeft,      tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C1_1,     LeftSlide,     tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     RightSlide,    tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S2_C2_1,    zipties,              tServoContinuousRotation)
#pragma config(Servo,  srvo_S2_C2_2,    leftGrab,             tServoStandard)
#pragma config(Servo,  srvo_S2_C2_3,    rightGrab,            tServoStandard)
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
byte slide_scale = SLIDE_HIGH;

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
		motor[BackLeft] = motor[FrontLeft] = drive_scale * y1 * ANDYMARK_CONVERSION;
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
		if(((y1 < 0 && nMotorEncoder[LeftSlide] <= SLIDE_BOTTOM) || (y1 < 0 && nMotorEncoder[RightSlide] <= SLIDE_BOTTOM) || (y1 > 0 && nMotorEncoder[LeftSlide] >= SLIDE_TOP) || (y1 > 0 && nMotorEncoder[LeftSlide] >= SLIDE_TOP)) && !joy2Btn(5))
			y1 = 0;

		//writeDebugStream("Slides:\n\tLeft Slide:\t%d\n\tRight Slide:\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);

		//Set the motors to scale
		if(joy2Btn(9)){		//If button nine is pressed, only move the left side
			motor[LeftSlide] = slide_scale * y1 * ANDYMARK_CONVERSION;
			motor[RightSlide] = 0;
		}
		else if(joy2Btn(10)){		//If button ten is pressed, only move the right side
			motor[LeftSlide] = 0;
			motor[RightSlide] = slide_scale * y1 * ANDYMARK_CONVERSION;
		}
		else {		//Else move both
		motor[LeftSlide] = motor[RightSlide] = slide_scale * y1 * ANDYMARK_CONVERSION;
		}
		//Preset Positions

		//Home
		if(joy2Btn(2)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((nMotorEncoder[LeftSlide] > ENCODER_PRECISION || nMotorEncoder[RightSlide] > ENCODER_PRECISION) && !joy2Btn(5)) {
				motor[LeftSlide] = targetMotorSpeed(0, nMotorEncoder[LeftSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				motor[RightSlide] = targetMotorSpeed(0, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}

		//Low Rolling Goal
		if(joy2Btn(1)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((abs(nMotorEncoder[LeftSlide] - LOW_GOAL) > ENCODER_PRECISION || abs(nMotorEncoder[RightSlide] - LOW_GOAL) > ENCODER_PRECISION) && !joy2Btn(5)) {
				motor[LeftSlide] = targetMotorSpeed(LOW_GOAL, nMotorEncoder[LeftSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				motor[RightSlide] = targetMotorSpeed(LOW_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}

		//Medium Rolling Goal
		if(joy2Btn(3)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((abs(nMotorEncoder[LeftSlide] - MEDIUM_GOAL) > ENCODER_PRECISION || abs(nMotorEncoder[RightSlide] - MEDIUM_GOAL) > ENCODER_PRECISION) && !joy2Btn(5)) {
				motor[LeftSlide] = targetMotorSpeed(MEDIUM_GOAL, nMotorEncoder[LeftSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				motor[RightSlide] = targetMotorSpeed(MEDIUM_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}

		//High Rolling Goal
		if(joy2Btn(4)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((abs(nMotorEncoder[LeftSlide] - HIGH_GOAL) > ENCODER_PRECISION || abs(nMotorEncoder[RightSlide] - HIGH_GOAL) > ENCODER_PRECISION) && !joy2Btn(5)) {
				motor[LeftSlide] = targetMotorSpeed(HIGH_GOAL, nMotorEncoder[LeftSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				motor[RightSlide] = targetMotorSpeed(HIGH_GOAL, nMotorEncoder[RightSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
				//writeDebugStream("LeftSlide:\t%d\t%d\RightSlide:\t%d\t%d\n", nMotorEncoder[LeftSlide], nMotorEncoder[RightSlide]);
			}
			motor[LeftSlide] = motor[RightSlide] = 0;
		}

		//Center Goal
		if(joy2Btn(7)) {
			motor[LeftSlide] = motor[RightSlide] = 0;
			while((abs(nMotorEncoder[LeftSlide] - CENTER_GOAL) > ENCODER_PRECISION || abs(nMotorEncoder[RightSlide] - CENTER_GOAL) > ENCODER_PRECISION) && !joy2Btn(5)) {
				motor[LeftSlide] = targetMotorSpeed(CENTER_GOAL, nMotorEncoder[LeftSlide]) * SLIDE_HIGH * ANDYMARK_CONVERSION;
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
		if(joy1Btn(2) && !joy1Btn(1) && !joy1Btn(4) && !joy1Btn(3)) {		//Both grabbers go into the down position
			servo[leftGrab] = 190;
			servo[rightGrab] = 60;
		}
		if(joy1Btn(4) && !joy1Btn(3) && !joy1Btn(1)&& !joy1Btn(2)) {		//Both grabbers go into the up position
			servo[leftGrab] = 0;
			servo[rightGrab] = 270;
		}
		if(joy1Btn(1) && joy1Btn(2) && !joy1Btn(4)) {		//Left grabber goes into the down position
			servo[leftGrab] = 190;
   	}
   	if(joy1Btn(1) && !joy1Btn(2) && joy1Btn(4)) {		//Left grabber goes into the up position
    	servo[leftGrab] = 0;
  	}
  	if(joy1Btn(3) && joy1Btn(2) && !joy1Btn(4)) {		//Right grabber goes into the down position
    	servo[rightGrab] = 60;
    }
  	if(joy1Btn(3) && !joy1Btn(2) && joy1Btn(4)) {		//Right grabber goes into the up position
   		servo[rightGrab] = 270;
  	}
  	
  	//Joystick 2 - Operator
		if(joy2Btn(6)) //If the operator is pressing button 6, scale down the slide movements
			slide_scale = SLIDE_LOW;
		else
			slide_scale = SLIDE_HIGH;

		//Zip Ties
		if(joystick.joy2_y2 > DEADBAND || joystick.joy2_y2 < -DEADBAND)		//If the operator is putting in a value on the x-axis of the right stick
			servo[zipties] = joystick.joy2_y2 + CONT_SERVO_CENTER;					//Make the servo spin accordingly
		else
			servo[zipties] = CONT_SERVO_CENTER;					//If within DEADBAND, remain stopped

		writeDebugStream("IR_left:\t%d\n", SensorValue[IR_left]);
		writeDebugStream("IR_right:\t%d\n" ,SensorValue[IR_right]);
	}
}
