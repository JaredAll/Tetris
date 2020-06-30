#include "engine.h"
#include "SDL_timer.h"
#include "cleanup.h"
#include "render_component.h"
#include <iostream>
#include <future>
#include <memory>
#include "sprite_config.h"

using std::unique_ptr;
using std::thread;
using std::vector;

Engine::Engine( vector<unique_ptr<GameComponent>>& param_components )
  : components( param_components )
{}

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
    frame_count = 0;
  }
}

void Engine::advance( InputEvent& event )
{
  if( should_render )
  {
    render_components();
  }

  handle_input( event );

  update_components( event );
}

void Engine::handle_input( InputEvent& input_event )
{
  //TODO: handle exiting the game here (with cleanup?)
}

GameRenderer& Engine::get_renderer()
{
  return *renderer;
}

bool Engine::peek_has_updated()
{
  bool peek_update = false;
  if( has_updated )
  {
    has_updated = false;
    peek_update = true;
  }
  return peek_update;
}

void Engine::maintain_time()
{
  Uint32 ms_per_frame = 16;
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
  renderer -> render( components );
  
  frame_count++;
  should_render = false;
  should_update = true;
}

void Engine::update( InputEvent& event )
{
  for( auto& component : components )
  {
    if( frame_count % component -> get_frames_per_update() == 0 && should_update )
    {
      component -> update();
      has_updated = true;
    }
  }
  
  should_update = false;
}
