#pragma once
#include "Matrix3.h"
#include <iostream>
using namespace std;

class Matrix3Tests
{
public:
	Matrix3Tests(void);
	~Matrix3Tests(void);



//CONSTANT VECTORS AND VARIABLES//
	//(INGREDIENTS)

	float dt;

	Matrix3 T1;
	Matrix3 T2;
	Matrix3 T3;

	float TScaler;
	float TScalerX;
	float TScalerY;

//EXPECTED RESULTS///////////////


	/*Matrix3 XResOrthographicProj;*/
	Matrix3 XResScale;
	Matrix3 XResRotation;
	Matrix3 XResTransformPoint;
	Matrix3 XResTransformVector;
	Matrix3 XResMatrixMultiplication;


//ACTUAL RESULTS/////////////////
	/*Matrix3 ResOrthographicProj;*/
	Matrix3 ResScale;
	Matrix3 ResRotation;
	Matrix3 ResTransformPoint;
	Matrix3 ResTransformVector;
	Matrix3 ResMatrixMultiplication;


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


	void ReportTestResult(bool a_WhichBool, Matrix3 a_WhichResultMat3, Matrix3 a_WhichExpectedMat3, char* a_Test);
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