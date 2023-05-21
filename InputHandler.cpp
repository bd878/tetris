#include <iostream>

#include "InputHandler.h"
#include "Game.h"
#include "Vector2D.h"
#include "SDL2/SDL.h"

InputHandler* InputHandler::_instance = 0;

void InputHandler::initialiseJoysticks()
{
  if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
  {
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
  }

  if (SDL_NumJoysticks() > 0)
  {
    for (int i = 0; i < SDL_NumJoysticks(); i++)
    {
      SDL_Joystick* joy = SDL_JoystickOpen(i);

      _joysticks.push_back(joy);
      _joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));
    }

    SDL_JoystickEventState(SDL_ENABLE);
    _joysticksInitialised = true;

    std::cout << "Initialised " << _joysticks.size() << "joysticks(s)";
  }
  else
  {
    _joysticksInitialised = false;
  }
}

void InputHandler::clean()
{
  if (_joysticksInitialised)
  {
    for(unsigned int i = 0; i < SDL_NumJoysticks(); i++)
    {
      SDL_JoystickClose(_joysticks[i]);
    }
  }
}

void InputHandler::update()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      TheGame::Instance()->quit();
    }
    if (event.type == SDL_JOYAXISMOTION)
    {
      int whichOne = event.jaxis.which;
      std::cout << whichOne << std::endl;
      // TODO: move joystick according to which position
    }
  }
}

int InputHandler::xvalue(int joy, int stick)
{
  if (_joystickValues.size() > 0)
  {
    if (stick == 1)
    {
      return _joystickValues[joy].first->GetX();
    }
    else if (stick == 2)
    {
      return _joystickValues[joy].second->GetX();
    }
  }
  return 0;
}

int InputHandler::yvalue(int joy, int stick)
{
  if (_joystickValues.size() > 0)
  {
    if (stick == 1)
    {
      return _joystickValues[joy].first->GetY();
    }
    else if (stick == 2)
    {
      return _joystickValues[joy].second->GetY();
    }
  }
  return 0;
}