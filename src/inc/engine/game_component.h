#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "render_component.h"
#include <vector>
#include <iostream>

class GameComponent
{
public:

  virtual void update() = 0;

  virtual void setRenderComponent( std::unique_ptr<RenderComponent> component )
  {
    render_component = move( component );
  }

  virtual RenderComponent& get_render_component()
  {
    return *render_component;
  }

  virtual ~GameComponent(){}

protected:

  GameComponent( std::unique_ptr<RenderComponent> param_render_component )
    : render_component( move( param_render_component ) ){}

  std::unique_ptr<RenderComponent> render_component;
};

#endif
