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


float RX = XPOS + 80.25;
float RMX = XPOSM + 113.5;
float LX = -XPOS - 80.25;
float LMX = -XPOSM - 113.5;
float FY = YPOS + 80.25;
float MY = 0.0;
float BY = -YPOS - 80.25;
float Z = TIBIALENGTH;

// >>> USE ALL CONSTANTS, AND MAKE BETTER NAMES

Leg lRF(XPOS, YPOS, &sRFK, &sRFV, &sRFH, 45.0, RX, FY, Z);
Leg lRM(XPOSM, 0, &sRMK, &sRMV, &sRMH, 90.0, RMX, MY, Z);
Leg lRB(XPOS, -YPOS, &sRBK, &sRBV, &sRBH, 135.0, RX, BY, Z);

Leg lLB(-XPOS, -YPOS, &sLBK, &sLBV, &sLBH, -135.0, LX, BY, Z);
Leg lLM(-XPOSM, 0, &sLMK, &sLMV, &sLMH, -90.0, LMX, MY, Z);
Leg lLF(-XPOS, YPOS, &sLFK, &sLFV, &sLFH, -45.0, LX, FY, Z);


void CenterAllPWM(int Time)
{
  lLF.CenterPWM(Time);
  lLM.CenterPWM(Time);
  lLB.CenterPWM(Time);
  lRF.CenterPWM(Time);
  lRM.CenterPWM(Time);
  lRB.CenterPWM(Time);
}


void NaturalAllPWM(int Time)
{
  lLF.NaturalPWM(Time);
  lLM.NaturalPWM(Time);
  lLB.NaturalPWM(Time);
  lRF.NaturalPWM(Time);
  lRM.NaturalPWM(Time);
  lRB.NaturalPWM(Time);
}
