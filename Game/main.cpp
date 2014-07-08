#include "Game.h"

int main(int argc, char* argv[])
{
	if(TheGame::Instance()->init("Gremla", 100, 100, 640, 480, false))
	{
		while(TheGame::Instance()->run())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			
			SDL_Delay(10);
		}
	} else {
		return -1;
	}
	TheGame::Instance()->clean();
	return 0;
}