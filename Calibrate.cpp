// Calibrate.cpp

#include "Robot.h"

#ifdef CALIBRATE

#include "Calibrate.h"

//#define DISABLE_PARITY_CHECKS // Disable parity checks. Saves 48 bytes of program memory.
#define USE_CALLBACK_FOR_TINY_RECEIVER  // Call the user provided function "void handleReceivedTinyIRData()" each time a frame or repeat is received.

#include "TinyIRReceiver.hpp" // include the code
#include "IRCodes.h"


float angleSteps[] =
{
  5.0, 4.0, 3.0, 2.0, 1.0, 0.5, 0.4, 0.3, 0.2, 0.1, 0.05, 0.02, 0.01
};

float angleStepArrayLength = sizeof(angleSteps) / sizeof(angleSteps[0]);
int angleStepIndex = 0;

float angleStep = angleSteps[angleStepIndex];


void setup()
{
  Serial.begin(115200);
  delay(1000);

  SetRobotAxisAndRotation(0.0, 0.0, 1.0, 0.0);

  //CenterAll(0);     // Start with all servos in ABSOLUTE_MIDDLE postion to get horns right.
  //NaturalAll(0);    // Start with all servos in "natural" position to check calibration.
  StartForUpsideDown(1000); // As it turns out, it is easier to calibrate upside down...

  Serial.println("\nStartForUpsideDown\n");

  delay(1000);

  // Enables the interrupt generation on change of IR input signal
  initPCIInterruptForTinyReceiver();
}

volatile uint8_t Command = 0;

#define servoKnee 0
#define servoVertical 1
#define servoHorizontal 2

int whichServo = servoKnee;
Leg *selectedLeg = &legLF;
Servo *selectedServo = &servoLFK;

String legName = "Left Front";
String servoName = "Knee";

String GetServoName() { return legName + " " + servoName; }

void loop()
{
  switch (Command)
  {
    case codeOK:
      SetRobotPosition0(800);     // Go to "natural" pose.
      break;

    case codeLeft:
      HipCCW45();
      break;

    case codeRight:
      HipCW45();
      break;

    case codeUp:
      IncreaseStep();
      break;

    case codeDown:
      DecreaseStep();
      break;

    case code1:
      SelectLeg(&legLF);
      legName = "Left Front";
      Serial.println("Selected Left Front leg");
      break;
    case code4:
      SelectLeg(&legLM);
      legName = "Left Middle";
      Serial.println("Selected Left Middle leg");
      break;
    case code7:
      SelectLeg(&legLB);
      legName = "Left Back";
      Serial.println("Selected Left Back leg");
      break;
    case code2:
      SelectLeg(&legRF);
      legName = "Right Front";
      Serial.println("Selected Right Front leg");
      break;
    case code5:
      SelectLeg(&legRM);
      legName = "Right Middle";
      Serial.println("Selected Right Middle leg");
      break;
    case code8:
      SelectLeg(&legRB);
      legName = "Right Back";
      Serial.println("Selected Right Back leg");
      break;

    case code3:
      SelectServo(servoKnee);
      servoName = "Knee";
      break;
    case code6:
      SelectServo(servoVertical);
      servoName = "Vertical";
      break;
    case code9:
      SelectServo(servoHorizontal);
      servoName = "Horizontal";
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
  delay(10);
}


void StartForUpsideDown(int Time)
{
  // Leave the knees pliant to start with. This makes calibrating the vertical servos easier.
  legLF.SetServoAngles(0.0, 0.0, 0.0, Time);
  legLM.SetServoAngles(0.0, 0.0, 0.0, Time);
  legLB.SetServoAngles(0.0, 0.0, 0.0, Time);
  legRF.SetServoAngles(0.0, 0.0, 0.0, Time);
  legRM.SetServoAngles(0.0, 0.0, 0.0, Time);
  legRB.SetServoAngles(0.0, 0.0, 0.0, Time);
}


void DecreaseStep()
{
  angleStepIndex++;

  if (angleStepIndex >= angleStepArrayLength)
  {
    angleStepIndex = angleStepArrayLength - 1;
  }

  angleStep = angleSteps[angleStepIndex];

  Serial.println("Angle Step " + String(angleStep));
  delay(200);
}


void IncreaseStep()
{
  angleStepIndex--;

  if (angleStepIndex < 0)
  {
    angleStepIndex = 0;
  }

  angleStep = angleSteps[angleStepIndex];

  Serial.println("Angle Step " + String(angleStep));
  delay(200);
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
  delay(200);
}


void SelectServo(int whichServoIn)
{
  switch (whichServoIn)
  {
    case servoKnee:
      Serial.println("Selected Knee servo");
      selectedServo = selectedLeg->Knee();
      break;

    case servoVertical:
      Serial.println("Selected Vertical servo");
      selectedServo = selectedLeg->Vertical();
      break;

    case servoHorizontal:
      Serial.println("Selected Horizontal servo");
      selectedServo = selectedLeg->Horizontal();
      break;
  }
  whichServo = whichServoIn;
  delay(200);
}


void ServoMinus()
{
  float angle = selectedServo->GetAngle();
  if (angle == UNKNOWN_ANGLE)
  {
    angle = 0.0;  // The first step from ABSOLUTE_MIDDLE must assume a resonable angle.
  }
  selectedServo->SetAngle(angle - angleStep, 20);

  float angleAfter = selectedServo->GetAngle();
  Serial.println(GetServoName() + " at " + String(angleAfter) + " degrees");
  delay(400);
}


void ServoNatural()
{
  selectedServo->SetNatural(500);
  float angleAfter = selectedServo->GetAngle();
  Serial.println(GetServoName() + " at " + String(angleAfter) + " degrees");
}


void ServoPlus()
{
  float angle = selectedServo->GetAngle();
  if (angle == UNKNOWN_ANGLE)
  {
    angle = 0.0;  // The first step from ABSOLUTE_MIDDLE must assume a resonable angle.
  }
  selectedServo->SetAngle(angle + angleStep, 20);

  float angleAfter = selectedServo->GetAngle();
  Serial.println(GetServoName() + " at " + String(angleAfter) + " degrees");
  delay(400);
}


void HipCW45()
{
  selectedLeg->Horizontal()->SetAngle(45.0, 800);
}

void HipCCW45()
{
  selectedLeg->Horizontal()->SetAngle(-45.0, 800);
}


void handleReceivedTinyIRData()
{
  Command = TinyIRReceiverData.Command;
}


// Command each servo individually...
// Show the PWM in Serial monitor

#endif // CALIBRATE


// END //
