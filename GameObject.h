#pragma once

#include "SDL2/SDL.h"
#include "LoaderParams.h"
#include <iostream>
#include <string>

class GameObject
{
public:
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void clean() = 0;

protected:
  virtual ~GameObject() = default;

  std::string _textureID;

  int _currentFrame;
  int _currentRow;

  int _x;
  int _y;

  int _width;
  int _height;
};
