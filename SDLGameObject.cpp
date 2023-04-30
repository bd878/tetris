#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* params) :
  _position(params->GetX(), params->GetY()), _velocity(0, 0)
{
  _width = params->GetWidth();
  _height = params->GetHeight();
  _textureID = params->GetTextureID();

  _currentRow = 1;
  _currentFrame = 1;
}

void SDLGameObject::draw()
{
  TextureManager::Instance()->drawFrame(_textureID,
    (int)_position.GetX(), (int)_position.GetY(), _width, _height,
    _currentRow, _currentFrame, TheGame::Instance()->GetRenderer());
}

void SDLGameObject::update()
{
  _velocity += _acceleration;
  _position += _velocity;
}

void SDLGameObject::clean()
{
}