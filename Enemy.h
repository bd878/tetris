#pragma once

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  virtual void draw();
  virtual void update();
  virtual void clean();
};
