///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			2D Vector Class Definition
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector2.h"

using namespace std;

//////////////////////////////-- CONSTRUCTION / DESTRUCTION --////////////////////////////////////////////////////////////

// default constructor
Vector2::Vector2 ()
{
	m_X = 0.0;
	m_Y = 0.0;
	m_fThreshold = .0005;
	//cout<< "Default Vector Constructed!\n";
}

// constructor that takes in x and y values
Vector2::Vector2 (float a_fX, float a_fY)
{
	m_X = a_fX;
	m_Y = a_fY;
	m_fThreshold = .0005;
	//cout<< "Vector constructed with given values " << a_fX << " and " << a_fY <<"!\n";
}

// destructor
Vector2::~Vector2 ()
{
	//cout<< "Vector Destroyed, Muhahah!\n";
}

//////////////////////////////-- MATHS --////////////////////////////////////////////////////////////

// subtracts a scalar from a vector, returns new vector
Vector2 Vector2::operator - (float a_S)
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X - a_S;
	TemporaryVector.m_Y = this->m_Y - a_S;
	return TemporaryVector;
}

// adds a scalar to a vector, returns new vector
Vector2 Vector2::operator + (float a_S)
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X + a_S;
	TemporaryVector.m_Y = this->m_Y + a_S;
	return TemporaryVector;
}

// multiplies a vector by a scalar, returns new vector
Vector2 Vector2::operator * (float a_S)
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X * a_S;
	TemporaryVector.m_Y = this->m_Y * a_S;
	return TemporaryVector;
}

// subtracts one vector from another, returns new vector
Vector2 Vector2::operator - (const Vector2& a_OtherVector)
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X - a_OtherVector.m_X;
	TemporaryVector.m_Y = this->m_Y - a_OtherVector.m_Y;
	return TemporaryVector;
}

// adds one vector to another, returns new vector
Vector2 Vector2::operator + (const Vector2& a_OtherVector)
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X + a_OtherVector.m_X;
	TemporaryVector.m_Y = this->m_Y + a_OtherVector.m_Y;
	return TemporaryVector;
}
void Vector2::operator += (const Vector2& a_OtherVector)
{
	
	m_X += a_OtherVector.m_X;
	m_Y += a_OtherVector.m_Y;
	
}

void Vector2::operator -= (const Vector2& a_OtherVector)
{
	m_X -= a_OtherVector.m_X;
	m_Y -= a_OtherVector.m_Y;
}

// tests vector equality, returns bool
bool Vector2::Equals(const Vector2& a_OtherVector)
{
	if ((this->m_X - a_OtherVector.m_X < this->m_fThreshold) && (this->m_Y - a_OtherVector.m_Y < this->m_fThreshold))
		return true;
	else
		return false;
}

//////////////////////////////-- GET / SET --////////////////////////////////////////////////////////////

// returns x value
float Vector2::GetX()
{
	return this->m_X;
}

// returns y value
float Vector2::GetY()
{
	return this->m_Y;
}

// sets x value
void Vector2::SetX(float a_fX)
{
	this->m_X = a_fX;
}

// sets y value
void Vector2::SetY(float a_fY)
{
	this->m_Y = a_fY;
}
