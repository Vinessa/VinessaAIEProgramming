///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2.h
// Author:			Vinessa Mayer
// Date Created:	November 2013
// Brief:			2D Vector Class .CPP, part of 3DMathsLibrary
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

// Comparisons //
	void Vector2::operator += (Vector2& a_OtherVector) //allows the use of  +=
	{
		m_X += a_OtherVector.m_X;
		m_Y += a_OtherVector.m_Y;
	}

	void Vector2::operator -= (Vector2& a_OtherVector) // Allows the use of -=
	{
		m_X -= a_OtherVector.m_X;
		m_Y -= a_OtherVector.m_Y;
	}

	bool Vector2::Equals( Vector2& a_OtherVector) // Tests to see if Vectors are equal
	{
		if ((m_X - a_OtherVector.GetX()) && (m_Y - a_OtherVector.GetY()))
		return true;
	else
		return false;
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

	void Vector2::SetX(float a_X)
	{
		m_X = a_X;
	}

	void Vector2::SetY(float a_Y)
	{
		m_Y = a_Y;
	}