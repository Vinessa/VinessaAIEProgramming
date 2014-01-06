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

	XResHEX2RGB.m_XRed = 255;
	XResHEX2RGB.m_YGreen = 0;
	XResHEX2RGB.m_ZBlue = 0;
	XResHEX2RGB.m_AAlpha = 1;



	TScaler = 9;
	dt = .5;


	XResGetMAG = 2.236;


	
	XResEuler = 0.18;

	XResGetDotProd = 11;
	m_HexValue = 0xff0000;

	

	

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

bool Vector4Tests::DoTestHEX2RGB() 
{
cout << "Testing HEX2RGB ... \n";
ResHEX2RGB = (T1.ConvertHexidecimaltoRGB(m_HexValue));
	return (XResHEX2RGB == ResHEX2RGB);
	
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


	
	 PassFailGetMAG = (DoTestGetMag());
	 PassFailGetNorm = (DoTestNormalize()); 
	PassFailHex2RGB = (DoTestHEX2RGB());
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
	ReportTestResultVec(PassFailHEX2RGB, ResHEX2RGB, XResHEX2RGB, HEX2RGB);
	/*ReportTestResultFloat(PassFailEuler, ResEuler, XResEuler, EulerAngle);
	ReportTestResultFloat(PassFailGetDotProd, ResGetDotProd, XResGetDotProd, GetDotProduct);
	ReportTestResultVec(PassFailLinInt, ResLinInt, XResLinInt, LinearInterpolation);*/
}