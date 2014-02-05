#ifndef _UTILITIES_H_
#define _UTILITIES_H_
 
//#include <glfw\glfw.h>

#include <GL\glew.h>

#include <GL\glfw3.h>

#include <iostream>

unsigned int LoadTexture(const char* a_szTexture);

void UnloadTexture(GLuint TexID);

 
#endif