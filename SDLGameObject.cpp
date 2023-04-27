#include "SDLGameObject.h"
#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"

void SDLGameObject::draw()
{
  TextureManager::Instance()->drawFrame(_textureID, _x, _y, _width,
    _height, _currentRow, _currentFrame, TheGame()::Instance()->GetRenderer());
}