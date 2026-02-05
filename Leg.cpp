// Handle a robot leg.

#include "Robot.h"


Leg::Leg(float xPos, float yPos, Servo *Knee, Servo *Vertical, Servo *Horizontal, float Angle, float FootX, float FootY, float FootZ)
{
  _xPos = xPos;
  _yPos = yPos;
  
  _Knee = Knee;
  _Vertical = Vertical;
  _Horizontal = Horizontal;

  _Knee->SetLeg(this);
  _Vertical->SetLeg(this);
  _Horizontal->SetLeg(this);
  
  _Angle = Angle;

  _FootXNatural = FootX;
  _FootYNatural = FootY;
  _FootZNatural = FootZ;

  _FootXCurrent = UNKNOWN_POSITION;
  _FootYCurrent = UNKNOWN_POSITION;
  _FootZCurrent = UNKNOWN_POSITION;

  _FootPositionValid = false;
}


// Set the foot to its natural position.
// This is the same as all servos to zero angle.
void Leg::SetNatural(int Time)
{
  _Knee->SetAngle(0.0, Time);
  _Vertical->SetAngle(0.0, Time);
  _Horizontal->SetAngle(0.0, Time);

  _FootXCurrent = _FootXNatural;
  _FootYCurrent = _FootYNatural;
  _FootZCurrent = _FootZNatural;
  
  _FootPositionValid = true;
}


// Set foot position relative to "natural" foot position.
// This makes keyframing gaits simpler.
void Leg::SetFootNatural(float x, float y, float z, int Time)
{
  SetFootPosition(_FootXNatural + x, _FootYNatural + y, _FootZNatural + z, Time);
}


// Set foot position relative to "central" coords.
// Center of robot (0,0). Z=0 is level with the axis of the vertical servos. 
// x is right, y is forward, z is down
void Leg::SetFootPosition(float x, float y, float z, int Time)
{
  float kneeAngle;
  float verticalAngle;
  float hipAngle;
  
  // This should be the "natural" front right leg.
  ComputeAngles(x, y, z, _Angle, _xPos, _yPos, &kneeAngle, &verticalAngle, &hipAngle);

  //>>> Use function to set all the servos at once...
  _Knee->SetAngle(kneeAngle, Time);
  _Vertical->SetAngle(verticalAngle, Time);
  _Horizontal->SetAngle(hipAngle, Time);

  _FootXCurrent = x;
  _FootYCurrent = y;
  _FootZCurrent = z;

  _FootPositionValid = true;
}

// END
