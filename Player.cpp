#include "SDL2/SDL.h"
#include "InputHandler.h"
#include "Player.h"
#include "SDLGameObject.h"

void Player::update()
{
  _velocity.SetX(0);
  _velocity.SetY(0);

  handleInput();

  _currentFrame = int(((SDL_GetTicks() / 100) % 6));

  SDLGameObject::update();
}

void Player::clean()
{}

void Player::handleInput()
{
  if (TheInputHandler::Instance()->joysticksInitialised())
  {
    if (TheInputHandler::Instance()->xvalue(0, 1) > 0 ||
      TheInputHandler::Instance()->xvalue(0, 1) < 0)
    {
      _velocity.SetX(1 * TheInputHandler::Instance()->xvalue(0, 1));
    }

    if (TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
      TheInputHandler::Instance()->yvalue(0, 1) < 0)
    {
      _velocity.SetY(1 * TheInputHandler::Instance()->yvalue(0, 1));
    }

    /* ...etc */
  }
}