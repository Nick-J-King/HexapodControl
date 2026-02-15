// Exercises.cpp

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

    // Start off trying a +ve 10 degree about z-axis...
    // This makes legs all go 10 degrees CCW (looking from the top).
    // Looking along the +ve z axis (down) this is CCW.
    //
    // Now try a +ve 10 degree about y-axis...
    // This makes left legs go down, right legs go up.
    // Looking along +ve y axis (forward), this is CCW.
    //
    // Now try a +ve 10 degree about x-axis...
    // This makes front legs go down, back legs come up.
    // Looking along +ve x axis (right), this is CCW.
    //
    // So the body moves the other way: CW is positive for the body.
    // I like it that way! The rotation axis refers to the centre of the robot.

  SetRobotAxisAndRotation(0.0, 0.0, 1.0, 0.0);  // Start with neutral rotation.

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
      SetRobotTwirlCW(1000);
      break;
    
    case code3:
      SetRobotTwirlCCW(1000);
      break;
    
    case code4:
      SetRobotKickOut(700);
      break;
    
    case code5:
      SetRobotKickIn(700);
      break;
 
    case code6:
      SwirlTest();
      break;

    case code7:
      YawTest();
      break;
 
    case code8:
      PitchTest();
      break;
 
    case code9:
      RollTest();
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
void SetRobotTwirlCW(int Time)
{
  lRF.SetServoAngles(30.0, 30.0, 20.0, Time);
  lRM.SetServoAngles(30.0, 30.0, 20.0, Time);
  lRB.SetServoAngles(30.0, 30.0, 20.0, Time);

  lLF.SetServoAngles(30.0, 30.0, 20.0, Time);
  lLM.SetServoAngles(30.0, 30.0, 20.0, Time);
  lLB.SetServoAngles(30.0, 30.0, 20.0, Time);
}

// *In, *down, CCW
void SetRobotTwirlCCW(int Time)
{
  lRF.SetServoAngles(-30.0, -30.0, -20.0, Time);
  lRM.SetServoAngles(-30.0, -30.0, -20.0, Time);
  lRB.SetServoAngles(-30.0, -30.0, -20.0, Time);

  lLF.SetServoAngles(-30.0, -30.0, -20.0, Time);
  lLM.SetServoAngles(-30.0, -30.0, -20.0, Time);
  lLB.SetServoAngles(-30.0, -30.0, -20.0, Time);
}


void SetRobotKickOut(int Time)
{
  lRF.SetServoAngles(80.0, -10.0, 0.0, Time);
  lRM.SetServoAngles(80.0, -10.0, 0.0, Time);
  lRB.SetServoAngles(80.0, -10.0, 0.0, Time);

  lLF.SetServoAngles(80.0, -10.0, 0.0, Time);
  lLM.SetServoAngles(80.0, -10.0, 0.0, Time);
  lLB.SetServoAngles(80.0, -10.0, 0.0, Time);
}


// Kick in
void SetRobotKickIn(int Time)
{
  lRF.SetServoAngles(-70.0, 10.0, 0.0, Time);
  lRM.SetServoAngles(-70.0, 10.0, 0.0, Time);
  lRB.SetServoAngles(-70.0, 10.0, 0.0, Time);

  lLF.SetServoAngles(-70.0, 10.0, 0.0, Time);
  lLM.SetServoAngles(-70.0, 10.0, 0.0, Time);
  lLB.SetServoAngles(-70.0, 10.0, 0.0, Time);
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
  lRF.SetFootDelta(0.0, -5.0, 0.0, Time);
  lRM.SetFootDelta(0.0, -5.0, 0.0, Time);
  lRB.SetFootDelta(0.0, -5.0, 0.0, Time);

  lLF.SetFootDelta(0.0, -5.0, 0.0, Time);
  lLM.SetFootDelta(0.0, -5.0, 0.0, Time);
  lLB.SetFootDelta(0.0, -5.0, 0.0, Time);
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

#define DB 5
 // Delay for body move exercises loops

#define DBB 400
 // Delay for body move exercises changes

#define DBS 500
 // Delay at the start

#define DBF 100
 // Delay at the end

// Starting from natural, twist one way, then come back and twist the other, then return to normal.
void YawTest()
{
  SetRobotAxisAndRotation(0.0, 0.0, 1.0, 0.0);  // Start with neutral rotation.
  SetRobotPosition0(DBS);     // Start in "natural" pose.
  delay(DBS);

  float angle = 1.0;

  for (angle = 1.0; angle <= 25.0; angle += 1.0)
  {
    SetRobotAxisAndRotation(0.0, 0.0, 1.0, angle);  // Start with neutral rotation.
    SetRobotPosition0(DB);     // Start in "natural" pose.
    delay(DB);
  }
  angle -= 1.0;
  delay(DBB);

  for (; angle >= -25.0; angle -= 1.0)
  {
    SetRobotAxisAndRotation(0.0, 0.0, 1.0, angle);
    SetRobotPosition0(DB);
    delay(DB);
  }
  angle += 1.0;
  delay(DBB);

  for (; angle < 0.0; angle += 1.0)
  {
    SetRobotAxisAndRotation(0.0, 0.0, 1.0, angle);
    SetRobotPosition0(DB);
    delay(DB);
  }
  SetRobotAxisAndRotation(0.0, 0.0, 1.0, 0.0);  // End with neutral rotation.
  SetRobotPosition0(DBF);     // End in "natural" pose.
  delay(DBF);
}


// Starting from natural, tip one way, then come back and tip the other, then return to normal.
void PitchTest()
{
  SetRobotAxisAndRotation(1.0, 0.0, 0.0, 0.0);  // Start with neutral rotation.
  SetRobotPosition0(DBS);     // Start in "natural" pose.
  delay(DBS);

  float angle = 1.0;

  for (angle = 1.0; angle <= 25.0; angle += 1.0)
  {
    SetRobotAxisAndRotation(1.0, 0.0, 0.0, angle);  // Start with neutral rotation.
    SetRobotPosition0(DB);     // Start in "natural" pose.
    delay(DB);
  }
  angle -= 1.0;
  delay(DBB);

  for (; angle >= -25.0; angle -= 1.0)
  {
    SetRobotAxisAndRotation(1.0, 0.0, 0.0, angle);
    SetRobotPosition0(DB);
    delay(DB);
  }
  angle += 1.0;
  delay(DBB);

  for (; angle < 0.0; angle += 1.0)
  {
    SetRobotAxisAndRotation(1.0, 0.0, 0.0, angle);
    SetRobotPosition0(DB);
    delay(DB);
  }
  SetRobotAxisAndRotation(1.0, 0.0, 0.0, 0.0);  // End with neutral rotation.
  SetRobotPosition0(DBF);     // End in "natural" pose.
  delay(DBF);
}


// Starting from natural, tip one way, then come back and tip the other, then return to normal.
void RollTest()
{
  SetRobotAxisAndRotation(0.0, 1.0, 0.0, 0.0);  // Start with neutral rotation.
  SetRobotPosition0(DBS);     // Start in "natural" pose.
  delay(DBS);

  float angle = 1.0;

  for (angle = 1.0; angle <= 25.0; angle += 1.0)
  {
    SetRobotAxisAndRotation(0.0, 1.0, 0.0, angle);  // Start with neutral rotation.
    SetRobotPosition0(DB);     // Start in "natural" pose.
    delay(DB);
  }
  angle -= 1.0;
  delay(DBB);

  for (; angle >= -25.0; angle -= 1.0)
  {
    SetRobotAxisAndRotation(0.0, 1.0, 0.0, angle);
    SetRobotPosition0(DB);
    delay(DB);
  }
  angle += 1.0;
  delay(DBB);

  for (; angle < 0.0; angle += 1.0)
  {
    SetRobotAxisAndRotation(0.0, 1.0, 0.0, angle);
    SetRobotPosition0(DB);
    delay(DB);
  }
  SetRobotAxisAndRotation(0.0, 1.0, 0.0, 0.0);  // End with neutral rotation.
  SetRobotPosition0(DBF);     // End in "natural" pose.
  delay(DBF);
}

#define SA 15
  // Target swirl angle

#define SI 300
  // Iterations of full swirl

#define AI 0.2
  // Angle increment

// Starting from natural, and a y-axis rotation small, rotate that axis constantly around the z-axis,
// while increasing that rotation, then decrease it back to zero, and beyond to negative rotation.
// Then come back to zero rotation.
void SwirlTest()
{
  SetRobotAxisAndRotation(0.0, 1.0, 0.0, 0.0);  // Start with neutral rotation.
  SetRobotPosition0(DBS);     // Start in "natural" pose.
  delay(DBS);

  float rotateAxisX = 0.0;
  float rotateAxisY = 1.0;
  float rotateAxisZ = 0.0;
  float rotateAxisXin = 0.0;
  float rotateAxisYin = 1.0;
  float rotateAxisZin = 0.0;
  
  float angle = 1.0;

  Matrix3D zRotation;
  Construct3DRotationMatrix(&zRotation, 0.0, 0.0, 1.0, 5.0);

  for (angle = 1.0; angle <= SA; angle += AI)
  {
    SetRobotAxisAndRotation(rotateAxisX, rotateAxisY, rotateAxisZ, angle);
    SetRobotPosition0(DB);
    rotateAxisXin = rotateAxisX;
    rotateAxisYin = rotateAxisY;
    rotateAxisZin = rotateAxisZ;
    Multiply3D(&zRotation, rotateAxisXin, rotateAxisYin, rotateAxisZin, &rotateAxisX, &rotateAxisY, &rotateAxisZ);
    delay(DB);
  }
  for (int i = 1; i < SI; i++)
  {
    SetRobotAxisAndRotation(rotateAxisX, rotateAxisY, rotateAxisZ, angle);
    SetRobotPosition0(DB);
    rotateAxisXin = rotateAxisX;
    rotateAxisYin = rotateAxisY;
    rotateAxisZin = rotateAxisZ;
    Multiply3D(&zRotation, rotateAxisXin, rotateAxisYin, rotateAxisZin, &rotateAxisX, &rotateAxisY, &rotateAxisZ);
    delay(DB);
  }
  for (; angle > 0.0; angle -= AI)
  {
    SetRobotAxisAndRotation(rotateAxisX, rotateAxisY, rotateAxisZ, angle);
    SetRobotPosition0(DB);
    rotateAxisXin = rotateAxisX;
    rotateAxisYin = rotateAxisY;
    rotateAxisZin = rotateAxisZ;
    Multiply3D(&zRotation, rotateAxisXin, rotateAxisYin, rotateAxisZin, &rotateAxisX, &rotateAxisY, &rotateAxisZ);
    delay(DB);
  }

  delay(DBB);

  for (angle = 1.0; angle >= -SA; angle -= AI)
  {
    SetRobotAxisAndRotation(rotateAxisX, rotateAxisY, rotateAxisZ, angle);
    SetRobotPosition0(DB);
    rotateAxisXin = rotateAxisX;
    rotateAxisYin = rotateAxisY;
    rotateAxisZin = rotateAxisZ;
    Multiply3DInverse(&zRotation, rotateAxisXin, rotateAxisYin, rotateAxisZin, &rotateAxisX, &rotateAxisY, &rotateAxisZ);
    delay(DB);
  }
  for (int i = 1; i < SI; i++)
  {
    SetRobotAxisAndRotation(rotateAxisX, rotateAxisY, rotateAxisZ, angle);
    SetRobotPosition0(DB);
    rotateAxisXin = rotateAxisX;
    rotateAxisYin = rotateAxisY;
    rotateAxisZin = rotateAxisZ;
    Multiply3DInverse(&zRotation, rotateAxisXin, rotateAxisYin, rotateAxisZin, &rotateAxisX, &rotateAxisY, &rotateAxisZ);
    delay(DB);
  }
  for (; angle < 0.0; angle += AI)
  {
    SetRobotAxisAndRotation(rotateAxisX, rotateAxisY, rotateAxisZ, angle);
    SetRobotPosition0(DB);
    rotateAxisXin = rotateAxisX;
    rotateAxisYin = rotateAxisY;
    rotateAxisZin = rotateAxisZ;
    Multiply3DInverse(&zRotation, rotateAxisXin, rotateAxisYin, rotateAxisZin, &rotateAxisX, &rotateAxisY, &rotateAxisZ);
    delay(DB);
  }

  SetRobotAxisAndRotation(0.0, 1.0, 0.0, 0.0);  // End with neutral rotation.
  SetRobotPosition0(DBF);     // End in "natural" pose.
  delay(DBF);
}


#endif // EXERCISE


// END //
