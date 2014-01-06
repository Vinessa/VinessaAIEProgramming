
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector4.h
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
	~Vector4(void);

	Vector4 operator - (float a_S);  //Subtracts using a scaler
	Vector4 operator + (float a_S);  // Adds using a scaler
	Vector4 operator * (float a_S);  //Multiplies using a scaler
	Vector4 operator / (float a_S);  // Divide by scaler

	Vector4 operator - (const Vector4& a_V1); // Subtracts one Vector from another Vector
	Vector4 operator + (const Vector4& a_V1); // Adds one Vector to another Vector


	void operator += (Vector4& a_V1); //allows the use of  +=
	void operator -= (Vector4& a_V1); // Allows the use of -=
	bool operator == (Vector4& a_V1); // Allows the use of ==

	float GetMagnitude4D(); // Returns the magnitude of this Vector4
	void Normalize(); //Normalizes this Vector4
	Vector4 GetNormal(); // returns a normalized version of this vector but does not change the current vector
	unsigned long ConvertRGBToHexidecimal(); //Converts this vector 4 as an RGBA into an unsigned Long Hexidecimal for graphics
	Vector4 ConvertHexidecimaltoRGB(int a_HexValue, int a_AlphaValue); // Take a Hexidecimal value

	// Getters and Setters - technically not nessisary because of public status.. but planning for the future //
	float GetXRed();	//Returns X/Red
	float GetYGreen();   //Returns Y/Green
	float GetZBlue();   //Returns Z/Blue
	float GetAAlpha(); //Returns A/Alpha

	void SetXRed(float a_XRed); //Sets X/Red	
	void SetYGreen(float a_YGreen); //Sets Y/Green
	void SetZBlue(float a_ZBlue); //Sets Z/Blue
	void SetAAlpha(float a_AAlpha); //Sets A/Alpha


	float m_XRed;
	float m_YGreen;
	float m_ZBlue;
	float m_AAlpha;

	float Threshold;

};
#endif /*_VECTOR4_H_*/
