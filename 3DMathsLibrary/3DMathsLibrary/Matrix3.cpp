
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
	Vector3 Rads = (ConvertDegreesToRadians(a_Degrees_X, 0, 0));
	Matrix3 RotX;

	RotX.m_A1=1; RotX.m_B1=0; RotX.m_C1=0;
	RotX.m_A2=0; RotX.m_B2=(acos(Rads.m_X)); RotX.m_C2=-(asin(Rads.m_X));
	RotX.m_A3=0; RotX.m_B3=(asin(Rads.m_X)); RotX.m_C3=(acos(Rads.m_X));

	return RotX;
}

Matrix3 Matrix3::CreateRotationMatrix_Y(float a_Degrees_Y)
{
	Vector3 Rads = (ConvertDegreesToRadians(0, a_Degrees_Y, 0));
	Matrix3 RotY;

	RotY.m_A1=acos(Rads.m_Y); RotY.m_B1=0; RotY.m_C1=asin(Rads.m_Y);
	RotY.m_A2= 0; RotY.m_B2= 1; RotY.m_C2= 0;
	RotY.m_A3=-(asin(Rads.m_Y); RotY.m_B3= 0; RotY.m_C3=acos(Rads.m_Y);
	
	return RotY;
} 


Matrix3 Matrix3::CreateRotationMatrix_Z(float a_Degrees_Z)
{
	Vector3 Rads = (ConvertDegreesToRadians(0, 0, a_Degrees_Z));
	Matrix3 RotZ;

	RotZ.m_A1 = acos(Rads.m_Z); RotZ.m_B1 = -(asin(Rads.m_Z)); RotZ.m_C1 = 0;
	RotZ.m_A2 = asin(Rads.m_Z); RotZ.m_B2 = acos(Rads.m_Z); RotZ.m_C2= 0;
	RotZ.m_A3 = 0; RotZ.m_B3 = 0; RotZ.m_C3 = 1;

	return RotZ;
} 

Matrix3 Matrix3::CreateRotationMatrix_2D(float a_Degrees_X, float a_Degrees_Y)
{
	Matrix3 RotXYZ;
	RotXYZ = ((CreateRotationMatrix_X(a_Degrees_X)) * (CreateRotationMatrix_Y(a_Degrees_Y)));
	
	return RotXYZ;

}

 




float* Matrix3::GetRotation_3D() //Returns a float pointer that points to all three arrays because a function is not allowed to return an array.
{
	Pointer = RotateX, RotateY, RotateZ;
	return Pointer;
}

float*  Matrix3::GetRotation_X()
{
	Pointer = RotateX;
	return Pointer;
}

float*  Matrix3::GetRotation_Y()
{
	Pointer = RotateY;
	return Pointer;
}

float*  Matrix3::GetRotation_Z()
{
	Pointer = RotateZ;
	return Pointer;
}


void Matrix3::SetRotation()
{

}

Matrix3 Matrix3::CreateScaleMatrix(float a_Scale_X, float a_Scale_Y)
{
	ScaleMatrix[3][3]
	 = {{a_ScaleX, 0,0}
	{0,a_ScaleY, 0}
	{0,0,0}};

	return ScaleMatrix;
}
//void Matrix3::ScaleMatrix(float a_ScaleX, float a_ScaleY)
//{
//	Scale[3][3]
//	{{a_ScaleX, 0,0}
//	 {0,a_ScaleY, 0}
//	 {0,0,0}};
//
//	 this -> *= Scale;
//}

void Matrix3::operator *=(Matrix& OtherMatrix)
{
	
	//Assume the following:
	//This [3][3]{{a,b,c}      OtherMatrix [3][3]{{A,B,C}
	//            {d,e,f}                         {D,E,F}
	//            {g,h,i}}                        {G,H,I}

	//finds the dot product of the first row of this by multiplying matching members. In this case Sum1 = (a*B) + (b*D) + (c+G)

float Sum1 = ((this[1][1] * OtherMatrix[1][1]) +
			  (this[1][2] * OtherMatrix[1][2]) +
              (this[1][3] * OtherMatrix[1][3])); 

float Sum2 = ((this[1][1]* OtherMatrix[1



/*this[1][1]{((this[1][1] * OtherMatrix[1][2]) +
(this[1][2] * OtherMatrix[2][1]) +
(this[1][3] * OtherMatrix[1][3]))};*/ //finds the dot product of the first row of this by multiplying matching members. In this case this[1][1] = (a*B) + (b*D) + (c+G) (AKA Sum1)


}