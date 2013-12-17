
#include "Vector2Tests.h"


Vector2Tests::Vector2Tests(void)
{
}


Vector2Tests::~Vector2Tests(void)
{
}


void Vector2Tests::SetData (float FirstVecX, float FirstVecY, float SecondVecX, float SecondVecY, float ExpResultVecX, float ExpResultVecY)

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
	Result = (T1 + TScaler);
	return (XResAddS == Result);
}

bool Vector2Tests::DoTestAddVector()
{
	cout << "Testing VECTOR + VECTOR ... \n";
	Result = (T1 + T2);
	return (XResAddV == Result);
	
}

bool Vector2Tests::DoTestSubScaler()
{
	cout << "Testing VECTOR - Scaler ... \n";
	Result = (T1 - TScaler);
	return (XResSubS == Result);
	
}

bool Vector2Tests::DoTestSubVector()
{
	cout << "Testing VECTOR - VECTOR ... \n";
	Result = (T1 - T2);
	return (XResSubV == Result);
	
}

bool Vector2Tests::DoTestMultScaler()
{
	cout << "Testing VECTOR * SCALER ... \n";
	Result = (T1 * TScaler);
	return (XResMultS == Result);
	
}

bool Vector2Tests::DoTestDivScaler()
{
cout << "Testing VECTOR / SCALER ... \n";
	Result = (T1 / TScaler);
	return (XResDivS == Result);
	
}

bool Vector2Tests::DoTestGetMag()
{
cout << "Testing GetMagnitude ... \n";
	Resultf = (T1.GetMagnitude2D());
	return (XResGetMAG == Resultf);
	
}





void Vector2Tests::ReportTestResult(char a_WhichTest)
{
	
	if (a_WhichTest != true)
		cout << "----------FAILED------: \n Expected: " << ExpResult.GetX() << ","<< ExpResult.GetY() << "\n Got: " << Result.GetX() << "," <<Result.GetY() << "\n";
	else
		if (a_WhichTest == true)
			cout << "Passed: \n Expected: " << ExpResult.GetX() << ","<< ExpResult.GetY() << "\n Got: " << Result.GetX() << "," <<Result.GetY() << "\n \n";

}



void Vector2Tests::TestAll(ALG)
{
	switch(ALG)
	{
	case ADDS:
		DoTestAddVector();
		TestResult(DoTestAddVector);
		break;

	case ADDV:

		break;
	case SUBS:

		break;
	case SUBV:

		break;
	case MULTS:

		break;
	case DIVS:

		break;
	case GETMAG:

		break;
	case NORM:

		break;
	case GETNORM:

		break;
	case EULER:

		break;
	case GETDOTPROD:

		break;
	case XPROD:

		break;
	case LININT:

		break;

	}