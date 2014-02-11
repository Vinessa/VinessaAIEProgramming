#include "Quad.h"


Quad::Quad(void) //Defaut Constructor contains default shaders
{
	const char* VertexShader = // Vertex Shaders deal with objects in 3d space
		"#version 400\n"
		" in vec3 position;"
		" in vec4 color;"
		//"in vec2 texcoord;" ???
		"out vec4 vColor;"
		"void main()"
		" {"
		"	vColor = color;"
		"	gl_Position = vec4 (position, 1.0);"
		" }";

	const char * FragmentShader = //FragmentShaders deal with pixel data
		"#version 330\n"
		"in vec4 vColor;"
		"out vec4 outColor;"
		"void main () {"
		"	outColor = vColor;"
		"}";
	
	//Compile Vertex Shader
	m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_VertexShader, 1, &VertexShader, NULL);
	glCompileShader(m_VertexShader);
	printShaderInfoLog(m_VertexShader);

	//Compile Fragment Shader

	m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_FragmentShader, 1, &FragmentShader, NULL);
	glCompileShader(m_FragmentShader);
	printShaderInfoLog(m_FragmentShader);

	// Link Shaders into Shader Program
	m_ShaderProgram = glCreateProgram();

	glAttachShader(m_ShaderProgram, m_FragmentShader);
	glAttachShader(m_ShaderProgram, m_VertexShader);

	glLinkProgram(m_ShaderProgram);
	printProgramInfoLog(m_ShaderProgram);
	glUseProgram(m_ShaderProgram);

	// Create Vertex Attribute object
	glGenVertexArrays(1, &m_VertexAttribute);
	glBindVertexArray(m_VertexAttribute);

	//Create Buffers
	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

	GLfloat points[] = 
{
	-0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0,
	 0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0,
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0,
	 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0
};

glBufferData (GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
//Specify layout of vertex Data
GLint posAttrib = glGetAttribLocation(m_ShaderProgram, "position");
glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 7*(sizeof(float)),0);
glEnableVertexAttribArray(posAttrib);

GLint colAttrib = glGetAttribLocation (m_ShaderProgram, "color");
glEnableVertexAttribArray(colAttrib);
glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 7*(sizeof(float)), (void*) (3* sizeof(GLfloat)));

glGenBuffers(1, &m_ElementBuffer);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBuffer);
GLuint elements[]=
{
	0,1,2,3
};

glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

}


Quad::~Quad(void)
{
}



void Quad::Draw()
{
	glUseProgram(m_ShaderProgram);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBuffer);
	glBindVertexArray(m_VertexAttribute);

	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);

}