
Vector::Vector()
{


}

 Vector2D(void) :m_fX(0.0f), m_fY(0.0f) {} 
 Vector2D(float a_fX, float a_fY) :m_fX(a_fX), m_fY(a_fY) {} 
 ~Vector2D(void) {}; 
 
 float GetX() {return m_fX;} 
 float GetY() {return m_fY;} 
 
 void SetX(float a_fX) {m_fX = a_fX;} 
 void SetY(float a_fY) {m_fY = a_fY;} 
 
 void IncrementX(float a_fX) {m_fX += a_fX;} 
 void IncrementY(float a_fY) {m_fY += a_fY;} 
 
 private: 
 float m_fX; 
 float m_fY; 
}; 