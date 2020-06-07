#include "sprite.h"

using namespace std;

Sprite::Sprite( int param_x, int param_y, std::shared_ptr<SDL_Texture> param_texture )
  : x( param_x ), y( param_y ), texture( param_texture )
{}

shared_ptr<SDL_Texture> Sprite::getTexture() const
{
  return texture;
}

shared_ptr<SDL_Rect> Sprite::getDestination() const
{
  return destination;
}

shared_ptr<SDL_Rect> Sprite::getClip() const
{
  return clip;
}

void Sprite::set_clip( shared_ptr<SDL_Rect> param_clip ) 
{
  clip = param_clip;
}

void Sprite::set_destination( shared_ptr<SDL_Rect> param_destination )
{
  destination = param_destination;
}

int Sprite::get_x()
{
  return x;
}

int Sprite::get_y()
{
  return y;
}

void Sprite::set_x( int param_x )
{
  x = param_x;
}

void Sprite::set_y( int param_y )
{
  y = param_y;
}

void Sprite::calculate_destination()
{
}

