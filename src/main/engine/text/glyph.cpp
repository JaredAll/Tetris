#include "glyph.h"

using std::make_shared;

Glyph::Glyph( int param_x,
              int param_y,
              int param_h,
              int param_w,
              std::shared_ptr<SDL_Texture> param_texture )
  : x( param_x ), y( param_y ), h( param_h ), w( param_w ), texture( param_texture )
{
  destination = make_shared<SDL_Rect>();
  destination -> x = param_x;
  destination -> y = param_y;
  destination -> h = param_h;
  destination -> w = param_w;
}

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

