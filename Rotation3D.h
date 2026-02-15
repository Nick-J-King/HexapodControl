// Rotation3D.h

#ifndef Rotation3D_h
#define Rotation3D_h


// Matrix entries: m[row][col]
struct Matrix3D
{
  float m00;
  float m01;
  float m02;
  float m10;
  float m11;
  float m12;
  float m20;
  float m21;
  float m22;
};


float Length3D(float x, float y, float z);

void Multiply3D(Matrix3D *m, float x, float y, float z, float *xOut, float *yOut, float *zOut);
void Multiply3DInverse(Matrix3D *m, float x, float y, float z, float *xOut, float *yOut, float *zOut);
void NormaliseXYZ(float *x, float *y, float *z);
void Construct3DRotationMatrix(Matrix3D *m, float x, float y, float z, float angle);

#endif // Rotation3D_h

// END //
