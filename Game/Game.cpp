#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		mWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(mWindow != 0)
		{
			mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
			if(mRenderer != 0)
			{
				SDL_SetRenderDrawColor(mRenderer, 0, 255, 0, 255);
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	} 

	TheTextureManager::Instance()->load("assets/PlayerDestroyed.png", "Player", mRenderer);

	go = new GameObject();
	player = new Player();
	enemy = new Enemy();

	go->load(100, 100, 32, 30, "Player");
	player->load(240, 240, 32, 30, "Player");
	enemy->load(0, 0, 32, 30, "Player");

	gameObjs.push_back(go);
	gameObjs.push_back(player);
	gameObjs.push_back(enemy);


	mRunning = true;
	return true;
}
void Game::update()
{
	for(vector<GameObject*>::size_type i = 0; i != gameObjs.size(); i++)
		gameObjs[i]->update();
}
void Game::render()
{
	SDL_RenderClear(mRenderer);

	for(vector<GameObject*>::size_type i = 0; i != gameObjs.size(); i++)
		gameObjs[i]->draw(mRenderer);

	SDL_RenderPresent(mRenderer);
}
void Game::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			mRunning = false;
			break;
		default:
			break;
		}
	}
}
void Game::clean()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	SDL_Quit();
}