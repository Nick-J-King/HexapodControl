#ifndef Servo_h
#define Servo_h

class Leg;


class Servo
{
  private:

    int _Pin;
    int _Min;
    int _Max;
    int _Natural;   // PMW at zero degrees.

    Leg *_leg;

    int _CurrentPWM;
    int _CurrentAngle;

    void SetPWM(int Pos, int Time);   // Set Position by PWM (us) and Time (ms).

  public:

    Servo(int Pin, int Min, int Max, int Natural);
    void SetLeg(Leg *leg) { _leg = leg; }
    
    void SetAngle(float angle, int Time);
    
    int CurrentAngle();
};


#endif
