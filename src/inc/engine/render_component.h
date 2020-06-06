#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include "SDL_rect.h"
#include "cleanup.h"
#include <SDL.h>
#include <iostream>
#include <memory>

class RenderComponent
{
public:
  
  virtual std::unique_ptr<SDL_Texture, SDL_Texture_Destroyer> getTexture() const = 0; 

  virtual std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> getDestination() const = 0;

  virtual std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> getClip() const = 0;

  virtual void set_clip( std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> clip ) = 0;

  virtual void set_destination( std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> destination ) = 0;

  virtual int get_x() = 0;

  virtual int get_y() = 0;

  virtual void set_x( int x ) = 0;

  virtual void set_y( int y ) = 0;

  virtual void calculate_destination() = 0;
  
};

#endif
