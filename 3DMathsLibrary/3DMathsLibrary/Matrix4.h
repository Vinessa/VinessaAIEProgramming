#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include "Vector2.h"
#include "Vector3.h"
#include "math.h"

class Matrix4
{
public:
	Matrix4(void);
	Matrix4(float a_A1, float a_B1, float a_C1, float a_D1, float a_A2, float a_B2, float a_C2, float a_D2, float a_A3, float a_B3, float a_C3, float a_D3, float a_A4, float a_B4, float a_C4, float a_D4);
	~Matrix4(void);

	Vector3 ConvertDegreesToRadians(float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z);
	Matrix4 CreateRotationMatrix_X(float a_Degrees_X);
	Matrix4 CreateRotationMatrix_Y(float a_Degrees_Y);
	Matrix4 CreateRotationMatrix_Z(float a_Degrees_Z);
	Matrix4 CreateRotationMatrix_3D(float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z);
	Matrix4 CreateScaleMatrix(float a_Scale_X, float a_Scale_Y, float a_Scale_Z);


	float m_A1, m_B1, m_C1, m_D1;
	float m_A2, m_B2, m_C2, m_D2;
	float m_A3, m_B3, m_C3, m_D3;
	float m_A4, m_B4, m_C4, m_D4;
	
};
#endif /*_MATRIX4_H_*/

