#ifndef _UTILITIES_H_
#define _UTILITIES_H_
 
//#include <glfw\glfw.h>

#include <GL\glew.h>

#include <GL\glfw3.h>

#include <iostream>

unsigned int LoadTexture(const char* a_szTexture);

void UnloadTexture(GLuint TexID);

extern Matrix4 * Ortho;

void Orthographic(float a_fLeft, float a_fRight, float a_fTop, float a_fBottom, float a_fNear, float a_fFar, tbyte::Matrix4 * mat);

 
#endif