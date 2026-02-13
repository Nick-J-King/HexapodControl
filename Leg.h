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

    float _xPos;  // Position of hip axis (in mm) in central coordinates.
    float _yPos;
    float _Angle; // Natural angle of leg (from forward = 0 degrees). Left is negative, Right is positive.

    float _FootXNatural;  // Natural position of foot in central coordinates.
    float _FootYNatural;
    float _FootZNatural;

    float _FootXCurrent;  // Position of foot in central coordinates.
    float _FootYCurrent;
    float _FootZCurrent;

    bool _FootPositionValid;

  public:
    
    Leg(float xPos, float yPos, Servo *Knee, Servo *Vertical, Servo *Horizontal, float Angle, float FootX, float FootY, float FootZ);

    Servo *Knee() { return _Knee; }
    Servo *Vertical() { return _Vertical; }
    Servo *Horizontal() { return _Horizontal; }
    
    void SetNatural(int Time);

    void InvalidateFootPosition() { _FootPositionValid = false; }
    
    void SetFootNatural(float x, float y, float z, int Time);   // Relative to natural foot position.
    void SetFootPosition(float x, float y, float z, int Time);  // Relative to central coordinates.

    void SetFootDelta(float x, float y, float z, int Time);     // Relative to current foot position.

    void ReportLeg(String Name)
    {
      P(" " + Name + " foot at current position Central:(" + String(_FootXCurrent) + ", " + String(_FootYCurrent) + ", " + String(_FootZCurrent) + ")  Natural:(" + String(_FootXCurrent - _FootXNatural) + ", " + String(_FootYCurrent - _FootYNatural) + ", " + String(_FootZCurrent - _FootZNatural) + ")");

      _Knee->ReportServo(Name + " Knee");
      _Vertical->ReportServo(Name + " Vertical");
      _Horizontal->ReportServo(Name + " Horizontal");
    }
};

#endif

// END
