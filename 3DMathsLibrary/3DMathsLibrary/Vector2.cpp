///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2.h
// Author:			Vinessa Mayer
// Date Created:	November 2013
// Brief:			2D Vector Class .CPP, part of 3DMathsLibrary
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "Vector2.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
///// CONSTRUCTORS AND DESTRUCTOR //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

Vector2::Vector2(void)
{
	m_X = 0.0;
	m_Y = 0.0;
}

Vector2::Vector2 (float a_X, float a_Y)
{
	m_X = a_X;
	m_Y = a_Y;
}

Vector2::~Vector2(void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
///// MEMBER FUNCTIONS /////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

///OVERLOADED OPERATORS///

// Additive //
Vector2 Vector2::operator + (float a_S) // Adds using a scaler
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X + a_S;
	TemporaryVector.m_Y = this->m_Y + a_S;
	return TemporaryVector;
}

Vector2 Vector2::operator + (Vector2& a_OtherVector) // Adds one Vector to another Vector
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X + a_OtherVector.m_X;
	TemporaryVector.m_Y = this->m_Y + a_OtherVector.m_Y;
	return TemporaryVector;
}

// Subtractive //
Vector2 Vector2::operator - (float a_S) //Subtracts using a scaler
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X - a_S;
	TemporaryVector.m_Y = this->m_Y - a_S;
	return TemporaryVector;
}

Vector2 Vector2::operator - (Vector2& a_OtherVector) // Subtracts one Vector from another Vector
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X - a_OtherVector.m_X;
	TemporaryVector.m_Y = this->m_Y - a_OtherVector.m_Y;
	return TemporaryVector;
}


// Multiply //
Vector2 Vector2::operator * (float a_S) //Multiplies using a scaler
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X * a_S;
	TemporaryVector.m_Y = this->m_Y * a_S;
	return TemporaryVector;
}

// Divide //
Vector2 Vector2::operator / (float a_S) // Divide by scaler
{
	Vector2 TemporaryVector;
	TemporaryVector.m_X = this->m_X / a_S;
	TemporaryVector.m_Y = this->m_Y / a_S;
	return TemporaryVector;
}

// Comparisons //
//void Vector2::operator += (Vector2& a_OtherVector) //allows the use of  +=
//{
//	m_X += a_OtherVector.m_X;
//	m_Y += a_OtherVector.m_Y;
//}
//
//void Vector2::operator -= (Vector2& a_OtherVector) // Allows the use of -=
//{
//	m_X -= a_OtherVector.m_X;
//	m_Y -= a_OtherVector.m_Y;
//}

bool Vector2::Equals( Vector2& a_OtherVector) // Tests to see if Vectors are equal
{
	if ((m_X - a_OtherVector.GetX()) && (m_Y - a_OtherVector.GetY()))
		return true;
	else
		return false;
}

///MAGNITUDE///
float Vector2::GetMagnitude2D() // Get Magnitude of a vector
{
	return sqrt((m_X * m_X) + (m_Y * m_Y));
}

///DOT-PRODUCT///
float Vector2::GetDotProduct2D(Vector2 &a_OtherVector2) //Get DotProduct between two vectors
{
	return(((m_X) * (a_OtherVector2.GetX())) +
		(m_Y) * (a_OtherVector2.GetY()));
}

///NORMALISATION///
void Vector2::Normalize() //Normalize a Vector2
{
	if (GetMagnitude2D() != 0)
	{
		m_X = (m_X / GetMagnitude2D());
		m_Y = (m_Y / GetMagnitude2D());
	}
}

///EULER///
float Vector2::EulerAngle(Vector2 &a_Vector2) //Euler Angle
{
	Vector2 A = GetNormal();
	Vector2 B = a_Vector2.GetNormal();
	return acos (A.GetDotProduct2D(B));
}

///LINEAR INTERPOLATION///
Vector2 Vector2::LinearInterpolation(Vector2 v2Destination, float dt) // Linear Interpolation //
{ 
	/*Vector2 Temp;
	Temp.SetX((this ->GetX()) + ((v2Destination.GetX() - m_X)*dt));
	Temp.SetY((this ->GetY()) + ((v2Destination.GetY() - m_Y)*dt));
	return Temp;*/

	return ((v2Destination - *this ) * dt) +*this;
	
}

///CROSS PRODUCT///
float CrossProduct(Vector2 & v2_A, Vector2 & v2_B)// Cross Product.. fake cross product anyway. Assumes that the Z value is 0 and returns a float instead of a Vector2
{
    return (((v2_A.GetX()) * (v2_B.GetY())) - (v2_A.GetY()) * (v2_B.GetX()));
}


// Getters and Setters //
float Vector2::GetX() // Returns X
{
	return m_X;
}

float Vector2::GetY() // Returns Y
{
	return m_Y;
}

void Vector2::SetX(float a_X) //Sets X
{
	m_X = a_X;
}

void Vector2::SetY(float a_Y) //Sets Y
{
	m_Y = a_Y;
}

Vector2 Vector2::GetNormal() //Get Normal of a Vector2
{
	Vector2 TemporaryVector2 = Vector2((m_X / GetMagnitude2D()), (m_Y / GetMagnitude2D()));
	return TemporaryVector2;
}




