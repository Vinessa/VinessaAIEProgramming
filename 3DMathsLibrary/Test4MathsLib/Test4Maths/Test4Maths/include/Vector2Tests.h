#pragma once
#include "Vector2.h"
#include <iostream>
using namespace std;

enum ALG
{
	ADDS,
	ADDV,
	SUBS,
	SUBV,
	MULTS,
	DIVS,
	GETMAG,
	NORM,
	GETNORM,
	EULER,
	GETDOTPROD,
	XPROD,
	LININT
};


class Vector2Tests
{
public:
	Vector2Tests(void);
	~Vector2Tests(void);

	float dt;

	Vector2 T1;
	Vector2 T2;
	Vector2 T3;
	Vector2 ExpResult;

	Vector2 XResAddS;
	Vector2 XResAddV;
	Vector2 XResSubS;
	Vector2 XResSubV;
	Vector2 XResMultS;
	Vector2 XResDivS;
	float XResGetMAG;
	Vector2 XResNorm;
	Vector2 XResGetNorm;
	float XResEuler;
	float XResGetDotProd;
	
	Vector2 XResLinInt;

	Vector2 Result;
	float Resultf;

	bool PassFailAddS;
	bool PassFailAddV;
	bool PassFailSubS;
	bool PassFailSubV;
	bool PassFailMultS;
	bool PassFailDivS;
	bool PassFailGetMAG;
	bool PassFailNorm;
	bool PassFailGetNorm;
	bool PassFailEuler;
	bool PassFailGetDotProd;
	bool PassFailXProd;
	bool PassFailLinInt;

	float TScaler;



	void SetData (float FirstVecX, float FirstVecY, float SecondVecX, float SecondVecY, float ExpResultVecX, float ExpResultVecY);
	bool DoTestAddVector();
	bool DoTestAddScaler();
	bool DoTestMultScaler();
	bool DoTestDivScaler();

	bool DoTestGetMag();

	bool Vector2Tests::DoTestSubVector();
	bool DoTestSubScaler();
	void ReportTestResult(char a_WhichTest);
	
};



