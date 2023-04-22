#include "SDL2/SDL.h"
#include "TextureManager.h"
#include "GameObject.h"

void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
  _x = x;
  _y = y;
  _width = width;
  _height = height;
  _textureID = textureID;

  _currentRow = 1;
  _currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* renderer)
{
  TextureManager::Instance()->drawFrame(_textureID, _x, _y,
    _width, _height, _currentRow, _currentFrame, renderer);
}

void GameObject::update()
{
  _x += 1;
}