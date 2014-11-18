void initialize() {
	//Initialize motors and encoders
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = motor[LeftSlide] = motor[RightSlide] = 0; //Turn off the motors
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = nMotorEncoder[LeftSlide] = nMotorEncoder[RightSlide] = 0; //Might as well reset the encoders too

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

double updateXpos(double angle, double Xpos, double dist) {
	Xpos += (dist * cos(angle));
	return Xpos;

}

double updateYpos (double angle, double Ypos, double dist) {
	Ypos += (dist * sin (angle));
	return Ypos;

}

void move(double angle, double Xpos, double Ypos, double dist) {
		nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0;

		while(abs(nMotorEncoder[FrontLeft] - dist) > ENCODER_PRECISION || abs(nMotorEncoder[FrontRight] - dist) > ENCODER_PRECISION || abs(nMotorEncoder[BackLeft] - dist) > ENCODER_PRECISION || abs(nMotorEncoder[BackRight] - dist) > ENCODER_PRECISION) {
			motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor [BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * dist/(abs(dist));
		}

		motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor [BackRight] = 0;
		updateXpos(angle, Xpos, dist);
		updateYpos(angle, Ypos, dist);
}

void turn(double angle){
		while(abs(angle - SensorValue[Compass]) > ANGLE_PRECISION){
			if(angle - SensorValue[Compass] > ANGLE_PRECISION){		//turn left
				motor[FrontLeft] = motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION;
			}
			else {		//turn right
				motor[FrontLeft] = motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION;
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
			}
	}
}

double updateAngle (double angleOld, double angleNew){  //returns
	return angleNew - angleOld;
}

void wait() {
	wait10Msec(WAIT);
}
