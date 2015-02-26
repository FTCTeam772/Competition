#include "JoystickDriver.c"

//Constants
#include "constants.h"

//Useful functions
#include "common.h"

//Music player
#include "Player.h"

void kickCenter(bool kick, bool center){

		if (RAMP == true && center == true){		//Correct if the robot started on the ramp
			turn(-3500);
			drive(-800);
			turn(3500);
    }

    //Get IR Values
		int distance = 1;

		if ((SensorValue[Ultrasonic] - 52) <= ULTRASONIC_PRECISION) { //center goal is facing the box
			distance = 0;
		}
		else if ((SensorValue[Ultrasonic] - 71) <= ULTRASONIC_PRECISION) { //center goal is facing toward the side of the ramp
			distance = 2;
		}

		if (center == true) {
			//run kickstand method for ramp start

			if (distance == 0) { //center goal is facing the box
				//score in the centergoal
				turn(-2000);
				drive(-2500);
				turn(-2200);
				drive(2100);
				liftScoreCenter();

				if (kick == true){
					//knock over kickstand

				}
			}

			if (distance == 1) { //center goal is facing at a 45 degree angle
				//score in the centergoal
				turn(-1200);
				drive(-5000);
				turn(-3500);
				drive(-500);
				liftScoreCenter();

				if (kick == true){
					//knock over kickstand

				}
			}

			if (distance == 2) { //center goal is facing toward the side of the ramp
				//score in the centergoal
				turn(-1400);
				drive(-7300);
				turn(-2200);
				liftScoreCenter();

				if (kick == true){
					//knock over kickstand

				}
			}
		}

		if (kick == true){		//center is false & kickstand is true

			if (distance == 0) { //center goal is facing the box
				//knock over kickstand
				turn(1000);
				drive(-1500);
				turn(-1500);
				drive(-5000);
			}

			if (distance == 1) { //center goal is facing at a 45 degree angle
				//knock over kickstand
				drive(-700);
				oneSideTurn(-2200, false);
				drive(-3000);
			}

			if (distance == 2) { //center goal is facing toward the side of the ramp
				//knock over kickstand
				drive(-1800);
				turn(-3500);
				drive(-2000);
			}
		}
	}


void execute(bool ramp, bool def, bool kick, bool center, int roll) {

		if (ramp == true) {			//If starting from ramp

			if (roll == 1) {
				//score in medium goal and bring it back to parking zone
				drive(11800);
				oneSideTurn(300, false);
				setGrabbers();
				liftScore(MEDIUM_GOAL);
				grabGoal();
				turnGyro(1100);
				
				if(getGyroNumber() > 630){		//Only continue the program if the gyro value is greater than 630
						drive(-10700);
						turn(5500);
						releaseGoal();
						drive(-750);
						goHome();
					}
				}
			kickCenter(kick, center);
		}

		if (ramp == false) {

			if (def == true) {
				//run defense program for floor beginning
				oneSideTurn(-1000, true);
				drive(-8000);
			}
			if (def == false) {

				if (roll == 0) {		//If not scoring in rolling goals
					drive(-3000);
					wait();
					wait();
				}

				if (roll == 1) {
					//score in medium goal and bring it back
					drive(1600);
					turn(1050);
					drive(11300);
					setGrabbers();
					liftScore(MEDIUM_GOAL);
					grabGoal();
					wait();
					drive(-8300);
					turn(6800);
					releaseGoal();
				}
				if (roll == 2) {
					//score in tallest goal and bring it back
					drive(1800);
					turn(1000);
					drive(8600);
					oneSideTurn(1300, true);
					drive(5000);
					setGrabbers();
					liftScore(HIGH_GOAL);
					grabGoal();
					wait();
					drive(-4500);
					oneSideTurn(-1500, true);
					drive(-7000);
					turn(9000);
					releaseGoal();
				}

				kickCenter(kick, center);
			}
		}
	}
