#include "sprite.h"
#include "SDL_rect.h"

using namespace std;

Sprite::Sprite( SpriteConfig config, shared_ptr<SDL_Texture> param_texture )
  : texture( param_texture )
{
  destination = make_shared<SDL_Rect>();
  destination -> x = config.x;
  destination -> y = config.y;
  destination -> h = config.h;
  destination -> w = config.w;
}

Sprite::~Sprite()
{
}

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
  return destination -> x;
}

int Sprite::get_y()
{
  return destination -> y;
}

void Sprite::set_x( int param_x )
{
  destination -> x = param_x;
}

void Sprite::set_y( int param_y )
{
  destination -> y = param_y;
}

void Sprite::calculate_destination()
{
}

