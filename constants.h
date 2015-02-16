//Flags
#define NONLINEARTARGET

//Controller constants
#define DEADBAND 15

//Scaling
#define DRIVE_HIGH 100
#define DRIVE_LOW 40
#define SLIDE_HIGH -100
#define SLIDE_LOW -50
#define BUMP 15

//Robot Constants
#define ENCODER_PRECISION 80
#define ULTRASONIC_PRECISION 6
#define ANDYMARK_CONVERSION -78.0/100.0
#define SLIDE_TOP 8800
#define SLIDE_BOTTOM 0

//Presets
#define GOAL_GRAB_LIFT 750
#define LOW_GOAL 2400
#define MEDIUM_GOAL 4600
#define HIGH_GOAL 6700
#define CENTER_GOAL 8500
#define LEFT_GRAB_UP 220
#define RIGHT_GRAB_UP 0
#define LEFT_GRAB_DOWN 45
#define RIGHT_GRAB_DOWN 180

//Autonomous
#define DELAY 0     //Delay at beginning of autonomous
#define WAIT 30       //Used in wait()
#define ZIPTIE_WAIT 170
#define RAMP false    //Will the robot start on the ramp?
#define DEF true     //Will the robot play defence?
#define KICK false    //Will the robot knock down the kick stand?
#define CENTER false  //Will the robot attempt to score in center goal?
#define ROLLING 0    //Which rolling goal will the robot go for?  (0 = no rolling goals, 1 = medium goal only, 2 = high goal only)
