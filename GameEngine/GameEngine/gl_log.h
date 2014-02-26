// By Vinessa

#define GL_LOG_FILE "gl.log"
#ifndef _GL_LOG_H_
#define _GL_LOG_H_
#include <time.h>
#include <fstream>
#include <iostream>
#include <GL/glew.h>


bool restart_gl_log () ;

bool gl_log (const char* message, const char* filename, int line); 
bool printShaderInfoLog(GLuint obj);

bool printProgramInfoLog(GLuint obj);


void log_gl_params ();

#endif //_GL_LOG_H_