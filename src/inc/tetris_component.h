#ifndef TETRIS_COMPONENT_H
#define TETRIS_COMPONENT_H

#include "game_component.h"

class TetrisComponent : public GameComponent
{
public:
  
    virtual void accept( ComponentVisitor& visitor ) = 0;
    
};

#endif
