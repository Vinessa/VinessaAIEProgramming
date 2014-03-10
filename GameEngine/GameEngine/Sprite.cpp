//by Vinessa

#include "Sprite.h"

Sprite::Sprite(void)
{
	srand(time(NULL));
	LoadVertShader("./Resources/LoadVertexShader.glsl");
	LoadFragShader("./Resources/LoadFragmentShader.glsl");
	LinkShaders();

	m_v4SpriteColor = Vector4(1,1,1,1);
	

	m_aoVerts[0].Color = m_v4SpriteColor;
	m_aoVerts[1].Color = m_v4SpriteColor;
	m_aoVerts[2].Color = m_v4SpriteColor;
	m_aoVerts[3].Color = m_v4SpriteColor;

	m_aoVerts[0].UV = Vector2(1.0f,  0.0f);
	m_aoVerts[1].UV = Vector2(0.0f,  1.0f);
	m_aoVerts[2].UV = Vector2(1.0f,  0.0f);
	m_aoVerts[3].UV = Vector2(1.0f,  1.0f);

	
	m_v2Scale = Vector2(1,1);


	m_v3Position = Vector3(g_gl_width/2,g_gl_height/2,0);

}


Sprite::~Sprite(void)
{

}
Sprite::Sprite( const char* a_pTexture, int a_iWidth, int a_iHeight, Vector4 a_v4Color ,GLFWwindow * window)
{

	GameWindow = window;
	
	LoadVertShader("./Resources/LoadVertexShader.glsl");
	LoadFragShader("./Resources/LoadFragmentShader.glsl");
	LinkShaders();
	GLint uvAttrib = glGetAttribLocation(m_ShaderProgram,"texcoord");
	glEnableVertexAttribArray(uvAttrib);
	matrix_location = glGetUniformLocation (m_ShaderProgram, "matrix");
	LoadTexture(a_pTexture);


	m_v4SpriteColor = a_v4Color;

	
	m_aoVerts[0].Color = m_v4SpriteColor;
	m_aoVerts[1].Color = m_v4SpriteColor;
	m_aoVerts[2].Color = m_v4SpriteColor;
	m_aoVerts[3].Color = m_v4SpriteColor;
	
	m_v2Scale = Vector2(a_iWidth,a_iHeight);

	m_v3Position = Vector3(g_gl_width/2,g_gl_height/2,0);

	
}

void Sprite::Draw()
{
	
	

	modelMatrix->m_afArray[0]  = m_v2Scale.m_fX * m_fZoom;
	modelMatrix->m_afArray[5]  = m_v2Scale.m_fY * m_fZoom;
	modelMatrix->m_afArray[12] = m_v3Position.m_fX;
	modelMatrix->m_afArray[13] = m_v3Position.m_fY;
	modelMatrix->m_afArray[14] = m_v3Position.m_fZ;


	*MVP =  (*Ortho * *modelMatrix) ;

	

	
	Quad::Draw();
}


void Sprite::SetPosition(Vector3 a_v3Pos)
{
	Vector3 m_v3Position = a_v3Pos;

}



