// Servo Controller for Hexapod
//
// Written by NJK, 2026

// Define ONE of these flags
#define DEBUG // Flag for debug mode
//#define EXERCISE
//#define NORMAL


#include "Robot.h"

#ifdef DEBUG
#include "Debug.h"
#include "Tests.h"
#endif // DEBUG

#ifdef EXERCISE
#include "Exercises.h"
#endif // EXERCISE

#ifdef NORMAL

//#define DISABLE_PARITY_CHECKS // Disable parity checks. Saves 48 bytes of program memory.
#define USE_CALLBACK_FOR_TINY_RECEIVER  // Call the user provided function "void handleReceivedTinyIRData()" each time a frame or repeat is received.

#include "TinyIRReceiver.hpp" // include the code
#include "IRCodes.h"

#endif // NORMAL


void setup()
{
  Serial.begin(115200);
  delay(1000);
  
#ifdef DEBUG

  RunDebugChecks();

#elif EXERCISE

  ExerciseRobot();

#elif NORMAL // "Normal" mode with commands from IR

  WakeUp();

  SetRobotPosition0(1000);     // Start in "natural" pose.
  WaitForServos();
  
  SetRobotPosition1(1000);  // Start to move by lifting tripod A in neutral position
  WaitForServos();

  // Enables the interrupt generation on change of IR input signal
  initPCIInterruptForTinyReceiver();

#endif
}


volatile int state = 1;

void loop()
{
#ifdef NORMAL
  if (state == 1)
  {
    WalkLoop();
  }
#endif // NORMAL
}


#ifdef NORMAL

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

#endif // NORMAL


// END //
