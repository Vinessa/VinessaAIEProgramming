#ifndef _VERTEXSTRUCT_H_
#define _VERTEXSTRUCT_H_

#include <TerrehByteMath.h>


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



#endif //_VERTEX_H_