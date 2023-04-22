#include "Game.h"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

bool Game::init(const std::string& title, int xpos, int ypos,
  int width, int height, int flags) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cerr << "SDL could not be initialized, error: %s\n" << SDL_GetError()
      << std::endl;
    return false;
  }

  _go.load(100, 100, 128, 82, "animate");
  _player.load(300, 300, 128, 82, "animate");

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

  if (!TheTextureManager::Instance()->load("../assets/animate-alpha.png", "animate", _renderer)) {
    return false;
  }

  return true;
}

void Game::render() {
  SDL_RenderClear(_renderer);

  _go.draw(_renderer);
  _player.draw(_renderer);

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
  _go.update();
  _player.update();
}

void Game::clean() {
  std::cout << "cleaning game" << std::endl;

  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  _window = NULL;
  _renderer = NULL;

  SDL_Quit();
}