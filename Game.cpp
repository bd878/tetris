#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "Game.h"
#include "LoaderParams.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

Game* Game::_instance = 0;

bool Game::init(const std::string& title, int xpos, int ypos,
  int width, int height, int flags) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cerr << "SDL could not be initialized, error: %s\n" << SDL_GetError()
      << std::endl;
    return false;
  }

  _gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
  _gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

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

  for (std::vector<GameObject*>::size_type i = 0; i != _gameObjects.size(); i++) {
    _gameObjects[i]->draw();
  }

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
  for (std::vector<GameObject*>::size_type i = 0; i != _gameObjects.size(); i++) {
    _gameObjects[i]->update();
  }
}

void Game::clean() {
  std::cout << "cleaning game" << std::endl;

  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  _window = NULL;
  _renderer = NULL;

  SDL_Quit();
}

void Game::draw() {
  for (std::vector<GameObject*>::size_type i = 0; i != _gameObjects.size(); i++) {
    _gameObjects[i]->draw();
  }
}