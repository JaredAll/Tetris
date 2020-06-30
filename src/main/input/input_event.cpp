#include "input_event.h"

InputEvent::InputEvent( int param_x_input, int param_y_input )
  : x_input( param_x_input ),
    y_input( param_y_input )
{}

int InputEvent::get_x_input() const
{
  return x_input;
}

int InputEvent::get_y_input() const
{
  return y_input;
}
