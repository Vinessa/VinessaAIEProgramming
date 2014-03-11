#pragma once
#ifndef _FONT_ENGINE_H_
#define _FONT_ENGINE_H_

#include "GlobalUtilities.h"
#include <tinyxml2.h>
#include "Sprite.h"

struct Char
{
	union
	{
		struct
		{
			std::string sName;
			Vector2 v2Size;
			Vector4 v4Location;
			float yOffset;
		};
		struct
		{
			std::string Name;
			float width;
			float height;
			float x0;
			float x1;
			float y0;
			float y1;
			float Offset;

		};
	};
};

struct Font
{
	Vector2 v2Size;
	std::string sSheet;
	float fKerning;
};

class FontEngine
{
public:
	static FontEngine& Instance();
	void LoadFont(const char * a_pFontSheet);
	void DrawString(std::string str, Vector2 pos, float scale);

protected:
	static void CleanUp();

	FontEngine(void);
	~FontEngine(void);

	void LoadString(std::string str);
	Sprite iSprite;
	Font FontAtlas;
	std::map<char, Char> charMap;
	std::vector<Char> DrawList;
	int CharCount;

	static FontEngine* MInstance;

	GLuint PositionBuffer;
	GLuint ColorBuffer;
	GLuint UVBuffer;
	GLuint MatrixBuffer;



};
#endif // _FONT_MANAGER_H_


