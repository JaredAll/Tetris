#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "render_component.h"
#include <vector>
#include <iostream>

class GameComponent
{
public:

  virtual void setRenderComponent( RenderComponent& component )
  {
    renderComponent = component;
  }

  virtual RenderComponent& get_render_component()
  {
    return renderComponent;
  }

protected:

  GameComponent( RenderComponent& renderComponent );

  RenderComponent& renderComponent;
};

#endif
