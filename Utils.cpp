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


int ClampInt(int val, int Min, int Max)
{
  if (val <= Min)
    return Min;
  else if (val >= Max)
    return Max;
  else
    return val;
}


float ClampFloat(float val, float Min, float Max)
{
  if (val <= Min)
    return Min;
  else if (val >= Max)
    return Max;
  else
    return val;
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
 