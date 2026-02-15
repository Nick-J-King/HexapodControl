// Calibrate.cpp

#include "Robot.h"

#ifdef CALIBRATE

#include "Calibrate.h"

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

#define servoKnee 0
#define servoVertical 1
#define servoHorizontal 2

int whichServo = servoKnee;
Leg *selectedLeg = &lLF;
Servo *selectedServo = &sLFK;


void loop()
{
  switch (Command)
  {
    case codeOK:
      SetRobotPosition0(0);     // Start in "natural" pose.
      break;

    case code1:
      SelectLeg(&lLF);
      break;
    case code4:
      SelectLeg(&lLM);
      break;
    case code7:
      SelectLeg(&lLB);
      break;
    case code2:
      SelectLeg(&lRF);
      break;
    case code5:
      SelectLeg(&lRM);
      break;
    case code8:
      SelectLeg(&lRB);
      break;

    case code3:
      SelectServo(servoKnee);
      break;
    case code6:
      SelectServo(servoVertical);
      break;
    case code9:
      SelectServo(servoHorizontal);
      break;

    case codeStar:
      ServoMinus();
      break;

    case code0:
      ServoNatural();
      break;

    case codeHash:
      ServoPlus();
  }
  
  Command = 0;  // Done the action! Must await further instructions!
  delay(100);
}


void SelectLeg(Leg *leg)
{
  selectedLeg = leg;
  switch (whichServo)
  {
    case servoKnee:
      selectedServo = leg->Knee();
      break;

    case servoVertical:
      selectedServo = leg->Vertical();
      break;

    case servoHorizontal:
      selectedServo = leg->Horizontal();
      break;
  }
}


void SelectServo(int whichServoIn)
{
  switch (whichServoIn)
  {
    case servoKnee:
      selectedServo = selectedLeg->Knee();
      break;

    case servoVertical:
      selectedServo = selectedLeg->Vertical();
      break;

    case servoHorizontal:
      selectedServo = selectedLeg->Horizontal();
      break;
  }
  whichServo = whichServoIn;
}


void ServoMinus()
{
  float angle = selectedServo->GetAngle();
  selectedServo->SetAngle(angle - 1.0, 20);
}


void ServoNatural()
{
  selectedServo->SetNatural(500);
}


void ServoPlus()
{
  float angle = selectedServo->GetAngle();
  selectedServo->SetAngle(angle + 1.0, 20);
}


void handleReceivedTinyIRData()
{
  Command = TinyIRReceiverData.Command;
}


// Command each servo individually...
// Show the PWM in Serial monitor

#endif // CALIBRATE


// END //
