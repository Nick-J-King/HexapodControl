#ifndef Leg_h
#define Leg_h

//>>>> SOMEHOW, add proper interpolation.
// A single leg of the Hexapod robot.

class Leg
{
  public:

    Servo *_Knee;
    Servo *_Vertical;
    Servo *_Horizontal;

    float _xPos;  // Position of hip axis in mm.
    float _yPos;
    float _Angle; // Angle from forward = 0 degrees. Left is negative, Right is positive.

    float _FootXNatural;
    float _FootYNatural;
    float _FootZNatural;

    Leg(float xPos, float yPos, Servo *Knee, Servo *Vertical, Servo *Horizontal, float Angle, float FootX, float FootY, float FootZ);

    void SetFootPosition(float x, float y, float z, int Time);
    void SetFootNatural(int Time);
    void SetFootNaturalDelta(float x, float y, float z, int Time);

    //>>> Add function to set all servos in one go.
    
    void CenterPWM(int Time);   // Centre all servos in the leg (ABSOLUTE_MIDDLE).
    void NaturalPWM(int Time);  // Centre of the servos to "natural" rest position.

    // Move by a PWM time from "natural" PWM position.
    void PushForwardPWM(int amount, int Time);
    void PushBackwardPWM(int amount, int Time);
    void LowerLegOutPWM(int amount, int Time);
    void LowerLegInPWM(int amount, int Time);
    void UpperLegUpPWM(int amount, int Time);
    void UpperLegDownPWM(int amount, int Time);
};

#endif
