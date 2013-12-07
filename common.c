#include "constants.h"

float targetMotorSpeed(float target, float current, float offset) {
#ifdef NONLINEARTARGET
	//return 100 * (1 - sqrt((1 / total) * (current - offset)));
	return cos(PI / 2 * (current - offset) / target);
	//return 100 * (1 + cos(PI * (current - offset) / target)) / 2;
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
	int shoulder_initial = nMotorEncoder[LeftArmShoulder];
	int elbow_initial = nMotorEncoder[LeftArmElbow];
	while(abs(nMotorEncoder[LeftArmShoulder] - shoulder) > ENCODER_PRECISION || abs(nMotorEncoder[LeftArmElbow] - elbow) > ENCODER_PRECISION) {
		motor[LeftArmShoulder] = targetMotorSpeed(shoulder, nMotorEncoder[LeftArmShoulder], shoulder_initial) * ARM_LOW;
		motor[LeftArmElbow] = targetMotorSpeed(elbow, nMotorEncoder[LeftArmElbow], elbow_initial) * ARM_LOW;
	}
}

void moveRightArm(int shoulder, int elbow) {
	int shoulder_initial = nMotorEncoder[RightArmShoulder];
	int elbow_initial = nMotorEncoder[RightArmElbow];
	while(abs(nMotorEncoder[RightArmShoulder] - shoulder) > ENCODER_PRECISION || abs(nMotorEncoder[RightArmElbow] - elbow) > ENCODER_PRECISION) {
		motor[RightArmShoulder] = targetMotorSpeed(shoulder, nMotorEncoder[RightArmShoulder], shoulder_initial) * ARM_LOW;
		motor[RightArmElbow] = targetMotorSpeed(elbow, nMotorEncoder[RightArmElbow], elbow_initial) * ARM_LOW;
	}
}
