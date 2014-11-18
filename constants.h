//Flags
#define NONLINEARTARGET

//Controller constants
#define DEADBAND 15

//Scaling
#define DRIVE_HIGH 100
#define DRIVE_LOW 40
#define SLIDE_HIGH 100
#define SLIDE_LOW 40

//Robot Constants
#define ENCODER_PRECISION 60
#define ANGLE_PRECISION 3
#define ANDYMARK_CONVERSION -78.0/100.0
#define SLIDE_TOP 28000       //Needs to be calibrated
#define SLIDE_BOTTOM 0

//Presets (all must be calibrated)
#define LOW_GOAL 7000
#define MEDIUM_GOAL 14000
#define HIGH_GOAL 21000
#define CENTER_GOAL 28000
//Autonomous
#define WAIT 30
#define RAMP true    //Will the robot start on the ramp?
#define DEF true     //Will the robot do defense?
#define KICK true    //Will the robot knock down the kick stand?
#define CENTER true  //Will the robot go for the center goal?
#define ROLLING 0    //Which rolling goal will the robot go for?  (0 = no rolling goals, 1 = medium goal only, 2 = tall goal only, 3 = both goals)
