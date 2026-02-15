// Rotation3D.cpp

#include "Rotation3D.h"
#include "Utils.h"


float Length3D(float x, float y, float z)
{
  return sqrt(x * x + y * y + z * z);
}


// Assume x,y,z is a 3x1 column matrix, and matrix m is 3x3.
// Return matrix * (x,y,z)
void Multiply3D(Matrix3D *m, float x, float y, float z, float *xOut, float *yOut, float *zOut)
{
  *xOut = m->m00 * x + m->m01 * y + m->m02 * z;
  *yOut = m->m10 * x + m->m11 * y + m->m12 * z;
  *yOut = m->m20 * x + m->m21 * y + m->m22 * z;
}


void NormaliseXYZ(float *x, float *y, float *z)
{
  float length = sqrt(*x * *x + *y * *y + *z * *z);

  *x = *x / length;
  *y = *y / length;
  *z = *z / length;
}


// Assume the axis (vector x,y,z) is normalised.
void Construct3DRotationMatrix(Matrix3D *m, float x, float y, float z, float angle)
{
  float s = sin(deg2rad(angle));
  float c = cos(deg2rad(angle));
  float c1 = 1.0 - c;
  
  float xyc1 = x * y * c1;
  float xzc1 = x * z * c1;
  float yzc1 = y * z * c1;
  
  float xs = x * s;
  float ys = y * s;
  float zs = z * s;
  
  m->m00 = x * x * c1 + c;
  m->m01 = xyc1 - zs;
  m->m02 = xzc1 + ys;

  m->m10 = xyc1 + zs;
  m->m11 = y * y * c1 + c;
  m->m12 = yzc1 - xs;

  m->m20 = xzc1 - ys;
  m->m21 = yzc1 + xs;
  m->m22 = z * z * c1 + c;
}


// END //
