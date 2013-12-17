
#include "Vector2Tests.h"


Vector2Tests::Vector2Tests(void)
{
}


Vector2Tests::~Vector2Tests(void)
{
}


void Vector2Tests::SetData (float FirstVecX, float FirstVecY, float SecondVecX, float SecondVecY, float ExpResultVecX, float ExpResultVecY)

{

	T1.SetX(FirstVecX);
	T1.SetY(FirstVecY);

	T2.SetX(SecondVecX);
	T2.SetY(SecondVecY);

	ExpResult.SetX(ExpResultVecX);
	ExpResult.SetY(ExpResultVecY);



}

bool Vector2Tests::DoTest()
{
	cout << "Testing VECTOR + VECTOR ... \n";
	Result = (T1 + T2);
	return (ExpResult == Result);
	
}

void Vector2Tests::TestResult()
{
	PassFail = (DoTest());
	if (PassFail != true)
		cout << "----------FAILED------: \n Expected: " << ExpResult.GetX() << ","<< ExpResult.GetY() << "\n Got: " << Result.GetX() << "," <<Result.GetY() << "\n";
	else
		if (PassFail == true)
			cout << "Passed: \n Expected: " << ExpResult.GetX() << ","<< ExpResult.GetY() << "\n Got: " << Result.GetX() << "," <<Result.GetY() << "\n \n";

}