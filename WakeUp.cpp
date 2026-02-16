// WakeUp.cpp

#include "Robot.h"
#include <Arduino.h>

// Assume the robot starts on its belly.


void WakeUpLeg(Leg *leg)
{
  Servo *knee = leg->Knee();
  Servo *vertical = leg->Vertical();
  Servo *horizontal = leg->Horizontal();

  knee->SetAngle(80, 0); // Extend lower leg.
  delay(200);
  vertical->SetAngle(50, 0);
  horizontal->SetAngle(0, 0);
  delay(300);
  vertical->SetAngle(40, 500);
  knee->SetAngle(30, 500);
  delay(1000);
}


// Push all feet down to natural Z position to stand up.
void StandUp()
{
  float Time = 1000;
  float Time1 = 1000;
  float Z0 = 0;
  float Z1 = TIBIALENGTH / 3.0;
  float Z2 = -TIBIALENGTH + 20;
  
  // Right
  legRF.SetFootNatural(0.0, 0, Z0, Time); // A
  legRM.SetFootNatural(0.0, 0, Z0, Time);
  legRB.SetFootNatural(0.0, 0, Z0, Time); // A

  // Left
  legLF.SetFootNatural(0.0, 0, Z0, Time);
  legLM.SetFootNatural(0.0, 0, Z0, Time); // A
  legLB.SetFootNatural(0.0, 0, Z0, Time);

  WaitForServos();

    // Right
  legRF.SetFootNatural(0.0, 0, Z1, Time1); // A
  legRM.SetFootNatural(0.0, 0, Z1, Time1);
  legRB.SetFootNatural(0.0, 0, Z1, Time1); // A

  // Left
  legLF.SetFootNatural(0.0, 0, Z1, Time1);
  legLM.SetFootNatural(0.0, 0, Z1, Time1); // A
  legLB.SetFootNatural(0.0, 0, Z1, Time1);

  WaitForServos();
    
  // Right
  legRF.SetFootNatural(0.0, 0, Z0, Time); // A
  legRM.SetFootNatural(0.0, 0, Z0, Time);
  legRB.SetFootNatural(0.0, 0, Z0, Time); // A

  // Left
  legLF.SetFootNatural(0.0, 0, Z0, Time);
  legLM.SetFootNatural(0.0, 0, Z0, Time); // A
  legLB.SetFootNatural(0.0, 0, Z0, Time);

  WaitForServos();
  
    // Right
  legRF.SetFootNatural(0.0, 0, -Z1, Time1); // A
  legRM.SetFootNatural(0.0, 0, -Z1, Time1);
  legRB.SetFootNatural(0.0, 0, -Z1, Time1); // A

  // Left
  legLF.SetFootNatural(0.0, 0, -Z1, Time1);
  legLM.SetFootNatural(0.0, 0, -Z1, Time1); // A
  legLB.SetFootNatural(0.0, 0, -Z1, Time1);

  WaitForServos();
    
  // Right
  legRF.SetFootNatural(0.0, 0, Z0, Time); // A
  legRM.SetFootNatural(0.0, 0, Z0, Time);
  legRB.SetFootNatural(0.0, 0, Z0, Time); // A

  // Left
  legLF.SetFootNatural(0.0, 0, Z0, Time);
  legLM.SetFootNatural(0.0, 0, Z0, Time); // A
  legLB.SetFootNatural(0.0, 0, Z0, Time);

  WaitForServos();
  
    // Right
  legRF.SetFootNatural(0.0, 0, Z1, Time1); // A
  legRM.SetFootNatural(0.0, 0, Z1, Time1);
  legRB.SetFootNatural(0.0, 0, Z1, Time1); // A

  // Left
  legLF.SetFootNatural(0.0, 0, Z1, Time1);
  legLM.SetFootNatural(0.0, 0, Z1, Time1); // A
  legLB.SetFootNatural(0.0, 0, Z1, Time1);

  WaitForServos();

    // Right
  legRF.SetFootNatural(0.0, 0, Z2, Time1); // A
  legRM.SetFootNatural(0.0, 0, Z2, Time1);
  legRB.SetFootNatural(0.0, 0, Z2, Time1); // A

  // Left
  legLF.SetFootNatural(0.0, 0, Z2, Time1);
  legLM.SetFootNatural(0.0, 0, Z2, Time1); // A
  legLB.SetFootNatural(0.0, 0, Z2, Time1);
}


void WakeUp()
{
  WakeUpLeg(&legRF);
  WakeUpLeg(&legLF);

  WakeUpLeg(&legRB);
  WakeUpLeg(&legLB);
  
  WakeUpLeg(&legRM);
  WakeUpLeg(&legLM);

  StandUp();
}

// END //
