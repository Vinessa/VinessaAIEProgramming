#pragma once
class Matrix3Tests
{
public:
	Matrix3Tests(void);
	~Matrix3Tests(void);
};

class Vector3Tests
{
public:
	Vector3Tests(void);
	~Vector3Tests(void);

//CONSTANT VECTORS AND VARIABLES//
	//(INGREDIENTS)

	float dt;

	Vector3 T1;
	Vector3 T2;
	Vector3 T3;

	float TScaler;

	//TEMPS////////
	Vector3 Result;
	float Resultf;
	Vector3 ExpResult;

//EXPECTED RESULTS///////////////

	Vector3 XResAddS;
	Vector3 XResAddV;
	Vector3 XResSubS;
	Vector3 XResSubV;
	Vector3 XResMultS;
	Vector3 XResDivS;
	float XResGetMAG;
	Vector3 XResNorm;
	Vector3 XResGetNorm;
	float XResEuler;
	Vector3 XResCrossProduct;
	float XResGetDotProd;
	Vector3 XResLinInt;
	Vector3 XResLinIntVec;


//ACTUAL RESULTS/////////////////
	Vector3 ResAddS;
	Vector3 ResAddV;
	Vector3 ResSubS;
	Vector3 ResSubV;
	Vector3 ResMultS;
	Vector3 ResDivS;
	float ResGetMAG;
	Vector3 ResNorm;
	Vector3 ResGetNorm;
	float ResEuler;
	Vector3 ResCrossProduct;
	float ResGetDotProd;
	Vector3 ResLinInt;


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

	void ReportTestResultFloat(bool a_WhichBool, float a_WhichResultf, float a_WhichExpectedf, char* a_Test);
	void ReportTestResultVec(bool a_WhichBool, Matrix3 a_WhichResult, Matrix3 a_WhichExpected, char* a_Test);
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