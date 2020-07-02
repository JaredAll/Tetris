#include "input_handler.h"
#include "SDL_events.h"
#include "input_type.h"

using std::unique_ptr;
using std::make_unique;

InputHandler::InputHandler()
{
  keyboard_state = SDL_GetKeyboardState( NULL );
  current_input_type = InputType::none;
  previous_input_type = InputType::none;
}

void InputHandler::determine_input()
{
  previous_input_type = current_input_type;
  
  while( SDL_PollEvent( &e ))
  {
    if( e.type == SDL_KEYDOWN )
    {
      if( right_arrow( e ) )
      {
        current_input_type = InputType::right;
      }
      
      if( left_arrow( e ))
      {
        current_input_type = InputType::left;
      }

      if( escape( e ))
      {
        current_input_type = InputType::exit;
      }
    }

    if( e.type == SDL_KEYUP )
    {
      current_input_type = InputType::none;
    }

    if( e.type == SDL_QUIT )
    {
      current_input_type = InputType::exit;
    }
  }
  
  current_event = make_unique<InputEvent>( current_input_type, previous_input_type );  
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
