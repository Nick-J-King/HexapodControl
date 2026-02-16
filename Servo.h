#ifndef Servo_h
#define Servo_h


#include <Arduino.h>
#include "Utils.h"

class Leg;


class Servo
{
  private:

    int _Pin;
    bool _Reverse;
    float _MinAngle;
    float _MaxAngle;
    int _NaturalPWM;   // PWM value at zero degrees.

    Leg *_leg;

    int _CurrentPWM;
    float _CurrentAngle;

    void SetPWM(int Pos, int Time);   // Set Position by PWM (us) and Time (ms).

  public:

    Servo(int Pin, bool Reverse, int NaturalPWM, float MinAngle, float MaxAngle);
    void SetLeg(Leg *leg) { _leg = leg; }
    
    bool IsAngleValid(float angle) { return ((angle >= _MinAngle) && (angle <= _MaxAngle)); }
    void SetAngle(float angle, int Time);
    void SetNatural(int Time);
    void SetCenter(int Time);
    
    float GetAngle()
    {
      return _CurrentAngle;
    }  // <<< Assume current angle is valid for now...

#ifdef DEBUG
    void ReportServo(String Name) { P("  " + Name + " servo at angle " + String(_CurrentAngle) + " degrees"); }
#endif // DEBUG
};


#endif // Servo_h


// END //
