#include "Matrix3Tests.h"


Matrix3Tests::Matrix3Tests(void)
{
}


Matrix3Tests::~Matrix3Tests(void)
{
}

void Matrix3Tests::SetData ()

{
	T1.SetX(1);
	T1.SetY(2);
	T1.SetZ(3);

	T2.SetX(4);
	T2.SetY(5);
	T2.SetZ(6);
	
	T3.SetX(7);
	T3.SetY(8);
	T3.SetZ(9);

	TScaler = 10;
	dt = .5;

	XResAddS.SetX(11);
	XResAddS.SetY(12);
	XResAddS.SetZ(13);

	XResAddV.SetX(5);
	XResAddV.SetY(7);
	XResAddV.SetZ(9);


	XResSubS.SetX(-9);
	XResSubS.SetY(-8);
	XResSubS.SetZ(-7);

	XResSubV.SetX(-3);
	XResSubV.SetY(-3);
	XResSubV.SetZ(-3);

	XResMultS.SetX(10);
	XResMultS.SetY(20);
	XResMultS.SetY(30);
	
	XResDivS.SetX(0.1);
	XResDivS.SetY(0.2);
	XResDivS.SetZ(0.3);

	XResGetMAG = 3.741;


	XResGetNorm.SetX(0.2673);
	XResGetNorm.SetY(0.5346);
	XResGetNorm.SetZ(0.8019);
	
	XResEuler = 0.225;

	XResCrossProduct.SetX(-3);
	XResCrossProduct.SetY(6);
	XResCrossProduct.SetZ(-3);

	XResGetDotProd = 32;

	XResLinIntVec.SetX(-0.5);
	XResLinIntVec.SetY(0.5);
	XResLinIntVec.SetZ(1.5);

	XResLinInt.SetX(5.5);
	XResLinInt.SetX(7);
	XResLinInt.SetZ(3.5);

	AddVec = "AddVector";
	AddScaler = "AddbyScaler";
	SubtractVec = "SubtractVector";
	SubtractScaler = "SubtractbyScaler";
	MultScaler = "MultiplybyScaler";
	DivScaler = "DividebyScaler";
	GetMAG = "GetMagnitude";
	Normalize = "Normalize";
	EulerAngle = "EulerAngle";
	CrossProd = "CrossProduct";
	GetDotProduct = "GetDotProduct";
	LinearInterpolation = "LinearInterpolation";



}