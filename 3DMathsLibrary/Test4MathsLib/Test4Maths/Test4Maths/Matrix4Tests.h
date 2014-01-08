#pragma once
#include "Matrix4.h"
class Matrix4Tests
{
public:
	Matrix4Tests(void);
	~Matrix4Tests(void);
	//CONSTANT VECTORS AND VARIABLES//
	//(INGREDIENTS)

	float dt;

	Matrix4 T1;
	Matrix4 T2;
	Matrix4 T3;

	float TScaler;
	float TScalerX;
	float TScalerY;

//EXPECTED RESULTS///////////////


	//Matrix4 XResOrthographicProj;
	Matrix4 XResScale;
	Matrix4 XResRotation;
	Matrix4 XResTransformPoint;
	Matrix4 XResTransformVector;
	Matrix4 XResMatrixMultiplication;


//ACTUAL RESULTS/////////////////
	//Matrix4 ResOrthographicProj;
	Matrix4 ResScale;
	Matrix4 ResRotation;
	Matrix4 ResTransformPoint;
	Matrix4 ResTransformVector;
	Matrix4 ResMatrixMultiplication;


//PASS OR FAILS////////////////////
	bool PassFailOrthographicProj;
	bool PassFailScale;

	bool PassFailRotation;
	bool PassFailTransformPoint;

	bool PassFailTransformVector;
	bool PassFailMatrixMultiplication;




//FUNCTIONS////////////////////////
	void SetData();
	bool DoTestOrthographicProj();
	bool DoTestScale();

	bool DoTestRotation();
	bool DoTestTransformPoint();

	bool DoTestTransformVector();
	bool DoTestMatrixMultiplication();


	void ReportTestResult(bool a_WhichBool, Matrix4 a_WhichResultMat3, Matrix4 a_WhichExpectedMat3, char* a_Test);
	void ReportTestResultOrtho();
	void AssignTestResults();
	void RunTestAll();

	//LABELS///

	char* Mat3;
	char* OrthoProj;
	char* Scale;

	char* Rotation;
	char* TransformPoint;

	char* TransformVector;
	char* MatrixMultiplication;

	
};

