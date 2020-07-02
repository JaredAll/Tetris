#include "input_event.h"

InputEvent::InputEvent( InputType current, InputType previous )
  : current_frame_input( current ), previous_frame_input( previous )
{}

bool InputEvent::left_up() const
{
  return previous_frame_input == InputType::left &&
    current_frame_input == InputType::none;
}

bool InputEvent::right_up() const
{
  return previous_frame_input == InputType::right &&
    current_frame_input == InputType::none;
}

bool InputEvent::exit() const
{
  return current_frame_input == InputType::exit;
}
