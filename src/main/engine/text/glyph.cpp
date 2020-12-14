#include "glyph.h"

std::shared_ptr<SDL_Texture> Glyph::getTexture() const 
{
  return texture;
}
  
std::shared_ptr<SDL_Rect> Glyph::getDestination() const
{
  return destination;
}
  
std::shared_ptr<SDL_Rect> Glyph::getClip() const
{
  return clip;
}
  
void Glyph::set_clip( std::shared_ptr<SDL_Rect> param_clip )
{
  clip = param_clip;
}
  
void Glyph::set_destination( std::shared_ptr<SDL_Rect> param_destination )
{
  destination = param_destination;
}
  
int Glyph::get_x()
{
  return x;
}
  
int Glyph::get_y()
{
  return y;
}
  
int Glyph::get_h()
{
  return h;
}
  
int Glyph::get_w()
{
  return w;
}
  
void Glyph::set_x( int param_x )
{
  x = param_x;
}
  
void Glyph::set_y( int param_y )
{
  y = param_y;
}
  
void Glyph::calculate_destination()
{
}

