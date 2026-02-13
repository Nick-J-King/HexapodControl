// Servo Controller for Hexapod
//
// Written by NJK, 2026

#include "Robot.h"

//#define DISABLE_PARITY_CHECKS // Disable parity checks. Saves 48 bytes of program memory.
#define USE_CALLBACK_FOR_TINY_RECEIVER  // Call the user provided function "void handleReceivedTinyIRData()" each time a frame or repeat is received.

#include "TinyIRReceiver.hpp" // include the code

#include "IRCodes.h"


void setup()
{
  Serial.begin(115200);
  delay(1000);
  
  ///////////////////
  P("\nSet natural position");
  SetRobotPosition0(0);     // Start in "natural" pose...
  ReportRobot();
  delay(1000);

  //TestKinematics();

  P("\nSet right front foot delta 10,20,30");
  lRF.SetFootDelta(10.0, 20.0, 30.0, 0);
  ReportRobot();

  ///////////////////

/*
  WakeUp();

  SetRobotPosition0(1000);     // Start in "natural" pose.
  WaitForServos();
  
  SetRobotPosition1(1000);  // Start to move by lifting tripod A in neutral position
  WaitForServos();

  // Enables the interrupt generation on change of IR input signal
  initPCIInterruptForTinyReceiver();
*/
}


volatile int state = 1;

void loop()
{
  /*
  if (state == 1)
  {
    WalkLoop();
  }
  */
}


volatile uint8_t Command = 0;


void handleReceivedTinyIRData()
{
  Command = TinyIRReceiverData.Command;
  //if (TinyIRReceiverData.Flags == IRDATA_FLAGS_IS_REPEAT)
  //{
  //  ;
  //}

  if (Command == codeUp)
  {
    state = 1;  // Start
  }

  if (Command == codeOK)
  {
    state = 0;  // Stop
  }  
}


// END
