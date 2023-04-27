#include "SDL2/SDL.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject::GameObject(const LoaderParams* params)
{
  _x = params->GetX();
  _y = params->GetY();
  _width = params->GetWidth();
  _height = params->GetHeight();
  _textureID = params->GetTextureID();

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