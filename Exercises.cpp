#include "Robot.h"


//>>> Add exercise to move body up and down...

void ExerciseRobot()
{
  CycleLegs();
}


#define T 200
#define D 1000
#define BLD 2000


void CycleLegs()
{
  // RF test
  lRF.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(D);
  
  lRF.SetFootNatural(-50.0, 50.0, -30.0, T);
  delay(D);
  
  lRF.SetFootNatural(50.0, 50.0, -30.0, T);
  delay(D);

  lRF.SetFootNatural(50.0, -50.0, -30.0, T);
  delay(D);
  
  lRF.SetFootNatural(-50.0, -50.0, -30.0, T);
  delay(D);

  lRF.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(BLD);


  // RM test
  lRM.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(D);
  
  lRM.SetFootNatural(-50.0, 50.0, -30.0, T);
  delay(D);
  
  lRM.SetFootNatural(50.0, 50.0, -30.0, T);
  delay(D);

  lRM.SetFootNatural(50.0, -50.0, -30.0, T);
  delay(D);
  
  lRM.SetFootNatural(-50.0, -50.0, -30.0, T);
  delay(D);
  
  lRM.SetFootNatural(0.0, 0.0, 0.0, T);
  
  delay(BLD);


  // RB test
  lRB.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(D);
  
  lRB.SetFootNatural(-50.0, 50.0, -30.0, T);
  delay(D);
  
  lRB.SetFootNatural(50.0, 50.0, -30.0, T);
  delay(D);

  lRB.SetFootNatural(50.0, -50.0, -30.0, T);
  delay(D);
  
  lRB.SetFootNatural(-50.0, -50.0, -30.0, T);
  delay(D);
  
  lRB.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(BLD);

////////////////

  // LF test
  lLF.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(D);
  
  lLF.SetFootNatural(-50.0, 50.0, -30.0, T);
  delay(D);
  
  lLF.SetFootNatural(50.0, 50.0, -30.0, T);
  delay(D);

  lLF.SetFootNatural(50.0, -50.0, -30.0, T);
  delay(D);
  
  lLF.SetFootNatural(-50.0, -50.0, -30.0, T);
  delay(D);

  lLF.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(BLD);


  // RM test
  lLM.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(D);
  
  lLM.SetFootNatural(-50.0, 50.0, -30.0, T);
  delay(D);
  
  lLM.SetFootNatural(50.0, 50.0, -30.0, T);
  delay(D);

  lLM.SetFootNatural(50.0, -50.0, -30.0, T);
  delay(D);
  
  lLM.SetFootNatural(-50.0, -50.0, -30.0, T);
  delay(D);
  
  lLM.SetFootNatural(0.0, 0.0, 0.0, T);
  
  delay(BLD);


  // LB test
  lLB.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(D);
  
  lLB.SetFootNatural(-50.0, 50.0, -30.0, T);
  delay(D);
  
  lLB.SetFootNatural(50.0, 50.0, -30.0, T);
  delay(D);

  lLB.SetFootNatural(50.0, -50.0, -30.0, T);
  delay(D);
  
  lLB.SetFootNatural(-50.0, -50.0, -30.0, T);
  delay(D);
  
  lLB.SetFootNatural(0.0, 0.0, 0.0, T);
  delay(BLD);
}


// Set servos manually...
// *Out, *up, CW.
void SetRobotPositionE(int Time)
{
  sLFK.SetAngle(30.0, 1000);
  sLMK.SetAngle(30.0, 1000);
  sLBK.SetAngle(30.0, 1000);
  sRFK.SetAngle(30.0, 1000);
  sRMK.SetAngle(30.0, 1000);
  sRBK.SetAngle(30.0, 1000);

  sLFV.SetAngle(30.0, 1000);
  sLMV.SetAngle(30.0, 1000);
  sLBV.SetAngle(30.0, 1000);
  sRFV.SetAngle(30.0, 1000);
  sRMV.SetAngle(30.0, 1000);
  sRBV.SetAngle(30.0, 1000);

  sLFH.SetAngle(10.0, 1000);
  sLMH.SetAngle(10.0, 1000);
  sLBH.SetAngle(10.0, 1000);
  sRFH.SetAngle(10.0, 1000);
  sRMH.SetAngle(10.0, 1000);
  sRBH.SetAngle(10.0, 1000);
}

// *In, *down, CCW
void SetRobotPositionF(int Time)
{
  sLFK.SetAngle(-30.0, 1000);
  sLMK.SetAngle(-30.0, 1000);
  sLBK.SetAngle(-30.0, 1000);
  sRFK.SetAngle(-30.0, 1000);
  sRMK.SetAngle(-30.0, 1000);
  sRBK.SetAngle(-30.0, 1000);

  sLFV.SetAngle(-20.0, 1000);
  sLMV.SetAngle(-20.0, 1000);
  sLBV.SetAngle(-20.0, 1000);
  sRFV.SetAngle(-20.0, 1000);
  sRMV.SetAngle(-20.0, 1000);
  sRBV.SetAngle(-20.0, 1000);

  sLFH.SetAngle(-10.0, 1000);
  sLMH.SetAngle(-10.0, 1000);
  sLBH.SetAngle(-10.0, 1000);
  sRFH.SetAngle(-10.0, 1000);
  sRMH.SetAngle(-10.0, 1000);
  sRBH.SetAngle(-10.0, 1000);
}


// Splay out
void SetRobotPositionG(int Time)
{
  // Right
  lRF.SetFootNatural(40.0, 40.0, 0.0, Time);  // A
  lRM.SetFootNatural(60.0, 0.0, 0.0, Time);
  lRB.SetFootNatural(40.0, -40.0, 0.0, Time);  // A

  // Left
  lLF.SetFootNatural(-40.0, 40.0, 0.0, Time);
  lLM.SetFootNatural(-60.0, 0.0, 0.0, Time);  // A
  lLB.SetFootNatural(-40.0, -40.0, 0.0, Time);
}


// Splay int
void SetRobotPositionH(int Time)
{
  // Right
  lRF.SetFootNatural(-40.0, -40.0, 0.0, Time);  // A
  lRM.SetFootNatural(-60.0, 0.0, 0.0, Time);
  lRB.SetFootNatural(-40.0, 40.0, 0.0, Time);  // A

  // Left
  lLF.SetFootNatural(40.0, -40.0, 0.0, Time);
  lLM.SetFootNatural(60.0, 0.0, 0.0, Time);  // A
  lLB.SetFootNatural(40.0, 40.0, 0.0, Time);
}


// END //
