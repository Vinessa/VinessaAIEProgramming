
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector3.h
// Author:			Vinessa Mayer
// Date Created:	November 2013
// Brief:			3D Vector Class Header
// Copyright: Vinessa Mayer 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include "math.h"
#include "AIE.h"

class Vector4
{
public:
	Vector4(void);
	Vector4(float a_X, float a_Y, float a_Z, float a_A);
	Vector4(int a_Red, int a_Green, int a_Blue, int a_Alpha);
	~Vector4(void);

	float GetMagnitude4D();
	void Normalize();
	unsigned long ConvertRGBToHexidecimal();
	Vector4 ConvertHexidecimaltoRGB(int a_HexValue, int a_AlphaValue);


	float m_X;
	float m_Y;
	float m_Z;
	float m_A;

	int m_Red;
	int m_Green;
	int m_Blue;
	int m_Alpha;

};
#endif /*_VECTOR4_H_*/
