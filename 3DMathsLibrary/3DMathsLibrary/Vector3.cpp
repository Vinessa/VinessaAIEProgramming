///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector3.cpp
// Author:			Vinessa Mayer
// Date Created:	November 2013
// Brief:			3D Vector Class Definition
// Copyright: Vinessa Mayer 2013
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "Vector3.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////
//CONSTRUCTORS AND DESTRUCTORS/////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

Vector3::Vector3(void)
{
	m_X = 0.0;
	m_Y = 0.0;
	m_Z = 0.0;
}

Vector3::Vector3(float a_X, float a_Y, float a_Z)
{
	m_X = a_X;
	m_Y = a_Y;
	m_Z = a_Z;
}

Vector3::~Vector3(void) 
{
}




/////////////////////////////////////////////////////////////////////////////////////////////////////
////MEMBER FUNCTIONS////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

///OVERLOADED OPERATORS///
Vector3 Vector3:: operator - (float a_S) //Subtract by Scaler
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X - a_S;
	TemporaryVector3.m_Y = this->m_Y - a_S;
	TemporaryVector3.m_Z = this->m_Z - a_S;
	return TemporaryVector3;
}

Vector3 Vector3:: operator + (float a_S) // Add by Scaler
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X + a_S;
	TemporaryVector3.m_Y = this->m_Y + a_S;
	TemporaryVector3.m_Z = this->m_Z + a_S;
	return TemporaryVector3;
}

Vector3 Vector3:: operator * (float a_S) // Multiply by Scaler
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X * a_S;
	TemporaryVector3.m_Y = this->m_Y * a_S;
	TemporaryVector3.m_Z = this->m_Z * a_S;
	return TemporaryVector3;
}

Vector3 Vector3:: operator / (float a_S) // Divide by Scaler
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X / a_S;
	TemporaryVector3.m_Y = this->m_Y / a_S;
	TemporaryVector3.m_Z = this->m_Z / a_S;
	return TemporaryVector3;
}

Vector3 Vector3::operator - (const Vector3& a_V1) //Subtract by Vector3
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X - a_V1.m_X;
	TemporaryVector3.m_Y = this->m_Y - a_V1.m_Y;
	TemporaryVector3.m_Z = this->m_Z - a_V1.m_Z;
	return TemporaryVector3;
}

Vector3 Vector3::operator + (const Vector3& a_V1) //Add by Vector3
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X + a_V1.m_X;
	TemporaryVector3.m_Y = this->m_Y + a_V1.m_Y;
	TemporaryVector3.m_Z = this->m_Z + a_V1.m_Z;
	return TemporaryVector3;
}

///MAGNITUDE///
float Vector3::GetMagnitude3D() //Returns a Scaler that is the Magnitude of this Vector3
{
	return sqrt((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z));
}

///DOT-PRODUCT///
float Vector3::GetDotProduct3D(Vector3 &a_OtherVector3) //Returns a Scaler that is the Dot Product between two Vector3's
{
	return((this -> m_X * a_OtherVector3.m_X) +
		(this -> m_Y * a_OtherVector3.m_Y) +
		(this -> m_Z * a_OtherVector3.m_Z));
}

///NORMALISATION///
void Vector3::Normalize() //Normalize this Vector3
{
	if (GetMagnitude3D() != 0)
	{
		m_X = (m_X / GetMagnitude3D());
		m_Y = (m_Y / GetMagnitude3D());
		m_Z = (m_Z / GetMagnitude3D());
	}
}

Vector3 Vector3::GetNormal() //Return the normalized Vector of this Vector3
{
	Vector3 TemporaryVector3 = Vector3((this ->m_X / GetMagnitude3D()), (this ->m_Y / GetMagnitude3D()), (this ->m_Z / GetMagnitude3D()));
	return TemporaryVector3;
}

///EULER///
float Vector3::EulerAngle(Vector3 &a_Vector3) //Euler Angle
{
	Vector3 A = this->GetNormal();
	Vector3 B = a_Vector3.GetNormal();
	return acos (A.GetDotProduct3D(B));
}

///CROSS PRODUCT///
Vector3 Vector3::CrossProduct(Vector3 &a_OtherVector3) // Cross Product //
{
	Vector3 TemporaryVector3;
	TemporaryVector3.SetX((m_Y * a_OtherVector3.GetZ())  - (a_OtherVector3.GetZ() * m_Y));
	TemporaryVector3.SetY((m_Z * a_OtherVector3.GetX())  - (a_OtherVector3.GetX() * m_Z));
	TemporaryVector3.SetZ((m_X - a_OtherVector3.GetY())  - (a_OtherVector3.GetY() * m_X));
	return TemporaryVector3;
}

///LINEAR INTERPOLATION///
Vector3 Vector3::LinearInterpolation(Vector3 v3_Destination, float dt) // Linear Interpolation //
{ 
	return ((v3_Destination - *this) * dt) +*this;
}

Vector3 Vector3::LinearInterpolationScaler(float Scaler, float dt)
{
	Vector3 Temp;

	Temp.m_X = ((Scaler - m_X) * dt) + m_X;
	Temp.m_Y = ((Scaler - m_Y) * dt) + m_Y;
	Temp.m_Z = ((Scaler - m_Z) * dt) + m_Y;

	return Temp;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GETTERS AND SETTERS /////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

float Vector3::GetX()
{
	return m_X;
}

float Vector3::GetY()
{
	return m_Y;
}

float Vector3::GetZ()
{
	return m_Z;
}

void Vector3::SetX(float a_X)
{
	m_X = a_X;
}

void Vector3::SetY(float a_Y)
{
	m_Y = a_Y;
}

void Vector3::SetZ(float a_Z)
{
	m_Z = a_Z;
}