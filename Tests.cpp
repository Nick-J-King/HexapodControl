// Tests.cpp

#include "Tests.h"

#ifdef DEBUG


// Test kinematics of right front leg.
void TestKinematics()
{

  float footXin = 130;  //119.75;
  float footYin = 155.0;
  float footZin = 50.0; //125.0;

  float hipNatural = 40.0; //45.0;  // Test right front leg...
  float hipX = 39.5;
  float hipY = 74.75;

  float kneeAngle;
  float verticalAngle;
  float hipAngle;

  float footXout = 0;  
  float footYout = 0;  
  float footZout = 0;  

// hipNatural, hipX, hipY, kneeAngle, verticalAngle, hipAngle
  P("\nBasic test of foot position 1");
  ComputeFootPosition(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, &footXout, &footYout, &footZout);
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);

  P("\nBasic test of foot position 2");
  ComputeFootPosition(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, &footXout, &footYout, &footZout);
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);

  P("\nBasic test of foot position 3");
  ComputeFootPosition(10.0, 0.0, 0.0, 0.0, 0.0, 10.0, &footXout, &footYout, &footZout);
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);

  P("\nBasic test of foot position 4");
  ComputeFootPosition(10.0, 0.0, 0.0, 0.0, 0.0, -10.0, &footXout, &footYout, &footZout);
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);

  P("\nBasic test of foot position 5");
  ComputeFootPosition(0.0, 0.0, 0.0, 0.0, 0.0, -10.0, &footXout, &footYout, &footZout);
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);

  P("\nBasic test of foot position 6");
  ComputeFootPosition(0.0, 0.0, 0.0, 10.0, 0.0, 0.0, &footXout, &footYout, &footZout);
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);

  P("\nBasic test of foot position 7");
  ComputeFootPosition(0.0, 0.0, 0.0, 0.0, 10.0, 0.0, &footXout, &footYout, &footZout);
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);

  P("\nBasic test of foot position 8");
  ComputeFootPosition(0.0, 0.0, 0.0, 30.0, 10.0, 0.0, &footXout, &footYout, &footZout);
  PFV("footXout", footXout);
  PFV("footYout", footYout);
  PFV("footZout", footZout);

//return;

  P("\nTest kinematics of right front leg");

  ComputeAngles(footXin, footYin, footZin, hipNatural, hipX, hipY, &kneeAngle, &verticalAngle, &hipAngle);

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




  P("\nTest kinematics of right middle leg");

  footXin = 160.0;  //119.75;
  footYin = 0.0; //15.0;
  footZin = 50.0; //125.0;

  hipNatural = 90.0;  // Test right front leg...
  hipX = 64.3;
  hipY = 0.0;

  ComputeAngles(footXin, footYin, footZin, hipNatural, hipX, hipY, &kneeAngle, &verticalAngle, &hipAngle);

  footXout = 0;  
  footYout = 0;  
  footZout = 0;  

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
