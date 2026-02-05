#ifndef Leg_h
#define Leg_h

#include "Servo.h"


//>>>> SOMEHOW, add proper interpolation.
// A single leg of the Hexapod robot.

class Leg
{
  private:
  
    Servo *_Knee;
    Servo *_Vertical;
    Servo *_Horizontal;

    float _xPos;  // Position of hip axis in mm.
    float _yPos;
    float _Angle; // Natural angle from forward = 0 degrees. Left is negative, Right is positive.

    float _FootXNatural;
    float _FootYNatural;
    float _FootZNatural;

    float _FootXCurrent;
    float _FootYCurrent;
    float _FootZCurrent;

    bool _FootPositionValid;

  public:
    
    Leg(float xPos, float yPos, Servo *Knee, Servo *Vertical, Servo *Horizontal, float Angle, float FootX, float FootY, float FootZ);

    void SetNatural(int Time);

    void InvalidateFootPosition() { _FootPositionValid = false; }
    
    void SetFootNatural(float x, float y, float z, int Time);   // Relative to natural foot position.
    void SetFootPosition(float x, float y, float z, int Time);  // Relative to central coordinates.
};

#endif

// END
