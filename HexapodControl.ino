// Servo Controller for Hexapod
//
// Written by NJK, 2026

#include "Robot.h"


void setup()
{
  Serial.begin(115200);
  delay(1000);

  SetRobotPosition0(0);     // Start in "natural" pose.
  delay(1000);
/*
  sRFH.PositionAngle(45, 500);
  delay(10000);
  sRFH.PositionAngle(-45, 500);
  delay(10000);
  sRFH.PositionAngle(0, 500);
  delay(1000);
  
  sLFH.PositionAngle(45, 500);
  delay(10000);
  sLFH.PositionAngle(-45, 500);
  delay(10000);
  sLFH.PositionAngle(0, 500);
  delay(1000);
*/
/*
  SetRobotPosition1(1000);  // Start to move by lifting tripod A in neutral position
  delay(2000);
*/
  //CenterAllPWM(0);
  //delay(1000);
  
  //NaturalAllPWM(1000);
}


#define T1 100
#define D1 150
#define T2 400
#define D2 450

void loop()
{
  /*
  SetRobotPositionA(1000);
  delay(2000);

  SetRobotPositionB(1000);
  delay(2000);
*/

/*
  SetRobotPositionC(1000);  // FWD
  delay(2000);

  SetRobotPositionD(1000);  // BKW
  delay(2000);
*/

  // Walking loop
  SetRobotPosition2(T2);
  delay(D2);
  SetRobotPosition3(T1);
  delay(D1);
  SetRobotPosition4(T1);
  delay(D1);

  SetRobotPosition5(T2);
  delay(D2);
  SetRobotPosition6(T1);
  delay(D1);
  SetRobotPosition7(T1);
  delay(D1);
}


// Natural (resting) pose.
void SetRobotPosition0(int Time)
{
  lRF.SetFootNatural(Time);
  lRM.SetFootNatural(Time);
  lRB.SetFootNatural(Time);
  
  lLF.SetFootNatural(Time);
  lLM.SetFootNatural(Time);
  lLB.SetFootNatural(Time);
}


// Legs down
void SetRobotPositionA(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, 0.0, 30.0, Time);  // A
  lRM.SetFootNaturalDelta(0.0, 0.0, 30.0, Time);
  lRB.SetFootNaturalDelta(0.0, 0.0, 30.0, Time);  // A

  // Left
  lLF.SetFootNaturalDelta(0.0, 0.0, 30.0, Time);
  lLM.SetFootNaturalDelta(0.0, 0.0, 30.0, Time);  // A
  lLB.SetFootNaturalDelta(0.0, 0.0, 30.0, Time);
}


// Legs up
void SetRobotPositionB(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, 0.0, -30.0, Time);  // A
  lRM.SetFootNaturalDelta(0.0, 0.0, -30.0, Time);
  lRB.SetFootNaturalDelta(0.0, 0.0, -30.0, Time);  // A

  // Left
  lLF.SetFootNaturalDelta(0.0, 0.0, -30.0, Time);
  lLM.SetFootNaturalDelta(0.0, 0.0, -30.0, Time);  // A
  lLB.SetFootNaturalDelta(0.0, 0.0, -30.0, Time);
}


// Legs fwd
void SetRobotPositionC(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, 40.0, -20.0, Time);  // A
  lRM.SetFootNaturalDelta(0.0, 40.0, -20.0, Time);
  lRB.SetFootNaturalDelta(0.0, 40.0, -20.0, Time);  // A

  // Left
  lLF.SetFootNaturalDelta(0.0, 40.0, -20.0, Time);
  lLM.SetFootNaturalDelta(0.0, 40.0, -20.0, Time);  // A
  lLB.SetFootNaturalDelta(0.0, 40.0, -20.0, Time);
}


// Legs back
void SetRobotPositionD(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, -40.0, -20.0, Time);  // A
  lRM.SetFootNaturalDelta(0.0, -40.0, -20.0, Time);
  lRB.SetFootNaturalDelta(0.0, -40.0, -20.0, Time);  // A

  // Left
  lLF.SetFootNaturalDelta(0.0, -40.0, -20.0, Time);
  lLM.SetFootNaturalDelta(0.0, -40.0, -20.0, Time);  // A
  lLB.SetFootNaturalDelta(0.0, -40.0, -20.0, Time);
}


#define Z0 -15 // On ground
#define Z1 -25  // Lifted a bit
#define Z2 -30  // Lifted more

#define S 20 // Stride length


// Lift Tripod A a bit, relatively to Tripod B. Get into a general "crouch".
void SetRobotPosition1(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, 0.0, Z1, Time); // A
  lRM.SetFootNaturalDelta(0.0, 0.0, Z0, Time);
  lRB.SetFootNaturalDelta(0.0, 0.0, Z1, Time); // A

  // Left
  lLF.SetFootNaturalDelta(0.0, 0.0, Z0, Time);
  lLM.SetFootNaturalDelta(0.0, 0.0, Z1, Time); // A
  lLB.SetFootNaturalDelta(0.0, 0.0, Z0, Time);
}


// Tripod A goes forward (20) and up a bit more (-15). Tripod B goes back (-20) on the ground.
void SetRobotPosition2(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, S, Z2, Time); // A
  lRM.SetFootNaturalDelta(0.0, -S, Z0, Time);
  lRB.SetFootNaturalDelta(0.0, S, Z2, Time); // A

  // Left
  lLF.SetFootNaturalDelta(0.0, -S, Z0, Time);
  lLM.SetFootNaturalDelta(0.0, S, Z2, Time); // A
  lLB.SetFootNaturalDelta(0.0, -S, Z0, Time);
}


// Tripod A comes down in forward pos (20), and Tripod B stays in back position (-20). MIDSTRIDE.
void SetRobotPosition3(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, S, Z0, Time);  // A
  lRM.SetFootNaturalDelta(0.0, -S, Z0, Time);
  lRB.SetFootNaturalDelta(0.0, S, Z0, Time);  // A

  // Left
  lLF.SetFootNaturalDelta(0.0, -S, Z0, Time);
  lLM.SetFootNaturalDelta(0.0, S, Z0, Time);  // A
  lLB.SetFootNaturalDelta(0.0, -S, Z0, Time);
}


// Tripod B comes up a bit (-10). MIDSTRIDE
void SetRobotPosition4(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, S, Z0, Time);  // A
  lRM.SetFootNaturalDelta(0.0, -S, Z1, Time);
  lRB.SetFootNaturalDelta(0.0, S, Z0, Time);  // A

  // Left
  lLF.SetFootNaturalDelta(0.0, -S, Z1, Time);
  lLM.SetFootNaturalDelta(0.0, S, Z0, Time);  // A
  lLB.SetFootNaturalDelta(0.0, -S, Z1, Time);
}


// Tripod B goes forward (20), and lifts a little more (-15). Tripod A goes backward (-20) on the ground.
void SetRobotPosition5(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, -S, Z0, Time); // A
  lRM.SetFootNaturalDelta(0.0, S, Z2, Time);
  lRB.SetFootNaturalDelta(0.0, -S, Z0, Time); // A

  // Left
  lLF.SetFootNaturalDelta(0.0, S, Z2, Time);
  lLM.SetFootNaturalDelta(0.0, -S, Z0, Time); // A
  lLB.SetFootNaturalDelta(0.0, S, Z2, Time);
}


// Tripod B comes down. MIDSTRIDE.
void SetRobotPosition6(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, -S, Z0, Time); // A
  lRM.SetFootNaturalDelta(0.0, S, Z0, Time);
  lRB.SetFootNaturalDelta(0.0, -S, Z0, Time); // A

  // Left
  lLF.SetFootNaturalDelta(0.0, S, Z0, Time);
  lLM.SetFootNaturalDelta(0.0, -S, Z0, Time); // A
  lLB.SetFootNaturalDelta(0.0, S, Z0, Time);
}


// Tripod A comes up a bit (10). MIDSTRIDE.
void SetRobotPosition7(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, -S, Z1, Time); // A
  lRM.SetFootNaturalDelta(0.0, S, Z0, Time);
  lRB.SetFootNaturalDelta(0.0, -S, Z1, Time); // A

  // Left
  lLF.SetFootNaturalDelta(0.0, S, Z0, Time);
  lLM.SetFootNaturalDelta(0.0, -S, Z1, Time); // A
  lLB.SetFootNaturalDelta(0.0, S, Z0, Time);
}


/*

void SetRobotPositionX(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(0.0, 0.0, 0.0, Time);
  lRM.SetFootNaturalDelta(0.0, 0.0, 0.0, Time);
  lRB.SetFootNaturalDelta(0.0, 0.0, 0.0, Time);

  // Left
  lLF.SetFootNaturalDelta(0.0, 0.0, 0.0, Time);
  lLM.SetFootNaturalDelta(0.0, 0.0, 0.0, Time);
  lLB.SetFootNaturalDelta(0.0, 0.0, 0.0, Time);
}

*/
