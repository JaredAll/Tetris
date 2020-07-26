#ifndef JARED_ALL_TETRIS_BLOCK_H
#define JARED_ALL_TETRIS_BLOCK_H

#include "render_component.h"
#include <memory>
#include "sprite.h"

class Block : public RenderComponent
{
public:
  
  Block( std::unique_ptr<Sprite> sprite );

  ~Block();  

  std::shared_ptr<SDL_Texture> getTexture() const;
 
  std::shared_ptr<SDL_Rect> getDestination() const;
  
  std::shared_ptr<SDL_Rect> getClip() const;
  
  void set_clip( std::shared_ptr<SDL_Rect> clip );
  
  void set_destination( std::shared_ptr<SDL_Rect> destination );
  
  int get_x();
  
  int get_y();

  int get_h();
  
  int get_w();
  
  void set_x( int x );
  
  void set_y( int y );
  
  void calculate_destination();

  int get_row();

  void set_row( int row );

  int get_column();

  void set_column( int column );

  void fall();

private:
  
  std::unique_ptr<Sprite> sprite;
  int row;
  int column;

};

#endif
