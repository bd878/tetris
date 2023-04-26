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
  Game() {}
  ~Game() {}

  bool init(const std::string&, int, int, int, int, int);

  void render();
  void update();
  void handleEvents();
  void clean();
  void draw();

  bool running() { return _running; }

private:
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  SDL_Rect _sourceRectangle;
  SDL_Rect _targetRectangle;

  int _currentFrame;

  bool _running;

  GameObject* _go;
  GameObject* _player;
  GameObject* _enemy;

  std::vector<GameObject*> _gameObjects;
};