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


// >>> ALERT IF TRIANGLE CANNOT BE FORMED.
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

// Forward kinematics to determine foot position in central coordinates from given servo angles.
void ComputeFootPosition(float hipNatural, float hipX, float hipY, float kneeAngle, float verticalAngle, float hipAngle, float *xOut, float *yOut, float *zOut)
{
  // Start in "hip coords"
  float xKnee = FEMURLENGTH * cos(deg2rad(verticalAngle)) + HIPWIDTH;
  float zKnee = FEMURLENGTH * -sin(deg2rad(verticalAngle));

  float kneeAngleAdjusted = verticalAngle + kneeAngle;
   
  float xFoot = TIBIALENGTH * sin(deg2rad(kneeAngleAdjusted)) + xKnee;
  float zFoot = TIBIALENGTH * cos(deg2rad(kneeAngleAdjusted)) + zKnee;

  float hipAngleAdjusted = hipNatural - hipAngle;

  // Here, "distanceOut" is just the xFoot.
  // At the moment, yFoot is 0.
  
  // Now rotate and translate according to hip
  float xFootNew = xFoot * cos(deg2rad(hipAngleAdjusted));
  float yFootNew = xFoot * sin(deg2rad(hipAngleAdjusted));

  *xOut = xFootNew + hipX;
  *yOut = yFootNew + hipY;
  *zOut = zFoot;
}


// Inverse kinematics to determine servo angles from the desired foot position.
void ComputeAngles(float x, float y, float z, float hipNatural, float hipX, float hipY, float *kneeAngleOut, float *verticalAngleOut, float *hipAngleOut)
{
  float xNormal;
  float yNormal;

  NormalisePosition(x, y, z, hipNatural, hipX, hipY, &xNormal, &yNormal);

  float distanceOut = sqrt(xNormal * xNormal + yNormal * yNormal) - HIPWIDTH;
  *hipAngleOut = rad2deg(atan2(xNormal, yNormal));

    // >> If distance too small, use natural hip angle...
    // >> If angle > 90 or < -90, reverse it!!
  float dist2foot = sqrt(z * z + distanceOut * distanceOut);
    // If distance to foot is > FEMURLENGTH + TIBIALENGTH, we have a problem!

  *kneeAngleOut = GetAngleFromCosineLaw(dist2foot, FEMURLENGTH, TIBIALENGTH) - 90.0;

  float c = GetAngleFromCosineLaw(TIBIALENGTH, FEMURLENGTH, dist2foot);
  float d = rad2deg(atan2(z, distanceOut));
  
  *verticalAngleOut = c - d;
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


#ifdef DEBUG

void P(String s)
{
  Serial.println(s);
}


void NL()
{
  Serial.println("");
}

void PFV(String Name, float var)
{
  char sBuffer[150];
  char sVar[16];
  dtostrf(var, 4, 2, sVar);

  sprintf(sBuffer, "%s = %s", Name.c_str(), sVar);
  Serial.println(sBuffer);
}

#endif // DEBUG


void WaitForServos()
{
  String s;
  
  do
  {
    Serial.println("Q");
    s = ReadSerial();
    if (s == ".")
    {
      return;
    }
    delay(100);
  } while (true);
}


String ReadSerial()
{
  String readString;
  String Q;

  // Wait for text...
  while (!Serial.available()) {
    delay(1);
  }
  
  while (Serial.available())
  {
    delay(1);
 
    if (Serial.available() > 0)
    {
      char c = Serial.read();  //gets one byte from serial buffer
      if (isControl(c))
      {
        break;
      }
      readString += c; //makes the string readString    
    }
  }
  
  return readString;
}


 // END //
 