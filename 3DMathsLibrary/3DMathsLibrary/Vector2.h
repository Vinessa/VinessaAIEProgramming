
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2.h
// Author:			Vinessa Mayer
// Date Created:	November 2013
// Brief:			2D Vector Class Header, part of 3DMathsLibrary
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef _VECTOR2_H_
#define _VECTOR2_H_
#include <string> 
#include <iostream>


class Vector2
{
public:
/////////////////////////////////////////////////////////////////////////////////////////////////////
///// CONSTRUCTORS AND DESTRUCTOR //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	Vector2(void); //Default
	Vector2(float a_X, float a_Y); //  Takes an X and a Y value (floats)
	~Vector2(void); // Destructor

/////////////////////////////////////////////////////////////////////////////////////////////////////
///// MEMBER FUNCTIONS /////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	Vector2 operator + (float a_S); // Adds using a scaler
	Vector2 operator + (Vector2& a_OtherVector); // Adds one Vector to another Vector

	Vector2 operator - (float a_S); //Subtracts using a scaler
	Vector2 operator - (Vector2& a_OtherVector); // Subtracts one Vector from another Vector

	Vector2 operator * (float a_S); //Multiplies using a scaler
	Vector2 operator / (float a_S); // Divide by scaler

	void operator += (Vector2& a_OtherVector); //allows the use of  +=
	void operator -= (Vector2& a_OtherVector); // Allows the use of -=

	bool Equals(Vector2& a_OtherVector); // Tests to see if Vectors are equal
	float GetMagnitude2D(); // Returns the magnitude of this Vector2
	void Normalize(); //Normalizes this Vector2
	float EulerAngle(Vector2 &a_Vector2);  // Returns the Euler Angle of this Vector2



	float GetX(); // Returns X of this Vector2
	void SetX(float a_X); // Sets X of this Vector2

	float GetY(); // Returns Y of this Vector2
	void SetY(float a_Y); // Sets Y of this Vector2

	Vector2 GetNormal(); // Returns the Normal of this Vector2 as a Vector2
	float GetDotProduct2D(Vector2 &a_Vector2); //returns The Dot product between this Vector2 and another Vector2

	float CrossProduct(Vector2 & v2_A, Vector2 & v2_B); //Returns the Cross Product of this Vector2 and two other Vector 2s

	Vector2 LinearInterpolation(Vector2 v2_A, float dt); // Returns the new position of this Vector 2 between the second vector (destination * time)
	
	

/////////////////////////////////////////////////////////////////////////////////////////////////////
///// MEMBER VARIABLES (Private) ///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
	
private:
	float m_X; // X!
	float m_Y; // Y!
	// NO Z BECAUSE IT'S A VECTOR 2!!
};

#endif /*_VECTOR2_H_*/