#include <GameEntity.h>


GameEntity::GameEntity(void)
{
}

GameEntity::GameEntity(const char* a_pTexture, int a_iWidth, int a_iHeight, tbyte::Vector4 a_v4Color,GLFWwindow* Window)
	:Sprite(a_pTexture, a_iWidth, a_iHeight, a_v4Color, Window)
	
{
	float Framespeed = 0.00004;
	
	PlaySpeedTimer.SetStartTime();
	PlaySpeedTimer = Vi_Timer(Framespeed);
	RunRight = Animations(0.0f, 0.0f, 0.0f, 0.0835f, 0.167f, 0.0f, 0.167f, 0.0835f, 0.0835, 0.5, 12);
	RunRight.CurrentFrame == 0;
}

GameEntity::~GameEntity(void)
{

}





void GameEntity::Animate(Animations &a_AnimationName)
{ 
	//a_AnimationName.CurrentFrame = 0;

	if((PlaySpeedTimer.TimeUpCheck()) == true)
		if (a_AnimationName.CurrentFrame == 0)
		{
			(a_AnimationName.CurrentFrame)++;
			m_aoVerts[0].UV = a_AnimationName.StartUV0;
			m_aoVerts[1].UV = a_AnimationName.StartUV1;
			m_aoVerts[2].UV = a_AnimationName.StartUV2;
			m_aoVerts[3].UV = a_AnimationName.StartUV3;
			PlaySpeedTimer.SetStartTime();
		}

		else
			if((a_AnimationName.CurrentFrame < a_AnimationName.m_LengthInFrames)&&(a_AnimationName.CurrentFrame > 0))
			{
				(a_AnimationName.CurrentFrame)++;
				m_aoVerts[0].U +=  a_AnimationName.m_AnimationOffsetU;
				m_aoVerts[1].U +=  a_AnimationName.m_AnimationOffsetU;
				m_aoVerts[2].U +=  a_AnimationName.m_AnimationOffsetU;
				m_aoVerts[3].U +=  a_AnimationName.m_AnimationOffsetU;
				PlaySpeedTimer.SetStartTime();


			}

			else
				if(a_AnimationName.CurrentFrame >= a_AnimationName.m_LengthInFrames)
				{
					a_AnimationName.CurrentFrame = 0;

				/*	m_aoVerts[0].UV = tbyte::Vector2(0.0f, 0.0f);
					m_aoVerts[1].UV = tbyte::Vector2(0.0f, 0.0835f);
					m_aoVerts[2].UV = tbyte::Vector2(0.167f, 0.0f);
					m_aoVerts[3].UV = tbyte::Vector2(0.167f, 0.0835f);*/
					PlaySpeedTimer.SetStartTime();
				}



}

//void Sprite::AnimateRunL()
//{	
//	AnimationFrameJump = 0;
//
//	if((PlaySpeedTimer.TimeUpCheck()) == true)
//		if (AnimationFrameRun == 0)
//		{
//			AnimationFrameRun++;
//			m_aoVerts[0].UV = tbyte::Vector2(0.167f, 0.0f);
//			m_aoVerts[1].UV = tbyte::Vector2(0.167f, 0.0835f);
//			m_aoVerts[2].UV = tbyte::Vector2(0.334f, 0.0f);
//			m_aoVerts[3].UV = tbyte::Vector2(0.334f, 0.0835f);
//			PlaySpeedTimer.SetStartTime();
//		}
//		else
//			if((AnimationFrameRun < 12)&&(AnimationFrameRun > 0))
//			{
//				AnimationFrameRun++;
//
//				m_aoVerts[0].U +=  AnimationOffsetU;
//				m_aoVerts[1].U +=  AnimationOffsetU;
//				m_aoVerts[2].U +=  AnimationOffsetU;
//				m_aoVerts[3].U +=  AnimationOffsetU;
//				PlaySpeedTimer.SetStartTime();
//
//
//			}
//
//			else
//				if(AnimationFrameRun >= 12)
//				{
//					AnimationFrameRun = 0;
//
//					m_aoVerts[0].UV = tbyte::Vector2(0.167f, 0.0f);
//					m_aoVerts[1].UV = tbyte::Vector2(0.167f, 0.0835f);
//					m_aoVerts[2].UV = tbyte::Vector2(0.334f, 0.0f);
//					m_aoVerts[3].UV = tbyte::Vector2(0.334f, 0.0835f);
//					PlaySpeedTimer.SetStartTime();
//				}
//
//
//
//}

//void Sprite::AnimateJumpRight()
//{ 
//	AnimationFrameRun = 0;
//	if((PlaySpeedTimer.TimeUpCheck()) == true)
//		if (AnimationFrameJump == 0)
//		{
//			AnimationFrameJump++;
//			m_aoVerts[0].V = 0.501f;
//			m_aoVerts[1].V = 0.501f;
//			m_aoVerts[2].V = 0.668f;
//			m_aoVerts[3].V = 0.668f;
//
//			m_aoVerts[0].U =  0.0f;
//			m_aoVerts[1].U =  AnimationOffsetU;
//			m_aoVerts[2].U =  0.0f;
//			m_aoVerts[3].U =  AnimationOffsetU;
//			PlaySpeedTimer.SetStartTime();
//
//		}
//		else
//			if((AnimationFrameJump < 12)&&(AnimationFrameJump > 0))
//			{
//				AnimationFrameJump++;
//
//				m_aoVerts[0].V = 0.501f;
//				m_aoVerts[1].V = 0.501f;
//				m_aoVerts[2].V = 0.668f;
//				m_aoVerts[3].V = 0.668f;
//
//				m_aoVerts[0].U +=  AnimationOffsetU;
//				m_aoVerts[1].U +=  AnimationOffsetU;
//				m_aoVerts[2].U +=  AnimationOffsetU;
//				m_aoVerts[3].U +=  AnimationOffsetU;
//				PlaySpeedTimer.SetStartTime();
//
//
//			}
//
//			else
//				if((AnimationFrameJump >= 12) && (AnimationFrameJump < 23))
//				{
//					AnimationFrameJump++;
//
//					m_aoVerts[0].V = 0.668f;
//					m_aoVerts[1].V = 0.668;
//					m_aoVerts[2].V = 0.835f;
//					m_aoVerts[3].V = 0.835f;
//
//					m_aoVerts[0].U -=  AnimationOffsetU;
//					m_aoVerts[1].U -=  AnimationOffsetU;
//					m_aoVerts[2].U -=  AnimationOffsetU;
//					m_aoVerts[3].U -=  AnimationOffsetU;
//					PlaySpeedTimer.SetStartTime();
//				}
//
//				else
//					if (AnimationFrameJump >= 23)
//					{
//						AnimationFrameJump = 0;
//
//						m_aoVerts[0].V = 0.501f;
//						m_aoVerts[1].V = 0.501f;
//						m_aoVerts[2].V = 0.668f;
//						m_aoVerts[3].V = 0.668f;
//
//						m_aoVerts[0].U =  0.0f;
//						m_aoVerts[1].U =  AnimationOffsetU;
//						m_aoVerts[2].U =  0.0f;
//						m_aoVerts[3].U =  AnimationOffsetU;
//						PlaySpeedTimer.SetStartTime();
//					}
//
//
//
//}

//void GameEntity::AnimateJumpLeft()
//{ 
//	AnimationFrameRun = 0;
//	if((PlaySpeedTimer.TimeUpCheck()) == true)
//		if (AnimationFrameJump == 0)
//		{
//			AnimationFrameJump++;
//			m_aoVerts[0].V = 0.835f;
//			m_aoVerts[1].V = 0.835f;
//			m_aoVerts[2].V = 0.668f;
//			m_aoVerts[3].V = 0.668f;
//
//			m_aoVerts[0].U =  0.0f;
//			m_aoVerts[1].U =  AnimationOffsetU;
//			m_aoVerts[2].U =  0.0f;
//			m_aoVerts[3].U =  AnimationOffsetU;
//			PlaySpeedTimer.SetStartTime();
//
//		}
//		else
//			if((AnimationFrameJump < 12)&&(AnimationFrameJump > 0))
//			{
//				AnimationFrameJump++;
//
//				m_aoVerts[0].V = 0.501f;
//				m_aoVerts[1].V = 0.501f;
//				m_aoVerts[2].V = 0.668f;
//				m_aoVerts[3].V = 0.668f;
//
//				m_aoVerts[0].U +=  AnimationOffsetU;
//				m_aoVerts[1].U +=  AnimationOffsetU;
//				m_aoVerts[2].U +=  AnimationOffsetU;
//				m_aoVerts[3].U +=  AnimationOffsetU;
//				PlaySpeedTimer.SetStartTime();
//
//
//			}
//
//			else
//				if((AnimationFrameJump >= 12) && (AnimationFrameJump < 23))
//				{
//					AnimationFrameJump++;
//
//					m_aoVerts[0].V = 0.668f;
//					m_aoVerts[1].V = 0.668;
//					m_aoVerts[2].V = 0.835f;
//					m_aoVerts[3].V = 0.835f;
//
//					m_aoVerts[0].U -=  AnimationOffsetU;
//					m_aoVerts[1].U -=  AnimationOffsetU;
//					m_aoVerts[2].U -=  AnimationOffsetU;
//					m_aoVerts[3].U -=  AnimationOffsetU;
//					PlaySpeedTimer.SetStartTime();
//				}
//
//				else
//					if (AnimationFrameJump >= 23)
//					{
//						AnimationFrameJump = 0;
//
//						m_aoVerts[0].V = 0.501f;
//						m_aoVerts[1].V = 0.501f;
//						m_aoVerts[2].V = 0.668f;
//						m_aoVerts[3].V = 0.668f;
//
//						m_aoVerts[0].U =  0.0f;
//						m_aoVerts[1].U =  AnimationOffsetU;
//						m_aoVerts[2].U =  0.0f;
//						m_aoVerts[3].U =  AnimationOffsetU;
//						PlaySpeedTimer.SetStartTime();
//					}
//
//
//
//}

void GameEntity::Input()
{
	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_W))
	{
		//m_v3Position += tbyte::Vector3(0.0f, 0.005f, 0.0f);
		//AnimateRunR();
	}

	if (GLFW_PRESS == glfwGetKey (GameWindow, GLFW_KEY_A))
	{
		//m_v3Position += tbyte::Vector3((-0.05f*PlaySpeedTimer.DeltaTime), 0.0f, 0.0f);
		//AnimateRunL();
	}

	if (GLFW_PRESS == glfwGetKey (GameWindow, GLFW_KEY_S))
	{
		//m_v3Position += tbyte::Vector3(0.0f, (-0.05f*PlaySpeedTimer.DeltaTime), 0.0f);
		//AnimateRunL();
	}

	if (GLFW_PRESS == glfwGetKey (GameWindow, GLFW_KEY_D))
	{
		//m_v3Position += tbyte::Vector3((0.05f * PlaySpeedTimer.GetDeltaTime()), 0.0f, 0.0f);
		Animate(RunRight);
	}

	if (GLFW_PRESS == glfwGetKey (GameWindow, GLFW_KEY_SPACE))
	{
		//m_v3Position += tbyte::Vector3((0.05f*PlaySpeedTimer.DeltaTime), 0.0f, 0.0f);
		//AnimateJumpRight();
	}
}
