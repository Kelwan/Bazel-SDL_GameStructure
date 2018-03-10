
#include "Game.h"
#include <typeinfo>
#include <entity.h>

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
      switch(event.key.keysym.sym)
      {
        case SDLK_UP:
          std::cout << "up has been pressed" << std::endl;
          y-=3;
          break;

        case SDLK_DOWN:
          std::cout << "Down key pressed" << std::endl;
          y+=3;
          break;

        case SDLK_LEFT:
          std::cout << "Left key pressed" << std::endl;
          x-=3;
          break;

        case SDLK_RIGHT:
          std::cout << "Right key pressed" << std::endl;
          x+=3;
          break;
      }
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
  //std::cout << typeid("idle.bmp").name() << std::endl;


}

void Game::buildSquare()
{
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  SDL_RenderDrawRect(renderer, &rect);
  //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

  SDL_RenderCopy(renderer, characterTexture, NULL, &rect);

}
