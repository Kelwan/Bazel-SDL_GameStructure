
#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

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
  void poll();
  bool running() { return isRunning; }

  void makeObject();


private:
  //Running state
  int count = 0;
  bool isRunning;

  //For main window operation
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;

  //For basic image loading
  SDL_Surface* characterBmp = NULL;
  SDL_Texture* characterTexture = NULL;

  SDL_Surface* groundBmp = NULL;
  SDL_Texture* groundTexture = NULL;

  //Positioning Character
  SDL_Rect rect;
  int x = 10;
  int y = 10;
  int w = 75;
  int h = 75;




  //Main event
  SDL_Event event;

  //Key presses
  enum KeyPressSurfaces
  {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
  };

};

#endif /* Game_h */
