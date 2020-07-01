#include "input_event.h"

InputEvent::InputEvent( InputType param_input )
  : input( param_input )
{}

InputType InputEvent::get_input() const
{
  return input;
}
