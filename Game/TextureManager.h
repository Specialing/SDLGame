#ifndef __TextureManager__
#define __TextureManager__

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class TextureManager
{
	static TextureManager* s_pInstance;

public:
	~TextureManager(){};

	bool load(string fileName, string ID, SDL_Renderer* pRenderer);
	void draw(string ID, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip= SDL_FLIP_NONE);
	void drawFrame(string ID, int x, int y, int width, int height, int cRow, int cFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	map<string, SDL_Texture*> mTextureMap;

	static TextureManager* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	TextureManager(){}


};
typedef TextureManager TheTextureManager;
#endif