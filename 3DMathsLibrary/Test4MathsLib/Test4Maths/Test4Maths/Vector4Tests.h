


#pragma once
#include "Vector4.h"
#include <iostream>
using namespace std;



class Vector4Tests
{
public:
	Vector4Tests(void);
	~Vector4Tests(void);

//CONSTANT VECTORS AND VARIABLES//
	//(INGREDIENTS)

	float dt;

	Vector4 T1;
	Vector4 T2;
	Vector4 T3;
	Vector4 TA;

	float TScaler;

	//TEMPS////////
	Vector4 Result;
	float Resultf;
	Vector4 ExpResult;
	char* m_HexValue;

//EXPECTED RESULTS///////////////

	Vector4 XResAddS;
	Vector4 XResAddV;
	Vector4 XResSubS;
	Vector4 XResSubV;
	Vector4 XResMultS;
	Vector4 XResDivS;
	float XResGetMAG;
	Vector4 XResNorm;
	Vector4 XResGetNorm;
	float XResEuler;
	Vector4 XResCrossProduct;
	float XResGetDotProd;
	Vector4 XResLinInt;
	Vector4 XResLinIntVec;
	Vector4 XResHEX2RGB;


//ACTUAL RESULTS/////////////////
	Vector4 ResAddS;
	Vector4 ResAddV;
	Vector4 ResSubS;
	Vector4 ResSubV;
	Vector4 ResMultS;
	Vector4 ResDivS;
	float ResGetMAG;
	Vector4 ResNorm;
	Vector4 ResGetNorm;
	float ResEuler;
	Vector4 ResCrossProduct;
	float ResGetDotProd;
	Vector4 ResLinInt;
	Vector4 ResHEX2RGB;


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
	bool PassFailXProd;
	bool PassFailGetDotProd;
	bool PassFailLinInt;


//FUNCTIONS////////////////////////
	void SetData ();

	bool DoTestAddVector();
	bool DoTestAddScaler();

	bool DoTestSubVector();
	bool DoTestSubScaler();

	bool DoTestMultScaler();
	bool DoTestDivScaler();

	bool DoTestGetMag();
	bool DoTestNormalize();
	bool DoTestEuler();
	bool DoTestXProd();
	bool DoTestGetDotProd();
	bool DoTestLinInt();
	bool DoTestHEX2RGB();

	void ReportTestResultFloat(bool a_WhichBool, float a_WhichResultf, float a_WhichExpectedf, char* a_Test);
	void ReportTestResultVec(bool a_WhichBool, Vector4 a_WhichResult, Vector4 a_WhichExpected, char* a_Test);
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
	char* CrossProd;
	char* GetDotProduct;
	char* LinearInterpolation;
	
};



