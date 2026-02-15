// Main Robot functions go here...

#include "Robot.h"


Matrix3D robotRotationMatrix;
float robotRotationAxisX;
float robotRotationAxisY;
float robotRotationAxisZ;
float robotRotation;


//>>> FUNCTION to set all servos at once.
//>>> FUNCTIONS to query SSC...

// >>> Add ALL feet move (delta) at once and check ALL feet positions are valid!!!

// Knee: Min retracted, Max extended
// Vertical: Min down, Max up
// Horizontal: Min CCW, Max CW

#define minKnee -70.0
#define maxKnee 80.0
#define minVertical -80.0
#define maxVertical 80.0
#define minHorizontal -45.0
#define maxHorizontal 45.0

Servo sRFK(RFK, false, 1514, minKnee, maxKnee);
Servo sRFV(RFV, true, 1428, minVertical, maxVertical);
Servo sRFH(RFH, false, 1487, minHorizontal, maxHorizontal);

Servo sRMK(RMK, false, 1523, minKnee, maxKnee);
Servo sRMV(RMV, true, 1507, minVertical, maxVertical);
Servo sRMH(RMH, false, 1535, minHorizontal, maxHorizontal);

Servo sRBK(RBK, false, 1455, minKnee, maxKnee);
Servo sRBV(RBV, true, 1531, minVertical, maxVertical);
Servo sRBH(RBH, false, 1368, minHorizontal, maxHorizontal);


Servo sLFK(LFK, true, 1516, minKnee, maxKnee);
Servo sLFV(LFV, false, 1427, minVertical, maxVertical);
Servo sLFH(LFH, false, 1593, minHorizontal, maxHorizontal);

Servo sLMK(LMK, true, 1469, minKnee, maxKnee);
Servo sLMV(LMV, false, 1478, minVertical, maxVertical);
Servo sLMH(LMH, false, 1500, minHorizontal, maxHorizontal);

Servo sLBK(LBK, true, 1540, minKnee, maxKnee);
Servo sLBV(LBV, false, 1488, minVertical, maxVertical);
Servo sLBH(LBH, false, 1327, minHorizontal, maxHorizontal);


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


void SetRobotAxisAndRotation(float x, float y, float z, float angle)
{
  robotRotationAxisX = x;
  robotRotationAxisY = y;
  robotRotationAxisZ = z;
  NormaliseXYZ(&robotRotationAxisX, &robotRotationAxisY, &robotRotationAxisZ);

  Construct3DRotationMatrix(&robotRotationMatrix, robotRotationAxisX, robotRotationAxisY, robotRotationAxisZ, angle);

  robotRotation = angle;
}

void NaturalAll(int Time)
{
  lLF.SetNatural(Time);
  lLM.SetNatural(Time);
  lLB.SetNatural(Time);
  lRF.SetNatural(Time);
  lRM.SetNatural(Time);
  lRB.SetNatural(Time);
}


#ifdef DEBUG


void ReportRobot()
{
  P("\nReport Robot status");

//  lLF.ReportLeg("Left Front");
//  lLM.ReportLeg("Left Middle");
//  lLB.ReportLeg("Left Back");
  lRF.ReportLeg("Right Front");
//  lRM.ReportLeg("Right Middle");
//  lRB.ReportLeg("Right Back");
}


#endif // DEBUG


// END //
