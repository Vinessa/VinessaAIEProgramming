#ifndef _CLASS_H_
#define _CLASS_H_



class Vector
{
	public
	Vector();
	VectorSubtract(Vector2 &v);
	VectorAdd(Vector2 &v, float s);
	VectorMultiplyScalar(Vector2 &v, float s);

	private
	{
			float x;
			float y;
	}
};

#endif