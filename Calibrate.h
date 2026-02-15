// Calibrate.h

#include "Robot.h"


void IncreaseStep();
void DecreaseStep();

void SelectLeg(Leg *leg);
void SelectServo(int whichServo);

void ServoMinus();
void ServoNatural();
void ServoPlus();

void HipCW45();
void HipCCW45();


// END //
