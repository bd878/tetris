#pragma once

#include "GameObject.h"
#include <string>
#include <iostream>

class Player : public GameObject
{
public:
  void load(int x, int y, int width, int height, std::string textureID);

  void draw(SDL_Renderer* renderer) {
    GameObject::draw(renderer);
    std::cout << "draw player";
  }

  void update() {
    std::cout << "update player";
    _x = 10;
    _y = 20;
  }
};
