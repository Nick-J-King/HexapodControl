#include "Robot.h"

#ifdef EXERCISE

#include "Exercises.h"

//#define DISABLE_PARITY_CHECKS // Disable parity checks. Saves 48 bytes of program memory.
#define USE_CALLBACK_FOR_TINY_RECEIVER  // Call the user provided function "void handleReceivedTinyIRData()" each time a frame or repeat is received.

#include "TinyIRReceiver.hpp" // include the code
#include "IRCodes.h"


void setup()
{
    SetRobotPosition0(0);     // Start in "natural" pose.

  // Enables the interrupt generation on change of IR input signal
  initPCIInterruptForTinyReceiver();
}

volatile uint8_t Command = 0;


void loop()
{
  switch (Command)
  {
    case code0:
      break;  // Stop exercising!
    
    case code1:
      ExerciseRobot1();
      break;
    
    case code2:
      ExerciseRobot2();
      break;
    
    case code3:
      ExerciseRobot3();
      break;
    
    case code4:
      ExerciseRobot4();
      break;
    
    case code5:
      ExerciseRobot5();
      break;
  }

  delay(100);
}


void handleReceivedTinyIRData()
{
  int Command = TinyIRReceiverData.Command;
}


//>>> Add exercise to move body up and down...

void ExerciseRobot1()
{
  CycleLegs();
}

void ExerciseRobot2()
{
  SetRobotPositionE(1000);
}

void ExerciseRobot3()
{
  SetRobotPositionF(1000);
}

void ExerciseRobot4()
{
  SetRobotPositionG(1000);
}

void ExerciseRobot5()
{
  SetRobotPositionH(1000);
}


void CycleLegs()
{
  CycleLeg(&lRF);
  CycleLeg(&lRM);
  CycleLeg(&lRB);

  CycleLeg(&lLF);
  CycleLeg(&lLM);
  CycleLeg(&lLB);
}


#define T 200
#define D 1000
#define BLD 2000


void CycleLeg(Leg *leg)
{
  leg->SetFootNatural(0.0, 0.0, 0.0, T);
  delay(D);
  
  leg->SetFootNatural(-50.0, 50.0, -30.0, T);
  delay(D);
  
  leg->SetFootNatural(50.0, 50.0, -30.0, T);
  delay(D);

  leg->SetFootNatural(50.0, -50.0, -30.0, T);
  delay(D);
  
  leg->SetFootNatural(-50.0, -50.0, -30.0, T);
  delay(D);
  
  leg->SetFootNatural(0.0, 0.0, 0.0, T);
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


#endif // EXERCISE


// END //
