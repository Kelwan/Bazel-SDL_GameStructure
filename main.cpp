
#include "Game.h"




int main(int argc, char* argv[])
{
  Game game;

  game.init("Kelwan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 640, false);
  //game.loadMedia();


  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;

  while(game.running()){

    frameStart = SDL_GetTicks();

    game.handleEvents();
    game.update();
    game.render();
    //game.buildSquare();

    frameTime = SDL_GetTicks() - frameStart;

    if(frameDelay > frameTime)
    {
      SDL_Delay(frameDelay - frameTime);
    }

  }

  return 0;
}
