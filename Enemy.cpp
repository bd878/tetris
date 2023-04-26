#include "Enemy.h"

#include "SDL2/SDL.h"

void Enemy::update()
{
  _y += 1;
  _x += 1;
  _currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
