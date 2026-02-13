// Tests.cpp

#include "Tests.h"

#ifdef DEBUG


// Test kinematics of right front leg.
void TestKinematics()
{

  P("\nTest kinmatics of right front leg");

  float footXin = 130;  //119.75;
  float footYin = 155.0;
  float footZin = 50.0; //125.0;

  float hipNatural = 45.0;  // Test right front leg...
  float hipX = 39.5;
  float hipY = 74.75;

  float kneeAngle;
  float verticalAngle;
  float hipAngle;
  
  ComputeAngles(footXin, footYin, footZin, hipNatural, hipX, hipY, &kneeAngle, &verticalAngle, &hipAngle);

  float footXout = 0;  
  float footYout = 0;  
  float footZout = 0;  

  ComputeFootPosition(hipNatural, hipX, hipY, kneeAngle, verticalAngle, hipAngle, &footXout, &footYout, &footZout);

  // Now, foot[XYZ]out should equal foot[XYZ]in...
  PFV("footXin", footXin);
  PFV("footYin", footYin);
  PFV("footZin", footZin);
  NL();
  PFV("kneeAngle", kneeAngle);
  PFV("verticalAngle", verticalAngle);
  PFV("hipAngle", hipAngle);
  NL();
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);
}

#endif // DEBUG


// END //
