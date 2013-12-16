///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector2.h
// Author:			Vinessa Mayer
// Date Created:	December 2013
// Brief:			Matrix3 Class Header, part of 3DMathsLibrary
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _MATRIX3_H_
#define _MATRIX3_H_
#include "Vector2.h"
#include "Vector3.h"
#include "math.h"

class Matrix3
{
	
/////////////////////////////////////////////////////////////////////////////////////////////////////
///// CONSTRUCTORS AND DESTRUCTOR //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

public:
	Matrix3(void);
	Matrix3(float a_A_1, float a_B_1, float a_C_1, float a_A_2, float a_B_2, float a_C_2, float a_A_3, float a_B_3, float a_C_3);
	~Matrix3(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////
///// MEMBER FUNCTIONS /////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

	Matrix3 CreateIdentityMatrix(); // Returns an identity matrix3
	Matrix3 CreateTranslationMatrix(Vector3 XYZ);//returns a translation matrix3 that will translate in the X and the Y
	Matrix3 CreateRotationMatrix_X(float a_Degrees_X); // Creates and returns a matrix that will rotate in the x. converts degres to rads for you.
	Matrix3 CreateRotationMatrix_Y(float a_Degrees_Y); // Creates and returns a matrix that will rotate in the Y. converts degres to rads for you.
	/*Matrix3 CreateRotationMatrix_Z(float a_Degrees_Z); */
	Matrix3 CreateRotationMatrix_2D(float a_Degrees_X, float a_Degrees_Y); // Creates and returns a matrix that will rotate in both the X and the Y. Converts degres to rads for you.
	Matrix3 CreateScaleMatrix( float a_XScaler, float a_YScaler); //Returns a Matrix that will scale in the X and Y
	Matrix3 CreateTransformMatrix(Vector3 XYZ, float a_Degrees_X, float a_Degrees_Y,float a_XScaler, float a_YScaler); //Creates a Transformation Matrix that will Translate, rotate and scale at once

	Matrix3 operator * (Matrix3& OtherMatrix3); // Multiplies this Matrix3 by another Matrix3
	Matrix3 operator * (float Scaler); // Multiplies this Matrix3 by a Scaler



	//Vector2 GetTranslations();
	//float* GetRotation_3D();
	//float* GetRotation_X();
	//float* GetRotation_Y();
	//float* GetRotation_Z();

	//float* Pointer;//For GetRotation

	//void SetTranslation(float X, float Y);
	//void SetRotation();

	

	void TransformVector(Vector3 &Start, Vector3 &Destination, float a_Degrees_X, float a_Degrees_Y,float a_XScaler, float a_YScaler); // Transforms a Vector
	void TransformPoint(Vector3 &Start, Vector3 &Destination, Vector3 XYZ, float a_Degrees_X, float a_Degrees_Y,float a_XScaler, float a_YScaler); // Transforms a point

	Vector2 ConvertDegreesToRadians(float Degrees_X, float Degrees_Y); // Converts degrees to radians and returns them as a Vector2

	

	//variables

	float m_A1, m_B1, m_C1;
	float m_A2, m_B2, m_C2;
	float m_A3, m_B3, m_C3;
	
	
};

#endif /*_Matrix3_H_*/