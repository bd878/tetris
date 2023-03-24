#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void close();

int main(int argc, char* args[]) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("SDL could not be initialized, error: %s\n", SDL_GetError());
    return 1;
  }

  gWindow = SDL_CreateWindow("SDL tutorial",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (gWindow == NULL) {
    printf("Window could not be created, %s\n", SDL_GetError());
    return 1;
  }

  gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
  if (gRenderer == NULL) {
    printf("Renderer could not be initialized, %s\n", SDL_GetError());
    return 1;
  }

  SDL_Event e;

  bool quit = false;

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      } else {
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
        SDL_RenderClear(gRenderer);
        SDL_RenderPresent(gRenderer);
      }
    }
  }

  close();

  return 0;
}

void close() {
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  gRenderer = NULL;

  SDL_Quit();
}