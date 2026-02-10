#include <Arduino.h>
#include "Tests.h"

//>>> Add exercise to move body up and down...

#define T 200
#define D 1000
#define BLD 2000


void CycleLegs()
{
P("Right front foot test");
NL();

  // RF test
  P("SetFootNatural 0, 0, 0");
  lRF.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNatural -50, 50, 0");
  lRF.SetFootNatural(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNatural 50, 50, 0");
  lRF.SetFootNatural(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNatural 50, -50, 0");
  lRF.SetFootNatural(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNatural -50, -50, 0");
  lRF.SetFootNatural(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);

  P("SetFootNatural 0, 0, 0");
  lRF.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  delay(BLD);


  P("Right middle foot test");
NL();

  // RM test
  P("SetFootNatural 0, 0, 0");
  lRM.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNatural -50, 50, 0");
  lRM.SetFootNatural(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNatural 50, 50, 0");
  lRM.SetFootNatural(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNatural 50, -50, 0");
  lRM.SetFootNatural(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNatural -50, -50, 0");
  lRM.SetFootNatural(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("SetFootNatural 0, 0, 0");
  lRM.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  
  delay(BLD);


    P("Right back foot test");
NL();

  // RB test
  P("SetFootNatural 0, 0, 0");
  lRB.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNatural -50, 50, 0");
  lRB.SetFootNatural(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNatural 50, 50, 0");
  lRB.SetFootNatural(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNatural 50, -50, 0");
  lRB.SetFootNatural(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNatural -50, -50, 0");
  lRB.SetFootNatural(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("SetFootNatural 0, 0, 0");
  lRB.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  delay(BLD);

////////////////

P("Left front foot test");
NL();

  // LF test
  P("SetFootNatural 0, 0, 0");
  lLF.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNatural -50, 50, 0");
  lLF.SetFootNatural(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNatural 50, 50, 0");
  lLF.SetFootNatural(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNatural 50, -50, 0");
  lLF.SetFootNatural(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNatural -50, -50, 0");
  lLF.SetFootNatural(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);

  P("SetFootNatural 0, 0, 0");
  lLF.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  delay(BLD);


  P("Left middle foot test");
NL();

  // RM test
  P("SetFootNatural 0, 0, 0");
  lLM.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNatural -50, 50, 0");
  lLM.SetFootNatural(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNatural 50, 50, 0");
  lLM.SetFootNatural(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNatural 50, -50, 0");
  lLM.SetFootNatural(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNatural -50, -50, 0");
  lLM.SetFootNatural(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("SetFootNatural 0, 0, 0");
  lLM.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  
  delay(BLD);


    P("Left back foot test");
NL();

  // LB test
  P("SetFootNatural 0, 0, 0");
  lLB.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
  delay(D);
  
  P("1 - SetFootNatural -50, 50, 0");
  lLB.SetFootNatural(-50.0, 50.0, -30.0, T);
  NL();
  delay(D);
  
  P("2 - SetFootNatural 50, 50, 0");
  lLB.SetFootNatural(50.0, 50.0, -30.0, T);
  NL();
  delay(D);

  P("3 - SetFootNatural 50, -50, 0");
  lLB.SetFootNatural(50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("4 - SetFootNatural -50, -50, 0");
  lLB.SetFootNatural(-50.0, -50.0, -30.0, T);
  NL();
  delay(D);
  
  P("SetFootNatural 0, 0, 0");
  lLB.SetFootNatural(0.0, 0.0, 0.0, T);
  NL();
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



void TestKinematics()
{
  
  float footXin = 130;  //119.75;
  float footYin = 155.0;
  float footZin = 50.0; //125.0;

  float hipNatural = 45.0;  // Test right front leg...
  float hipX = 39.5;
  float hipY = 74.75;

  float kneeAngle;
  float verticalAngle;
  float hipAngle;
  
  ComputeAngles(footXin, footYin, footZin, hipNatural, hipX, hipY, &kneeAngle, &verticalAngle, &hipAngle);

  float footXout = 0;  
  float footYout = 0;  
  float footZout = 0;  

  ComputeFootPosition(hipNatural, hipX, hipY, kneeAngle, verticalAngle, hipAngle, &footXout, &footYout, &footZout);

  NL();
  // Now, foot[XYZ]out should equal foot[XYZ]in...
  PFV("footXin", footXin);
  PFV("footYin", footYin);
  PFV("footZin", footZin);
  NL();
  PFV("kneeAngle", kneeAngle);
  PFV("verticalAngle", verticalAngle);
  PFV("hipAngle", hipAngle);
  NL();
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);
}


// END
