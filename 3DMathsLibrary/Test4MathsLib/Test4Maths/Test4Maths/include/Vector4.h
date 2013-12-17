
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

/////////////////////////////////////////////////////////////////////////////////////////////////////
///// CONSTRUCTORS AND DESTRUCTOR //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

	Vector4(void);
	Vector4(float a_X, float a_Y, float a_Z, float a_A);
	Vector4(int a_Red, int a_Green, int a_Blue, int a_Alpha);
	~Vector4(void);

	float GetMagnitude4D(); // Returns the magnitude of this Vector4
	void Normalize(); //Normalizes this Vector4
	unsigned long ConvertRGBToHexidecimal(); //Converts this vector 4 as an RGBA into an unsigned Long Hexidecimal for graphics
	Vector4 ConvertHexidecimaltoRGB(int a_HexValue, int a_AlphaValue); // Take a Hexidecimal value


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
