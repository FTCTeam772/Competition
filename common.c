#include "constants.h"

float targetMotorSpeed(int target, int current) {
#ifdef NONLINEARTARGET
	if(abs(current - target) > 400)
		return sgn(target - current);
	else if(abs(current - target) > ENCODER_PRECISION)
		return 2 * pow(cos(PI / 4 * (current - target + 400) / 400), 2) - 1;
	else
		return 0;
#else
	return 1;
#endif
}

void turn(int clockwise) {
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; //Reset encoders
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = sgn(clockwise) * DRIVE_HIGH; //Drive wheels clockwise
	while(abs(nMotorEncoder[FrontLeft]) < abs(clockwise) || abs(nMotorEncoder[FrontRight]) < abs(clockwise) || abs(nMotorEncoder[BackLeft]) < abs(clockwise) || abs(nMotorEncoder[BackRight]) < abs(clockwise)); //Wait until all of the wheels reach encoderCount
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0; //Stop wheels
}

void move(int forward, int sideways) {
	/*
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; //Reset encoders
	float distance = sqrt(forward*forward + sideways*sideways); //Get total distance
	float y = forward / distance; //Get motor power based on distance
	float x = sideways / distance;
	motor[FrontLeft] = -y + x; //Set wheels
	motor[FrontRight]= -y + -x;
	motor[BackLeft] = y + x;
	motor[BackRight] = y + -x;
	while(); //Wait until ...
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0; //Stop wheels
	*/
}

void moveLeftArm(int shoulder, int elbow) {
	while(abs(nMotorEncoder[LeftArmShoulder] - shoulder) > ENCODER_PRECISION || abs(nMotorEncoder[LeftArmElbow] - elbow) > ENCODER_PRECISION) {
		motor[LeftArmShoulder] = targetMotorSpeed(shoulder, nMotorEncoder[LeftArmShoulder]) * ARM_HIGH;
		motor[LeftArmElbow] = targetMotorSpeed(elbow, nMotorEncoder[LeftArmElbow]) * ARM_LOW;
	}
}

void moveRightArm(int shoulder, int elbow) {
	while(abs(nMotorEncoder[RightArmShoulder] - shoulder) > ENCODER_PRECISION || abs(nMotorEncoder[RightArmElbow] - elbow) > ENCODER_PRECISION) {
		motor[RightArmShoulder] = targetMotorSpeed(shoulder, nMotorEncoder[RightArmShoulder]) * ARM_HIGH;
		motor[RightArmElbow] = targetMotorSpeed(elbow, nMotorEncoder[RightArmElbow]) * ARM_LOW;
	}
}
