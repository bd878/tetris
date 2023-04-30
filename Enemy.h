#pragma once

#include "LoaderParams.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* params) : SDLGameObject(params) {}

  virtual void draw() {};
  virtual void update();
  virtual void clean();
};
