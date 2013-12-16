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
/////////////////////////////////////////////////////////////////////////////////////////////////////
///// CONSTRUCTORS AND DESTRUCTOR //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

	Vector3(void);//Default
	Vector3(float a_X, float a_Y, float a_Z); //  Takes an X, Y and Z value (floats)
	~Vector3(void); // Destructor

/////////////////////////////////////////////////////////////////////////////////////////////////////
///// MEMBER FUNCTIONS /////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

	Vector3 operator - (float a_S);  //Subtracts using a scaler
	Vector3 operator + (float a_S);  // Adds using a scaler
	Vector3 operator * (float a_S);  //Multiplies using a scaler
	Vector3 operator / (float a_S);  // Divide by scaler

	Vector3 operator - (const Vector3& a_V1); // Subtracts one Vector from another Vector
	Vector3 operator + (const Vector3& a_V1); // Adds one Vector to another Vector


	void operator += (const Vector3& a_V1); //allows the use of  +=
	void operator -= (const Vector3& a_V1); // Allows the use of -=
	
	float GetMagnitude3D();// Returns the magnitude of this Vector3
	void Normalize(); //Normalizes this Vector3
	Vector3 GetNormal(); //
	float GetDotProduct3D(Vector3 &a_Vector3);
	float EulerAngle(Vector3 &a_Vector3); // Returns the Euler Angle of this Vector3
	Vector3 CrossProduct(Vector3 &a_OtherVector3); //Returns the Cross Product of this Vector3 and two other Vector 3s
	Vector3 LinearInterpolation(Vector3 v3_Destination, float dt); // Returns the new position of this Vector3 between the second Vector3 (destination * time)
	Vector3 LinearInterpolationScaler(float Scaler, float dt); //Linear Interpolation by a scaler?

	
	// Getters and Setters - technically not nessisary because of public status.. but planning for the future //
	float GetX();	//Returns X
	float GetY();   //Returns Y
	float GetZ();   //Returns Z

	void SetX(float a_X); //Sets X	
	void SetY(float a_Y); //Sets Y
	void SetZ(float a_Z); //Sets Z


	// The meat of the Vector3!
	float m_X; // X!
	float m_Y; // Y!
	float m_Z; // Z!

};

#endif /*_VECTOR3_H_*/
