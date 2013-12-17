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
#define HAND_MAX 1400
#define HAND_MIN 0

//Presets
#define ARM_SHOULDER_PICKUP 26600
#define ARM_ELBOW_PICKUP 1800
#define ARM_SHOULDER_HANG 12500
#define ARM_ELBOW_HANG -700
#define ARM_SHOULDER_BASKET 14200
#define ARM_ELBOW_BASKET -1200

/* Selected Autonomous Program
 *
 * 0 - Left and IR
 * 1 - Left and no IR
 * 2 - Right and IR
 * 3 - Right and no IR
 */
#define AUTO_PROGRAM 0

//Autonomous
#define WAIT 100
#define AUTO_DETECT 12000
#define AUTO_IR_CORRECT -1100
#define AUTO_IR_TURN 900
