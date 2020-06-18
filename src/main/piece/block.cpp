#include "block.h"

Block::Block( std::unique_ptr<Sprite> param_sprite )
{
  sprite = move( param_sprite );
}

Block::~Block()
{
}

std::shared_ptr<SDL_Texture> Block::getTexture() const
{
  return sprite -> getTexture();
}

std::shared_ptr<SDL_Rect> Block::getDestination() const
{
  return sprite -> getDestination();
}

std::shared_ptr<SDL_Rect> Block::getClip() const
{
  return sprite -> getClip();
}

void Block::set_clip( std::shared_ptr<SDL_Rect> clip )
{
  sprite -> set_clip( clip );
}

void Block::set_destination( std::shared_ptr<SDL_Rect> destination )
{
  sprite -> set_destination( destination );
}

int Block::get_x()
{
  return sprite -> get_x();
}

int Block::get_y()
{
  return sprite -> get_y();
}

int Block::get_h()
{
  return sprite -> get_h();
}

int Block::get_w()
{
  return sprite -> get_w();
}

void Block::set_x( int x )
{
  sprite -> set_x( x );
}

void Block::set_y( int y )
{
  sprite -> set_y( y );
}

void Block::calculate_destination()
{
}

int Block::get_row()
{
  return row;
}

void Block::set_row( int param_row )
{
  row = param_row;
}

int Block::get_column()
{
  return column;
}

void Block::set_column( int param_column )
{
  column = param_column;
}

