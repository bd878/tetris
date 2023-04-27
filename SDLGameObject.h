#pragma once

#include "GameObject.h"

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* params) : GameObject(params) {};

  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
  int _x;
  int _y;

  int _width;
  int _height;

  int _currentRow;
  int _currentFrame;

  std::string _textureID;
};
