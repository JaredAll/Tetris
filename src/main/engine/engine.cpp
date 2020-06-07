#include "engine.h"
#include "SDL_timer.h"
#include "cleanup.h"
#include "render_component.h"
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
    component_factory = make_unique<GameComponentFactory>();
  }
}

void Engine::loop()
{
  unique_ptr<Sprite> first_block = component_factory ->
    initialize_sprite( 0, 0, "/home/jared/Games/Tetris/resources/j.png", *renderer );

  piece = first_block.get();

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
  renderer -> render( *piece );
}
