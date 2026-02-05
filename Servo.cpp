// Controls individual servos.

#include <Arduino.h>
#include "Robot.h"

//>>> Record current PWM, and don't send if it is the same...

Servo::Servo(int Pin, int Min, int Max, int Natural)
{
  _Pin = Pin;
  _Min = Min;
  _Max = Max;
  _Natural = Natural;   // PWM in "natural" position.
}


// Set angle according to IK.
void Servo::PositionAngle(float angle, int Time)
{
  int pos;
  if (_Min < _Max)
  {
    pos = _Natural + angle * PWMPERDEGREE;
  }
  else
  {
    pos = _Natural - angle * PWMPERDEGREE;
  }
  
  PositionPWM(pos, Time);
}


// >>> Clamp against ABSOLUTEMIN and ABSOLUTEMAX too.

void Servo::PositionPWM(int Pos, int Time)
{
  char sBuffer [35];

  if (Time == 0)
  {
    sprintf(sBuffer, "#%dP%d", _Pin, Clamp(Pos, _Min, _Max));
  }
  else
  {
    sprintf(sBuffer, "#%dP%dT%d", _Pin, Clamp(Pos, _Min, _Max), Time);
  }

  Serial.println(sBuffer);
}


void Servo::CenterPWM(int Time)
{
  PositionPWM(ABSOLUTE_MIDDLE, Time);
}


void Servo::NaturalPWM(int Time)
{
  PositionPWM(_Natural, Time);
}


void Servo::PushForwardPWM(int amount, int Time)
{
  // From natural, go a bit towards "max".
  int pos;
  if (_Max > _Natural)
    pos = _Natural + amount;
  else
    pos = _Natural - amount;

  PositionPWM(pos, Time);
}


void Servo::PushBackwardPWM(int amount, int Time)
{
  // From natural, go a bit towards "min".
  int pos;
  if (_Max < _Natural)
    pos = _Natural + amount;
  else
    pos = _Natural - amount;

  PositionPWM(pos, Time);
}
