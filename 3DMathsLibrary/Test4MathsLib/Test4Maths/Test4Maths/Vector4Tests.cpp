#include "Vector4Tests.h"


Vector4Tests::Vector4Tests(void)
{
}


Vector4Tests::~Vector4Tests(void)
{
}

void Vector4Tests::SetData ()

{
	T1.m_XRed = 1;
	T1.m_YGreen = 2;
	T1.m_ZBlue = 3;
	T1.m_AAlpha = 1;

	T2.m_XRed = 4;
	T2.m_YGreen = 5;
	T2.m_ZBlue = 6;
	T2.m_AAlpha = 1;

	T3.m_XRed = 7;
	T3.m_YGreen = 8;
	T3.m_ZBlue = 9;
	T3.m_AAlpha = 1;

	TA.m_XRed = 1;
	TA.m_YGreen = 2;
	TA.m_ZBlue = 2;
	TA.m_AAlpha = 1;

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

bool Vector4Tests::DoTestGetMag()
{
cout << "Testing GetMagnitude ... \n";
	ResGetMAG = (T1.GetMagnitude4D());
	return (XResGetMAG == ResGetMAG);
	
}

bool Vector4Tests::DoTestNormalize() //only tested this instead of normalize because getnormal has normalize in it and will test both
{
cout << "Testing Normalization ... \n";
	ResGetNorm = (T1.GetNormal());
	return (XResGetNorm == ResGetNorm);
	
}

void Vector4Tests::ReportTestResultVec(bool a_WhichBool, Vector4 a_WhichResult, Vector4 a_WhichExpected, char* a_Test )
{
	
	cout << "\n\n Results for: \n " << "--- "<<a_Test <<" ---\n\n";
	if (a_WhichBool != true)
		
		cout << ">>>>>>>>> - FAILED - <<<<<<<<< \n \n Expected: " << a_WhichExpected.GetXRed() << ","<< a_WhichExpected.GetYGreen() << "\n Got: " << a_WhichResult.GetXRed() << "," <<a_WhichResult.GetYGreen() << "\n\n\n";
	else
		if (a_WhichBool == true)
			cout << " >^._.^< PASSED! >^._.^< \n\n Expected: " << a_WhichExpected.GetXRed() << ","<< a_WhichExpected.GetYGreen() << "\n Got: " << a_WhichResult.GetXRed() << "," <<a_WhichResult.GetYGreen() << "\n \n \n";

}

void Vector4Tests::ReportTestResultFloat(bool a_WhichBool, float a_WhichResultf, float a_WhichExpectedf, char* a_Test)
{
	
	cout << "\n\n Results for: \n " << "--- "<<a_Test <<" ---\n\n";
	if (a_WhichBool != true)
		
		cout << ">>>>>>>>> - FAILED - <<<<<<<<< \n \n Expected: " << a_WhichExpectedf << "\n Got: " << a_WhichResultf << "\n\n\n";
	else
		if (a_WhichBool == true)
			cout << " >^._.^< PASSED! >^._.^< \n\n Expected: " << a_WhichExpectedf << "\n Got: " << a_WhichResultf << "\n\n\n";

}


void Vector4Tests:: AssignTestResults()
{


	 /*PassFailAddS = (DoTestAddScaler());
	 PassFailAddV = (DoTestAddVector());
	 PassFailSubS = (DoTestSubScaler());
	 PassFailSubV = (DoTestSubVector());
	 PassFailMultS = (DoTestMultScaler());
	 PassFailDivS = (DoTestDivScaler());*/
	 PassFailGetMAG = (DoTestGetMag());
	 PassFailGetNorm = (DoTestNormalize()); 
	/* PassFailEuler = (DoTestEuler());
	 PassFailGetDotProd = (DoTestGetDotProd());
	 PassFailLinInt = (DoTestLinInt());*/

}

void Vector4Tests:: RunTestAll()
{
	AssignTestResults();
	/*ReportTestResultVec(PassFailAddS, ResAddS, XResAddS, AddScaler);
	ReportTestResultVec(PassFailAddV, ResAddV, XResAddV, AddVec);
	ReportTestResultVec(PassFailSubV, ResSubV, XResSubV, SubtractVec);
	ReportTestResultVec(PassFailSubS, ResSubS, XResSubS, SubtractScaler);
	ReportTestResultVec(PassFailMultS, ResMultS, XResMultS, MultScaler);
	ReportTestResultVec(PassFailDivS, ResDivS, XResDivS, DivScaler);*/
	ReportTestResultFloat(PassFailGetMAG, ResGetMAG, XResGetMAG, GetMAG);
	ReportTestResultVec(PassFailGetNorm, ResGetNorm, XResGetNorm, Normalize);
	/*ReportTestResultFloat(PassFailEuler, ResEuler, XResEuler, EulerAngle);
	ReportTestResultFloat(PassFailGetDotProd, ResGetDotProd, XResGetDotProd, GetDotProduct);
	ReportTestResultVec(PassFailLinInt, ResLinInt, XResLinInt, LinearInterpolation);*/
}