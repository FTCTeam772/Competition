void initialize() {
	//Initialize motors and encoders
	motor[FrontLeft] = motor[FrontRight] = motor[BackLeft] = motor[BackRight] = motor[LeftSlide] = motor[RightSlide] = 0; //Turn off the motors
	nMotorEncoder[FrontLeft] = nMotorEncoder[FrontRight] = nMotorEncoder[BackLeft] = nMotorEncoder[BackRight] = nMotorEncoder[LeftSlide] = nMotorEncoder[RightSlide] = 0; //Might as well reset the encoders too
	SensorValue[Compass] = 0;		//NEED TO DO THIS DIFFERENTLY IT ALWAYS READ NORTH

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

void updatexPos(float angle, float Xpos, float dist){
	xPos += (dist * sin (angle));

	xPos = Xpos;
}

void updateyPos (float angle, float Ypos, float dist) {
	yPos += (dist * cos (angle));

	yPos = Ypos;
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

void turnTo(float newAngle){
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
}

void moveTo(float angle, float Xi, float Yi, float Xf, float Yf) {
	float theta = atan2((Xf - Xi),(Yf - Yi)) * (180.0 / PI);
	turnTo(theta);
	float dist = sqrt(pow(Xf - Xi, 2) + pow(Yf - Yi, 2));
	move(angle, Xi, Yi, dist);
}
float atan2(float x, float y){
  float phi;

   if (x>0) {phi=atan(y/x);}
   else
   if ((x<0)&&(y>=0))  {phi=PI+atan(y/x);}
   else
   if ((x<0)&&(y<0))   {phi=-PI+atan(y/x);}
   else
   if ((x==0)&&(y>0))  {phi=PI/2;}
   else
   if ((x==0)&&(y<0))  {phi=-PI/2;}
   else
   if ((x==0)&&(y==0)) {phi=0;}

   return phi;
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
		wait10Msec(ZIPTIE_WAIT);
		servo[zipties] = 0;			//Stop servo after wait

		while((nMotorEncoder[LeftSlide] > ENCODER_PRECISION && nMotorEncoder[RightSlide] > ENCODER_PRECISION)){
			motor[LeftSlide] = motor[RightSlide] = -SLIDE_HIGH * ANDYMARK_CONVERSION;		//Full power until they reach the home position
		}
		motor[LeftSlide] = motor[RightSlide] = 0;		//Stop motors
}
