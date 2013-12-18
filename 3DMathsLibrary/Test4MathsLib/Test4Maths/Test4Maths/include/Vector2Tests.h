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

//CONSTANT VECTORS AND VARIABLES//
	//(INGREDIENTS)

	float dt;

	Vector2 T1;
	Vector2 T2;
	Vector2 T3;

	//TEMPS////////
	Vector2 Result;
	float Resultf;
	Vector2 ExpResult;

//EXPECTED RESULTS///////////////

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


//ACTUAL RESULTS/////////////////
	Vector2 ResAddS;
	Vector2 ResAddV;
	Vector2 ResSubS;
	Vector2 ResSubV;
	Vector2 ResMultS;
	Vector2 ResDivS;
	float ResGetMAG;
	Vector2 ResNorm;
	Vector2 ResGetNorm;
	float ResEuler;
	float ResGetDotProd;
	Vector2 ResLinInt;


//PASS OR FAILS////////////////////
	bool PassFailAddS;
	bool PassFailAddV;
	bool PassFailSubS;
	bool PassFailSubV;
	bool PassFailMultS;
	bool PassFailDivS;
	bool PassFailGetMAG;
	bool PassFailNorm;
	bool PassFailGetNorm; //only tested this instead of normalize because get normal has normalize in it and will test both
	bool PassFailEuler;
	bool PassFailGetDotProd;
	bool PassFailXProd;
	bool PassFailLinInt;

	float TScaler;


//FUNCTIONS////////////////////////
	void SetData ();
	bool DoTestAddVector();
	bool DoTestAddScaler();
	bool DoTestMultScaler();
	bool DoTestDivScaler();

	bool DoTestGetMag();
	bool DoTestNormalize();
	bool DoTestEuler();

	bool DoTestSubVector();
	bool DoTestGetDotProd();
	bool DoTestSubScaler();
	bool DoTestLinInt();
	void ReportTestResultFloat(bool a_WhichBool, float a_WhichResultf, float a_WhichExpectedf, char* a_Test);
	void ReportTestResultVec(bool a_WhichBool, Vector2 a_WhichResult, Vector2 a_WhichExpected, char* a_Test);
	void AssignTestResults();
	void RunTestAll();

	//LABELS///

	char* AddVec;
	char* AddScaler;
	char* SubtractVec;
	char* SubtractScaler;
	char* MultScaler;
	char* DivScaler;
	char* GetMAG;
	char* Normalize;
	char* EulerAngle;
	char* GetDotProduct;
	char* LinearInterpolation;
	
};



