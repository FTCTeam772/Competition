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

void turn(int cclockwise) {
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; //Reset encoders
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = sgn(cclockwise) * DRIVE_HIGH; //Drive wheels clockwise
	while(abs(nMotorEncoder[FrontLeft]) < abs(cclockwise) || abs(nMotorEncoder[FrontRight]) < abs(cclockwise) || abs(nMotorEncoder[BackLeft]) < abs(cclockwise) || abs(nMotorEncoder[BackRight]) < abs(cclockwise)); //Wait until all of the wheels reach encoderCount
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0; //Stop wheels
}

void move(int left_diag, int right_diag) {
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0; //Reset encoders
	motor[FrontLeft] = sgn(right_diag) * DRIVE_HIGH; //Set wheels
	motor[FrontRight]= sgn(left_diag) * DRIVE_HIGH;
	motor[BackLeft] = -sgn(left_diag) * DRIVE_HIGH;
	motor[BackRight] = -sgn(right_diag) * DRIVE_HIGH;
	while(abs(nMotorEncoder[FrontLeft]) < abs(right_diag) || abs(nMotorEncoder[FrontRight]) < abs(left_diag) || abs(nMotorEncoder[BackLeft]) < abs(left_diag) || abs(nMotorEncoder[BackRight]) < abs(right_diag)); //Wait until encoder count is reached
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0; //Stop wheels
}

void moveLeftArm(int shoulder, int elbow) {
	while(abs(nMotorEncoder[LeftArmShoulder] - shoulder) > ENCODER_PRECISION || abs(nMotorEncoder[LeftArmElbow] - elbow) > ENCODER_PRECISION) {
		motor[LeftArmShoulder] = targetMotorSpeed(shoulder, nMotorEncoder[LeftArmShoulder]) * ARM_HIGH;
		motor[LeftArmElbow] = targetMotorSpeed(elbow, nMotorEncoder[LeftArmElbow]) * ARM_LOW;
	}
	motor[LeftArmShoulder] = motor[LeftArmElbow] = 0;
}

void moveRightArm(int shoulder, int elbow) {
	while(abs(nMotorEncoder[RightArmShoulder] - shoulder) > ENCODER_PRECISION || abs(nMotorEncoder[RightArmElbow] - elbow) > ENCODER_PRECISION) {
		motor[RightArmShoulder] = targetMotorSpeed(shoulder, nMotorEncoder[RightArmShoulder]) * ARM_HIGH;
		motor[RightArmElbow] = targetMotorSpeed(elbow, nMotorEncoder[RightArmElbow]) * ARM_LOW;
	}
	motor[RightArmShoulder] = motor[RightArmElbow] = 0;
}
