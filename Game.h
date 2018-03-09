
#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <iostream>


class Game {
public:
  Game();
  ~Game();

  void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();
  void loadMedia();
  void buildSquare();
  bool running() { return isRunning; }

private:
  int count = 0;
  bool isRunning;

  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;

  SDL_Surface* testBmp = NULL;
  SDL_Texture* bmpTexture = NULL;
  SDL_Rect rect;
};

#endif /* Game_h */
