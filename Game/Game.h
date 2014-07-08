#ifndef __Game__
#define __Game__

class Game
{
	static Game* s_pInstance;

public:
	
	~Game(){}

	GameObject* go;
	GameObject* player;
	GameObject* enemy;

	vector<GameObject*> gameObjs;

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool run() { return mRunning; }

	static Game* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getR() const { return mRenderer; }

private:
	Game(){}
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	bool mRunning;
	
	int mcFrame;
};
typedef Game TheGame;
#endif