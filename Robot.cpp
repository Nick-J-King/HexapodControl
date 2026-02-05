// Main Robot functions go here...

#include "Robot.h"

//>>> FUNCTION to set all servos at once.
//>>> FUNCTIONS to query SSC...


// Knee: Min retracted, Max extended
// Vertical: Min down, Max up
// Horizontal: Min CCW, Max CW

Servo sRFK(RFK, 1000, 2000, 1514);  //1489);
Servo sRFV(RFV, 2000, 1000, 1428);  //1466);  //1428);
Servo sRFH(RFH, 1000, 2000, 1499);  //1523);  // REV

Servo sRMK(RMK, 1000, 2000, 1523);  //1517);
Servo sRMV(RMV, 2000, 1000, 1507);  //1489);
Servo sRMH(RMH, 1000, 2000, 1513);  //1520);  // REV

Servo sRBK(RBK, 1000, 2000, 1455);  //1401);
Servo sRBV(RBV, 2000, 1000, 1531);  //1467);
Servo sRBH(RBH, 1000, 2000, 1538);  //1599);  // REV


Servo sLFK(LFK, 2000, 1000, 1516);  //1478);
Servo sLFV(LFV, 1000, 2000, 1427);  //1447);  //1400);
Servo sLFH(LFH, 1000, 2000, 1537);  //1670);

Servo sLMK(LMK, 2000, 1000, 1469);  //1445);
Servo sLMV(LMV, 1000, 2000, 1478);  //1489);
Servo sLMH(LMH, 1000, 2000, 1489);  //1501);

Servo sLBK(LBK, 2000, 1000, 1540);  //1570);
Servo sLBV(LBV, 1000, 2000, 1488);  //1526);
Servo sLBH(LBH, 1000, 2000, 1406);  //1379);


// 113.5 is HIPWIDTH + FEMURLENGTH
#define DO 113.5

// 80.25 is the width / height of square when that is the diagonal
#define DO2 80.25

#define RX (XPOS + DO2)
#define RMX (XPOSM + DO)
#define LX (-XPOS - DO2)
#define LMX (-XPOSM - DO)
#define FY (YPOS + DO2)
#define MY 0.0
#define BY (-YPOS - DO2)
#define Z TIBIALENGTH

// Give the leg the postion in frame, the servos, the natural angle of leg, and natural position of the feet.
Leg lRF(XPOS, YPOS, &sRFK, &sRFV, &sRFH, 45.0, RX, FY, Z);
Leg lRM(XPOSM, 0, &sRMK, &sRMV, &sRMH, 90.0, RMX, MY, Z);
Leg lRB(XPOS, -YPOS, &sRBK, &sRBV, &sRBH, 135.0, RX, BY, Z);

Leg lLB(-XPOS, -YPOS, &sLBK, &sLBV, &sLBH, -135.0, LX, BY, Z);
Leg lLM(-XPOSM, 0, &sLMK, &sLMV, &sLMH, -90.0, LMX, MY, Z);
Leg lLF(-XPOS, YPOS, &sLFK, &sLFV, &sLFH, -45.0, LX, FY, Z);


void NaturalAll(int Time)
{
  lLF.SetNatural(Time);
  lLM.SetNatural(Time);
  lLB.SetNatural(Time);
  lRF.SetNatural(Time);
  lRM.SetNatural(Time);
  lRB.SetNatural(Time);
}


// END
