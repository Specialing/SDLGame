#ifndef __SDLGameObject__
#define __SDLGameObject__

#include "GameObject.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	~SDLGameObject(){}
	virtual void draw();
	virtual void update();
	virtual void clean();

	private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int cFrame;
	int cRow;
	string textureID;
};
#endif;