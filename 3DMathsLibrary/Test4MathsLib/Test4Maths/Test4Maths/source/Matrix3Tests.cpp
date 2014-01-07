#include "Matrix3Tests.h"


Matrix3Tests::Matrix3Tests(void)
{
}


Matrix3Tests::~Matrix3Tests(void)
{
}

void Matrix3Tests::SetData()

{
	Matrix3 Temp(1,0,0,0,1,0,0,0,1);
	Matrix3 Temp2(1,2,3,4,1,2,3,4,1);
	Matrix3 Temp3(1,4,3,2,1,4,3,2,1);
	Matrix3 TempOrthoProject();
	Matrix3 XTempScale(5,0,0,0,4,0,0,0,0);
	Matrix3 XTempRotation();
	Matrix3 XTempTransformPoint();
	Matrix3 XTempTransformVector();
	Matrix3 XTempMatrixMultiplication(14,12,14,12,21,18,14,18,26);

	/*XResOrthographicProj = TempOrthoProject;*/
	XResScale = XTempScale;
	/*XResRotation = XTempRotation;*/
	/*XResTransformPoint = XTempTransformPoint;
	XResTransformVector = XTempTransformVector;*/
	ResMatrixMultiplication = XTempMatrixMultiplication;

	T1 = Temp;
	T2 = Temp2;
	T3 = Temp3;


	TScaler = 10;
	TScalerX = 5;
	TScalerY = 4;
	dt = .5;


	Mat3 = "MATRIX 3";
	/*OrthoProj = "Orthographic Projection";*/
	Scale = "Scale Matrix3";
	Rotation = "Rotate Matrix3";
	TransformPoint = "Transform Point";
	TransformVector = "Transform Vector";
	MatrixMultiplication = "Matrix Multiplication";
	
}

bool Matrix3Tests::DoTestScale()
{
	cout << "Testing CREATE SCALE MATRIX ... \n";
	ResScale = (T1.CreateScaleMatrix(TScalerX,TScalerY));
	return (XResScale == ResScale);
}


bool Matrix3Tests::DoTestMatrixMultiplication()
{
	cout << "Testing MatrixMultiplication ... \n";
	ResMatrixMultiplication = (T2*T3);
	return (XResMatrixMultiplication == ResMatrixMultiplication);
}

void Matrix3Tests:: AssignTestResults()
{


	 //PassFailOrthographicProj = (DoTestOrthographicProjection()); //NOT IN TEST YET
	 PassFailScale = (DoTestScale());
	  // PassFailRotation = (DoTestRotation()); //NOT YET IN TEST
	 //PassFailTransformPoint = (DoTestTransformPoint()); // NOT YET IN TEST
	// PassFailTransformVector = (DoTestTransformVector()); //NOT YET IN TEST
	 PassFailMatrixMultiplication = (DoTestMatrixMultiplication());
	
}

void Matrix3Tests::ReportTestResult(bool a_WhichBool, Matrix3 a_WhichResultMat3, Matrix3 a_WhichExpectedMat3, char* a_Test)
{
	
	cout << "\n\n Results for: \n " << "--- "<<a_Test <<" ---\n\n";
	if (a_WhichBool != true)
		
		cout << ">>>>>>>>> - FAILED - <<<<<<<<< \n \n Expected: " << a_WhichExpectedMat3 << "\n Got: " << a_WhichResultMat3 << "\n\n\n";
	else
		if (a_WhichBool == true)
			cout << " >^._.^< PASSED! >^._.^< \n\n Expected: " << a_WhichExpectedMat3 << "\n Got: " << a_WhichResultMat3 << "\n\n\n";

}

void Matrix3Tests:: RunTestAll()
{
	AssignTestResults();
	//ReportTestResult(PassFailOrthographicProj, ResOrthographicProj, XResOrthographicProj,OrthoProj);
	ReportTestResult(PassFailScale, ResScale, XResScale, Scale);
	//ReportTestResult(PassFailRotation, ResRotation, XResRotation, Rotation);
	//ReportTestResult(PassFailTransformPoint, ResTransformPoint, XResTransformPoint, TransformPoint);
	//ReportTestResult(PassFailTransformVector, ResTransformVector, XResTransformVector, TransformVector);
	ReportTestResult(PassFailMatrixMultiplication, ResMatrixMultiplication, XResMatrixMultiplication, MatrixMultiplication);
}   
