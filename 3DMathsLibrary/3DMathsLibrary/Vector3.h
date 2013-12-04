///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector3.h
// Author:			Vinessa Mayer
// Date Created:	November 2013
// Brief:			3D Vector Class Header
// Copyright: Vinessa Mayer 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include "math.h"
#include "AIE.h"
class Vector3
{
public:
	Vector3(void);
	Vector3(float a_X, float a_Y, float a_Z);
	~Vector3(void);

	float GetMagnitude3D();
	void Normalize();
	Vector3 GetNormal();
	float GetDotProduct3D(Vector3 &a_Vector3);
	float EulerAngle(Vector3 &a_Vector3);
	Vector3 CrossProduct(Vector3 &a_OtherVector3);
	Vector3 LinearInterpolation(Vector3 v3_Destination, float dt);

	Vector3 operator - (float a_S);
	Vector3 operator + (float a_S);
	Vector3 operator * (float a_S);
	Vector3 operator / (float a_S);

	Vector3 operator - (const Vector3& a_V1);
	Vector3 operator + (const Vector3& a_V1);


	void operator += (const Vector3& a_V1);
	void operator -= (const Vector3& a_V1);

	float GetX();	
	float GetY();
	float GetZ();

	void SetX(float a_X);	
	void SetY(float a_Y);
	void SetZ(float a_Z);

	float m_X;
	float m_Y;
	float m_Z;

};

#endif /*_VECTOR3_H_*/
