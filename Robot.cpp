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
#define minHorizontal -50.0
#define maxHorizontal 50.0


Servo sRFK(RFK, false, 1457, minKnee, maxKnee);
Servo sRFV(RFV, true, 1439, minVertical, maxVertical);
Servo sRFH(RFH, false, 1492, minHorizontal, maxHorizontal);
// Horizontal PWM Forward: 990
// Horizontal PWM Side: 1994
// Calculated 45

Servo sRMK(RMK, false, 1590, minKnee, maxKnee);
Servo sRMV(RMV, true, 1529, minVertical, maxVertical);
Servo sRMH(RMH, false, 1546, minHorizontal, maxHorizontal); // Calibrated by straight line.

Servo sRBK(RBK, false, 1420, minKnee, maxKnee);  //*
Servo sRBV(RBV, true, 1536, minVertical, maxVertical);
Servo sRBH(RBH, false, 1548, minHorizontal, maxHorizontal); //*
// Horizontal PWM Forward: 2044
// Horizontal PWM Side: 1052
// Calculated 45


Servo sLFK(LFK, true, 1583, minKnee, maxKnee);
Servo sLFV(LFV, false, 1404, minVertical, maxVertical); //*
Servo sLFH(LFH, false, 1585, minHorizontal, maxHorizontal);
// Horizontal PWM Forward: 2075
// Horizontal PWM Side: 1096
// Calculated 45

Servo sLMK(LMK, true, 1435, minKnee, maxKnee);
Servo sLMV(LMV, false, 1466, minVertical, maxVertical);
Servo sLMH(LMH, false, 1511, minHorizontal, maxHorizontal); // Calibrated by straight line.

Servo sLBK(LBK, true, 1516, minKnee, maxKnee);
Servo sLBV(LBV, false, 1493, minVertical, maxVertical);
Servo sLBH(LBH, false, 1484, minHorizontal, maxHorizontal); //*
// Horizontal PWM Forward: 994
// Horizontal PWM Side: 1975
// Calculated 45 - (1484) This hip has a dodgy servo.
// The others front and back horizontal servos liked the calibration technique of
// averaging the front and side (45 degrees each way) PWM values.
// This is a dodgy servo. It makes funny clicking noises...
// Luckily, I have a spare replacement from before. I'll fit that some other day... 
// For now, just get approximate recal for the 45 degrees...

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
Leg legRF(XPOS, YPOS, &sRFK, &sRFV, &sRFH, 45.0, RX, FY, Z);
Leg legRM(XPOSM, 0, &sRMK, &sRMV, &sRMH, 90.0, RMX, MY, Z);
Leg legRB(XPOS, -YPOS, &sRBK, &sRBV, &sRBH, 135.0, RX, BY, Z);

Leg legLB(-XPOS, -YPOS, &sLBK, &sLBV, &sLBH, -135.0, LX, BY, Z);
Leg legLM(-XPOSM, 0, &sLMK, &sLMV, &sLMH, -90.0, LMX, MY, Z);
Leg legLF(-XPOS, YPOS, &sLFK, &sLFV, &sLFH, -45.0, LX, FY, Z);


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
  legLF.SetNatural(Time);
  legLM.SetNatural(Time);
  legLB.SetNatural(Time);
  legRF.SetNatural(Time);
  legRM.SetNatural(Time);
  legRB.SetNatural(Time);
}


// Centre all servos on PWM ABSOLUTE_MIDDLE.
void CenterAll(int Time)
{
  legLF.SetCenter(Time);
  legLM.SetCenter(Time);
  legLB.SetCenter(Time);
  legRF.SetCenter(Time);
  legRM.SetCenter(Time);
  legRB.SetCenter(Time);
}


#ifdef DEBUG


void ReportRobot()
{
  P("\nReport Robot status");

//  legLF.ReportLeg("Left Front");
//  legLM.ReportLeg("Left Middle");
//  legLB.ReportLeg("Left Back");
  legRF.ReportLeg("Right Front");
//  legRM.ReportLeg("Right Middle");
//  legRB.ReportLeg("Right Back");
}


#endif // DEBUG


// END //
