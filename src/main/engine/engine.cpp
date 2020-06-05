#include "engine.h"
#include "SDL_timer.h"
#include <iostream>
#include <future>

void Engine::initialize()
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    std::cout << "SDL_Init failed" << std::endl;
  }

  int window_width = 1000;
  int window_height = 500;
  SDL_Window *win = SDL_CreateWindow("Tetris",
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     window_width, window_height,
                                     SDL_WINDOW_SHOWN);
  if (win == nullptr)
  {
    std::cout << "Create Window failed" << std::endl;
    SDL_Quit();
  }
}

void Engine::loop()
{
  std::async( [=](){ maintain_time(); } );
}

void Engine::maintain_time()
{
  Uint32 ms_per_frame = 1000;
  Uint32 last_frame = SDL_GetTicks();
  while( true )
  {
    Uint32 current_time = SDL_GetTicks();
    if( current_time - last_frame >= ms_per_frame )
    {
      render();
      last_frame = current_time;
    }
  }
}

void Engine::render()
{
  std::cout << "tick" << std::endl;  
}
