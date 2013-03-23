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

void placeRing() {
	//Get arm in position
	moveArm(SHOULDERTOP, ARMTOP);
	//Move forward until ring is around peg
	forward(PLACEFORWARD, 30);
	//Now open the hand
	openHand();
}

void goToStart() {
	//Go backwards
	backward(BACKWARDS);
	//Turn right in the direction of the rings
	turnRight(TURNTORINGS);
	//Go forward toward the rings
	forward(FORWARDTORINGS, 100);
}

task main() {
	//Initialize
	motor[LeftForward] = motor[RightForward] = motor[BackSideways] = motor[FrontSideways] = motor[ArmLeft] = motor[ArmRight] = motor[ShoulderLeft] = motor[ShoulderRight] = motor[ArmHandLeft] = motor[ArmHandRight] = 0; //Turn off the motors
	nMotorEncoder[LeftForward] = nMotorEncoder[RightForward] = nMotorEncoder[BackSideways] = nMotorEncoder[FrontSideways] = nMotorEncoder[ArmLeft] = nMotorEncoder[ShoulderLeft] = nMotorEncoder[ArmHandLeft] = 0; //Might as well reset the encoders too

	waitForStart();

	//Get up to detect the beacon
	right(STARTFORWARD);
	turnRight(SENSORTURN);

	int IRValue = SensorValue[IR];

	turnRight(TURN);

	//Go up toward the pegs
	switch(IRValue) { //0 - not found, 1-4 - Left, 5 - Center, 6-9 - Right
		case 1:
		case 2:
		case 3:
		case 4:
			left(SIDEWAYS);
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			right(SIDEWAYS);
			break;
		default:
	}

	forward(CENTERFORWARD, 100);

	//Place the ring then get ready for the match
	placeRing();
	goToStart();
}
