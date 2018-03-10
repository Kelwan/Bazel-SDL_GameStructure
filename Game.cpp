
#include "Game.h"

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
      int flags = 0;
      if(fullscreen)
      {
        flags = SDL_WINDOW_FULLSCREEN;
      }

      std::cout << "Subsystems Initialized" << std::endl;

      window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
      if(window)
      {
        std::cout << "Window created!" << std::endl;
      }

      renderer = SDL_CreateRenderer(window, -1, 0);
      if(renderer)
      {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        std::cout << "Renderer created!" << std::endl;
      }

      isRunning = true ;
  }
  else
  {
    isRunning = false;
  }
}

void Game::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch(event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;

    case SDL_KEYDOWN:
      rect.x += event.motion.xrel;
      std::cout << "KEYDOWN pressed" << std::endl;
      break;

    default:
      break;
  }
}

void Game::update()
{
  //count++;
  //std::cout << count << std::endl;
}

void Game::render()
{
  //Add stuff to renderer
  SDL_RenderPresent(renderer);
  SDL_RenderClear(renderer);

}

void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}

void Game::loadMedia()
{
  testBmp = SDL_LoadBMP("test.bmp");
  if(testBmp)
  {
    std::cout << "Image has been loaded!" << std::endl;
  }
  bmpTexture = SDL_CreateTextureFromSurface(renderer, testBmp);
}

void Game::buildSquare()
{
  rect.x = 10;
  rect.y = 10;
  rect.w = 50;
  rect.h = 50;

  //SDL_RenderDrawRect(renderer, &rect);
  //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

  SDL_RenderCopy(renderer, bmpTexture, NULL, &rect);

}
