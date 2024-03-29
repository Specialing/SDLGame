#ifndef __LoaderParams__
#define __LoaderParams__

#include "TextureManager.h"

class LoaderParams
{
public:	
	LoaderParams(int x, int y, int width, int height, string textureID) : m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID){}
	~LoaderParams(){}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getW() const { return m_width; }
	int getH() const { return m_height; }
	string getT() const { return m_textureID; }
	
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	string m_textureID;
	
};
#endif