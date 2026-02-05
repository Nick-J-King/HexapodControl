// Main Robot stuff.

#include "Servo.h"
#include "Leg.h"

#include "Tests.h"
#include "Utils.h"

// >>> MAKE THIS A CLASS

#define T 200
#define D 1000
#define BLD 2000


// PWM values.
#define ABSOLUTE_MIN 600      // Never go above this. (500)
#define ABSOLUTE_MAX 2400     // Never go below this. (2500)
#define ABSOLUTE_MIDDLE 1500  // Servo centered position.

#define PWMPERDEGREE (2030.0 / 180.0)


// Pin values on servo conroller (Knee, Vertical, Horizontal = Hip):

// Right Front
#define RFK 0
#define RFV 1
#define RFH 2

// Right Middle
#define RMK 7
#define RMV 6
#define RMH 5

// Right Back
#define RBK 10
#define RBV 11
#define RBH 12

// Left Forward
#define LFK 31
#define LFV 30
#define LFH 29

// Left Middle
#define LMK 24
#define LMV 25
#define LMH 26

// Left Back
#define LBK 21
#define LBV 20
#define LBH 19


// Position of "hip" axis from centre (0, 0).
#define XPOS 39.5     // For front & back, right (+ve) & left (-ve)
#define XPOSM 64.3    // For middle, right (+ve) & left (-ve)
#define YPOS 74.5     // For front (+ve) & back (-ve)

#define HIPWIDTH 28.0   // 28.0 mm from Hip vertical axis to Vertical servo axis.
#define FEMURLENGTH 85.5
#define TIBIALENGTH 125.0

extern Servo sRFK;
extern Servo sRFV;
extern Servo sRFH;

extern Servo sRMK;
extern Servo sRMV;
extern Servo sRMH;

extern Servo sRBK;
extern Servo sRBV;
extern Servo sRBH;


extern Servo sLFK;
extern Servo sLFV;
extern Servo sLFH;

extern Servo sLMK;
extern Servo sLMV;
extern Servo sLMH;

extern Servo sLBK;
extern Servo sLBV;
extern Servo sLBH;


extern Leg lLF;
extern Leg lRF;
extern Leg lRM;
extern Leg lRB;
extern Leg lLB;
extern Leg lLM;


// END
