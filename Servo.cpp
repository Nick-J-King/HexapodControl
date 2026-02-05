// Controls individual servos.

#include <Arduino.h>
#include "Robot.h"


Servo::Servo(int Pin, int Min, int Max, int Natural)
{
  _Pin = Pin;
  _Min = Min;
  _Max = Max;
  _Natural = Natural;   // PWM in "natural" position.

  _CurrentPWM = 0;
  _CurrentAngle = UNKNOWN_ANGLE;
}


// Set angle according to IK.
void Servo::SetAngle(float angle, int Time)
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
  
  SetPWM(pos, Time);

  _CurrentAngle = angle;
  _leg->InvalidateFootPosition();
}


// >>> Clamp against ABSOLUTEMIN and ABSOLUTEMAX too.

void Servo::SetPWM(int Pos, int Time)
{
  if (_CurrentPWM == Pos)
    return;

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

  _CurrentPWM = Pos;
}


// END
