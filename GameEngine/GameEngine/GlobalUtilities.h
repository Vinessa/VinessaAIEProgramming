//By Vinessa

#pragma once
#ifndef _GLOBALUTILITIES_H_
#define _GLOBALUTILITIES_H_
#include <TerrehByteMath.h>
using namespace tbyte;

extern int g_gl_width;
extern int g_gl_height;
extern Matrix4 * Ortho;
void Orthographic(float a_fLeft, float a_fRight, float a_fTop, float a_fBottom, float a_fNear, float a_fFar, tbyte::Matrix4 * mat);



struct Vertex
{
	union
	{
		struct
		{	
			tbyte::Vector3 Pos;
			tbyte::Vector4 Color;
			tbyte::Vector2 UV;
		};
		struct
		{
			float X, Y, Z;
			float R, G, B, A;
			float U, V;

		};};

		bool operator == (const Vertex& rhs) {
			return (X == rhs.X && Y == rhs.Y && Z == rhs.Z
				&& R == rhs.R && G == rhs.G && B == rhs.B && A == rhs.A && U == rhs.U && V == rhs.V);
		}};

#endif //_GLOBALUTILITIES_H_