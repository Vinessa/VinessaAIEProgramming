#pragma once
#include "Vector2.h"
#include <iostream>
using namespace std;

class Vector2Tests
{
public:
	Vector2Tests(void);
	~Vector2Tests(void);


	Vector2 T1;
	Vector2 T2;
	Vector2 T3;
	Vector2 ExpResult;
	Vector2 Result;
	bool PassFail;

	float TScaler;



	void SetData (float FirstVecX, float FirstVecY, float SecondVecX, float SecondVecY, float ExpResultVecX, float ExpResultVecY);
	virtual bool DoTest();
	void Vector2Tests::TestResult();
};



