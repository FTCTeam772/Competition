void initialize() {
	//Initialize motors and encoders
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = motor[LeftSlide] = motor[RightSlide] = 0; //Turn off the motors
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = nMotorEncoder[LeftSlide] = nMotorEncoder[RightSlide] = 0; //Might as well reset the encoders too
	SensorValue[Compass] = 0;

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

void updateXpos(double angle, double Xpos, double dist){
	xPos += (dist * cos(angle));

}

void updateYpos (double angle, double Ypos, double dist) {
	yPos += (dist * sin (angle));

}

void move(double angle, double xPos, double yPos, double dist) {
		nMotorEncoder[FrontLeft] = 0;
		nMotorEncoder[FrontRight] = 0;
		nMotorEncoder[BackLeft] = 0;
		nMotorEncoder[BackRight] = 0;

		while(abs(nMotorEncoder[FrontLeft] - dist) > ENCODER_PRECISION || abs(nMotorEncoder[FrontRight] - dist) > ENCODER_PRECISION || abs(nMotorEncoder[BackLeft] - dist) > ENCODER_PRECISION || abs(nMotorEncoder[BackRight] - dist) > ENCODER_PRECISION) {
			motor[FrontLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION * dist/(abs(dist));
			motor[FrontRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * dist/(abs(dist));
			motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION * dist/(abs(dist));
			motor [BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * dist/(abs(dist));
		}

		motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0;
		updateXpos(angle, Xpos, dist);
		updateYpos(angle, Ypos, dist);
}

double turn(double newAngle, double oldAngle){
		while(abs(newAngle - SensorValue[Compass]) > ANGLE_PRECISION){
			if(newAngle - SensorValue[Compass] > ANGLE_PRECISION){						//turn left
				motor[FrontLeft] = motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION;
			}
			else {		//turn right
				motor[FrontLeft] = motor[BackLeft] = DRIVE_HIGH * ANDYMARK_CONVERSION;
				motor[FrontRight] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * -1;
			}
		}
		return newAngle;
}


void wait() {
	wait10Msec(WAIT);
}
