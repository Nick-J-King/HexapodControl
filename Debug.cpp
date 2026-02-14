// Debug.cpp

#include "Robot.h"

#ifdef DEBUG

#include "Debug.h"
#include "Tests.h"


void loop()
{
}


// Run debug checks from setup(), if in DEBUG mode.
void RunDebugChecks()
{
/*
  P("\nSet natural position");
  SetRobotPosition0(0);     // Start in "natural" pose...
  ReportRobot();
  delay(1000);
*/
  TestKinematics();
/*
  P("\nSet right front foot delta 10,20,30");
  lRF.SetFootDelta(10.0, 20.0, 30.0, 0);
  ReportRobot();

  P("\nSet right front hip servo to 0 degrees");
  lRF.Horizontal()->SetAngle(0.0, 0);
  ReportRobot();

  P("\nSet right front foot delta -10,-20,-30");
  lRF.SetFootDelta(-10.0, -20.0, -30.0, 0);
  ReportRobot();
*/
}


#endif // DEBUG


// END //
