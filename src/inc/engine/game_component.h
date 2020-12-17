#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "component_visitor.h"
#include "render_component.h"
#include <vector>
#include <iostream>
#include "input_event.h"

class GameRenderer;

class GameComponent
{
public:

  virtual void update() = 0;

  virtual void update( InputEvent& event ) = 0;

  virtual bool accepting_input() = 0;

  virtual void accept_renderer( GameRenderer& renderer ) = 0;

  virtual ~GameComponent() = default;

protected:

  GameComponent(){}
};

#endif
