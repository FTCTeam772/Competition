void initialize() {
	//Initialize motors and encoders
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = motor[LeftSlide] = motor[RightSlide] = motor[LeftHand] = motor[RightHand] = 0; //Turn off the motors
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = nMotorEncoder[LeftSlide] = nMotorEncoder[RightSlide] = nMotorEncoder[LeftHand] = nMotorEncoder[RightHand] = 0; //Might as well reset the encoders too

	//Display the robot's name
	nxtDisplayCenteredTextLine(0, "Rock 0.5");
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

void turn(int cclockwise) {
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; //Reset encoders
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = sgn(cclockwise) * DRIVE_HIGH; //Drive wheels clockwise
	while(abs(nMotorEncoder[FrontLeft]) < abs(cclockwise) || abs(nMotorEncoder[FrontRight]) < abs(cclockwise) || abs(nMotorEncoder[BackLeft]) < abs(cclockwise) || abs(nMotorEncoder[BackRight]) < abs(cclockwise)); //Wait until all of the wheels reach encoderCount
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0; //Stop wheels
}

void move(int left_diag, int right_diag) {
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; //Reset encoders
	motor[FrontLeft] = -sgn(right_diag) * DRIVE_HIGH; //Set wheels
	motor[FrontRight] = sgn(left_diag) * DRIVE_HIGH;
	motor[BackLeft] = -sgn(left_diag) * DRIVE_HIGH;
	motor[BackRight] = sgn(right_diag) * DRIVE_HIGH;
	while(abs(nMotorEncoder[FrontLeft]) < abs(right_diag) || abs(nMotorEncoder[FrontRight]) < abs(left_diag) || abs(nMotorEncoder[BackLeft]) < abs(left_diag) || abs(nMotorEncoder[BackRight]) < abs(right_diag)); //Wait until all of the wheels reach their encoder count
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0; //Stop wheels
}

//void moveLeftArm(int shoulder, int elbow) {
	//While the shoulder and elbow are not within a certain amount
//	while(abs(nMotorEncoder[LeftArmShoulder] - shoulder) > ENCODER_PRECISION || abs(nMotorEncoder[LeftArmElbow] - elbow) > ENCODER_PRECISION) {
//		motor[LeftArmShoulder] = targetMotorSpeed(shoulder, nMotorEncoder[LeftArmShoulder]) * SLIDE_HIGH; //Shoulder goes ARM_HIGH
//		motor[LeftArmElbow] = targetMotorSpeed(elbow, nMotorEncoder[LeftArmElbow]) * SLIDE_LOW; //Elbow goes ARM_LOW
//	}
//	motor[LeftArmShoulder] = motor[LeftArmElbow] = 0; //Be sure the motors are stopped
//}

void openLeftHand() {
	motor[LeftHand] = HAND_HIGH;
	int interrupt = 0;
	while(nMotorEncoder[LeftHand] < HAND_MAX && interrupt < 300) { //Wait for hand to open or until a pseudo interrupt happens
		wait10Msec(1);
		interrupt++;
	}
	motor[LeftHand] = 0;
}

void closeLeftHand() {
	motor[LeftHand] = -HAND_HIGH;
	int interrupt = 0;
	while(nMotorEncoder[LeftHand] > HAND_MIN && interrupt < 300) { //Wait for hand to close
		wait10Msec(1);
		interrupt++;
	}
	motor[LeftHand] = 0;
}

void openRightHand() {
	motor[RightHand] = HAND_HIGH;
	int interrupt = 0;
	while(nMotorEncoder[RightHand] < HAND_MAX && interrupt < 300) { //Wait for hand to open or until a pseudo interrupt happens
		wait10Msec(1);
		interrupt++;
	}
	motor[RightHand] = 0;
}

void closeRightHand() {
	motor[RightHand] = -HAND_HIGH;
	int interrupt = 0;
	while(nMotorEncoder[RightHand] > HAND_MIN && interrupt < 300) { //Wait for hand to close
		wait10Msec(1);
		interrupt++;
	}
	motor[RightHand] = 0;
}

void wait() {
	wait10Msec(WAIT);
}
