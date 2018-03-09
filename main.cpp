
#include "Game.h"


Game *game = nullptr;

int main(int argc, char* argv[])
{
  game = new Game();

  game->init("Kelwan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, false);
  game->loadMedia();

  while(game->running()){

    game->handleEvents();
    game->update();
    game->render();

  }

  game->clean();

  return 0;
}
