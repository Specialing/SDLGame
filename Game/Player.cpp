#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw();
}
void Player::update()
{
	m_x -= 1;
	cFrame = int(((SDL_GetTicks() / 100) % 6);
}
void Player::clean(){}