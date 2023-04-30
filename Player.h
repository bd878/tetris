#pragma once

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include <string>
#include <iostream>

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* params) : SDLGameObject(params) {};

  virtual void draw()
  {
    SDLGameObject::draw();
  }

  virtual void update();

  virtual void clean();
};
