// Kinematics.cpp

#include "Kinematics.h"
#include "Robot.h"


// >>> ALERT IF TRIANGLE CANNOT BE FORMED.
float GetAngleFromCosineLaw(float opp, float adj1, float adj2)
{
  return rad2deg(acos((adj1 * adj1 + adj2 * adj2 - opp * opp) / (2 * adj1 * adj2)));
}


// ((( OPTIMISE )))
// ((( ALERT ON ERRORS )))
// >>> CHECK THE EDGE CASES

// TEMP:


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

// In mm:
//  x to the right
//  y forward
//  z down


// >>> DON'T USE DELTA MOVES UNTIL THE ROBOT ORIENTATION IS INCORPORATED!!!

// Forward kinematics to determine foot position in central coordinates from given servo angles.
void ComputeFootPosition(float hipNatural, float hipX, float hipY, float kneeAngle, float verticalAngle, float hipAngle, float *xOut, float *yOut, float *zOut)
{
  // Start in "hip coords"
  float yKnee = FEMURLENGTH * cos(deg2rad(verticalAngle)) + HIPWIDTH;
  float zKnee = FEMURLENGTH * -sin(deg2rad(verticalAngle));

  float kneeAngleAdjusted = verticalAngle + kneeAngle;
   
  float yFoot = TIBIALENGTH * sin(deg2rad(kneeAngleAdjusted)) + yKnee;
  float zFoot = TIBIALENGTH * cos(deg2rad(kneeAngleAdjusted)) + zKnee;

  float hipAngleAdjusted = hipNatural + hipAngle;

  // Here, "distanceOut" is just the yFoot.
  // At the moment, xFoot is 0.
  
  // Now rotate and translate according to hip
  float xFootNew = yFoot * sin(deg2rad(hipAngleAdjusted));
  float yFootNew = yFoot * cos(deg2rad(hipAngleAdjusted));

  *xOut = xFootNew + hipX;
  *yOut = yFootNew + hipY;
  *zOut = zFoot;
}


// Inverse kinematics to determine servo angles from the desired foot position.
// Return true if OK, false for an impossible position.
bool ComputeAngles(float xIn, float yIn, float zIn, float hipNatural, float hipX, float hipY, float *kneeAngleOut, float *verticalAngleOut, float *hipAngleOut)
{
  float x, y, z;
//PrintMatrix("Robot matrix", &robotRotationMatrix);

  // OK! We are adjusting to an oriented body!!
  Multiply3D(&robotRotationMatrix, xIn, yIn, zIn, &x, &y, &z);

//PrintVector("\nIN", xIn, yIn, zIn);
//PrintVector("Rotated", x, y, z);

  bool OK = true;

  float xNormal;
  float yNormal;

  NormalisePosition(x, y, z, hipNatural, hipX, hipY, &xNormal, &yNormal);

  float distanceOut = sqrt(xNormal * xNormal + yNormal * yNormal) - HIPWIDTH;
  *hipAngleOut = rad2deg(atan2(xNormal, yNormal));

    // >> If distance too small, use natural hip angle...
  float dist2foot = sqrt(z * z + distanceOut * distanceOut);
    // If distance to foot is > FEMURLENGTH + TIBIALENGTH, we have a problem!
  if (dist2foot > FEMURLENGTH + TIBIALENGTH)
  {
    OK = false;
  } 
  *kneeAngleOut = GetAngleFromCosineLaw(dist2foot, FEMURLENGTH, TIBIALENGTH) - 90.0;

  if (isnan(*kneeAngleOut))
  {
    OK = false;
  }

  float v = GetAngleFromCosineLaw(TIBIALENGTH, FEMURLENGTH, dist2foot) - rad2deg(atan2(z, distanceOut));;
  if (isnan(v))
  {
    OK = false;
  }
  
  *verticalAngleOut = v;

  return OK;
}


// >>> OPTIMISE

void NormalisePosition(float x, float y, float z, float hipNatural, float hipX, float hipY, float *xOut, float *yOut)
{
  float xTranslated = x - hipX;
  float yTranslated = y - hipY;
  float hipNaturalRadians = deg2rad(hipNatural);
  
  *xOut = xTranslated * cos(-hipNaturalRadians) + yTranslated * sin(-hipNaturalRadians);
  *yOut = -xTranslated * sin(-hipNaturalRadians) + yTranslated * cos(-hipNaturalRadians);
}


// END //
