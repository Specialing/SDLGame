#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams)
{
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_width = pParams->getW();
	m_height = pParams->getH();
	textureID = pParams->getT();
	
	cRow = 1;
	cFrame = 1;
}
void SDLGameObject::draw()
{
	TheTextureManager::Instance()->drawFrame(textureID, m_x, m_y, m_width, m_height, cRow, cFrame, TheGame::Instance()->getR());
}
