// Handle a robot leg.

#include "Robot.h"


Leg::Leg(float xPos, float yPos, Servo *Knee, Servo *Vertical, Servo *Horizontal, float Angle, float FootX, float FootY, float FootZ)
{
  _xPos = xPos;
  _yPos = yPos;
  
  _Knee = Knee;
  _Vertical = Vertical;
  _Horizontal = Horizontal;
  
  _Angle = Angle;

  _FootXNatural = FootX;
  _FootYNatural = FootY;
  _FootZNatural = FootZ;
}


void Leg::SetFootNatural(int Time)
{
  SetFootPosition(_FootXNatural, _FootYNatural, _FootZNatural, Time);
}


void Leg::SetFootNaturalDelta(float x, float y, float z, int Time)
{
  SetFootPosition(_FootXNatural + x, _FootYNatural + y, _FootZNatural + z, Time);
}


void Leg::SetFootPosition(float x, float y, float z, int Time)
{
  float kneeAngle;
  float verticalAngle;
  float hipAngle;
  float distanceOut;
  
  // This should be the "natural" front right leg.
  ComputeAngles(x, y, z, _Angle, _xPos, _yPos, &kneeAngle, &verticalAngle, &hipAngle, &distanceOut);

  //>>> Use function to set all the servos at once...
  _Knee->PositionAngle(kneeAngle, Time);
  _Vertical->PositionAngle(verticalAngle, Time);
  _Horizontal->PositionAngle(hipAngle, Time);
}


// Centre all servos in the leg.
void Leg::CenterPWM(int Time)
{
  _Knee->CenterPWM(Time);
  _Vertical->CenterPWM(Time);
  _Horizontal->CenterPWM(Time);
}


void Leg::NaturalPWM(int Time)
{
  _Knee->NaturalPWM(Time);
  _Vertical->NaturalPWM(Time);
  _Horizontal->NaturalPWM(Time);
}


void Leg::PushForwardPWM(int amount, int Time)
{
  _Knee->PushForwardPWM(amount, Time);
  _Vertical->PushForwardPWM(amount, Time);
  _Horizontal->PushForwardPWM(amount, Time);
}


void Leg::PushBackwardPWM(int amount, int Time)
{
  _Knee->PushBackwardPWM(amount, Time);
  _Vertical->PushBackwardPWM(amount, Time);
  _Horizontal->PushBackwardPWM(amount, Time);
}


void Leg::LowerLegOutPWM(int amount, int Time)
{
  _Knee->PushForwardPWM(amount, Time);
}


void Leg::LowerLegInPWM(int amount, int Time)
{
  _Knee->PushBackwardPWM(amount, Time);
}


void Leg::UpperLegUpPWM(int amount, int Time)
{
  _Vertical->PushForwardPWM(amount, Time);
}


void Leg::UpperLegDownPWM(int amount, int Time)
{
  _Vertical->PushBackwardPWM(amount, Time);
}
