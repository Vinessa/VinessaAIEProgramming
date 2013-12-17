///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2.h
// Author:			Vinessa Mayer
// Date Created:	December 2013
// Brief:			Matrix3 Class Header, part of 3DMathsLibrary
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include "Vector2.h"
#include "Vector3.h"
#include "math.h"
#include "CommonFunctionality.h"
#include "Misc.h"

class Matrix4
{

/////////////////////////////////////////////////////////////////////////////////////////////////////
///// CONSTRUCTORS AND DESTRUCTOR //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

public:
	Matrix4(void);
	Matrix4(float a_A1, float a_B1, float a_C1, float a_D1, float a_A2, float a_B2, float a_C2, float a_D2, float a_A3, float a_B3, float a_C3, float a_D3, float a_A4, float a_B4, float a_C4, float a_D4);
	~Matrix4(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////
///// MEMBER FUNCTIONS /////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

	Matrix4 CreateIdentityMatrix();
	Vector3 ConvertDegreesToRadians(float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z); //Converts degrees to radians in the X,Y and Z
	Matrix4 CreateTransformMatrix(Vector3 XYZ, float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z, float a_XScaler, float a_YScaler, float a_ZScaler); //Creates a Transformation Matrix that will Translate, rotate and scale at once
	Matrix4 CreateRotationMatrix_X(float a_Degrees_X); // Creates and returns a matrix that will rotate in the X. converts degrees to rads for you.
	Matrix4 CreateRotationMatrix_Y(float a_Degrees_Y); // Creates and returns a matrix that will rotate in the Y. converts degrees to rads for you.
	Matrix4 CreateRotationMatrix_Z(float a_Degrees_Z); // Creates and returns a matrix that will rotate in the Z. converts degrees to rads for you.
	Matrix4 CreateRotationMatrix_3D(float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z); // Creates and returns a matrix that will rotate in the X and the Y and Z. Converts degres to rads for you.
	Matrix4 CreateScaleMatrix(float a_Scale_X, float a_Scale_Y, float a_Scale_Z); //Returns a Matrix that will scale in the X, Y and Z.
	Matrix4 CreateXYOrthoProjectionMatrix(); // Creates an Orthographic Projection Matrix for the XY plane
	Matrix4 CreateXZOrthoProjectionMatrix(); // Creates an Orthographic Projection Matrix for the XZ plane
	Matrix4 CreateYZOrthoProjectionMatrix(); // Creates an Orthographic Projection Matrix for the YZ plane
	Matrix4 CreateOrthographicProjection (Plane3 WHICHPLANE); // Switch statement that will call one of the above 3. Arguments are either XY, XZ or YZ.
    Matrix4 CreateTranslationMatrix(Vector3 XYZ); //returns a translation matrix4 that will translate in the X, Y and or Z



	Matrix4 operator * (Matrix4& OtherMatrix4); //Multiplies this matrix by another matrix4
	Matrix4 operator * (float Scaler); // //Multiplies this matrix by the second

	void TransformVector(Vector3 &Start, Vector3 &Destination, float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z, float a_XScaler, float a_YScaler, float a_ZScaler); // Transforms a Vector
	void TransformPoint(Vector3 &Start, Vector3 &Destination, Vector3 XYZ, float a_Degrees_X, float a_Degrees_Y, float a_Degrees_Z,float a_XScaler, float a_YScaler, float a_ZScaler); // Transforms a point

	float m_A1, m_B1, m_C1, m_D1;
	float m_A2, m_B2, m_C2, m_D2;
	float m_A3, m_B3, m_C3, m_D3;
	float m_A4, m_B4, m_C4, m_D4;
	
	
};
#endif /*_MATRIX4_H_*/

