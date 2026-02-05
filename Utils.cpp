// Utils.cpp

#include <Arduino.h>
#include "Robot.h"


// >>> OPTIMISE THESE AWAY IN THE PWMPERDEGREE factor...


float deg2rad(float deg)
{
  return deg * DEG_TO_RAD;
}


float rad2deg(float rad)
{
  return rad * RAD_TO_DEG;
}


int Clamp(int val, int Min, int Max)
{
  if (Min < Max)
  {
    // Normal way.
    if (val <= Min)
      return Min;
    else if (val >= Max)
      return Max;
    else
      return val;
  }
  else
  {
    // Reversed way.
    if (val >= Min)
      return Min;
    else if (val <= Max)
      return Max;
    else
      return val;
  }
}


// >>> ALERT IF TRIANGE CANNOT BE FORMED.
float GetAngleFromCosineLaw(float opp, float adj1, float adj2)
{
  return rad2deg(acos((adj1 * adj1 + adj2 * adj2 - opp * opp) / (2 * adj1 * adj2)));
}


// ((( OPTIMISE )))
// ((( ALERT ON ERRORS )))
// >>> CHECK THE EDGE CASES


// In mm:
//  x to the right
//  y forward
//  z down
void ComputeAngles(float x, float y, float z, float hipNatural, float hipX, float hipY, float *kneeAngleOut, float *verticalAngleOut, float *hipAngleOut, float *distanceOut)
{
  float xNormal;
  float yNormal;

  NormalisePosition(x, y, z, hipNatural, hipX, hipY, &xNormal, &yNormal);

  *distanceOut = sqrt(xNormal * xNormal + yNormal * yNormal) - HIPWIDTH;
  *hipAngleOut = rad2deg(atan2(xNormal, yNormal));

    // >> If distance too small, use natural hip angle...
    // >> If angle > 90 or < -90, reverse it!!
  float dist2foot = sqrt(z * z + *distanceOut * *distanceOut);
    // If distance to foot is > FEMURLENGTH + TIBIALENGTH, we have a problem!

  *kneeAngleOut = GetAngleFromCosineLaw(dist2foot, FEMURLENGTH, TIBIALENGTH) - 90.0;

  float c = GetAngleFromCosineLaw(TIBIALENGTH, FEMURLENGTH, dist2foot);
  float d = rad2deg(atan2(z, *distanceOut));
  
  *verticalAngleOut = c - d;
}


// >>> OPTIMISE
// >>> DON'T NEED Z

void NormalisePosition(float x, float y, float z, float hipNatural, float hipX, float hipY, float *xOut, float *yOut)
{
  float xTranslated = x - hipX;
  float yTranslated = y - hipY;
  float hipNaturalRadians = deg2rad(hipNatural);
  
  *xOut = xTranslated * cos(-hipNaturalRadians) + yTranslated * sin(-hipNaturalRadians);
  *yOut = -xTranslated * sin(-hipNaturalRadians) + yTranslated * cos(-hipNaturalRadians);
}


void P(char *s)
{
  Serial.println(s);
}


void NL()
{
  Serial.println("");
}

void PFV(char *Name, float var)
{
  char sBuffer[150];
  char sVar[16];
  dtostrf(var, 4, 2, sVar);

  sprintf(sBuffer, "%s = %s", Name, sVar);
  Serial.println(sBuffer);
}
