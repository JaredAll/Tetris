#include "engine.h"
#include "SDL_timer.h"
#include "cleanup.h"
#include "render_component.h"
#include <iostream>
#include <future>
#include <memory>
#include "sprite_config.h"

using namespace std;

void Engine::initialize( int height, int width )
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    std::cout << "SDL_Init failed" << std::endl;
  }

  unique_ptr<SDL_Window, SDL_Window_Destroyer> win {
    SDL_CreateWindow("Tetris",
                     SDL_WINDOWPOS_CENTERED,
                     SDL_WINDOWPOS_CENTERED,
                     width,
                     height,
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
    thread timer{ [=](){ maintain_time(); } };
    timer.detach();
    should_render = true;
    should_update = true;
  }
}

void Engine::advance( vector<unique_ptr<GameComponent>>& components )
{
  if( should_render )
  {
    render( components );
  }

  if( should_update )
  {
    update( components );
  }
}

GameRenderer& Engine::get_renderer()
{
  return *renderer;
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
      should_render = true;
      last_frame = current_time;
    }
  }
}

void Engine::render( vector<unique_ptr<GameComponent>>& components )
{
  renderer -> render( components );
  
  should_render = false;
  should_update = true;
}

void Engine::update( vector<unique_ptr<GameComponent>>& components )
{
  for( auto& component : components )
  {
    component -> update();
  }
  
  should_update = false;
}
