#define GL_LOG_FILE "gl.log"
#ifndef __GL_LOG_H_
#define __GL_LOG_H_
#include <time.h>
#include <fstream>
#include <gl/glew.h>
#include <GL/glfw3.h>

bool restart_gl_log ();


bool gl_log (const char* message, const char* filename, int line);


void printShaderInfoLog (GLuint obj);


void printProgramInfoLog (GLuint obj);


	
#endif /*_GL_LOG_H_*/