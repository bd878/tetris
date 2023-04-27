#pragma once

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include <string>
#include <iostream>

class Player : public SDLGameObject
{
public:
  PLayer(const LoaderParams* params) : SDLGameObject(params) {};

  virtual void draw()
  {
    SDLGameObject::draw();
  }

  virtual void update()
  {
    _x -= 1;
    _currentFrame = int((SDL_GetTicks() / 100) % 6);
  }

  virtual void clean()
  {}
};
