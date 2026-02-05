#ifndef Servo_h
#define Servo_h

class Servo
{
  private:

    int _Pin;
    int _Min;
    int _Max;
    int _Natural;

    int _CurrentPWM;

  public:

    Servo(int Pin, int Min, int Max, int Natural);

    void PositionAngle(float angle, int Time);
    
    void PositionPWM(int Pos, int Time);   // Set Position by PWM (us) and Time (ms).
    void CenterPWM(int Time);  // Go to 1500
    void NaturalPWM(int Time); // Go to "resting" position.

    int CurrentPWM();
};


#endif
