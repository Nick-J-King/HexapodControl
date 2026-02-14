#include "Robot.h"

#ifdef EXERCISE

#include "Exercises.h"

//#define DISABLE_PARITY_CHECKS // Disable parity checks. Saves 48 bytes of program memory.
#define USE_CALLBACK_FOR_TINY_RECEIVER  // Call the user provided function "void handleReceivedTinyIRData()" each time a frame or repeat is received.

#include "TinyIRReceiver.hpp" // include the code
#include "IRCodes.h"


void setup()
{
  Serial.begin(115200);
  delay(1000);

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
      SetRobotPosition0(500);
      break;  // Go to natural pose.
    
    case codeOK:
      SetRobotBelly(1000);
      break;  // Get it ready to sit on belly.
    
    case code1:
      CycleLegs();
      break;
    
    case code2:
      SetRobotPositionE(1000);
      break;
    
    case code3:
      SetRobotPositionF(1000);
      break;
    
    case code4:
      SetRobotPositionG(1000);
      break;
    
    case code5:
      SetRobotPositionH(1000);
      break;
 
    case codeUp:
      FeetForward(200);
      break;

    case codeDown:
      FeetBackward(200);
      break;

    case codeLeft:
      FeetLeft(200);
      break;

    case codeRight:
      FeetRight(200);
      break;

    case codeStar:
      FeetDown(200);
      break;

    case codeHash:
      FeetUp(200);
      break;
  }
  
  Command = 0;  // Done the exercise! Must await further instructions!
  delay(100);
}


void handleReceivedTinyIRData()
{
  Command = TinyIRReceiverData.Command;
}


void SetRobotBelly(int Time)
{
  lRF.SetServoAngles(-40.0, 80.0, 0.0, Time);
  lRM.SetServoAngles(-40.0, 80.0, 0.0, Time);
  lRB.SetServoAngles(-40.0, 80.0, 0.0, Time);
  lLF.SetServoAngles(-40.0, 80.0, 0.0, Time);
  lLM.SetServoAngles(-40.0, 80.0, 0.0, Time);
  lLB.SetServoAngles(-40.0, 80.0, 0.0, Time);
}


// NOTE: This exercise has delays, and cannot be interrupted!
// All legs do their cycle before stopping.
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

// NOTE: This exercise has delays, and cannot be interrupted!
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
  lRF.SetFootNatural(40.0, 40.0, 0.0, Time);
  lRM.SetFootNatural(60.0, 0.0, 0.0, Time);
  lRB.SetFootNatural(40.0, -40.0, 0.0, Time);

  lLF.SetFootNatural(-40.0, 40.0, 0.0, Time);
  lLM.SetFootNatural(-60.0, 0.0, 0.0, Time);
  lLB.SetFootNatural(-40.0, -40.0, 0.0, Time);
}


// Splay int
void SetRobotPositionH(int Time)
{
  lRF.SetFootNatural(-40.0, -40.0, 0.0, Time);
  lRM.SetFootNatural(-60.0, 0.0, 0.0, Time);
  lRB.SetFootNatural(-40.0, 40.0, 0.0, Time);

  lLF.SetFootNatural(40.0, -40.0, 0.0, Time);
  lLM.SetFootNatural(60.0, 0.0, 0.0, Time);
  lLB.SetFootNatural(40.0, 40.0, 0.0, Time);
}



// All feet forward 5mm.
void FeetForward(int Time)
{
  lRF.SetFootDelta(0.0, 5.0, 0.0, Time);
  lRM.SetFootDelta(0.0, 5.0, 0.0, Time);
  lRB.SetFootDelta(0.0, 5.0, 0.0, Time);

  lLF.SetFootDelta(0.0, 5.0, 0.0, Time);
  lLM.SetFootDelta(0.0, 5.0, 0.0, Time);
  lLB.SetFootDelta(0.0, 5.0, 0.0, Time);
}

// All feet backward 5mm.
void FeetBackward(int Time)
{
  lRF.SetFootDelta(0.0, 5.0, 0.0, Time);
  lRM.SetFootDelta(0.0, 5.0, 0.0, Time);
  lRB.SetFootDelta(0.0, 5.0, 0.0, Time);

  lLF.SetFootDelta(0.0, 5.0, 0.0, Time);
  lLM.SetFootDelta(0.0, 5.0, 0.0, Time);
  lLB.SetFootDelta(0.0, 5.0, 0.0, Time);
}

// All feet left 5mm.
void FeetLeft(int Time)
{
  lRF.SetFootDelta(-5.0, 0.0, 0.0, Time);
  lRM.SetFootDelta(-5.0, 0.0, 0.0, Time);
  lRB.SetFootDelta(-5.0, 0.0, 0.0, Time);

  lLF.SetFootDelta(-5.0, 0.0, 0.0, Time);
  lLM.SetFootDelta(-5.0, 0.0, 0.0, Time);
  lLB.SetFootDelta(-5.0, 0.0, 0.0, Time);
}

// All feet right 5mm.
void FeetRight(int Time)
{
  lRF.SetFootDelta(5.0, 0.0, 0.0, Time);
  lRM.SetFootDelta(5.0, 0.0, 0.0, Time);
  lRB.SetFootDelta(5.0, 0.0, 0.0, Time);

  lLF.SetFootDelta(5.0, 0.0, 0.0, Time);
  lLM.SetFootDelta(5.0, 0.0, 0.0, Time);
  lLB.SetFootDelta(5.0, 0.0, 0.0, Time);
}

// All feet up 5mm.
void FeetUp(int Time)
{
  lRF.SetFootDelta(0.0, 0.0, -5.0, Time);
  lRM.SetFootDelta(0.0, 0.0, -5.0, Time);
  lRB.SetFootDelta(0.0, 0.0, -5.0, Time);

  lLF.SetFootDelta(0.0, 0.0, -5.0, Time);
  lLM.SetFootDelta(0.0, 0.0, -5.0, Time);
  lLB.SetFootDelta(0.0, 0.0, -5.0, Time);
}

// All feet down 5mm.
void FeetDown(int Time)
{
  lRF.SetFootDelta(0.0, 0.0, 5.0, Time);
  lRM.SetFootDelta(0.0, 0.0, 5.0, Time);
  lRB.SetFootDelta(0.0, 0.0, 5.0, Time);

  lLF.SetFootDelta(0.0, 0.0, 5.0, Time);
  lLM.SetFootDelta(0.0, 0.0, 5.0, Time);
  lLB.SetFootDelta(0.0, 0.0, 5.0, Time);
}


#endif // EXERCISE


// END //
