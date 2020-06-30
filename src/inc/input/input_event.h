#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

class InputEvent
{
public:

  InputEvent( int x_input, int y_input );

  int get_x_input() const;
  
  int get_y_input() const;
  
private:
  
  int x_input;
  int y_input;
  
};

#endif
