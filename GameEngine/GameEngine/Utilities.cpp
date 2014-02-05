#include "Utilities.h"



unsigned int LoadTexture(const char* a_szTexture) 
{ 
	FIBITMAP* pBitmap = nullptr;
 
	// Determime File Type from File Signature
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(a_szTexture, 0); 
 
	// Success
	if (fif != FIF_UNKNOWN && FreeImage_FIFSupportsReading(fif)) 
	{ 
		pBitmap = FreeImage_Load(fif, a_szTexture); 
	} 
 
	// Failure
	if (pBitmap == nullptr) 
	{ 
		printf("Error: Failed to load image '%s'!\n", a_szTexture); 
		return 0; 
	} 
 
	// Force the image to RGBA
 
	// Get size of pixel in bits
	unsigned int bpp = FreeImage_GetBPP(pBitmap);
	
	/*
 
	// How does this conversion to RGBA work?
	if( a_uiBPP != nullptr )
	{
		*a_uiBPP = bpp/8;
 
		//RGBA has 8 bits per color channel...
	}
 
	*/
 
	// Get Color Type
	FREE_IMAGE_COLOR_TYPE fi_colourType = FreeImage_GetColorType(pBitmap); 
 
	if (fi_colourType != FIC_RGBALPHA ) 
	{ 
		FIBITMAP* ndib = FreeImage_ConvertTo32Bits(pBitmap); 
		FreeImage_Unload(pBitmap); 
		pBitmap = ndib; 
		bpp = FreeImage_GetBPP(pBitmap); 
		fi_colourType = FreeImage_GetColorType(pBitmap); 
	} 
 
	// get the pixel data 
	BYTE* pData = FreeImage_GetBits(pBitmap); 
 
	// try to determine data type of file (bytes/floats) 
	FREE_IMAGE_TYPE fit = FreeImage_GetImageType(pBitmap);
 
	// VARIABLE	 =   (		CONDITION TO EVALUATE      ) ? IF_TRUE :	IF_FALSE	;
	GLenum eType = (fit == FIT_RGBF || fit == FIT_FLOAT) ? GL_FLOAT:GL_UNSIGNED_BYTE;
 
	// Create variable to store OGL Tex ID
	GLuint textureID;
	
	// Generate OGL Tex ID
	glGenTextures( 1, &textureID ); 
	
	// Bind Texture for Use by using the OGL Tex DI
	glBindTexture( GL_TEXTURE_2D, textureID ); 
	
	// Texturing allows elements of an image array to be read by shaders.
 
	glTexImage2D( GL_TEXTURE_2D,				// TARGET
				  0,							// level of detail
				  GL_RGBA,						// color format
				  FreeImage_GetWidth(pBitmap),	// width
				  FreeImage_GetHeight(pBitmap),	// height
				  0,							// border (must be 0)
				  fi_colourType,					// pixel data format - i.e. RGBA
				  eType,						// pixel data type
				  pData);						// data
 
	// specify default filtering and wrapping 
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE ); 
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE ); 
 
	// unbind texture 
	glBindTexture( GL_TEXTURE_2D, 0 ); 
 
	// delete data 
	FreeImage_Unload(pBitmap);
 
	return textureID; 
}
 
void UnloadTexture(GLuint TexID)
{
	glDeleteTextures(1, &TexID);
}