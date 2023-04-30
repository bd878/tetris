#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <string>

#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
  static Game* Instance()
  {
    if (_instance == 0)
    {
      _instance = new Game();
      return _instance;
    }
    return _instance;
  }
public:
  bool init(const std::string&, int, int, int, int, int);

  void render();
  void update();
  void handleEvents();
  void clean();
  void draw();

  bool running() { return _running; }

  SDL_Renderer* GetRenderer() const { return _renderer; }

private:
  Game() {};

  static Game* _instance;

  SDL_Window* _window;
  SDL_Renderer* _renderer;

  SDL_Rect _sourceRectangle;
  SDL_Rect _targetRectangle;

  int _currentFrame;

  bool _running;

  std::vector<GameObject*> _gameObjects;
};

typedef Game TheGame;
