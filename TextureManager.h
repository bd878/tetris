#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class TextureManager {
public:
  static TextureManager* _instance;

  static TextureManager* Instance() {
    if (_instance == nullptr) {
      _instance = new TextureManager();
    }

    return _instance;
  }

private:
  TextureManager() {}

public:
  bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
  void draw(std::string id, int x, int y, int width, int height,
    SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  void drawFrame(std::string id, int x, int y, int width, int height,
    int currentRow, int currentFrame, SDL_Renderer* pRenderer,
    SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
  std::map<std::string, SDL_Texture*> _textureMap;
};

typedef TextureManager TheTextureManager;
