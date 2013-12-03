#ifndef _MATRICES_H_
#define _MATRICES_H_
#include "Vector2.h"
#include "Vector3.h"
#include "math.h"

class Matrices
{
public:
	Matrices(void);
	Matrices(const int N_ColumnsSize, const int m_RowSize);
	~Matrices(void);

	void CreateIdentityMatrix(float X, float Y, float Z);
	void CreateRotationMatrix_3D(float Degrees_X, float Degrees_Y, float Degrees_Z);
	void CreateTranslationMatrix(float X, float Y);
	void CreateRotationMatrix_X(float Degrees_X);
	void CreateRotationMatrix_Y(float Degrees_Y);
	void CreateRotationMatrix_Z(float Degrees_Z);



	Vector2 GetTranslations();
	float* GetRotation_3D();
	float* GetRotation_X();
	float* GetRotation_Y();
	float* GetRotation_Z();

	float* Pointer;//For GetRotation

	void SetTranslation(float X, float Y);
	void SetRotation();

	void TransformVector();
	void TransformPoint();

	Vector3 ConvertDegreesToRadians(float Degrees_X, float Degrees_Y, float Degrees_Z);

	void CreateScaleMatrix( float a_XScaler, float a_YScaler, float a_ZScaler);



	float Array_A[][];
	float Identity[][];
	float Matrix[][];
	float Translation[][];
	float RotateX[][];
	float RotateY[][];
	float RotateZ[][];
	float RotateZ[][];
	float Scale[][]

	
};

#endif /*_MATRICES_H_*/