#include "drivers/hitechnic-sensormux.h"
#include "drivers/hitechnic-irseeker-v2.h"

const tMUXSensor IR_left = msensor_S4_1;
const tMUXSensor IR_right = msensor_S4_2;

void initialize() {
	//Initialize motors and encoders
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = motor[LeftSlide] = motor[RightSlide] = 0; //Turn off the motors
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = nMotorEncoder[LeftSlide] = nMotorEncoder[RightSlide] = 0; //Might as well reset the encoders too
	servo[leftGrab] = 0;
	servo[rightGrab] = 270;
	//Display the robot's name
	nxtDisplayCenteredTextLine(0, "Rock 1.3");
}

float targetMotorSpeed(int target, int current) {
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
		nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; 	//Reset encoders
		while((abs(nMotorEncoder[FrontLeft] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[FrontRight] + amount) > ENCODER_PRECISION) && (abs(nMotorEncoder[BackLeft] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[BackRight] + amount) > ENCODER_PRECISION)) {
				motor[FrontLeft] = motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
		}
		motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0;
}

void halfDrive(float amount) {
		nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; 	//Reset encoders
		while((abs(nMotorEncoder[FrontLeft] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[FrontRight] + amount) > ENCODER_PRECISION) && (abs(nMotorEncoder[BackLeft] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[BackRight] + amount) > ENCODER_PRECISION)) {
				motor[FrontLeft] = motor[BackLeft] = DRIVE_LOW * ANDYMARK_CONVERSION * sgn(amount);
				motor[FrontRight] = motor[BackRight] = DRIVE_LOW * ANDYMARK_CONVERSION * sgn(amount);
		}
		motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0;
}

void turnBy(float amount){
		float originalValue = SensorValue[Compass];
		while(abs(SensorValue[Compass] - originalValue) > ANGLE_PRECISION){
			if(SensorValue[Compass] - originalValue > ANGLE_PRECISION){						//turn left
				motor[FrontLeft] = motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION;
			}
			else {		//turn right
				motor[FrontLeft] = motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION;
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
			}
		}
}

void turn(float amount){		//If amount is positive, a right turn is made.
		nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; 	//Reset encoders
		while((abs(nMotorEncoder[FrontLeft] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[FrontRight] - amount) > ENCODER_PRECISION) && (abs(nMotorEncoder[BackLeft] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[BackRight] - amount) > ENCODER_PRECISION)) {
				motor[FrontLeft] = motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * -sgn(amount);
		}
		motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0;
}

void oneSideTurn(float amount, bool leftWheel){
		nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; 	//Reset encoders
		if(leftWheel == true){
			while(abs(nMotorEncoder[FrontLeft] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[BackLeft] + amount) > ENCODER_PRECISION) {
				motor[FrontLeft] = motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
			}
		}
		if(leftWheel == false){
			while(abs(nMotorEncoder[FrontRight] + amount) > ENCODER_PRECISION && abs(nMotorEncoder[BackRight] + amount) > ENCODER_PRECISION) {
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * sgn(amount);
			}
		}
		motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0;
}

void wait() {
	wait10Msec(WAIT);
}

void liftScore(int targetHeight){
		while(abs(nMotorEncoder[LeftSlide] - targetHeight) > ENCODER_PRECISION || abs(nMotorEncoder[RightSlide] - targetHeight) > ENCODER_PRECISION){
			motor[LeftSlide] = targetMotorSpeed(targetHeight, nMotorEncoder[LeftSlide]) * SLIDE_LOW * ANDYMARK_CONVERSION;
			motor[RightSlide] = targetMotorSpeed(targetHeight, nMotorEncoder[RightSlide]) * SLIDE_LOW * ANDYMARK_CONVERSION;
		}
		motor[LeftSlide] = motor[RightSlide] = 0;		//Stop lift motors after they have reached the desired height

		halfDrive(500);
		wait();
		wait();
		servo[zipties] = 200;		//Score balls
		wait10Msec(ZIPTIE_WAIT);
		servo[zipties] = 128;			//Stop servo after wait

		halfDrive(-700);

		while(nMotorEncoder[LeftSlide] > ENCODER_PRECISION || nMotorEncoder[RightSlide] > ENCODER_PRECISION){
			motor[LeftSlide] = targetMotorSpeed(0, nMotorEncoder[LeftSlide]) * SLIDE_LOW * ANDYMARK_CONVERSION;
			motor[RightSlide] = targetMotorSpeed(0, nMotorEncoder[RightSlide]) * SLIDE_LOW * ANDYMARK_CONVERSION;
		}

		motor[LeftSlide] = motor[RightSlide] = 0;		//Stop motors

}
