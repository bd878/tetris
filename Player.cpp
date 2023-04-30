#include "SDL2/SDL.h"
#include "Player.h"
#include "SDLGameObject.h"

void Player::update()
{
  _currentFrame = int(((SDL_GetTicks() / 100) % 6));

  _acceleration.SetX(1);

  SDLGameObject::update();
}

void Player::clean()
{}