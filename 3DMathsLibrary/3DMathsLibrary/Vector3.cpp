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
/////MEMBER FUNCTIONS////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

float Vector3::GetMagnitude3D() // Get Magnitude of a vector
{
	return sqrt((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z));
}

float Vector3::GetDotProduct3D(Vector3 &a_OtherVector3) //Get DotProduct between two vectors
{
	return((this -> m_X * a_OtherVector3.m_X) +
		(this -> m_Y * a_OtherVector3.m_Y) +
		(this -> m_Z * a_OtherVector3.m_Z));
}


void Vector3::Normalize() //Normalize a Vector3
{
	if (GetMagnitude3D() != 0)
	{
		m_X = (m_X / GetMagnitude3D());
		m_Y = (m_Y / GetMagnitude3D());
		m_Z = (m_Z / GetMagnitude3D());
	}
}

Vector3 Vector3::GetNormal() //Get Normal of a Vector3
{
	Vector3 TemporaryVector3V3 = Vector3((this ->m_X / GetMagnitude3D()), (this ->m_Y / GetMagnitude3D()), (this ->m_Z / GetMagnitude3D()));
	return TemporaryVector3V3;
}

float Vector3::EulerAngle(Vector3 &a_Vector3) //Euler Angle
{
	Vector3 A = this->GetNormal();
	Vector3 B = a_Vector3.GetNormal();
	return acos (A.GetDotProduct3D(B));
}

Vector3 Vector3::CrossProduct(Vector3 &a_OtherVector3)
{
	Vector3 TemporaryVector3;
	TemporaryVector3.SetX((m_Y - a_OtherVector3.GetY())  - (a_OtherVector3.GetZ() - m_Z));
	TemporaryVector3.SetY((m_Z - a_OtherVector3.GetZ())  - (a_OtherVector3.GetX() - m_X));
	TemporaryVector3.SetZ((m_X - a_OtherVector3.GetX())  - (a_OtherVector3.GetY() - m_Y));
	return TemporaryVector3;
}

Vector3 Vector3:: operator - (float a_S) //Minus Scaler
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X - a_S;
	TemporaryVector3.m_Y = this->m_Y - a_S;
	TemporaryVector3.m_Z = this->m_Z - a_S;
	return TemporaryVector3;
}

Vector3 Vector3:: operator + (float a_S) // Add Scaler
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X + a_S;
	TemporaryVector3.m_Y = this->m_Y + a_S;
	TemporaryVector3.m_Z = this->m_Z + a_S;
	return TemporaryVector3;
}
	
Vector3 Vector3:: operator * (float a_S) // Multiply Scaler
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X * a_S;
	TemporaryVector3.m_Y = this->m_Y * a_S;
	TemporaryVector3.m_Z = this->m_Z * a_S;
	return TemporaryVector3;
}

Vector3 Vector3:: operator / (float a_S) // Divide scaler
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X / a_S;
	TemporaryVector3.m_Y = this->m_Y / a_S;
	TemporaryVector3.m_Z = this->m_Z / a_S;
	return TemporaryVector3;
}

Vector3 Vector3::operator - (const Vector3& a_V1) //Subtract Vector3
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X - a_V1.m_X;
	TemporaryVector3.m_Y = this->m_Y - a_V1.m_Y;
	TemporaryVector3.m_Z = this->m_Z - a_V1.m_Z;
	return TemporaryVector3;
}

Vector3 Vector3::operator + (const Vector3& a_V1) //Add Vector3
{
	Vector3 TemporaryVector3;
	TemporaryVector3.m_X = this->m_X + a_V1.m_X;
	TemporaryVector3.m_Y = this->m_Y + a_V1.m_Y;
	TemporaryVector3.m_Z = this->m_Z + a_V1.m_Z;
	return TemporaryVector3;
}

void Vector3::operator += (const Vector3& a_V1) //+= Vector3
{
	m_X += a_V1.m_X;
	m_Y += a_V1.m_Y;
	m_Z += a_V1.m_Z;

}

void Vector3::operator -= (const Vector3& a_V1) //-= Vector3
{
	m_X -= a_V1.m_X;
	m_Y -= a_V1.m_Y;
	m_Z -= a_V1.m_Z;

}

Vector3 Vector3::LinearInterpolation(Vector3 v3_A, Vector3 v3_B, float dt)
{ 
	return v3_A + (v3_B - v3_A) *dt;
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