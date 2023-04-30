#pragma once

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* params);

  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
  Vector2D _position;
  Vector2D _velocity;
  Vector2D _acceleration;

  int _width;
  int _height;

  int _currentRow;
  int _currentFrame;

  std::string _textureID;
};
