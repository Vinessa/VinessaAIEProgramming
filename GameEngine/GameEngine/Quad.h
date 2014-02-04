#pragma once
#ifndef _QUAD_H_
#define _QUAD_H_

#include <gl\glew.h>
#include "gl_log.h" //for logging stuff such as errors
#include "TextFileReader.h"
//#include <GL/glfw3.h>


class Quad
{
public:
	Quad(void);
	~Quad(void);

	//buffers
	GLuint m_VertexBuffer;
	GLuint m_ElementBuffer;

	//information to go into buffer
	GLuint m_VertexAttribute;

	//Shaders to attach buffer to
	GLuint m_FragmentShader;
	GLint m_VertexShader;

	//Program to run shaders
	GLuint m_ShaderProgram;

	//Function to draw
	void Draw();
};
#endif //_QUAD_H_
