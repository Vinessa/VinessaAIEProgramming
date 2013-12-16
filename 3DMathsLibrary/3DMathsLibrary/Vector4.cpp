#include "StdAfx.h"
#include "Vector4.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////
//CONSTRUCTORS AND DESTRUCTORS/////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

Vector4::Vector4(void)
{
	m_X = 0.0;
	m_Y = 0.0;
	m_Z = 0.0;
	m_A = 0.0;
}

Vector4::Vector4(float a_X, float a_Y, float a_Z, float a_A)
{
	m_X = a_X;
	m_Y = a_Y;
	m_Z = a_Z;
	m_A = a_A;
}

Vector4::Vector4(int a_Red, int a_Green, int a_Blue, int a_Alpha)
{
	m_X = 0.0;
	m_Y = 0.0;
	m_Z = 0.0;
	m_A = 0.0;

	m_Red = a_Red;
	m_Green = a_Green;
	m_Blue = a_Blue;
	m_Alpha = a_Alpha;

}


Vector4::~Vector4(void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
////MEMBER FUNCTIONS////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

float Vector4::GetMagnitude4D() //Returns a Scaler that is the Magnitude of this Vector4
{
	return sqrt((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z) + (m_Alpha * m_Alpha));

}

void Vector4::Normalize()
{
	if(GetMagnitude4D() !=0)
	{
		m_X = (m_X / GetMagnitude4D());
		m_Y = (m_Y / GetMagnitude4D());
		m_Z = (m_Z / GetMagnitude4D());
		m_Alpha = (m_Alpha / GetMagnitude4D());
	}
}

unsigned long Vector4::ConvertRGBToHexidecimal() // returns the Hexadecimal version of this RGBA.
{
	return((m_Red & 0xff) << 24) + ((m_Green & 0xff) << 16) + ((m_Blue & 0xff) << 8) + (m_Alpha & 0xff);
}

Vector4 Vector4:: ConvertHexidecimaltoRGB(int a_HexValue, int a_AlphaValue) //takes in a hexidecimal and an Alpha value between 0 and 1. 0 = transparent, 1 = opaque. Returns a Vector4 with the R,G,B and Alpha value of the converted color.
{
Vector4 RGBAColor;
RGBAColor.m_Red = ((a_HexValue >>16) & 0xFF) / 255.0;
RGBAColor.m_Green = ((a_HexValue >>8) & 0xFF) / 255.0;
RGBAColor.m_Blue = ((a_HexValue & 0xFF) / 255.0);
RGBAColor.m_Alpha = a_AlphaValue;

return RGBAColor;
}