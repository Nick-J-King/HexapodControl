// Servo.cpp
//
// Controls individual servos.


#include "Robot.h"


Servo::Servo(int Pin, bool Reverse, int NaturalPWM, float MinAngle, float MaxAngle)
{
  _Pin = Pin;
  _Reverse = Reverse;
  _MinAngle = MinAngle;
  _MaxAngle = MaxAngle;
  _NaturalPWM = NaturalPWM;   // PWM in "natural" position.

  _CurrentPWM = 0;
  _CurrentAngle = UNKNOWN_ANGLE;
}

// >>> Need to flag if angle was clamped.

// Set angle according to IK.
void Servo::SetAngle(float angle, int Time)
{
  angle = ClampFloat(angle, _MinAngle, _MaxAngle);

  int PWM;
  if (_Reverse)
  {
    PWM = _NaturalPWM - angle * PWMPERDEGREE;
  }
  else
  {
    PWM = _NaturalPWM + angle * PWMPERDEGREE;
  }
  
  SetPWM(PWM, Time);

  _CurrentAngle = angle;
  _leg->InvalidateFootPosition();
}


// >>> Need to flag if PWM was clamped.

void Servo::SetPWM(int PWM, int Time)
{
  if (_CurrentPWM == PWM)
    return;

  PWM = ClampInt(PWM, ABSOLUTE_MIN, ABSOLUTE_MAX);

  char sBuffer [35];

  if (Time == 0)
  {
    sprintf(sBuffer, "#%dP%d", _Pin, PWM);
  }
  else
  {
    sprintf(sBuffer, "#%dP%dT%d", _Pin, PWM, Time);
  }

  Serial.println(sBuffer);

  _CurrentPWM = PWM;
}


// END //
