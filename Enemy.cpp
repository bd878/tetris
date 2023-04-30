#include "Enemy.h"

void Enemy::update()
{
  _position.SetX(_position.GetX() + 1);
  _position.SetY(_position.GetY() + 1);
}

void Enemy::clean()
{}