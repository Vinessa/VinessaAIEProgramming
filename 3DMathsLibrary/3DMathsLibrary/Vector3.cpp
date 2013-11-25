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

float Vector3::GetDotProduct3D(Vector3 &a_TargetVector3) //Get DotProduct between two vectors
{
	return((this -> m_X * a_TargetVector3.m_X) +
		(this -> m_Y * a_TargetVector3.m_Y) +
		(this -> m_Z * a_TargetVector3.m_Z));
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
	Vector3 TempV3 = Vector3((this ->m_X / GetMagnitude3D()), (this ->m_Y / GetMagnitude3D()), (this ->m_Z / GetMagnitude3D()));
	return TempV3;
}

float Vector3::EulerAngle(Vector3 &a_Vector3) //Euler Angle
{
	Vector3 A = this->GetNormal();
	Vector3 B = a_Vector3.GetNormal();
	return acos (A.GetDotProduct3D(B));
}

Vector3 Vector3:: operator - (float a_S) //Minus Scaler
{
	Vector3 Temp;
	Temp.m_X = this->m_X - a_S;
	Temp.m_Y = this->m_Y - a_S;
	Temp.m_Z = this->m_Z - a_S;
	return Temp;
}

Vector3 Vector3:: operator + (float a_S) // Add Scaler
{
	Vector3 Temp;
	Temp.m_X = this->m_X + a_S;
	Temp.m_Y = this->m_Y + a_S;
	Temp.m_Z = this->m_Z + a_S;
	return Temp;
}
	
Vector3 Vector3:: operator * (float a_S) // Multiply Scaler
{
	Vector3 Temp;
	Temp.m_X = this->m_X * a_S;
	Temp.m_Y = this->m_Y * a_S;
	Temp.m_Z = this->m_Z * a_S;
	return Temp;
}

Vector3 Vector3:: operator / (float a_S) // Divide scaler
{
	Vector3 Temp;
	Temp.m_X = this->m_X / a_S;
	Temp.m_Y = this->m_Y / a_S;
	Temp.m_Z = this->m_Z / a_S;
	return Temp;
}

Vector3 Vector3::operator - (const Vector3& a_V1) //Subtract Vector3
{
	Vector3 Temp;
	Temp.m_X = this->m_X - a_V1.m_X;
	Temp.m_Y = this->m_Y - a_V1.m_Y;
	Temp.m_Z = this->m_Z - a_V1.m_Z;
	return Temp;
}

Vector3 Vector3::operator + (const Vector3& a_V1) //Add Vector3
{
	Vector3 Temp;
	Temp.m_X = this->m_X + a_V1.m_X;
	Temp.m_Y = this->m_Y + a_V1.m_Y;
	Temp.m_Z = this->m_Z + a_V1.m_Z;
	return Temp;
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

float Vector3::SetX()
{
	
}