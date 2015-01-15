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
#define ANGLE_PRECISION 2
#define ANDYMARK_CONVERSION -78.0/100.0
#define SLIDE_TOP 7000
#define SLIDE_BOTTOM 0

//Presets
#define LOW_GOAL 2000
#define MEDIUM_GOAL 4900
#define HIGH_GOAL 6700
#define CENTER_GOAL 7000
#define LEFT_GRAB_UP 0
#define RIGHT_GRAB_UP 290
#define LEFT_GRAB_DOWN 180
#define RIGHT_GRAB_DOWN 60

//Autonomous
#define WAIT 30
#define ZIPTIE_WAIT 170
#define RAMP false    //Will the robot start on the ramp?
#define DEF false     //Will the robot do defense?
#define KICK true    //Will the robot knock down the kick stand?
#define CENTER false  //Will the robot go for the center goal?
#define ROLLING 0    //Which rolling goal will the robot go for?  (0 = no rolling goals, 1 = medium goal only, 2 = high goal only)
