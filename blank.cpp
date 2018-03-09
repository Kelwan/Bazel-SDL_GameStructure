
/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

SDL_Window* window = NULL;

SDL_Surface* screenSurface = NULL;

SDL_Renderer* renderer = NULL;

//SDL_Surface* loadSurface(std::string path);

//SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

SDL_Window* gWindow = NULL;

SDL_Surface* gCurrentSurface = NULL;

enum KeyPressSurfaces
{
  KEY_PRESS_SURFACE_DEFAULT,
  KEY_PRESS_SURFACE_UP,
  KEY_PRESS_SURFACE_DOWN,
  KEP_PRESS_SURFACE_LEFT,
  KEY_PRESS_SURFACE_RIGHT,
  KEY_PRESS_SURFACE_TOTAL
};

bool init()
{
  bool success = true;

  //Screen dimension constants
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 480;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow( "SDL Tutorial",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN );

    screenSurface = SDL_GetWindowSurface(window);
    screenSurface = SDL_LoadBMP("test.bmp");
    if(screenSurface = NULL){
      printf("unable to load image! SDL Error: %s\n", SDL_GetError());
      SDL_Quit();
    }
    SDL_UpdateWindowSurface(window);

    return success;
}


bool drawSurface()
{
  bool success = true;
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  return success;
}




int main( int argc, char* args[] )
{

  //Create window
  init();

  //drawSurface();

  SDL_Event e;
  bool quit = false;

  while(!quit)
  {
    while(SDL_PollEvent(&e) != 0)
    {
      if(e.type == SDL_QUIT)
      {
        quit = true;
      }
    }
    SDL_UpdateWindowSurface( window );
  }
	SDL_DestroyWindow( window );
	SDL_Quit();

	return 0;
}
