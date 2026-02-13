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
  lRF.SetFootNatural(0.0, 0, Z0, Time); // A
  lRM.SetFootNatural(0.0, 0, Z0, Time);
  lRB.SetFootNatural(0.0, 0, Z0, Time); // A

  // Left
  lLF.SetFootNatural(0.0, 0, Z0, Time);
  lLM.SetFootNatural(0.0, 0, Z0, Time); // A
  lLB.SetFootNatural(0.0, 0, Z0, Time);

  WaitForServos();

    // Right
  lRF.SetFootNatural(0.0, 0, Z1, Time1); // A
  lRM.SetFootNatural(0.0, 0, Z1, Time1);
  lRB.SetFootNatural(0.0, 0, Z1, Time1); // A

  // Left
  lLF.SetFootNatural(0.0, 0, Z1, Time1);
  lLM.SetFootNatural(0.0, 0, Z1, Time1); // A
  lLB.SetFootNatural(0.0, 0, Z1, Time1);

  WaitForServos();
    
  // Right
  lRF.SetFootNatural(0.0, 0, Z0, Time); // A
  lRM.SetFootNatural(0.0, 0, Z0, Time);
  lRB.SetFootNatural(0.0, 0, Z0, Time); // A

  // Left
  lLF.SetFootNatural(0.0, 0, Z0, Time);
  lLM.SetFootNatural(0.0, 0, Z0, Time); // A
  lLB.SetFootNatural(0.0, 0, Z0, Time);

  WaitForServos();
  
    // Right
  lRF.SetFootNatural(0.0, 0, -Z1, Time1); // A
  lRM.SetFootNatural(0.0, 0, -Z1, Time1);
  lRB.SetFootNatural(0.0, 0, -Z1, Time1); // A

  // Left
  lLF.SetFootNatural(0.0, 0, -Z1, Time1);
  lLM.SetFootNatural(0.0, 0, -Z1, Time1); // A
  lLB.SetFootNatural(0.0, 0, -Z1, Time1);

  WaitForServos();
    
  // Right
  lRF.SetFootNatural(0.0, 0, Z0, Time); // A
  lRM.SetFootNatural(0.0, 0, Z0, Time);
  lRB.SetFootNatural(0.0, 0, Z0, Time); // A

  // Left
  lLF.SetFootNatural(0.0, 0, Z0, Time);
  lLM.SetFootNatural(0.0, 0, Z0, Time); // A
  lLB.SetFootNatural(0.0, 0, Z0, Time);

  WaitForServos();
  
    // Right
  lRF.SetFootNatural(0.0, 0, Z1, Time1); // A
  lRM.SetFootNatural(0.0, 0, Z1, Time1);
  lRB.SetFootNatural(0.0, 0, Z1, Time1); // A

  // Left
  lLF.SetFootNatural(0.0, 0, Z1, Time1);
  lLM.SetFootNatural(0.0, 0, Z1, Time1); // A
  lLB.SetFootNatural(0.0, 0, Z1, Time1);

  WaitForServos();

    // Right
  lRF.SetFootNatural(0.0, 0, Z2, Time1); // A
  lRM.SetFootNatural(0.0, 0, Z2, Time1);
  lRB.SetFootNatural(0.0, 0, Z2, Time1); // A

  // Left
  lLF.SetFootNatural(0.0, 0, Z2, Time1);
  lLM.SetFootNatural(0.0, 0, Z2, Time1); // A
  lLB.SetFootNatural(0.0, 0, Z2, Time1);
}


void WakeUp()
{
  WakeUpLeg(&lRF);
  WakeUpLeg(&lLF);

  WakeUpLeg(&lRB);
  WakeUpLeg(&lLB);
  
  WakeUpLeg(&lRM);
  WakeUpLeg(&lLM);

  StandUp();
}

// END //
