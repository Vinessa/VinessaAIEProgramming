#ifndef _CLASS_H_
#define _CLASS_H_

class Vector2D
{
public:
	Vector2D(void);
	~Vector2D(void);	
	
	void Subtract(Vector2D &v);
	void Add(Vector2D &v);
	float Dot(Vector2D &v, Vector2D &v2);



	float x,y;
};

#endif