///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			2D Vector Class Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#pragma once
#ifndef _Vector2_H_
#define _Vector2_H_
#include <string> 
#include <iostream>

class Vector2
{
public: 
	Vector2();					// default constructor
	Vector2(float a_fX, float afY);	// constructor that takes in x and y values
	~ Vector2();				// destructor

	Vector2 operator - (float a_S);		// subtracts a scalar from a vector, returns new vector
	Vector2 operator + (float a_S);		// adds a scalar to a vector, returns new vector
	Vector2 operator * (float a_S);		// multiplies a vector by a scalar, returns new vector
	Vector2 operator - (const Vector2& a_OtherVector);	// subtracts one vector from another, returns new vector
	Vector2 operator + (const Vector2& a_OtherVector);	// adds one vector to another, returns new vector
	void operator += (const Vector2& a_OtherVector);
	void operator -= (const Vector2& a_OtherVector);
	bool Equals(const Vector2& a_OtherVector);		// tests vector equality, returns bool

	float GetX();	// returns x value
	float GetY();	// returns y value
	void SetX(float a_fX);	// sets x value
	void SetY(float a_fY);	// sets y value

private:		
	float m_X, m_Y;	// coordinate variables
	float m_fThreshold;	// float comparison threshold

};

#endif

