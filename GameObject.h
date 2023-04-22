#pragma once

#include "SDL2/SDL.h"
#include <iostream>
#include <string>

class GameObject {
public:
  void load(int x, int y, int width, int height, std::string textureID);

  void draw(SDL_Renderer* renderer);
  void update() ;
  void clean();

protected:
  std::string _textureID;

  int _currentFrame;
  int _currentRow;

  int _x;
  int _y;

  int _width;
  int _height;
};
