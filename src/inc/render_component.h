#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include <SDL.h>
#include <iostream>
#include <memory>

class RenderComponent
{
public:
  
  virtual SDL_Texture* getTexture() const = 0; 

  virtual std::unique_ptr<SDL_Rect> getDestination() const = 0;

  virtual SDL_Rect* getClip() const = 0;

  virtual void set_clip( SDL_Rect *clip ) = 0;

  virtual void set_destination( std::unique_ptr<SDL_Rect> destination ) = 0;

  virtual int get_x() = 0;

  virtual int get_y() = 0;

  virtual void set_x( int x ) = 0;

  virtual void set_y( int y ) = 0;

  virtual void calculate_destination()
  {
    std::unique_ptr<SDL_Rect> new_destination {new SDL_Rect()};
    new_destination -> x = get_x();
    new_destination -> y = get_y();
    new_destination -> h = ( getClip() -> h );
    new_destination -> w = ( getClip() -> w );

    set_destination( std::move( new_destination ) );
  }
  
};

#endif
