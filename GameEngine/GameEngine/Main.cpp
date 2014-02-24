#include <GL/glew.h>
#define GLFW_DLL
#include <GL/glfw3.h>
#include <stdio.h>
//#include "Quad.h"
//#include "Sprite.h"
#include "GameEntity.h"
#include "Vi_Timer.h"
#include <stdio.h>

int main()
{
	
	//Open an OS window using GLFW
	if(!glfwInit())
	{
		fprintf (stderr, "Error: Could not start GLFW\n");
			return 1;
	}

	GLFWwindow * window = glfwCreateWindow( g_gl_width, g_gl_height,"Hello Triangle", NULL, NULL);
	if (!window)
	{
		fprintf (stderr, "Error: could not open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);
	//Start the GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();
	// get version info
	const GLubyte* renderer = glGetString (GL_RENDERER); //Get the Renderer string
	const GLubyte* version = glGetString (GL_VERSION); //version as a string
	printf ("Renderer: %s\n", renderer);
	printf ("OpenGL verion supported %s\n", version);

	//tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable (GL_DEPTH_TEST); //Enables depth testing
	glDepthFunc (GL_LESS); // Tells the Depth tester to interpret a smaller value as "closer" prolly in the Zaxis"

	
	tbyte::Vector4 color(1,1,1,1);
	//Quad *tester = new Quad();
	//Sprite *testsprite = new Sprite("./Resources/OmnikittenLogo3.png", 240, 272, color, window); 
	GameEntity *Gypsy = new GameEntity("./Resources/RunJumpGapL_R.png",100 ,75, color, window);
	Ortho = new tbyte::Matrix4();
	Orthographic(0,g_gl_width, g_gl_height, 0,0, 1, Ortho);
//checking timers for debug
	/*Vi_Timer timecheck;

	timecheck.StartTimer();
	timecheck.UpdateTimer();
	printf ("Start Time: %.f", timecheck.f_StartTime);
	printf ("Current Time: %.f", timecheck.CurrentTime);
	printf ("Time Passed: %.f", timecheck.TimePassed);*/
	//end timercheck

///////////////////////////RENDER LOOP BEGIN/////////////////////////////////////

	 while (!glfwWindowShouldClose (window)) {

  // wipe the drawing surface clear
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //glClearColor(.5,0,1,1); //debug purple
  glClearColor(0,0,0,0);

  //tester ->Draw();
  Gypsy -> Input();
  Gypsy ->Draw();
  
  //testsprite->Draw();
  // update other events like input handling 
  glfwPollEvents ();
  // put the stuff we've been drawing onto the display
  glfwSwapBuffers (window);
  
}

	 
/////////////////////////////RENDER LOOP END//////////////////////////////////////



	//close GL context and any other GLFW resources
	glfwTerminate();
	return 0;
}