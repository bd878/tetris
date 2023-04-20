#include "Game.h"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

bool Game::init(const std::string& title, int xpos, int ypos,
  int width, int height, int flags) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cerr << "SDL could not be initialized, error: %s\n" << SDL_GetError()
      << std::endl;
    return false;
  }

  std::cout << "SDL init success\n" << std::endl;
  _window = SDL_CreateWindow(title.c_str(), xpos, ypos,
    width, height, flags);

  if (_window == NULL) {
    std::cerr << "Window could not be created, %s\n" << SDL_GetError()
      << std::endl;
    return false;
  }

  std::cout << "Window created successfully" << std::endl;

  _renderer = SDL_CreateRenderer(_window, -1, 0);
  if (_renderer == NULL) {
    std::cerr << "Renderer could not be initialized, %s\n" << SDL_GetError()
      << std::endl;
    return false;
  }

  std::cout << "Renderer created successfully" << std::endl;
  SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);

  std::cout << "init success" << std::endl;
  _running = true;

  SDL_Surface* tempSurface = IMG_Load("../assets/animate-alpha.png");
  if (tempSurface == NULL) {
    std::cerr << "unable to load image assets/animate-alpha.png! SDL Error:"
      << SDL_GetError() << std::endl;
    return false;
  }

  _texture = SDL_CreateTextureFromSurface(_renderer, tempSurface);
  if (_texture == NULL) {
    std::cerr << "unable to create texture from surface"
      << SDL_GetError() << std::endl;
    return false;
  }

  _sourceRectangle.w = 128;
  _sourceRectangle.h = 82;

  _targetRectangle.x = _sourceRectangle.x = 0;
  _targetRectangle.y = _sourceRectangle.y = 0;
  _targetRectangle.w = _sourceRectangle.w;
  _targetRectangle.h = _sourceRectangle.h;

  SDL_FreeSurface(tempSurface);

  return true;
}

void Game::render() {
  SDL_RenderClear(_renderer);
  SDL_RenderCopyEx(_renderer, _texture, &_sourceRectangle,
    &_targetRectangle, 0, 0, SDL_FLIP_HORIZONTAL)
;
  SDL_RenderPresent(_renderer);
}

void Game::handleEvents() {
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        _running = false;
        break;
      default:
        break;
    }
  }
}

void Game::update() {
  _sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::clean() {
  std::cout << "cleaning game" << std::endl;

  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  _window = NULL;
  _renderer = NULL;

  SDL_Quit();
}