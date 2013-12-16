#include "stdafx.h"
#include "CommonFunctionality.h"

void TestPower2(int a_Number)
{
	bool Po2;

	Po2 = (a_Number & (a_Number -1)) == 0;

	if (!Po2)
	{
		a_Number --;
		a_Number |= a_Number >> 1;
		a_Number |= a_Number >> 2;
		a_Number |= a_Number >> 4;
		a_Number |= a_Number >> 8;
		a_Number |= a_Number >> 16;
		a_Number++;

	}

}

float ConvertDegreesToRadians(float a_Degrees)
{
	float Rads = ((a_Degrees * 3.14) / 180);
	return Rads;
}

float LinearInterpolationScaler(float a_Start, float a_Destination, float T) // Linear Interpolation using a scaler//
{ 
	 return((a_Destination - a_Start * T) + a_Start);
}