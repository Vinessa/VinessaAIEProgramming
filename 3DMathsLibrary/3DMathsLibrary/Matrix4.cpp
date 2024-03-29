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


Matrix4 Matrix4::CreateIdentityMatrix() // Returns an identity matrix4
{
	Matrix4 Identity;
	Identity.m_A1=1; Identity.m_B1=0; Identity.m_C1=0; Identity.m_D1=0;
	Identity.m_A2=0; Identity.m_B2=1; Identity.m_C2=0; Identity.m_D2=0;
	Identity.m_A3=0; Identity.m_B3=0; Identity.m_C3=1; Identity.m_D3=0;
	Identity.m_A4=0; Identity.m_B4=0; Identity.m_C4=0; Identity.m_D4=0;
	return Identity;
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
	RotY.m_A3=-(asin(Rads.m_Y)); RotY.m_B3= 0; RotY.m_C3=acos(Rads.m_Y);
	
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

Matrix4 Matrix4::CreateXYOrthoProjectionMatrix()
{
	Matrix4 XYOrthoProj(1,0,0,0,
					    0,1,0,0,
					    0,0,0,0,
					    0,0,0,1);

	return XYOrthoProj;

}

Matrix4 Matrix4:: CreateXZOrthoProjectionMatrix()
{
	  Matrix4 XZOrthoProj(1,0,0,0,
						  0,0,0,0,
						  0,0,1,0,
						  0,0,0,1);

	  return XZOrthoProj;
}

Matrix4 Matrix4:: CreateYZOrthoProjectionMatrix()
{
	 Matrix4 YZOrthoProj(0,0,0,0, 
			                 0,1,0,0,
							 0,0,1,0,
							 0,0,0,1);

	return YZOrthoProj;

}


Matrix4 Matrix4::CreateOrthographicProjection (Plane3 WHICHPLANE)
{
	switch(WHICHPLANE)
	{
	case XY: //Projetcts to the X and Y but removes the Z (Front/Back)
		  
		 return (CreateXYOrthoProjectionMatrix());
		break;

	case XZ: //Projects to the X and Z but removes the Y (TopDown / BottomUp)

		 return (CreateXZOrthoProjectionMatrix());
		break;

	case YZ://Projects to the Y and the Z but removes the X (Left/Right SideView)
		 
		   return (CreateYZOrthoProjectionMatrix());
		break;

	};
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
}

Matrix4 Matrix4::operator * (float Scaler)
{
	//  A   B    C  D
	//1[A1][B1][C1][D1]
	//2[A2][B2][C2][D2]
	//3[A3][B3][C3][D3]
	//4[A4][B4][C4][D4]


Matrix4 Result;

Result.m_A1 = (m_A1 * Scaler)+(m_A2 * Scaler)+(m_A3 * Scaler)+(m_A4 * Scaler);
Result.m_A2 = (m_A1 * Scaler)+(m_A2 * Scaler)+(m_A3 * Scaler)+(m_A4 * Scaler);
Result.m_A3 = (m_A1 * Scaler)+(m_A2 * Scaler)+(m_A3 * Scaler)+(m_A4 * Scaler);
Result.m_A4 = (m_A1 * Scaler)+(m_A2 * Scaler)+(m_A3 * Scaler)+(m_C4 * Scaler);

Result.m_B1 = (m_B1 * Scaler)+(m_B2 * Scaler)+(m_B3 * Scaler)+(m_B4 * Scaler);
Result.m_B2 = (m_B1 * Scaler)+(m_B2 * Scaler)+(m_B3 * Scaler)+(m_B4 * Scaler);
Result.m_B3 = (m_B1 * Scaler)+(m_B2 * Scaler)+(m_B3 * Scaler)+(m_B4 * Scaler);
Result.m_B4 = (m_B1 * Scaler)+(m_B2 * Scaler)+(m_B3 * Scaler)+(m_B4 * Scaler);

Result.m_C1 = (m_C1 * Scaler)+(m_C2 * Scaler)+(m_C3 * Scaler)+(m_C4 * Scaler);
Result.m_C2 = (m_C1 * Scaler)+(m_C2 * Scaler)+(m_C3 * Scaler)+(m_C4 * Scaler);
Result.m_C3 = (m_C1 * Scaler)+(m_C2 * Scaler)+(m_C3 * Scaler)+(m_C4 * Scaler);
Result.m_C4 = (m_C1 * Scaler)+(m_C2 * Scaler)+(m_C3 * Scaler)+(m_C4 * Scaler);

Result.m_D1 = (m_D1 * Scaler)+(m_D2 * Scaler)+(m_D3 * Scaler)+(m_D4 * Scaler);
Result.m_D3 = (m_D1 * Scaler)+(m_D2 * Scaler)+(m_D3 * Scaler)+(m_D4 * Scaler);
Result.m_D2 = (m_D1 * Scaler)+(m_D2 * Scaler)+(m_D3 * Scaler)+(m_D4 * Scaler);
Result.m_D4 = (m_D1 * Scaler)+(m_D2 * Scaler)+(m_D3 * Scaler)+(m_D4 * Scaler);


return Result;
}


Matrix4 Matrix4::CreateTranslationMatrix(Vector3 XYZ) //returns a translation matrix4 that will translate in the X, Y and or Z
{
	Matrix4 Translation = CreateIdentityMatrix();
	Translation.m_C1 = (XYZ.GetX());
	Translation.m_C2 = (XYZ.GetY());
	
	return Translation;

}


Matrix4 Matrix4::CreateTransformMatrix(Vector3 XYZ, float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z, float a_XScaler, float a_YScaler, float a_ZScaler) //Creates a Transformation Matrix that will Translate, rotate and scale at once
{
	Matrix4 TransformMatrix;
	Matrix4 T = (CreateTranslationMatrix(XYZ));
	Matrix4 R = (CreateRotationMatrix_3D(a_Degrees_X, a_Degrees_Y, a_Degrees_Z));
	Matrix4 S = (CreateScaleMatrix(a_XScaler,a_YScaler, a_ZScaler));

	TransformMatrix = T*R*S;

	return TransformMatrix;
}

void Matrix4::TransformVector(Vector3 &Start, Vector3 &Destination, float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z, float a_XScaler, float a_YScaler, float a_ZScaler) // Transforms a Vector
{
	Vector3 TempVec(1,1,1);
	Matrix4 Temp = ((CreateTransformMatrix(TempVec, a_Degrees_X, a_Degrees_Y, a_Degrees_Z, a_XScaler, a_YScaler, a_ZScaler)));
	Destination.SetX((((Start.GetX())* Temp.m_A1)) + (((Start.GetY())* Temp.m_B1)) + (((Start.GetZ()) * Temp.m_C1)));
	Destination.SetY((((Start.GetX())* Temp.m_A2)) + (((Start.GetY())* Temp.m_B2)) + (((Start.GetZ()) * Temp.m_C2)));
	Destination.SetZ((((Start.GetZ())* Temp.m_A3)) + (((Start.GetY())* Temp.m_B3)) + (((Start.GetY()) * Temp.m_C3)));

	
}

void Matrix4::TransformPoint(Vector3 &Start, Vector3 &Destination, Vector3 XYZ, float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z,float a_XScaler, float a_YScaler, float a_ZScaler) // Transforms a point
{
	Matrix4 Temp = (CreateTransformMatrix(XYZ, a_Degrees_X, a_Degrees_Y, a_Degrees_Z, a_XScaler, a_YScaler, a_ZScaler));
	Destination.SetX((((Start.GetX())* Temp.m_A1)) + (((Start.GetY())* Temp.m_B1)) + (((Start.GetZ()) * Temp.m_C1)));
	Destination.SetY((((Start.GetX())* Temp.m_A2)) + (((Start.GetY())* Temp.m_B2)) + (((Start.GetZ()) * Temp.m_C2)));
	Destination.SetZ((((Start.GetZ())* Temp.m_A3)) + (((Start.GetY())* Temp.m_B3)) + (((Start.GetY()) * Temp.m_C3)));
	float W = (((Start.GetZ())* Temp.m_A3)) + (((Start.GetY())* Temp.m_B3)) + (((Start.GetY()) * Temp.m_C3));
		if(W != 1 && W !=0)
		{
			Destination.SetX((Destination.GetX())/W);
			Destination.SetY((Destination.GetY())/W);
		}
}
