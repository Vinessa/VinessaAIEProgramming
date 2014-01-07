//#include "libs\glfw\include\GL\glfw.h"
#include <GL/glew.h> 
#include <GL/wglew.h>
#include <GL/glfw.h>


 
//global window open Flag 
bool g_bWindowClosed = false; 
bool g_bFullscreen = false; 
char* a_pWindowTitle = "Somethingawesome";

static int GLFWCALL windowCloseListener() 
{ 
 g_bWindowClosed = true; 
 return 0; 
} 
 
int main(int argc, char* argv[] ) 
{ 
 //We need to call glfwInit() to init GLFW if this returns a value other than 
 // 0 we have been unable to create a window or OpenGL context 
 if( !glfwInit() ) 
 { 
 return -1; 
 } 
 //This is a Window hint to tell GLFW that we do not wish to allow our window to 
 //be resizeable adip Handout - Setting up an OpenGL context with GLFW.doc
//Binary Math and Boolean Logic Version 1.0
//Copyright 2013 Academy of Interactive Entertainment Page 2 of 5 Last saved by Jamie 
//Stewartjamie.stewart 
 
 glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE); 
 //This is the call to GLFW to open our window 
 glfwOpenWindow( 1024, 768, // resolution 
 8,8,8,8, // bits per colour channel (RGBA) 
 24, // depth bits 
 8, // stencil bits 
 (g_bFullscreen)? GLFW_FULLSCREEN:GLFW_WINDOW); 
 //Here we are setting the title for our window 
 glfwSetWindowTitle((a_pWindowTitle != NULL)? a_pWindowTitle : "GLFW Window"); 
 glfwSwapInterval(0); 
 //set listeners for window events such as close window 
 //windowCloseListener is a static function that will be called when the close 
 //button on the window is clicked 
 glfwSetWindowCloseCallback(&windowCloseListener); 
 
 if (glewInit() != GLEW_OK) 
{ 
 // OpenGL didn't start-up! shutdown GLFW and return an error code 
 glfwTerminate(); 
 return -1; 
} 
 
 while ( glfwGetWindowParam( GLFW_OPENED ) != 0 && !g_bWindowClosed ) 
 { 
 /* Render here */ 
 
 /* Swap front and back buffers and process events */ 
 glfwSwapBuffers(); 
 } 
 
 // shutdown GLFW 
 glfwTerminate(); 
 
 return 0; 
} 
 