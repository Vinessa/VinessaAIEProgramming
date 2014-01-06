#include "Vector4Tests.h"


Vector4Tests::Vector4Tests(void)
{
}


Vector4Tests::~Vector4Tests(void)
{
}

void Vector4Tests::SetData ()

{
	T1.m_X = 1;
	T1.m_Y = 2;
	T1.m_Z = 3;
	T1.m_A = 1;

	T2.m_X = 4;
	T2.m_Y = 5;
	T2.m_Z = 6;
	T2.m_A = 1;

	T3.m_X = 7;
	T3.m_Y = 8;
	T3.m_Z = 9;
	T3.m_A = 1;

	TA.m_Red = 1;
	TA.m_Green = 2;
	TA.m_Blue = 2;
	TA.m_Alpha = 1;

	TScaler = 9;
	dt = .5;

	/*XResAddS.SetX(10);
	XResAddS.SetY(11);

	XResAddV.SetX(4);
	XResAddV.SetY(6);

	XResSubS.SetX(-8);
	XResSubS.SetY(-7);

	XResSubV.SetX(-2);
	XResSubV.SetY(-2);

	XResMultS.SetX(9);
	XResMultS.SetY(18);*/
	
	/*XResDivS.SetX(0.11);
	XResDivS.SetY(0.22);*/

	XResGetMAG = 2.236;


	//XResGetNorm.SetX(0.45);
	//XResGetNorm.SetY(0.89);
	
	XResEuler = 0.18;

	XResGetDotProd = 11;

	/*XResLinInt.SetX(2);
	XResLinInt.SetX(3.5);*/

	AddVec = "AddVector";
	AddScaler = "AddbyScaler";
	SubtractVec = "SubtractVector";
	SubtractScaler = "SubtractbyScaler";
	MultScaler = "MultiplybyScaler";
	DivScaler = "DividebyScaler";
	GetMAG = "GetMagnitude";
	Normalize = "Normalize";
	EulerAngle = "EulerAngle";
	GetDotProduct = "GetDotProduct";
	LinearInterpolation = "LinearInterpolation";
}