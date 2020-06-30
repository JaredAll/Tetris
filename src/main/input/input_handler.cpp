#include "input_handler.h"
#include "SDL_events.h"

using std::unique_ptr;
using std::make_unique;

InputHandler::InputHandler()
{
  keyboard_state = SDL_GetKeyboardState( NULL );
  int x = 0;
  int y = 0;
  bool r_key = false;
}

void InputHandler::determine_input()
{
  while( SDL_PollEvent( &e ))
  {
    if( e.type == SDL_KEYDOWN )
    {
      if( right_arrow( e ) )
      {
        x = 1;
      }
      
      if( left_arrow( e ))
      {
        x = -1;
      }

      if( escape( e ))
      {
        exit( 0 );
      }
    }

    if( e.type == SDL_KEYUP )
    {
      x = 0;
    }

    if( e.type == SDL_QUIT )
    {
      exit( 0 );
    }
  }
  
  current_event = move( make_unique<InputEvent>( x, y ) );  
}

InputEvent& InputHandler::handle_input()
{ 
  determine_input();
  return *current_event;
}

bool InputHandler::escape( SDL_Event e )
{
  return e.key.keysym.sym == SDLK_ESCAPE;
}

bool InputHandler::right_arrow( SDL_Event e )
{
  return e.key.keysym.sym == SDLK_RIGHT;
}

bool InputHandler::left_arrow( SDL_Event e )
{
  return e.key.keysym.sym == SDLK_LEFT;
}
