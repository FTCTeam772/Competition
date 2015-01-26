#include "drivers/hitechnic-sensormux.h"
#include "drivers/hitechnic-irseeker-v2.h"

const tMUXSensor IR_left = msensor_S4_1;
const tMUXSensor IR_right = msensor_S4_2;

void initialize() {
	//Initialize motors and encoders
	motor[LeftWheels] = motor[FrontRight] = motor[BackRight] = motor[LeftSlide] = motor[RightSlide] = motor[zipties] = 0; //Turn off the motors
	nMotorEncoder[LeftWheels] = nMotorEncoder[FrontRight] = nMotorEncoder[BackRight] = nMotorEncoder[LeftSlide] = nMotorEncoder[RightSlide] = 0; //Might as well reset the encoders too
	servo[leftGrab] = LEFT_GRAB_UP;
	servo[rightGrab] = RIGHT_GRAB_UP;
	//Display the robot's name
	nxtDisplayCenteredTextLine(0, "Rock 1.5");
}

float targetMotorSpeed(int target, int current) {      //non-linear speed function using encoders
	#ifdef NONLINEARTARGET
	if(abs(current - target) > 400)
		return sgn(target - current);
	else if(abs(current - target) > ENCODER_PRECISION)
		return 2 * pow(cos(PI / 4 * (current - target + 400) / 400), 2) - 1;
	else
		return 0;
	#else
		return (abs(current - target) > ENCODER_PRECISION) ? 1 : 0;
	#endif
}

void drive(float amount) {
		nMotorEncoder[LeftWheels] = nMotorEncoder[FrontRight] = nMotorEncoder[BackRight] = 0; 	//Reset encoders
		while((abs(nMotorEncoder[LeftWheels] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[FrontRight] + amount) > ENCODER_PRECISION) && abs(nMotorEncoder[BackRight] + amount) > ENCODER_PRECISION) {
				motor[LeftWheels] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
		}
		motor[LeftWheels] = motor[FrontRight] = motor[BackRight] = 0;
}

void halfDrive(float amount) {
		nMotorEncoder[LeftWheels] = nMotorEncoder[FrontRight] = nMotorEncoder[BackRight] = 0; 	//Reset encoders
		while((abs(nMotorEncoder[LeftWheels] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[FrontRight] + amount) > ENCODER_PRECISION) && abs(nMotorEncoder[BackRight] + amount) > ENCODER_PRECISION) {
				motor[LeftWheels] = DRIVE_LOW * ANDYMARK_CONVERSION * sgn(amount);
				motor[FrontRight] = motor[BackRight] = DRIVE_LOW * ANDYMARK_CONVERSION * sgn(amount);
		}
		motor[LeftWheels] = motor[FrontRight] = motor[BackRight] = 0;
}

void turnBy(float amount){
		float originalValue = SensorValue[Compass];      //The value of the compass before the turn
		float targetValue = originalValue + amount;

		if(targetValue > 359){			//correct targetValue if it is too large
			targetValue = targetValue - 360;
		}
		else if(targetValue < 0){		//correct targetValue if it is too small
			targetValue = targetValue + 360;
		}

		if(abs(amount) <= 90){		//For small turns...

			while(abs(SensorValue[Compass] - targetValue) > SMALL_ANGLE_PRECISION){
				if(amount < 0){						//turn left (negative)
					motor[LeftWheels] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
					motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION;
				}
				else {		//turn right
					motor[LeftWheels] = DRIVE_HIGH * ANDYMARK_CONVERSION;
					motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
				}
			}
		}

		if(abs(amount) > 90){			//For large turns...

			while(abs(SensorValue[Compass] - targetValue) > LARGE_ANGLE_PRECISION){
				if(amount < 0){						//turn left (negative)
					motor[LeftWheels] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
					motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION;
				}
				else {		//turn right
					motor[LeftWheels] = DRIVE_HIGH * ANDYMARK_CONVERSION;
					motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
				}
			}
		}
}

void turn(float amount){		//If amount is positive, a right turn is made.
		nMotorEncoder[LeftWheels] = nMotorEncoder[FrontRight] = nMotorEncoder[BackRight] = 0; 	//Reset encoders
		while((abs(nMotorEncoder[LeftWheels] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[FrontRight] - amount) > ENCODER_PRECISION) && abs(nMotorEncoder[BackRight] - amount) > ENCODER_PRECISION) {
				motor[LeftWheels] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * -sgn(amount);
		}
		motor[LeftWheels] = motor[FrontRight] = motor[BackRight] = 0;
}

void releaseGoal(){          //Release the goal by putting the grabbers up
	servo[leftGrab] = LEFT_GRAB_UP;
	servo[rightGrab] = RIGHT_GRAB_UP;
}

void grabGoal(){             //Grab the goal by putting the grabbers down
	servo[leftGrab] = LEFT_GRAB_DOWN;
	servo[rightGrab] = RIGHT_GRAB_DOWN;
}

void setGrabbers(){          //The grabbers go to a middle position so lift doesn't hit it
	servo[leftGrab] = 140;
	servo[rightGrab] = 100;
}

void oneSideTurn(float amount, bool leftWheel){
		nMotorEncoder[LeftWheels] = nMotorEncoder[FrontRight] = nMotorEncoder[BackRight] = 0; 	//Reset encoders
		if(leftWheel == true){
			while(abs(nMotorEncoder[LeftWheels] + amount) > ENCODER_PRECISION) {
				motor[LeftWheels] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
			}
		}
		if(leftWheel == false){
			while(abs(nMotorEncoder[FrontRight] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[BackRight] + amount) > ENCODER_PRECISION) {
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
			}
		}
		motor[LeftWheels] = motor[FrontRight] = motor[BackRight] = 0;
}

void wait() {
	wait10Msec(WAIT);
}

void liftScore(int targetHeight){
		while(abs(nMotorEncoder[RightSlide] - targetHeight) > ENCODER_PRECISION){ //abs(nMotorEncoder[LeftSlide] - targetHeight) > ENCODER_PRECISION ||
			motor[LeftSlide] = SLIDE_HIGH * ANDYMARK_CONVERSION;		//targetMotorSpeed(targetHeight, nMotorEncoder[LeftSlide]) *
			motor[RightSlide] = SLIDE_HIGH * ANDYMARK_CONVERSION;		//targetMotorSpeed(targetHeight, nMotorEncoder[RightSlide]) *
		}
		motor[LeftSlide] = motor[RightSlide] = 0;		//Stop lift motors after they have reached the desired height

		halfDrive(500);
		wait();
		wait();
		motor[zipties] = DRIVE_HIGH;		//Score balls
		wait10Msec(ZIPTIE_WAIT);
		motor[zipties] = 0;			//Stop servo after wait

		halfDrive(-400);

		while(nMotorEncoder[LeftSlide] > ENCODER_PRECISION || (nMotorEncoder[RightSlide] - 100) > ENCODER_PRECISION){
			motor[LeftSlide] = -SLIDE_HIGH * ANDYMARK_CONVERSION;		//REMEMBER to take out negatives when >> is put back in targetMotorSpeed(0, nMotorEncoder[LeftSlide]) *
			motor[RightSlide] = -SLIDE_HIGH * ANDYMARK_CONVERSION;		//targetMotorSpeed(0, nMotorEncoder[RightSlide]) *
		}

		motor[LeftSlide] = motor[RightSlide] = 0;		//Stop motors

}
