// WakeUp.cpp

#include "Robot.h"

// Assume the robot starts on its belly.


void WakeUpLeg(Leg *leg)
{
  
}


// Push all feet down to natural Z position to stand up.
void StandUp()
{
  
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
