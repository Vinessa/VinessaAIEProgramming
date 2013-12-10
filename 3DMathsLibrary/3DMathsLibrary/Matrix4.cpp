#include "StdAfx.h"
#include "Matrix4.h"



Matrix4::Matrix4(void)
{
	m_A1=0; m_B1=0; m_C1=0; m_D1=0;
	m_A2=0; m_B2=0; m_C2=0; m_D2=0;
	m_A3=0; m_B3=0; m_C3=0; m_D3=0;
	m_A4=0; m_B4=0; m_C4=0; m_D4=0;

	//      A   B   C   D
	//   1[A1][B1][C1][D1]
	//   2[A2][B2][C2][D2]
	//   3[A3][B3][C3][D3]
	//   4[A4][B4][C4][D4]
}

Matrix4::Matrix4(float a_A1, float a_B1, float a_C1, float a_D1, float a_A2, float a_B2, float a_C2, float a_D2, float a_A3, float a_B3, float a_C3, float a_D3, float a_A4, float a_B4, float a_C4, float a_D4)
{
    m_A1=a_A1; m_B1=a_B1; m_C1=0; m_D1=0;
	m_A2=a_A2; m_B2=a_B2; m_C2=0; m_D2=0;
	m_A3=a_A3; m_B3=a_B3; m_C3=0; m_D3=0;
	m_A4=a_A4; m_B4=a_B4; m_C4=0; m_D4=0;

	//      A   B   C   D
	//   1[A1][B1][C1][D1]
	//   2[A2][B2][C2][D2]
	//   3[A3][B3][C3][D3]
	//   4[A4][B4][C4][D4]
}

Matrix4::~Matrix4(void)
{
}



Vector3 Matrix4::ConvertDegreesToRadians(float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z)
{
	float XRads = (a_Degrees_X * 3.14) / 180;
	float YRads = (a_Degrees_Y * 3.14) / 180;
	float ZRads = (a_Degrees_Z * 3.14) / 180;

	Vector3 a_Rads(XRads,YRads,ZRads);

	return a_Rads;
}

Matrix4 Matrix4::CreateRotationMatrix_X(float a_Degrees_X)
{
	Vector3 Rads = (ConvertDegreesToRadians(a_Degrees_X, 0, 0));
	Matrix4 RotX;

	RotX.m_A1=1; RotX.m_B1=0; RotX.m_C1=0;
	RotX.m_A2=0; RotX.m_B2=(acos(Rads.m_X)); RotX.m_C2=-(asin(Rads.m_X));
	RotX.m_A3=0; RotX.m_B3=(asin(Rads.m_X)); RotX.m_C3=(acos(Rads.m_X));

	return RotX;
}

Matrix4 Matrix4::CreateRotationMatrix_Y(float a_Degrees_Y)
{
	Vector3 Rads = (ConvertDegreesToRadians(0, a_Degrees_Y, 0));
	Matrix4 RotY;

	RotY.m_A1=acos(Rads.m_Y); RotY.m_B1=0; RotY.m_C1=asin(Rads.m_Y);
	RotY.m_A2= 0; RotY.m_B2= 1; RotY.m_C2= 0;
	RotY.m_A3=-(asin(Rads.m_Y); RotY.m_B3= 0; RotY.m_C3=acos(Rads.m_Y);
	
	return RotY;
} 


Matrix4 Matrix4::CreateRotationMatrix_Z(float a_Degrees_Z)
{
	Vector3 Rads = (ConvertDegreesToRadians(0, 0, a_Degrees_Z));
	Matrix4 RotZ;

	RotZ.m_A1 = acos(Rads.m_Z); RotZ.m_B1 = -(asin(Rads.m_Z)); RotZ.m_C1 = 0;
	RotZ.m_A2 = asin(Rads.m_Z); RotZ.m_B2 = acos(Rads.m_Z); RotZ.m_C2= 0;
	RotZ.m_A3 = 0; RotZ.m_B3 = 0; RotZ.m_C3 = 1;

	return RotZ;
} 
Matrix4 Matrix4::CreateRotationMatrix_3D(float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z)
{
	Matrix4 RotXYZ;
	RotXYZ = ((CreateRotationMatrix_X(a_Degrees_X)) * (CreateRotationMatrix_Y(a_Degrees_Y)) * (CreateRotationMatrix_Z(a_Degrees_Z)));
	
	return RotXYZ;

}

Matrix4 Matrix4::CreateScaleMatrix(float a_Scale_X, float a_Scale_Y, float a_Scale_Z)
{
	Matrix4 ScaleMatrix;

	ScaleMatrix.m_A1=a_Scale_X, ScaleMatrix.m_B1=0; ScaleMatrix.m_C1=0; ScaleMatrix.m_D1=0;
	ScaleMatrix.m_A2=0; ScaleMatrix.m_B2=a_Scale_Y; ScaleMatrix.m_C2=0; ScaleMatrix.m_D2=0;
	ScaleMatrix.m_A3=0; ScaleMatrix.m_B3=0; ScaleMatrix.m_C3=a_Scale_Z; ScaleMatrix.m_D3=0;
	ScaleMatrix.m_A4=0; ScaleMatrix.m_B4=0; ScaleMatrix.m_C4=0; ScaleMatrix.m_D4=0;

	return ScaleMatrix;
}

	Matrix4 Matrix4::operator * (Matrix4& OtherMatrix4)
{
	//  A   B  C
	//1[A1][B1][C1]
	//2[A2][B2][C2]
	//3[A3][B3][C3]     


Matrix4 Result;

Result.m_A1 = (m_A1 * OtherMatrix4.m_A1)+(m_A2 * OtherMatrix4.m_B1)+(m_A3 * OtherMatrix4.m_C1)+(m_A4 * OtherMatrix4.m_D1);
Result.m_A2 = (m_A1 * OtherMatrix4.m_A2)+(m_A2 * OtherMatrix4.m_B2)+(m_A3 * OtherMatrix4.m_C2)+(m_A4 * OtherMatrix4.m_D2);
Result.m_A3 = (m_A1 * OtherMatrix4.m_A3)+(m_A2 * OtherMatrix4.m_B3)+(m_A3 * OtherMatrix4.m_C3)+(m_A4 * OtherMatrix4.m_D3);
Result.m_A4 = (m_A1 * OtherMatrix4.m_A4)+(m_A2 * OtherMatrix4.m_B4)+(m_A3 * OtherMatrix4.m_C4)+(m_C4 * OtherMatrix4.m_D4);

Result.m_B1 = (m_B1 * OtherMatrix4.m_A1)+(m_B2 * OtherMatrix4.m_B1)+(m_B3 * OtherMatrix4.m_C1)+(m_B4 * OtherMatrix4.m_D1);
Result.m_B2 = (m_B1 * OtherMatrix4.m_A2)+(m_B2 * OtherMatrix4.m_B2)+(m_B3 * OtherMatrix4.m_C2)+(m_B4 * OtherMatrix4.m_D2);
Result.m_B3 = (m_B1 * OtherMatrix4.m_A3)+(m_B2 * OtherMatrix4.m_B3)+(m_B3 * OtherMatrix4.m_C3)+(m_B4 * OtherMatrix4.m_D3);
Result.m_B4 = (m_B1 * OtherMatrix4.m_A4)+(m_B2 * OtherMatrix4.m_B4)+(m_B3 * OtherMatrix4.m_C4)+(m_B4 * OtherMatrix4.m_D4);

Result.m_C1 = (m_C1 * OtherMatrix4.m_A1)+(m_C2 * OtherMatrix4.m_B1)+(m_C3 * OtherMatrix4.m_C1)+(m_C4 * OtherMatrix4.m_D1);
Result.m_C2 = (m_C1 * OtherMatrix4.m_A2)+(m_C2 * OtherMatrix4.m_B2)+(m_C3 * OtherMatrix4.m_C2)+(m_C4 * OtherMatrix4.m_D2);
Result.m_C3 = (m_C1 * OtherMatrix4.m_A3)+(m_C2 * OtherMatrix4.m_B3)+(m_C3 * OtherMatrix4.m_C3)+(m_C4 * OtherMatrix4.m_D3);
Result.m_C4 = (m_C1 * OtherMatrix4.m_A4)+(m_C2 * OtherMatrix4.m_B4)+(m_C3 * OtherMatrix4.m_C4)+(m_C4 * OtherMatrix4.m_D4);

Result.m_D1 = (m_D1 * OtherMatrix4.m_A1)+(m_D2 * OtherMatrix4.m_B1)+(m_D3 * OtherMatrix4.m_C1)+(m_D4 * OtherMatrix4.m_D1);
Result.m_D3 = (m_D1 * OtherMatrix4.m_A2)+(m_D2 * OtherMatrix4.m_B2)+(m_D3 * OtherMatrix4.m_C2)+(m_D4 * OtherMatrix4.m_D2);
Result.m_D2 = (m_D1 * OtherMatrix4.m_A3)+(m_D2 * OtherMatrix4.m_B3)+(m_D3 * OtherMatrix4.m_C3)+(m_D4 * OtherMatrix4.m_D3);
Result.m_D4 = (m_D1 * OtherMatrix4.m_A4)+(m_D2 * OtherMatrix4.m_B4)+(m_D3 * OtherMatrix4.m_C4)+(m_D4 * OtherMatrix4.m_D4);


return Result;