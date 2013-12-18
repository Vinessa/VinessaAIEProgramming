
#include "Vector2Tests.h"


Vector2Tests::Vector2Tests(void)
{
}


Vector2Tests::~Vector2Tests(void)
{
}


void Vector2Tests::SetData ()

{
	T1.SetX(1);
	T1.SetY(2);

	T2.SetX(3);
	T2.SetY(4);
	
	T3.SetX(5);
	T3.SetY(6);

	TScaler = 9;
	dt = .5;

	XResAddS.SetX(10);
	XResAddS.SetY(11);

	XResAddV.SetX(4);
	XResAddV.SetY(6);

	XResSubS.SetX(-8);
	XResSubS.SetY(-7);

	XResSubV.SetX(-2);
	XResSubV.SetY(-2);

	XResMultS.SetX(9);
	XResMultS.SetY(18);
	
	XResDivS.SetX(0.11);
	XResDivS.SetY(0.22);

	XResGetMAG = 2.24;


	XResGetNorm.SetX(0.45);
	XResGetNorm.SetY(0.89);
	
	XResEuler = 0.18;

	XResGetDotProd = 11;

	XResLinInt.SetX(2);
	XResLinInt.SetX(3.5);

	AddVec = "AddVector";
	AddScaler = "AddbyScaler";
	SubtractVec = "SubtractVector";
	SubtractScaler = "SubtractbyScaler";
	MultScaler = "MultiplybyScaler";
	DivScaler = "DividebyScaler";
	GetMagnitude = "GetMagnitude";
	Normalize = "Normalize";
	EulerAngle = "EulerAngle";
	GetDotProduct = "GetDotProduct";
	LinearInterpolation = "LinearInterpolation";





	/*T1.SetX(FirstVecX);
	T1.SetY(FirstVecY);

	T2.SetX(SecondVecX);
	T2.SetY(SecondVecY);

	ExpResult.SetX(ExpResultVecX);
	ExpResult.SetY(ExpResultVecY);*/



}

bool Vector2Tests::DoTestAddScaler()
{
	cout << "Testing VECTOR + SCALER ... \n";
	ResAddS = (T1 + TScaler);
	return (XResAddS == ResAddS);
}

bool Vector2Tests::DoTestAddVector()
{
	cout << "Testing VECTOR + VECTOR ... \n";
	ResAddV = (T1 + T2);
	return (XResAddV == ResAddV);
	
}

bool Vector2Tests::DoTestSubScaler()
{
	cout << "Testing VECTOR - Scaler ... \n";
	ResSubS = (T1 - TScaler);
	return (XResSubS == ResSubS);
	
}

bool Vector2Tests::DoTestSubVector()
{
	cout << "Testing VECTOR - VECTOR ... \n";
	Result = (T1 - T2);
	return (XResSubV == ResSubV);
	
}

bool Vector2Tests::DoTestMultScaler()
{
	cout << "Testing VECTOR * SCALER ... \n";
	ResMultS = (T1 * TScaler);
	return (XResMultS == ResMultS);
	
}

bool Vector2Tests::DoTestDivScaler()
{
cout << "Testing VECTOR / SCALER ... \n";
	ResDivS = (T1 / TScaler);
	return (XResDivS == ResDivS);
	
}

bool Vector2Tests::DoTestGetMag()
{
cout << "Testing GetMagnitude ... \n";
	ResGetMAG = (T1.GetMagnitude2D());
	return (XResGetMAG == ResGetMAG);
	
}

bool Vector2Tests::DoTestNormalize() //only tested this instead of normalize because getnormal has normalize in it and will test both
{
cout << "Testing Normalization ... \n";
	ResGetNorm = (T1.GetNormal());
	return (XResGetNorm == ResGetNorm);
	
}

bool Vector2Tests::DoTestEuler() 
{
cout << "Testing Euler ... \n";
	ResEuler = (T1.EulerAngle(T2));
	return (XResEuler == ResEuler);
	
}

bool Vector2Tests::DoTestGetDotProd() 
{
cout << "Testing GetDotProduct2D ... \n";
	ResGetDotProd = (T1.GetDotProduct2D(T2));
	return (XResGetDotProd == ResGetDotProd);
	
}

bool Vector2Tests::DoTestLinInt() 
{
cout << "Testing LinearInterpolation ... \n";
	XResLinInt = (T1.LinearInterpolation(T2,dt));
	return (XResLinInt == XResLinInt);
	
}

void Vector2Tests:: AssignTestResults()
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
	 PassFailGetDotProd = (DoTestGetDotProd());
	 PassFailLinInt = (DoTestLinInt());

}

void Vector2Tests::ReportTestResultVec(bool a_WhichBool, Vector2 a_WhichResult, Vector2 a_WhichExpected, char* a_Test )
{
	
	cout << "\n\n Results for: \n " << "--- "<<a_Test <<" ---\n\n";
	if (a_WhichBool != true)
		
		cout << ">>>>>>>>> - FAILED - <<<<<<<<< \n \n Expected: " << a_WhichExpected.GetX() << ","<< a_WhichExpected.GetY() << "\n Got: " << a_WhichResult.GetX() << "," <<a_WhichResult.GetY() << "\n\n\n";
	else
		if (a_WhichBool == true)
			cout << " >^._.^< PASSED! >^._.^< \n\n Expected: " << a_WhichExpected.GetX() << ","<< a_WhichExpected.GetY() << "\n Got: " << a_WhichResult.GetX() << "," <<a_WhichResult.GetY() << "\n \n \n";

}


void Vector2Tests:: RunTestAll()
{
	AssignTestResults();
	ReportTestResultVec(PassFailAddS, ResAddS, XResAddS, AddScaler);
	ReportTestResultVec(PassFailAddV, ResAddV, XResAddV, AddVec);
}

//void Vector2Tests::TestAll(ALG)
//{
//	switch(ALG)
//	{
//	case ADDS:
//		DoTestAddVector();
//		TestResult(DoTestAddVector);
//		break;
//
//	case ADDV:
//
//		break;
//	case SUBS:
//
//		break;
//	case SUBV:
//
//		break;
//	case MULTS:
//
//		break;
//	case DIVS:
//
//		break;
//	case GETMAG:
//
//		break;
//	case NORM:
//
//		break;
//	case GETNORM:
//
//		break;
//	case EULER:
//
//		break;
//	case GETDOTPROD:
//
//		break;
//	case XPROD:
//
//		break;
//	case LININT:
//
//		break;
//
//	}