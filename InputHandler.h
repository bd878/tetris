#pragma once

#include <vector>
#include "SDL2/SDL.h"
#include "Vector2D.h"

class InputHandler
{
public:
  static InputHandler* Instance()
  {
    if (_instance == 0)
    {
      _instance = new InputHandler();
    }
    return _instance;
  }

public:
  void update();
  void clean();

  void initialiseJoysticks();
  bool joysticksInitialised() {
    return _joysticksInitialised;
  }

  int xvalue(int joy, int stick);
  int yvalue(int joy, int stick);

private:
  InputHandler() {};
  ~InputHandler() {}

  static InputHandler* _instance;

  std::vector<std::pair<Vector2D*, Vector2D*>> _joystickValues;

  std::vector<SDL_Joystick*> _joysticks;
  bool _joysticksInitialised;
};

typedef InputHandler TheInputHandler;
