#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S3,     Ultrasonic,     sensorSONAR)
#pragma config(Sensor, S4,     Gyro,           sensorI2CHiTechnicGyro)
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
#include "C:\Users\Administrator\Documents\GitHub\Team772\Auto.h"
//Constants
#include "C:\Users\Administrator\Documents\GitHub\Team772\constants.h"

//Useful functions
#include "C:\Users\Administrator\Documents\GitHub\Team772\common.h"

//Music player
#include "C:\Users\Administrator\Documents\GitHub\Team772\Player.h"

void executeGrab() {
		//bring the medium goal back to the parking zone
		drive(11800);
		grabGoal();
		turnGyro(1200);
				if(getGyroNumber() > 650){		//Only continue the program if the gyro value is greater than 630
						drive(-10700);
						turn(5500);
						releaseGoal();
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

	wait10Msec(DELAY * 100);

 	executeGrab();

}
