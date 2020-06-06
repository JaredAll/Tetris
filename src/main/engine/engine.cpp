#include "engine.h"
#include "SDL_timer.h"
#include "cleanup.h"
#include <iostream>
#include <future>
#include <memory>

using namespace std;

void Engine::initialize()
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    std::cout << "SDL_Init failed" << std::endl;
  }

  int window_width = 1000;
  int window_height = 500;
  unique_ptr<SDL_Window, SDL_Window_Destroyer> win {
    SDL_CreateWindow("Tetris",
                     SDL_WINDOWPOS_CENTERED,
                     SDL_WINDOWPOS_CENTERED,
                     window_width, window_height,
                     SDL_WINDOW_SHOWN)
  };

  if (!win)
  {
    std::cout << "Create Window failed" << std::endl;
    SDL_Quit();
  }
  else
  {
    renderer = unique_ptr<GameRenderer>{ new GameRenderer( move( win ) ) };
  }
}

void Engine::loop()
{
  std::async( [=](){ maintain_time(); } );
  while( true )
  {
    
  }
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
