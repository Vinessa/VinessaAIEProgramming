#include <gl/glew.h>
#define GLFW_DLL
#include <GL/glfw3.h>
#include <stdio.h>
#include <iostream>

int main()
{
	//open an OS Window using GLFW
	if(!glfwInit())
	{
		fprintf (stderr,"ERROR: Could not start GLFW3\n");
		return 1;
}
	GLFWwindow * window = glfwCreateWindow (640,480, "Hello Triangle", NULL, NULL);
	if (!window) 
	{
		fprintf (stderr, "Error: could not open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}

glfwMakeContextCurrent (window);
//Start GLEW extention handler
glewExperimental = GL_TRUE;
glewInit();
//get version info
const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
const GLubyte* version = glGetString (GL_VERSION); // version as string
printf ("Renderer: %s\n", renderer);
printf("OpenGL version supported %s\n", version);

//Tell Gl to only draw onto a pixel if the shape is closer to the viewer than another

glEnable (GL_DEPTH_TEST); //enable depth-teststing
glDepthFunc (GL_LESS);
//depth-testing interprests a smaller value as "closer"

/* OTHER STUFF GOES HERE*/

// Close GL context and any other GLFW resources

glfwTerminate();

char* pause = "Paused"; 

	std::cin>> pause;
	return 0;
}