
#include "StdAfx.h"
#include "Matrix3.h"



Matrix3::Matrix3(void)
{
	int Matrix [3][3] = {{1,0,0},
	{0,1,0},
	{0,0,1}};
}

Matrix3::Matrix3(const int N_ColumnsSize, const int m_RowSize)
{
	int Matrix [3][3]= {{1,0,0},
	{0,1,0},
	{0,0,1}};
}

Matrix3::~Matrix3(void)
{
}


void Matrix3::CreateIdentityMatrix(float X, float Y, float Z)
{
	Identity[3][3] = {{X,0,0},
	{0,Y,0},
	{0,0,Z}};
}




void Matrix3::CreateTranslationMatrix(float X, float Y)
{
	Translation[3][3] = {{0,0,X},
	{0,0,Y},
	{0,0,0}};
}

void Matrix3::SetTranslation(float X, float Y)
{
	Translation[3][1] = {X};
	Translation[3][2] = {Y};
}

Vector2 Matrix3::GetTranslations()
{
	Vector2 vTemp (Translation[3][1],Translation[3][2]);
	return vTemp;
}

Vector3 Matrix3::ConvertDegreesToRadians(float Degrees_X, float Degrees_Y, float Degrees_Z)
{
	float XRads = (Degrees_X * 3.14) / 180;
	float YRads = (Degrees_Y * 3.14) / 180;
	float ZRads = (Degrees_Z * 3.14) / 180;

	Vector3 Rads(XRads,YRads,ZRads);

	return Rads;
}

void Matrix3::CreateRotationMatrix_X(float Degrees_X)
{
	float Degrees_Y = 0;
	float Degrees_Z = 0;
	Vector3 Rads = (ConvertDegreesToRadians(Degrees_X, Degrees_Y, Degrees_Z));
	RotateX[3][3] = {{1,0,0},
	{0, acos(Rads.m_X),-(asin(Rads.m_X))},
	{0, asin(Rads.m_X), acos(Rads.m_X)}};
}

void Matrix3::CreateRotationMatrix_Y(float Degrees_Y)
{
	float Degrees_X = 0;
	float Degrees_Z = 0;
	Vector3 Rads = (ConvertDegreesToRadians(Degrees_X, Degrees_Y, Degrees_Z));
	RotateY[3][3] = {{acos(Rads.m_Y),0,asin(Rads.m_Y)},
	{0,1,0},
	{-(asin(Rads.m_Y),0, acos(Rads.m_Y)}};
} 


void Matrix3::CreateRotationMatrix_Z(float Degrees_Z)
{
	float Degrees_X = 0;
	float Degrees_Y = 0;
	Vector3 Rads = (ConvertDegreesToRadians(Degrees_X, Degrees_Y, Degrees_Z));

	RotateZ[3][3] = {{acos(Rads.m_Z),-(asin(Rads.m_Z)),0},
	{asin(Rads.m_Z),acos(Rads.m_Z),0 },
	{0,0,1}};
} 

void Matrix3::CreateRotationMatrix_3D(float Degrees_X, float Degrees_Y, float Degrees_Z)
{
	Vector3 Rads = (ConvertDegreesToRadians(Degrees_X, Degrees_Y, Degrees_Z));

	RotateX[3][3] = {{1,0,0},
	{0, acos(Rads.m_X),-(asin(Rads.m_X))},
	{0, asin(Rads.m_X), acos(Rads.m_X)}};
	//More readable:
	//RotateX
	//[    1    ][    0    ][    0    ]
	//[    0    ][ cos(X)  ][ -sin(X) ]
	//[    0    ][ sin(X)  ][  cos(X) ]   *Note: X = degrees converted to radians


	RotateY[3][3] = {{acos(Rads.m_Y),0,asin(Rads.m_Y)},
	{0,1,0},
	{-(asin(Rads.m_Y),0, acos(Rads.m_Y)}};
	//More readable:
	//RotateY
	//[  cos(Y) ][    0    ][  sin(Y) ]
	//[    0    ][    1    ][    0    ]
	//[ -sin(Y) ][    0    ][  cos(Y) ]   *Note: Y = degrees converted to radians

	RotateZ[3][3] = {{acos(Rads.m_Z),-(asin(Rads.m_Z)),0},
	{asin(Rads.m_Z),acos(Rads.m_Z),0 },
	{0,0,1}};
	//More readable:
	//RotateZ
	//[  cos(Z) ][ -sin(Z) ][    0    ]
	//[  sin(Z) ][  cos(Z) ][    0    ]
	//[    0    ][    0    ][    1    ]   *Note: Z = degrees converted to radians

}

void 




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

void Matrix3::ScaleMatrix(float a_ScaleX, float a_ScaleY)
{
	Scale[3][3]
	{{a_ScaleX, 0,0}
	 {0,a_ScaleY, 0}
	 {0,0,0}};

	 this -> *= Scale;
}

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