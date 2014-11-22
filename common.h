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

float updatexPos(float angle, float xPos, float dist){
	xPos += (dist * cos(angle));
	
	return xPos;
}

float updateyPos (float angle, float yPos, float dist) {
	yPos += (dist * sin (angle));
	
	return yPos;
}

void move(float angle, float xPos, float yPos, float dist) {
		nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = 0;

		while(abs(nMotorEncoder[FrontLeft] - dist) > ENCODER_PRECISION || abs(nMotorEncoder[FrontRight] - dist) > ENCODER_PRECISION || abs(nMotorEncoder[BackLeft] - dist) > ENCODER_PRECISION || abs(nMotorEncoder[BackRight] - dist) > ENCODER_PRECISION) {
			motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = DRIVE_HIGH * ANDYMARK_CONVERSION * dist/(abs(dist));
		}

		motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = 0;
		updatexPos(angle, xPos, dist);
		updateyPos(angle, yPos, dist);
}

float turn(float newAngle, float oldAngle){
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

void liftScore(int targetHeight){
		while(abs(nMotorEncoder[LeftSlide] - targetHeight) > ENCODER_PRECISION && abs(nMotorEncoder[RightSlide] - targetHeight) > ENCODER_PRECISION){
			motor[LeftSlide] = motor[RightSlide] = SLIDE_HIGH * ANDYMARK_CONVERSION;		//Full power until they reach the desired encoder value
		}
		motor[LeftSlide] = motor[RightSlide] = 0;		//Stop lift motors after they have reached the desired height
		
		servo[zipties] = 100;		//Score balls
		wait();
		servo[zipties] = 0;			//Stop servo after wait
		
		while((nMotorEncoder[LeftSlide] > ENCODER_PRECISION && nMotorEncoder[RightSlide] > ENCODER_PRECISION)){
			motor[LeftSlide] = motor[RightSlide] = -SLIDE_HIGH * ANDYMARK_CONVERSION;		//Full power until they reach the home position
		}
		motor[LeftSlide] = motor[RightSlide] = 0;		//Stop motors
}
