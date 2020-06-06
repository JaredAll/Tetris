#include "sprite.h"

using namespace std;

unique_ptr<SDL_Texture, SDL_Texture_Destroyer> Sprite::getTexture()
{
  return unique_ptr<SDL_Texture, SDL_Texture_Destroyer>{ move( texture ) };
}

unique_ptr<SDL_Rect, SDL_Rect_Destroyer> Sprite::getDestination()
{
  return unique_ptr<SDL_Rect, SDL_Rect_Destroyer>{ move( destination) };
}

unique_ptr<SDL_Rect, SDL_Rect_Destroyer> Sprite::getClip()
{
  return unique_ptr<SDL_Rect, SDL_Rect_Destroyer>{ move( clip) };
}

void Sprite::set_clip( unique_ptr<SDL_Rect, SDL_Rect_Destroyer> clip ) 
{
  clip = move( clip );
}

void Sprite::set_destination( unique_ptr<SDL_Rect, SDL_Rect_Destroyer> destination )
{
  destination = move( destination );
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

