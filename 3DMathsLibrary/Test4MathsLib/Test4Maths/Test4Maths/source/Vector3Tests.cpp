
#include "Vector3Tests.h"


Vector3Tests::Vector3Tests(void)
{
}


Vector3Tests::~Vector3Tests(void)
{
}


void Vector3Tests::SetData ()

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

bool Vector3Tests::DoTestAddScaler()
{
	cout << "Testing VECTOR + SCALER ... \n";
	ResAddS = (T1 + TScaler);
	return (XResAddS == ResAddS);
}

bool Vector3Tests::DoTestAddVector()
{
	cout << "Testing VECTOR + VECTOR ... \n";
	ResAddV = (T1 + T2);
	return (XResAddV == ResAddV);
	
}

bool Vector3Tests::DoTestSubScaler()
{
	cout << "Testing VECTOR - Scaler ... \n";
	ResSubS = (T1 - TScaler);
	return (XResSubS == ResSubS);
	
}

bool Vector3Tests::DoTestSubVector()
{
	cout << "Testing VECTOR - VECTOR ... \n";
	Result = (T1 - T2);
	return (XResSubV == ResSubV);
	
}

bool Vector3Tests::DoTestMultScaler()
{
	cout << "Testing VECTOR * SCALER ... \n";
	ResMultS = (T1 * TScaler);
	return (XResMultS == ResMultS);
	
}

bool Vector3Tests::DoTestDivScaler()
{
cout << "Testing VECTOR / SCALER ... \n";
	ResDivS = (T1 / TScaler);
	return (XResDivS == ResDivS);
	
}

bool Vector3Tests::DoTestGetMag()
{
cout << "Testing GetMagnitude ... \n";
	ResGetMAG = (T1.GetMagnitude3D());
	return (XResGetMAG == ResGetMAG);
	
}

bool Vector3Tests::DoTestNormalize() //only tested this instead of normalize because getnormal has normalize in it and will test both
{
cout << "Testing Normalization ... \n";
	ResGetNorm = (T1.GetNormal());
	return (XResGetNorm == ResGetNorm);
	
}

bool Vector3Tests::DoTestEuler() 
{
cout << "Testing Euler ... \n";
	ResEuler = (T1.EulerAngle(T2));
	return (XResEuler == ResEuler);
	
}

bool Vector3Tests::DoTestXProd() 
{
cout << "Testing CrossProduct ... \n";
	ResCrossProduct = (T1.CrossProduct(T2));
	return (XResCrossProduct == ResCrossProduct);
	
}

bool Vector3Tests::DoTestGetDotProd() 
{
cout << "Testing GetDotProduct2D ... \n";
	ResGetDotProd = (T1.GetDotProduct3D(T2));
	return (XResGetDotProd == ResGetDotProd);
	
}

bool Vector3Tests::DoTestLinInt() 
{
	float delta = .5f;
	cout << "Testing LinearInterpolation ... \n";
	ResLinInt = (T1.LinearInterpolation(T2,delta));
	return (XResLinInt == ResLinInt);
}

void Vector3Tests:: AssignTestResults()
{


	 PassFailAddS = (DoTestAddScaler());
	 PassFailAddV = (DoTestAddVector());
	 PassFailSubS = (DoTestSubScaler());
	 PassFailSubV = (DoTestSubVector());
	 PassFailMultS = (DoTestMultScaler());
	 PassFailDivS = (DoTestDivScaler());
	 PassFailGetMAG = (DoTestGetMag());
	 PassFailGetNorm = (DoTestNormalize()); 
	 PassFailEuler = (DoTestEuler());
	 PassFailXProd = (DoTestXProd());
	 PassFailGetDotProd = (DoTestGetDotProd());
	 PassFailLinInt = (DoTestLinInt());

}

void Vector3Tests::ReportTestResultVec(bool a_WhichBool, Vector3 a_WhichResult, Vector3 a_WhichExpected, char* a_Test )
{
	
	cout << "\n\n Results for: \n " << "--- "<<a_Test <<" ---\n\n";
	if (a_WhichBool != true)
		
		cout << ">>>>>>>>> - PASSED - <<<<<<<<< \n \n Expected: " << a_WhichExpected.GetX() << ","<< a_WhichExpected.GetY() << "\n\n\n";
	else
		if (a_WhichBool == true)
			cout << " >^._.^< PASSED! >^._.^< \n\n Expected: " << a_WhichExpected.GetX() << ","<< a_WhichExpected.GetY() << "\n Got: " << a_WhichResult.GetX() << "," <<a_WhichResult.GetY() << "\n \n \n";

}

void Vector3Tests::ReportTestResultFloat(bool a_WhichBool, float a_WhichResultf, float a_WhichExpectedf, char* a_Test)
{
	
	cout << "\n\n Results for: \n " << "--- "<<a_Test <<" ---\n\n";
	if (a_WhichBool != true)
		
		cout << ">>>>>>>>> - PASSED - <<<<<<<<< \n \n Expected: " << a_WhichExpectedf << "\n\n\n";
	else
		if (a_WhichBool == true)
			cout << " >^._.^< PASSED! >^._.^< \n\n Expected: " << a_WhichExpectedf << "\n Got: " << a_WhichResultf << "\n\n\n";

}

void Vector3Tests:: RunTestAll()
{
	AssignTestResults();
	ReportTestResultVec(PassFailAddS, ResAddS, XResAddS, AddScaler);
	ReportTestResultVec(PassFailAddV, ResAddV, XResAddV, AddVec);
	ReportTestResultVec(PassFailSubV, ResSubV, XResSubV, SubtractVec);
	ReportTestResultVec(PassFailSubS, ResSubS, XResSubS, SubtractScaler);
	ReportTestResultVec(PassFailMultS, ResMultS, XResMultS, MultScaler);
	ReportTestResultVec(PassFailDivS, ResDivS, XResDivS, DivScaler);
	ReportTestResultFloat(PassFailGetMAG, ResGetMAG, XResGetMAG, GetMAG);
	ReportTestResultVec(PassFailGetNorm, ResGetNorm, XResGetNorm, Normalize);
	ReportTestResultFloat(PassFailEuler, ResEuler, XResEuler, EulerAngle);
	ReportTestResultFloat(PassFailGetDotProd, ResGetDotProd, XResGetDotProd, GetDotProduct);
	ReportTestResultVec(PassFailLinInt, ResLinInt, XResLinInt, LinearInterpolation);
}

