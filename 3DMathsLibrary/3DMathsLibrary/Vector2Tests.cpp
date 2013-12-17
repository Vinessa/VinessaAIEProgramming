#include "StdAfx.h"
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
	ExpResult.SetY(ExpResultVecX);



}