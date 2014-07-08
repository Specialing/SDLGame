#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(string fileName, string ID, SDL_Renderer* pRenderer)
{
	SDL_Surface* tSurface = IMG_Load(fileName.c_str());

	if(tSurface == 0)
		return false;

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, tSurface);
	SDL_FreeSurface(tSurface);

	if(pTexture != 0)
	{
		mTextureMap[ID] = pTexture;
		return true;
	}

	return false;
}
void TextureManager::draw(string ID, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect sRect;
	SDL_Rect dRect;

	sRect.x = 0;
	sRect.y = 0;
	sRect.w = dRect.w = width;
	sRect.h = dRect.h = height;

	dRect.x = x;
	dRect.y = y;

	SDL_RenderCopyEx(pRenderer, mTextureMap[ID], &sRect, &dRect, 0, 0, flip);
}
void TextureManager::drawFrame(string ID, int x, int y, int width, int height, int cRow, int cFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect sRect;
	SDL_Rect dRect;

	sRect.x = width * cFrame;
	sRect.y = height * (cRow - 1);
	sRect.w = dRect.w = width;
	sRect.h = dRect.h = height;

	dRect.x = x;
	dRect.y = y;

	SDL_RenderCopyEx(pRenderer, mTextureMap[ID], &sRect, &dRect, 0, 0, flip);
}