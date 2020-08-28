#ifndef RENDER_COMPONENT_MOCK_H
#define RENDER_COMPONENT_MOCK_H

#include "catch.hpp"
#include "catch2/trompeloeil.hpp"
#include "render_component.h"

class RenderComponentMock : public RenderComponent
{
public:
  MAKE_CONST_MOCK0( getTexture, std::shared_ptr<SDL_Texture>(), override );
  MAKE_CONST_MOCK0( getDestination, std::shared_ptr<SDL_Rect>(), override );
  MAKE_CONST_MOCK0( getClip, std::shared_ptr<SDL_Rect>(), override );
  MAKE_MOCK1( set_clip, void( std::shared_ptr<SDL_Rect> ), override );
  MAKE_MOCK1( set_destination, void( std::shared_ptr<SDL_Rect> ), override );
  MAKE_MOCK0( get_x, int(), override );
  MAKE_MOCK0( get_y, int(), override );
  MAKE_MOCK0( get_h, int(), override );
  MAKE_MOCK0( get_w, int(), override );
  MAKE_MOCK1( set_x, void( int ), override );
  MAKE_MOCK1( set_y, void( int ), override );
  MAKE_MOCK0( calculate_destination, void(), override );
};

#endif
