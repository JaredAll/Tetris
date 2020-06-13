#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "render_component.h"
#include <vector>
#include <iostream>

class GameComponent
{
public:

  virtual void update() = 0;

  virtual void add_render_component( std::unique_ptr<RenderComponent> component )
  {
    render_components.push_back( move( component ) );
  }

  virtual std::vector<std::unique_ptr<RenderComponent>>& get_render_components()
  {
    return render_components;
  }

  virtual ~GameComponent(){}

protected:

  GameComponent(){}

  std::vector<std::unique_ptr<RenderComponent>> render_components;
};

#endif
