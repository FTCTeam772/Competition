//Flags
#define NONLINEARTARGET

//Controller constants
#define DEADBAND 15

//Scaling
#define DRIVE_HIGH 100
#define DRIVE_LOW 40
#define SLIDE_HIGH -100
#define SLIDE_LOW -70

//Robot Constants
#define ENCODER_PRECISION 60
#define ANGLE_PRECISION 3
#define ANDYMARK_CONVERSION -78.0/100.0
#define SLIDE_TOP 40000       //Needs to be calibrated
#define SLIDE_BOTTOM 0
#define CONT_SERVO_CENTER 128

//Presets (all must be calibrated)
#define LOW_GOAL 15000
#define MEDIUM_GOAL 24000
#define HIGH_GOAL 32000
#define CENTER_GOAL 40000
//Autonomous
#define WAIT 30
#define ZIPTIE_WAIT 120
#define RAMP false    //Will the robot start on the ramp?
#define DEF false     //Will the robot do defense?
#define KICK true    //Will the robot knock down the kick stand?
#define CENTER true  //Will the robot go for the center goal?
#define ROLLING 0    //Which rolling goal will the robot go for?  (0 = no rolling goals, 1 = medium goal only, 2 = high goal only, 3 = both goals)
