#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include "input_type.h"

class InputEvent
{
public:

  InputEvent( InputType input );

  InputType get_input() const;
  
private:  

  InputType input;

};

#endif
