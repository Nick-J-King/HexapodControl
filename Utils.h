// Utils.h

#ifndef Utils_h
#define Utils_h


#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105


float deg2rad(float deg);
float rad2deg(float rad);


void SerialWriteLine();
void SerialWrite();

int Clamp(int val, int Min, int Max);
float GetAngleFromCosineLaw(float opp, float adj1, float adj2);

void ComputeAngles(float x, float y, float z, float hipNatural, float hipX, float hipY, float *kneeAngleOut, float *verticalAngleOut, float *hipAngleOut);
void NormalisePosition(float x, float y, float z, float hipNatural, float hipX, float hipY, float *xOut, float *yOut);

void P(char *s);
void NL();
void PFV(char *Name, float var);

#endif
