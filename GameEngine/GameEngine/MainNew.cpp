#include <gl/glew.h>
#define GLFW_DLL
#include <GL/glfw3.h>
#include <stdio.h>
#include <iostream>
//#include "gl_log.h"
#include <assert.h>
#include "Quad.h"

//Keep track of window size forthings like the viewport and the mouse cursor
int g_gl_width = 640;
int g_gl_height = 480;

//a_callback function
void glfw_window_size_callback (GLFWwindow* window, int width, int height)
{
	g_gl_width = width;
	g_gl_height = height;

	/* UPDATE ANY PERSPECTIVE MATRIX HERE*/
}


void glfw_error_callback (int error, const char* description)
{
	fputs (description, stderr);
	gl_log (description, __FILE__, __LINE__);

}

void _update_fps_counter (GLFWwindow* window)
{
	static double previous_seconds = glfwGetTime ();
	static int frame_count;
	double current_seconds = glfwGetTime();
	double elapsed_seconds = current_seconds - previous_seconds;
	double fps = (double) frame_count / elapsed_seconds;
	if (elapsed_seconds > 0.25)
	{
		previous_seconds = current_seconds;
		char tmp[128];
		sprintf (tmp, "opengl @ fps: %.21f", fps);
		glfwSetWindowTitle (window, tmp);
		frame_count = 1;
	}
	frame_count++;
}


int main()
{
	char message [256];
	sprintf (message, "starting GLFW %s", glfwGetVersionString());
	assert (gl_log (message,__FILE__, __LINE__));


	//open an OS Window using GLFW
	if(!glfwInit())
	{
		fprintf (stderr,"ERROR: Could not start GLFW3\n");
		return 1;
}
		glfwSetErrorCallback (glfw_error_callback);

	GLFWmonitor* mon = glfwGetPrimaryMonitor ();
	const GLFWvidmode* vmode = glfwGetVideoMode (mon);
	GLFWwindow* window = glfwCreateWindow (vmode ->width, vmode->height, "Extended GL Init", NULL /*mon*/,NULL
		);
	glfwSetWindowSize(window,640, 480);
	/*GLFWwindow * window = glfwCreateWindow (640,480, "Hello Triangle", NULL, NULL);*/
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

float points[] = 
{
	0.0f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
};
GLuint VBO = 0;
glGenBuffers (1, &VBO);
glBindBuffer (GL_ARRAY_BUFFER, VBO);
glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (float), points, GL_STATIC_DRAW);
GLuint VAO = 0;
glGenVertexArrays (1, &VAO);
glBindVertexArray (VAO);
glEnableVertexAttribArray (0);
glBindBuffer (GL_ARRAY_BUFFER, VBO);
glVertexAttribPointer (0,3,GL_FLOAT, GL_FALSE, 0, (GLubyte*) NULL);





//MAKING A SHADER!!!!!!!!!!

const char* vertex_shader = 
	"#version 330\n"
	"in vec3 vp;"
	"void main() {"
	" gl_Position = vec4 (vp, 1.0);"
	"}";

const char* fragment_shader = 
	"#version 330\n"
	"out vec4 frag_colour;"
	"void main () {"
	" frag_colour = vec4 (0.0, 2.0, 0.0, 1.0);"
	"}";

// Create a Shader
	GLuint vs = glCreateShader (GL_VERTEX_SHADER);
	//put the actual char* into the shader
	glShaderSource (vs, 1, &vertex_shader, NULL);
	//Compile the shader
	glCompileShader (vs);
	printShaderInfoLog(vs);
	GLint fs = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fs, 1, &fragment_shader, NULL);
	glCompileShader (fs);
	printShaderInfoLog(fs);
	//Create the conrtainer that holds your shaders
	GLuint shaderProgram = glCreateProgram();
	//attach the shaders you compiled
	glAttachShader(shaderProgram, fs);
	glAttachShader(shaderProgram, vs);
	//this is links the shaders together, it's kinds like a compile
	glLinkProgram (shaderProgram);
	printProgramInfoLog(shaderProgram);

//////////////////////////////////////////////////////////// OTHER OBJECT //////////////////////////

	float points2[] = 
{
	0.0f, 0.75f, 0.0f,
	0.75f, -0.75f, 0.0f,
	-0.75f, -0.75f, 0.0f
};

GLuint VBO2 = 0;
glGenBuffers (1, &VBO2);
glBindBuffer (GL_ARRAY_BUFFER, VBO2);
glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (float), points2, GL_STATIC_DRAW);
GLuint VAO2 = 0;
glGenVertexArrays (1, &VAO2);
glBindVertexArray (VAO2);
glEnableVertexAttribArray (0);
glBindBuffer (GL_ARRAY_BUFFER, VBO2);
glVertexAttribPointer (0,3,GL_FLOAT, GL_FALSE, 0, (GLubyte*) NULL);


const char* vertex_shader2 = 
	"#version 330\n"
	"in vec3 vp;"
	"void main() {"
	" gl_Position = vec4 (vp, 1.0);"
	"}";

const char* fragment_shader2 = 
	"#version 330\n"
	"out vec4 frag_colour;"
	"void main () {"
	" frag_colour = vec4 (0.5, 0.0, 1.0, 1.0);"
	"}";

// Create a Shader
	GLuint vs2 = glCreateShader (GL_VERTEX_SHADER);
	//put the actual char* into the shader
	glShaderSource (vs2, 1, &vertex_shader2, NULL);
	//Compile the shader
	glCompileShader (vs2);
	printShaderInfoLog(vs2);

	GLint fs2 = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fs2, 1, &fragment_shader2, NULL);
	glCompileShader (fs2);
	printShaderInfoLog(fs2);
	//Create the conrtainer that holds your shaders
	GLuint shaderProgram2 = glCreateProgram();
	//attach the shaders you compiled
	glAttachShader(shaderProgram2, fs2);
	glAttachShader(shaderProgram2, vs2);
	//this is links the shaders together, it's kinds like a compile
	glLinkProgram (shaderProgram2);
	printProgramInfoLog(shaderProgram2);

	while (!glfwWindowShouldClose (window))
	{
		_update_fps_counter (window);
			
		

		//wipe the drawing surface clear
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport (0,0, g_gl_width, g_gl_height);
		glUseProgram (shaderProgram);
		glBindVertexArray( VAO);
		glDrawArrays (GL_TRIANGLES, 0 ,3);

		glUseProgram (shaderProgram2);
		glBindVertexArray( VAO2);
		//draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawArrays (GL_TRIANGLES, 0 ,3);


		//glUseProgram (shaderProgramH);
		//glBindVertexArray( VAOH);

		//glDrawArrays (GL_TRIANGLE_FAN, 0 ,5);
		//update other events like input handling
		glfwPollEvents ();
		//put the stuff we've been drawing into the display
		glfwSwapBuffers (window);

		if (GLFW_PRESS == glfwGetKey (window, GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose (window,1);
	}
	}
// Close GL context and any other GLFW resources

glfwTerminate();
	return 0;
}
	