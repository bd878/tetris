#pragma once

#include <SDL2/SDL.h>
#include <string>

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

  bool running() { return _running; }

private:
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  SDL_Texture* _texture;
  SDL_Rect _sourceRectangle;
  SDL_Rect _targetRectangle;

  bool _running;
};