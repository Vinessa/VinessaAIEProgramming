
#include "StdAfx.h"
#include "Matrix3.h"



Matrix3::Matrix3(void)
{
	m_A1=0; m_B1=0; m_C1=0;
	m_A2=0; m_B2=0; m_C2=0;
	m_A3=0; m_B3=0; m_C3=0;

	//  A   B  C
	//1[A1][B1][C1]
	//2[A2][B2][C2]
	//3[A3][B3][C3]
}

Matrix3::Matrix3(float a_A1, float a_B1, float a_C1, float a_A2, float a_B2, float a_C2, float a_A3, float a_B3, float a_C3)
{
	m_A1 = a_A1; m_B1 = a_B1; m_C1 = a_C1;
	m_A2 = a_A2; m_B2 = a_B2; m_C2 = a_C2;
	m_A3 = a_A3; m_B3 = a_B3; m_C3 = a_C3;

	 //  A   B  C
	//1[A1][B1][C1]
	//2[A2][B2][C2]
	//3[A3][B3][C3]

}

Matrix3::~Matrix3(void)
{
}


Matrix3 Matrix3::CreateIdentityMatrix()
{
	Matrix3 Identity;
	Identity.m_A1=1; Identity.m_B1=0; Identity.m_C1=0;
	Identity.m_A2=0; Identity.m_B2=1; Identity.m_C2=0;
	Identity.m_A3=0; Identity.m_B3=0; Identity.m_C3=1;
	return Identity;
}

Matrix3 Matrix3::CreateTranslationMatrix(float X, float Y)
{
	Matrix3 Translation;
	Translation.m_A1=1; Translation.m_B1=0; Translation.m_C1=0;
	Translation.m_A2=0; Translation.m_B2=1; Translation.m_C2=0;
	Translation.m_A3=0; Translation.m_B3=0; Translation.m_C3=1;
	return Translation;

}



Vector2 Matrix3::ConvertDegreesToRadians(float a_Degrees_X, float a_Degrees_Y)
{
	float XRads = (a_Degrees_X * 3.14) / 180;
	float YRads = (a_Degrees_Y * 3.14) / 180;


	Vector2 a_Rads(XRads,YRads);

	return a_Rads;
}

Matrix3 Matrix3::CreateRotationMatrix_X(float a_Degrees_X)
{
	Vector2 Rads = (ConvertDegreesToRadians(a_Degrees_X, 0));
	Matrix3 RotX;

	RotX.m_A1=1; RotX.m_B1=0; RotX.m_C1=0;
	RotX.m_A2=0; RotX.m_B2=(acos(Rads.GetX())); RotX.m_C2=-(asin(Rads.GetX()));
	RotX.m_A3=0; RotX.m_B3=(asin(Rads.GetX())); RotX.m_C3=(acos(Rads.GetX()));

	return RotX;
}

Matrix3 Matrix3::CreateRotationMatrix_Y(float a_Degrees_Y)
{
	Vector2 Rads = (ConvertDegreesToRadians(0, a_Degrees_Y));
	Matrix3 RotY;

	RotY.m_A1=acos(Rads.GetY()); RotY.m_B1=0; RotY.m_C1=asin(Rads.GetY());
	RotY.m_A2= 0; RotY.m_B2= 1; RotY.m_C2= 0;
	RotY.m_A3=-(asin(Rads.GetY())); RotY.m_B3= 0; RotY.m_C3=acos(Rads.GetY());
	
	return RotY;
} 

Matrix3 Matrix3::CreateRotationMatrix_2D(float a_Degrees_X, float a_Degrees_Y)
{
	Matrix3 RotXY;
	RotXY = ((CreateRotationMatrix_X(a_Degrees_X)) * (CreateRotationMatrix_Y(a_Degrees_Y)));
	
	return RotXY;

}

 



//
//float* Matrix3::GetRotation_3D() //Returns a float pointer that points to all three arrays because a function is not allowed to return an array.
//{
//	Pointer = RotateX, RotateY, RotateZ;
//	return Pointer;
//}

//float*  Matrix3::GetRotation_X()
//{
//	Pointer = RotateX;
//	return Pointer;
//}

//float*  Matrix3::GetRotation_Y()
//{
//	Pointer = RotateY;
//	return Pointer;
//}

//float*  Matrix3::GetRotation_Z()
//{
//	Pointer = RotateZ;
//	return Pointer;
//}


//void Matrix3::SetRotation()
//{
//
//}

Matrix3 Matrix3::CreateScaleMatrix(float a_ScalerX, float a_YScaler)
{
	Matrix3 ScaleMatrix;

	ScaleMatrix.m_A1 = a_ScalerX, ScaleMatrix.m_B1=0; ScaleMatrix.m_C1=0;
	ScaleMatrix.m_A2=0; ScaleMatrix.m_B2 = a_YScaler; ScaleMatrix.m_C2=0;
	ScaleMatrix.m_A3=0; ScaleMatrix.m_B3=0; ScaleMatrix.m_C3=0;

	return ScaleMatrix;
}


Matrix3 Matrix3::operator * (Matrix3& OtherMatrix3)
{
	//  A   B  C
	//1[A1][B1][C1]
	//2[A2][B2][C2]
	//3[A3][B3][C3]     


Matrix3 Result;

Result.m_A1 = (m_A1* OtherMatrix3.m_A1)+(m_A2 * OtherMatrix3.m_B1)+(m_A3 * OtherMatrix3.m_C1);
Result.m_A2 = (m_A1* OtherMatrix3.m_A2)+(m_A2 * OtherMatrix3.m_B2)+(m_A3 * OtherMatrix3.m_C2);
Result.m_A3 = (m_A1* OtherMatrix3.m_A3)+(m_A2 * OtherMatrix3.m_B3)+(m_A3 * OtherMatrix3.m_C3);

Result.m_B1 = (m_B1 * OtherMatrix3.m_A1)+(m_B2 * OtherMatrix3.m_B1)+(m_B3 * OtherMatrix3.m_C1);
Result.m_B2 = (m_B1 * OtherMatrix3.m_A2)+(m_B2 * OtherMatrix3.m_B2)+(m_B3 * OtherMatrix3.m_C2);
Result.m_B3 = (m_B1 * OtherMatrix3.m_A3)+(m_B2 * OtherMatrix3.m_B3)+(m_B3 * OtherMatrix3.m_C3);

Result.m_C1 = (m_C1 * OtherMatrix3.m_A1)+(m_C2 * OtherMatrix3.m_B1)+(m_C3 * OtherMatrix3.m_C1);
Result.m_C2 = (m_C1 * OtherMatrix3.m_A2)+(m_C2 * OtherMatrix3.m_B2)+(m_C3 * OtherMatrix3.m_C2);
Result.m_C3 = (m_C1 * OtherMatrix3.m_A3)+(m_C2 * OtherMatrix3.m_B3)+(m_C3 * OtherMatrix3.m_C3);

return Result;


}

Matrix3 Matrix3::operator * (float Scaler)
{
	//  A   B  C
	//1[A1][B1][C1]
	//2[A2][B2][C2]
	//3[A3][B3][C3]     


Matrix3 Result;

Result.m_A1 = (m_A1* Scaler)+(m_A2 * Scaler)+(m_A3 * Scaler);
Result.m_A2 = (m_A1* Scaler)+(m_A2 * Scaler)+(m_A3 * Scaler);
Result.m_A3 = (m_A1* Scaler)+(m_A2 * Scaler)+(m_A3 * Scaler);

Result.m_B1 = (m_B1 * Scaler)+(m_B2 * Scaler)+(m_B3 * Scaler);
Result.m_B2 = (m_B1 * Scaler)+(m_B2 * Scaler)+(m_B3 * Scaler);
Result.m_B3 = (m_B1 * Scaler)+(m_B2 * Scaler)+(m_B3 * Scaler);

Result.m_C1 = (m_C1 * Scaler)+(m_C2 * Scaler)+(m_C3 * Scaler);
Result.m_C2 = (m_C1 * Scaler)+(m_C2 * Scaler)+(m_C3 * Scaler);
Result.m_C3 = (m_C1 * Scaler)+(m_C2 * Scaler)+(m_C3 * Scaler);

return Result;
}

void Matrix3::TransformVector(float X, float Y)
{
	m_C1 = X;
	m_C2 = Y;
}