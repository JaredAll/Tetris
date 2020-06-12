#include "engine.h"
#include "SDL_timer.h"
#include "cleanup.h"
#include "render_component.h"
#include <iostream>
#include <future>
#include <memory>
#include "sprite_config.h"

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
    component_factory = make_unique<TetrisComponentFactory>();
    should_render = false;
  }
}

void Engine::loop()
{
  pieces.push_back( move( component_factory -> build_component( PieceType::jay, *renderer ) ) );

  current_piece = pieces.at( 0 ).get();
    
  thread timer{ [=](){ maintain_time(); } };

  while( true )
  {
    if( should_render )
    {
      render();
    }
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
      should_render = true;
      last_frame = current_time;
    }
  }
}

void Engine::render()
{
  renderer -> render( current_piece -> get_render_component() );
  current_piece_index += 1;
  current_piece_index = current_piece_index % pieces.size();
  current_piece = pieces.at( current_piece_index ).get();
  should_render = false;
}
