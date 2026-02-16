// Walk.cpp

#include "Robot.h"


#define T1 150  // QUICK motion
#define T2 500  // Slower motion.


// NOTE: Assume we started in Position0, and already did Position1...
void WalkLoop()
{
    // Walking loop
  SetRobotPosition2(T2);
  WaitForServos();

  SetRobotPosition3(T1);
  WaitForServos();

  SetRobotPosition4(T1);
  WaitForServos();

  SetRobotPosition5(T2);
  WaitForServos();

  SetRobotPosition6(T1);
  WaitForServos();

  SetRobotPosition7(T1);
  WaitForServos();
}


// Natural (resting) pose.
void SetRobotPosition0(int Time)
{
  /*
  legRF.SetNatural(Time);
  legRM.SetNatural(Time);
  legRB.SetNatural(Time);
  
  legLF.SetNatural(Time);
  legLM.SetNatural(Time);
  legLB.SetNatural(Time);
  */
  
  // Right
  legRF.SetFootNatural(0.0, 0.0, 0.0, Time); // A
  legRM.SetFootNatural(0.0, 0.0, 0.0, Time);
  legRB.SetFootNatural(0.0, 0.0, 0.0, Time); // A

  // Left
  legLF.SetFootNatural(0.0, 0.0, 0.0, Time);
  legLM.SetFootNatural(0.0, 0.0, 0.0, Time); // A
  legLB.SetFootNatural(0.0, 0.0, 0.0, Time);
}


#define Z0 -15 // On ground
#define Z1 -25  // Lifted a bit
#define Z2 -30  // Lifted more

#define S 20 // Stride length


// Lift Tripod A a bit, relatively to Tripod B. Get into a general "crouch", ready to start walking.
void SetRobotPosition1(int Time)
{
  // Right
  legRF.SetFootNatural(0.0, 0.0, Z1, Time); // A
  legRM.SetFootNatural(0.0, 0.0, Z0, Time);
  legRB.SetFootNatural(0.0, 0.0, Z1, Time); // A

  // Left
  legLF.SetFootNatural(0.0, 0.0, Z0, Time);
  legLM.SetFootNatural(0.0, 0.0, Z1, Time); // A
  legLB.SetFootNatural(0.0, 0.0, Z0, Time);
}


// Tripod A goes forward and up a bit more. Tripod B goes back on the ground, moving robot forward.
void SetRobotPosition2(int Time)
{
  // Right
  legRF.SetFootNatural(0.0, S, Z2, Time); // A
  legRM.SetFootNatural(0.0, -S, Z0, Time);
  legRB.SetFootNatural(0.0, S, Z2, Time); // A

  // Left
  legLF.SetFootNatural(0.0, -S, Z0, Time);
  legLM.SetFootNatural(0.0, S, Z2, Time); // A
  legLB.SetFootNatural(0.0, -S, Z0, Time);
}


// Tripod A comes down in forward pos, and Tripod B stays in back position. MIDSTRIDE.
void SetRobotPosition3(int Time)
{
  // Right
  legRF.SetFootNatural(0.0, S, Z0, Time);  // A
  legRM.SetFootNatural(0.0, -S, Z0, Time);
  legRB.SetFootNatural(0.0, S, Z0, Time);  // A

  // Left
  legLF.SetFootNatural(0.0, -S, Z0, Time);
  legLM.SetFootNatural(0.0, S, Z0, Time);  // A
  legLB.SetFootNatural(0.0, -S, Z0, Time);
}


// Tripod B comes up a bit. MIDSTRIDE.
void SetRobotPosition4(int Time)
{
  // Right
  legRF.SetFootNatural(0.0, S, Z0, Time);  // A
  legRM.SetFootNatural(0.0, -S, Z1, Time);
  legRB.SetFootNatural(0.0, S, Z0, Time);  // A

  // Left
  legLF.SetFootNatural(0.0, -S, Z1, Time);
  legLM.SetFootNatural(0.0, S, Z0, Time);  // A
  legLB.SetFootNatural(0.0, -S, Z1, Time);
}


// Tripod B goes forward, and lifts a little more. Tripod A goes backward on the ground, moving robot forward.
void SetRobotPosition5(int Time)
{
  // Right
  legRF.SetFootNatural(0.0, -S, Z0, Time); // A
  legRM.SetFootNatural(0.0, S, Z2, Time);
  legRB.SetFootNatural(0.0, -S, Z0, Time); // A

  // Left
  legLF.SetFootNatural(0.0, S, Z2, Time);
  legLM.SetFootNatural(0.0, -S, Z0, Time); // A
  legLB.SetFootNatural(0.0, S, Z2, Time);
}


// Tripod B comes down. MIDSTRIDE.
void SetRobotPosition6(int Time)
{
  // Right
  legRF.SetFootNatural(0.0, -S, Z0, Time); // A
  legRM.SetFootNatural(0.0, S, Z0, Time);
  legRB.SetFootNatural(0.0, -S, Z0, Time); // A

  // Left
  legLF.SetFootNatural(0.0, S, Z0, Time);
  legLM.SetFootNatural(0.0, -S, Z0, Time); // A
  legLB.SetFootNatural(0.0, S, Z0, Time);
}


// Tripod A comes up a bit. MIDSTRIDE.
void SetRobotPosition7(int Time)
{
  // Right
  legRF.SetFootNatural(0.0, -S, Z1, Time); // A
  legRM.SetFootNatural(0.0, S, Z0, Time);
  legRB.SetFootNatural(0.0, -S, Z1, Time); // A

  // Left
  legLF.SetFootNatural(0.0, S, Z0, Time);
  legLM.SetFootNatural(0.0, -S, Z1, Time); // A
  legLB.SetFootNatural(0.0, S, Z0, Time);
}


// END //
