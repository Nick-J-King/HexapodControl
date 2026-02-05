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

  _FootXCurrent = -1000;
  _FootYCurrent = -1000;
  _FootZCurrent = -1000;
}


void Leg::SetFootNatural(int Time)
{
  SetFootPosition(_FootXNatural, _FootYNatural, _FootZNatural, Time);
}


void Leg::SetFootNaturalDelta(float x, float y, float z, int Time)
{
  SetFootPosition(_FootXNatural + x, _FootYNatural + y, _FootZNatural + z, Time);
}


// Set foot position relative to "natural" foot position.
// x is right, y is forward, z is down
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

  _FootXCurrent = x;
  _FootYCurrent = y;
  _FootZCurrent = z;

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
