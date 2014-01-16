/* Selected Autonomous Program
 *
 * 0 - Left and IR
 * 1 - Left and no IR
 * 2 - Right and IR
 * 3 - Right and no IR
 */
#define AUTO_PROGRAM 3

//Flags
#define NONLINEARTARGET

//Controller constants
#define DEADBAND 15

//Scaling
#define DRIVE_HIGH 100
#define DRIVE_LOW 30
#define ARM_HIGH 100
#define ARM_LOW 30
#define HAND_HIGH 50

//Robot Constants
#define ENCODER_PRECISION 60
#define ARM_SHOULDER_TOP 28000
#define ARM_SHOULDER_BOTTOM 0
#define HAND_MAX 150
#define HAND_MIN 0

//Presets
#define ARM_SHOULDER_PICKUP 27000
#define ARM_ELBOW_PICKUP 2200
#define ARM_SHOULDER_HANG 12500
#define ARM_ELBOW_HANG -700
#define ARM_SHOULDER_BASKET 14200
#define ARM_ELBOW_BASKET -1200

//Autonomous
#define WAIT 30
//Autonomous Programs 0 and 2
#define AUTO_DETECT 10400
#define AUTO_IR_CORRECT -1500
#define AUTO_IR_TURN 900
#define AUTO_RAMP_1 1300
#define AUTO_RAMP_2 6100
#define AUTO_RAMP_TURN 1000
#define AUTO_RAMP_UP 3700
//Autonomous Programs 1 and 3
#define AUTO_FIRST_BASKET 2250
#define AUTO_RAMP 2150
#define AUTO_RAMP_OVER 6400
