// Kinematics.h
// Handles forward and inverse kinematics for the robot legs.


float GetAngleFromCosineLaw(float opp, float adj1, float adj2);

void ComputeFootPosition(float hipNatural, float hipX, float hipY, float kneeAngle, float verticalAngle, float hipAngle, float *xOut, float *yOut, float *zOut);

bool ComputeAngles(float x, float y, float z, float hipNatural, float hipX, float hipY, float *kneeAngleOut, float *verticalAngleOut, float *hipAngleOut);

void NormalisePosition(float x, float y, float z, float hipNatural, float hipX, float hipY, float *xOut, float *yOut);


// END //
