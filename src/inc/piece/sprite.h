#ifndef JAREDALL_TETRIS_PIECE_SPRITE
#define JAREDALL_TETRIS_PIECE_SPRITE

#include "cleanup.h"
#include "render_component.h"

class Sprite: public RenderComponent
{
  std::unique_ptr<SDL_Texture, SDL_Texture_Destroyer> getTexture();
  
  std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> getDestination();
  
  std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> getClip();
  
  void set_clip( std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> clip );
  
  void set_destination( std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> destination );
  
  int get_x();
  
  int get_y();
  
  void set_x( int x );
  
  void set_y( int y );
  
  void calculate_destination();

private:
  
  std::unique_ptr<SDL_Texture, SDL_Texture_Destroyer> texture;
  std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> destination;
  std::unique_ptr<SDL_Rect, SDL_Rect_Destroyer> clip;
  int x;
  int y;

};

#endif
