#ifndef TETRIS_COMPONENT_H
#define TETRIS_COMPONENT_H

#include "block.h"
#include "game_component.h"
#include <memory>

class TetrisComponent : public GameComponent
{
public:
  
  virtual void accept( ComponentVisitor& visitor ) = 0;

  virtual std::vector<std::unique_ptr<Block>>& get_render_components() = 0;

};

#endif
