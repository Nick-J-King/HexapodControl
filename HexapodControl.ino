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

  SetRobotPosition1(1000);  // Start to move by lifting tripod A in neutral position
  delay(2000);

  //NaturalAllPWM(1000);
  //CenterAllPWM(0);
  //delay(1000);
}


#define T1 100
#define D1 150
#define T2 400
#define D2 450

void loop()
{
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
  lRF.SetNatural(Time);
  lRM.SetNatural(Time);
  lRB.SetNatural(Time);
  
  lLF.SetNatural(Time);
  lLM.SetNatural(Time);
  lLB.SetNatural(Time);
}


#define Z0 -15 // On ground
#define Z1 -25  // Lifted a bit
#define Z2 -30  // Lifted more

#define S 20 // Stride length


// Lift Tripod A a bit, relatively to Tripod B. Get into a general "crouch", ready to start walking.
void SetRobotPosition1(int Time)
{
  // Right
  lRF.SetFootNatural(0.0, 0.0, Z1, Time); // A
  lRM.SetFootNatural(0.0, 0.0, Z0, Time);
  lRB.SetFootNatural(0.0, 0.0, Z1, Time); // A

  // Left
  lLF.SetFootNatural(0.0, 0.0, Z0, Time);
  lLM.SetFootNatural(0.0, 0.0, Z1, Time); // A
  lLB.SetFootNatural(0.0, 0.0, Z0, Time);
}


// Tripod A goes forward and up a bit more. Tripod B goes back on the ground, moving robot forward.
void SetRobotPosition2(int Time)
{
  // Right
  lRF.SetFootNatural(0.0, S, Z2, Time); // A
  lRM.SetFootNatural(0.0, -S, Z0, Time);
  lRB.SetFootNatural(0.0, S, Z2, Time); // A

  // Left
  lLF.SetFootNatural(0.0, -S, Z0, Time);
  lLM.SetFootNatural(0.0, S, Z2, Time); // A
  lLB.SetFootNatural(0.0, -S, Z0, Time);
}


// Tripod A comes down in forward pos, and Tripod B stays in back position. MIDSTRIDE.
void SetRobotPosition3(int Time)
{
  // Right
  lRF.SetFootNatural(0.0, S, Z0, Time);  // A
  lRM.SetFootNatural(0.0, -S, Z0, Time);
  lRB.SetFootNatural(0.0, S, Z0, Time);  // A

  // Left
  lLF.SetFootNatural(0.0, -S, Z0, Time);
  lLM.SetFootNatural(0.0, S, Z0, Time);  // A
  lLB.SetFootNatural(0.0, -S, Z0, Time);
}


// Tripod B comes up a bit. MIDSTRIDE.
void SetRobotPosition4(int Time)
{
  // Right
  lRF.SetFootNatural(0.0, S, Z0, Time);  // A
  lRM.SetFootNatural(0.0, -S, Z1, Time);
  lRB.SetFootNatural(0.0, S, Z0, Time);  // A

  // Left
  lLF.SetFootNatural(0.0, -S, Z1, Time);
  lLM.SetFootNatural(0.0, S, Z0, Time);  // A
  lLB.SetFootNatural(0.0, -S, Z1, Time);
}


// Tripod B goes forward, and lifts a little more. Tripod A goes backward on the ground, moving robot forward.
void SetRobotPosition5(int Time)
{
  // Right
  lRF.SetFootNatural(0.0, -S, Z0, Time); // A
  lRM.SetFootNatural(0.0, S, Z2, Time);
  lRB.SetFootNatural(0.0, -S, Z0, Time); // A

  // Left
  lLF.SetFootNatural(0.0, S, Z2, Time);
  lLM.SetFootNatural(0.0, -S, Z0, Time); // A
  lLB.SetFootNatural(0.0, S, Z2, Time);
}


// Tripod B comes down. MIDSTRIDE.
void SetRobotPosition6(int Time)
{
  // Right
  lRF.SetFootNatural(0.0, -S, Z0, Time); // A
  lRM.SetFootNatural(0.0, S, Z0, Time);
  lRB.SetFootNatural(0.0, -S, Z0, Time); // A

  // Left
  lLF.SetFootNatural(0.0, S, Z0, Time);
  lLM.SetFootNatural(0.0, -S, Z0, Time); // A
  lLB.SetFootNatural(0.0, S, Z0, Time);
}


// Tripod A comes up a bit. MIDSTRIDE.
void SetRobotPosition7(int Time)
{
  // Right
  lRF.SetFootNatural(0.0, -S, Z1, Time); // A
  lRM.SetFootNatural(0.0, S, Z0, Time);
  lRB.SetFootNatural(0.0, -S, Z1, Time); // A

  // Left
  lLF.SetFootNatural(0.0, S, Z0, Time);
  lLM.SetFootNatural(0.0, -S, Z1, Time); // A
  lLB.SetFootNatural(0.0, S, Z0, Time);
}


// END
