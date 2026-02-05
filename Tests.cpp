#include <Arduino.h>
#include "Tests.h"

//>>> Add exercise to move body up and down...


void CycleLegs()
{
P("Right front foot test");
NL();

  // RF test
  P("SetFootNaturalDelta 0, 0, 0");
  lRF.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNaturalDelta -50, 50, 0");
  lRF.SetFootNaturalDelta(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNaturalDelta 50, 50, 0");
  lRF.SetFootNaturalDelta(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNaturalDelta 50, -50, 0");
  lRF.SetFootNaturalDelta(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNaturalDelta -50, -50, 0");
  lRF.SetFootNaturalDelta(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);

  P("SetFootNaturalDelta 0, 0, 0");
  lRF.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(BLD);


  P("Right middle foot test");
NL();

  // RM test
  P("SetFootNaturalDelta 0, 0, 0");
  lRM.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNaturalDelta -50, 50, 0");
  lRM.SetFootNaturalDelta(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNaturalDelta 50, 50, 0");
  lRM.SetFootNaturalDelta(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNaturalDelta 50, -50, 0");
  lRM.SetFootNaturalDelta(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNaturalDelta -50, -50, 0");
  lRM.SetFootNaturalDelta(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("SetFootNaturalDelta 0, 0, 0");
  lRM.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  
  delay(BLD);


    P("Right back foot test");
NL();

  // RB test
  P("SetFootNaturalDelta 0, 0, 0");
  lRB.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNaturalDelta -50, 50, 0");
  lRB.SetFootNaturalDelta(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNaturalDelta 50, 50, 0");
  lRB.SetFootNaturalDelta(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNaturalDelta 50, -50, 0");
  lRB.SetFootNaturalDelta(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNaturalDelta -50, -50, 0");
  lRB.SetFootNaturalDelta(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("SetFootNaturalDelta 0, 0, 0");
  lRB.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(BLD);

////////////////

P("Left front foot test");
NL();

  // LF test
  P("SetFootNaturalDelta 0, 0, 0");
  lLF.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNaturalDelta -50, 50, 0");
  lLF.SetFootNaturalDelta(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNaturalDelta 50, 50, 0");
  lLF.SetFootNaturalDelta(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNaturalDelta 50, -50, 0");
  lLF.SetFootNaturalDelta(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNaturalDelta -50, -50, 0");
  lLF.SetFootNaturalDelta(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);

  P("SetFootNaturalDelta 0, 0, 0");
  lLF.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(BLD);


  P("Left middle foot test");
NL();

  // RM test
  P("SetFootNaturalDelta 0, 0, 0");
  lLM.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNaturalDelta -50, 50, 0");
  lLM.SetFootNaturalDelta(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNaturalDelta 50, 50, 0");
  lLM.SetFootNaturalDelta(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNaturalDelta 50, -50, 0");
  lLM.SetFootNaturalDelta(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNaturalDelta -50, -50, 0");
  lLM.SetFootNaturalDelta(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("SetFootNaturalDelta 0, 0, 0");
  lLM.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  
  delay(BLD);


    P("Left back foot test");
NL();

  // LB test
  P("SetFootNaturalDelta 0, 0, 0");
  lLB.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNaturalDelta -50, 50, 0");
  lLB.SetFootNaturalDelta(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNaturalDelta 50, 50, 0");
  lLB.SetFootNaturalDelta(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNaturalDelta 50, -50, 0");
  lLB.SetFootNaturalDelta(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNaturalDelta -50, -50, 0");
  lLB.SetFootNaturalDelta(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("SetFootNaturalDelta 0, 0, 0");
  lLB.SetFootNaturalDelta(0.0, 0.0, 0.0, T);
  NL();
  delay(BLD);
}



// Set servos manually...
// *Out, *up, CW.
void SetRobotPositionE(int Time)
{
  sLFK.PositionAngle(30.0, 1000);
  sLMK.PositionAngle(30.0, 1000);
  sLBK.PositionAngle(30.0, 1000);
  sRFK.PositionAngle(30.0, 1000);
  sRMK.PositionAngle(30.0, 1000);
  sRBK.PositionAngle(30.0, 1000);

  sLFV.PositionAngle(30.0, 1000);
  sLMV.PositionAngle(30.0, 1000);
  sLBV.PositionAngle(30.0, 1000);
  sRFV.PositionAngle(30.0, 1000);
  sRMV.PositionAngle(30.0, 1000);
  sRBV.PositionAngle(30.0, 1000);

  sLFH.PositionAngle(10.0, 1000);
  sLMH.PositionAngle(10.0, 1000);
  sLBH.PositionAngle(10.0, 1000);
  sRFH.PositionAngle(10.0, 1000);
  sRMH.PositionAngle(10.0, 1000);
  sRBH.PositionAngle(10.0, 1000);
}

// *In, *down, CCW
void SetRobotPositionF(int Time)
{
  sLFK.PositionAngle(-30.0, 1000);
  sLMK.PositionAngle(-30.0, 1000);
  sLBK.PositionAngle(-30.0, 1000);
  sRFK.PositionAngle(-30.0, 1000);
  sRMK.PositionAngle(-30.0, 1000);
  sRBK.PositionAngle(-30.0, 1000);

  sLFV.PositionAngle(-20.0, 1000);
  sLMV.PositionAngle(-20.0, 1000);
  sLBV.PositionAngle(-20.0, 1000);
  sRFV.PositionAngle(-20.0, 1000);
  sRMV.PositionAngle(-20.0, 1000);
  sRBV.PositionAngle(-20.0, 1000);

  sLFH.PositionAngle(-10.0, 1000);
  sLMH.PositionAngle(-10.0, 1000);
  sLBH.PositionAngle(-10.0, 1000);
  sRFH.PositionAngle(-10.0, 1000);
  sRMH.PositionAngle(-10.0, 1000);
  sRBH.PositionAngle(-10.0, 1000);
}


// Splay out
void SetRobotPositionG(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(40.0, 40.0, 0.0, Time);  // A
  lRM.SetFootNaturalDelta(60.0, 0.0, 0.0, Time);
  lRB.SetFootNaturalDelta(40.0, -40.0, 0.0, Time);  // A

  // Left
  lLF.SetFootNaturalDelta(-40.0, 40.0, 0.0, Time);
  lLM.SetFootNaturalDelta(-60.0, 0.0, 0.0, Time);  // A
  lLB.SetFootNaturalDelta(-40.0, -40.0, 0.0, Time);
}


// Splay int
void SetRobotPositionH(int Time)
{
  // Right
  lRF.SetFootNaturalDelta(-40.0, -40.0, 0.0, Time);  // A
  lRM.SetFootNaturalDelta(-60.0, 0.0, 0.0, Time);
  lRB.SetFootNaturalDelta(-40.0, 40.0, 0.0, Time);  // A

  // Left
  lLF.SetFootNaturalDelta(40.0, -40.0, 0.0, Time);
  lLM.SetFootNaturalDelta(60.0, 0.0, 0.0, Time);  // A
  lLB.SetFootNaturalDelta(40.0, 40.0, 0.0, Time);
}
