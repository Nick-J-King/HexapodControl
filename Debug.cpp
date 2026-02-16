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

  TestKinematics();

  P("\nSet right front foot delta 10,20,30");
  legRF.SetFootDelta(10.0, 20.0, 30.0, 0);
  ReportRobot();

  P("\nSet right front hip servo to 0 degrees");
  legRF.Horizontal()->SetAngle(0.0, 0);
  ReportRobot();

  P("\nSet right front foot delta -10,-20,-30");
  legRF.SetFootDelta(-10.0, -20.0, -30.0, 0);
  ReportRobot();
*/

  float x, y, z;
  x = 0.0;
  y = 0.0;
  z = 4.0;

  P("Check my 3D vector maths");

  PrintVector("Un-normalised", x, y, z);
  NormaliseXYZ(&x, &y, &z);
  PrintVector("Normalised", x, y, z);
  PFV("Length", Length3D(x, y, z));

  Matrix3D m;
  Construct3DRotationMatrix(&m, x, y, z, 0.0);
  PrintMatrix("No rotation", &m);

  Construct3DRotationMatrix(&m, x, y, z, 1.0);
  PrintMatrix("Small +ve rotation about z axis", &m);

  Construct3DRotationMatrix(&m, x, y, z, 10.0);
  PrintMatrix("Reasonable +ve rotation about z axis", &m);

  Construct3DRotationMatrix(&m, x, y, z, 90.0);
  PrintMatrix("90 degree +ve rotation about z axis", &m);
}


void PrintMatrix(String sName, Matrix3D *m)
{
  char sBuffer[150];
  char s00[16];
  char s01[16];
  char s02[16];
  char s10[16];
  char s11[16];
  char s12[16];
  char s20[16];
  char s21[16];
  char s22[16];

  dtostrf(m->m00, 4, 2, s00);
  dtostrf(m->m01, 4, 2, s01);
  dtostrf(m->m02, 4, 2, s02);
  dtostrf(m->m10, 4, 2, s10);
  dtostrf(m->m11, 4, 2, s11);
  dtostrf(m->m12, 4, 2, s12);
  dtostrf(m->m20, 4, 2, s20);
  dtostrf(m->m21, 4, 2, s21);
  dtostrf(m->m22, 4, 2, s22);

  sprintf(sBuffer, "%s: [(%s, %s, %s), (%s, %s, %s), (%s, %s, %s)]", sName.c_str(), s00, s01, s02, s10, s11, s12, s20, s21, s22);
  Serial.println(sBuffer);
}

void PrintVector(String sName, float x, float y, float z)
{
  char sBuffer[150];
  char sX[16];
  char sY[16];
  char sZ[16];
  dtostrf(x, 4, 2, sX);
  dtostrf(y, 4, 2, sY);
  dtostrf(z, 4, 2, sZ);

  sprintf(sBuffer, "%s: (%s, %s, %s)", sName.c_str(), sX, sY, sZ);
  Serial.println(sBuffer);
}

#endif // DEBUG


// END //
