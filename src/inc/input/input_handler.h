#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "input_event.h"
#include <SDL.h>
#include <memory>

class InputHandler
{
public:

  InputHandler();

  InputEvent& handle_input();

private:

  void determine_input();

  bool escape( SDL_Event e );

  bool right_arrow( SDL_Event e );

  bool left_arrow( SDL_Event e );

  std::unique_ptr<InputEvent> current_event;
  SDL_Event e;
  const Uint8* keyboard_state;
  int x;
  int y;
};

#endif
