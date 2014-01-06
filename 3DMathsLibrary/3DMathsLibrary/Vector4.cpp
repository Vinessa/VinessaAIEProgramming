#include "StdAfx.h"
#include "Vector4.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////
//CONSTRUCTORS AND DESTRUCTORS/////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

Vector4::Vector4(void)
{
	m_XRed = 0.0;
	m_YGreen = 0.0;
	m_ZBlue = 0.0;
	m_AAlpha = 0.0;
}

Vector4::Vector4(float a_X, float a_Y, float a_Z, float a_A)
{
	m_XRed = a_X;
	m_YGreen = a_Y;
	m_ZBlue = a_Z;
	m_AAlpha = a_A;
}


Vector4::~Vector4(void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
////MEMBER FUNCTIONS////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

float Vector4::GetMagnitude4D() //Returns a Scaler that is the Magnitude of this Vector4
{
	return sqrt((m_XRed * m_XRed) + (m_YGreen * m_YGreen) + (m_ZBlue * m_ZBlue) + (m_AAlpha * m_AAlpha));

}

void Vector4::Normalize()
{
	if(GetMagnitude4D() !=0)
	{
		m_XRed = (m_XRed / GetMagnitude4D());
		m_YGreen = (m_YGreen / GetMagnitude4D());
		m_ZBlue = (m_ZBlue / GetMagnitude4D());
		m_AAlpha = (m_AAlpha / GetMagnitude4D());
	}
}

Vector4 Vector4::GetNormal() //Return the normalized Vector of this Vector4
{
	Vector4 TemporaryVector4 = Vector4((this ->m_XRed / GetMagnitude4D()), (this ->m_YGreen / GetMagnitude4D()), (this ->m_ZBlue / GetMagnitude4D()), this ->m_AAlpha / GetMagnitude4D());
	return TemporaryVector4;
}


//unsigned long Vector4::ConvertRGBToHexidecimal() // returns the Hexadecimal version of this RGBA.
//{
//	return((m_XRed & 0xff) << 24) + ((m_YGreen & 0xff) << 16) + ((m_ZBlue & 0xff) << 8) + (m_AAlpha & 0xff);
//}

Vector4 Vector4:: ConvertHexidecimaltoRGB(int a_HexValue, int a_AlphaValue) //takes in a hexidecimal and an Alpha value between 0 and 1. 0 = transparent, 1 = opaque. Returns a Vector4 with the R,G,B and Alpha value of the converted color.
{
Vector4 RGBAColor;
RGBAColor.m_XRed = ((a_HexValue >>16) & 0xFF) / 255.0;
RGBAColor.m_YGreen = ((a_HexValue >>8) & 0xFF) / 255.0;
RGBAColor.m_ZBlue = ((a_HexValue & 0xFF) / 255.0);
RGBAColor.m_AAlpha = a_AlphaValue;

return RGBAColor;
}

///OVERLOADED OPERATORS///
Vector4 Vector4:: operator - (float a_S) //Subtract by Scaler
{
	Vector4 TemporaryVector4;
	TemporaryVector4.m_XRed = this->m_XRed - a_S;
	TemporaryVector4.m_YGreen = this->m_YGreen - a_S;
	TemporaryVector4.m_ZBlue = this->m_ZBlue - a_S;
	TemporaryVector4.m_AAlpha = this->m_AAlpha - a_S;
	return TemporaryVector4;
}

Vector4 Vector4:: operator + (float a_S) // Add by Scaler
{
	Vector4 TemporaryVector4;
	TemporaryVector4.m_XRed = this->m_XRed + a_S;
	TemporaryVector4.m_YGreen = this->m_YGreen + a_S;
	TemporaryVector4.m_ZBlue = this->m_ZBlue + a_S;
	TemporaryVector4.m_AAlpha = this->m_AAlpha + a_S;
	return TemporaryVector4;
}

Vector4 Vector4:: operator * (float a_S) // Multiply by Scaler
{
	Vector4 TemporaryVector4;
	TemporaryVector4.m_XRed = this->m_XRed * a_S;
	TemporaryVector4.m_YGreen = this->m_YGreen * a_S;
	TemporaryVector4.m_ZBlue = this->m_ZBlue * a_S;
	TemporaryVector4.m_AAlpha = this->m_AAlpha * a_S;
	return TemporaryVector4;
}

Vector4 Vector4:: operator / (float a_S) // Divide by Scaler
{
	Vector4 TemporaryVector4;
	TemporaryVector4.m_XRed = this->m_XRed / a_S;
	TemporaryVector4.m_YGreen = this->m_YGreen / a_S;
	TemporaryVector4.m_ZBlue = this->m_ZBlue / a_S;
	TemporaryVector4.m_AAlpha = this->m_AAlpha - a_S;
	return TemporaryVector4;
}

Vector4 Vector4::operator - (const Vector4& a_V1) //Subtract by Vector4
{
	Vector4 TemporaryVector4;
	TemporaryVector4.m_XRed = this->m_XRed - a_V1.m_XRed;
	TemporaryVector4.m_YGreen = this->m_YGreen - a_V1.m_YGreen;
	TemporaryVector4.m_ZBlue = this->m_ZBlue - a_V1.m_ZBlue;
	TemporaryVector4.m_ZBlue = this->m_AAlpha - a_V1.m_AAlpha;
	return TemporaryVector4;
}

Vector4 Vector4::operator + (const Vector4& a_V1) //Add by Vector4
{
	Vector4 TemporaryVector4;
	TemporaryVector4.m_XRed = this->m_XRed + a_V1.m_XRed;
	TemporaryVector4.m_YGreen = this->m_YGreen + a_V1.m_YGreen;
	TemporaryVector4.m_ZBlue = this->m_ZBlue + a_V1.m_ZBlue;
	TemporaryVector4.m_ZBlue = this->m_AAlpha + a_V1.m_AAlpha;
	return TemporaryVector4;
}

float Vector4::GetXRed()
{
	return m_XRed;
}

float Vector4::GetYGreen()
{
	return m_YGreen;
}


float Vector4::GetZBlue()
{
	return m_ZBlue;
}

float Vector4::GetAAlpha()
{
	return m_AAlpha;
}

void Vector4::SetXRed(float a_XRed)
{
	m_XRed = a_XRed;
}

void Vector4::SetYGreen(float a_YGreen)
{
	m_YGreen = a_YGreen;
}

void Vector4::SetZBlue(float a_ZBlue)
{
	m_ZBlue = a_ZBlue;
}

void Vector4::SetAAlpha(float a_AAlpha)
{
	m_AAlpha = a_AAlpha;
}

// Comparisons //
void Vector4::operator += (Vector4& a_V1) //allows the use of  +=
{
	m_XRed += a_V1.m_XRed;
	m_YGreen += a_V1.m_YGreen;
	m_ZBlue += a_V1.m_ZBlue;
	m_AAlpha += a_V1.m_AAlpha;

}

void Vector4::operator -= (Vector4& a_V1) // Allows the use of -=
{
	m_XRed -= a_V1.m_XRed;
	m_YGreen -= a_V1.m_YGreen;
	m_ZBlue -= a_V1.m_ZBlue;
	m_AAlpha -= a_V1.m_AAlpha;
}

bool Vector4::operator == (Vector4& a_V1)
{
	Threshold = .0005;
	if (((m_XRed - a_V1.GetXRed()) < Threshold) && ((m_YGreen - a_V1.GetYGreen()) < Threshold) && ((m_ZBlue -a_V1.GetZBlue()) < Threshold) && ((m_AAlpha -a_V1.GetAAlpha()) < Threshold))
		return true;
	else
		return false;
	

}