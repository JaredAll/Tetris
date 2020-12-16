#ifndef JAREDALL_TETRIS_GLYPH
#define JAREDALL_TETRIS_GLYPH

#include "SDL_render.h"
#include "render_component.h"

class Glyph : public RenderComponent
{
public:

  Glyph( int x, int y, int h, int w, std::shared_ptr<SDL_Texture> texture );

  std::shared_ptr<SDL_Texture> getTexture() const override;
  
  std::shared_ptr<SDL_Rect> getDestination() const override;
  
  std::shared_ptr<SDL_Rect> getClip() const override;
  
  void set_clip( std::shared_ptr<SDL_Rect> clip ) override;
  
  void set_destination( std::shared_ptr<SDL_Rect> destination ) override;
  
  int get_x() override;
  
  int get_y() override;
  
  int get_h() override;
  
  int get_w() override;
  
  void set_x( int x ) override;
  
  void set_y( int y ) override;
  
  void calculate_destination() override;

private:
  
  int x;
  int y;
  int h;
  int w;

  std::shared_ptr<SDL_Texture> texture;
  std::shared_ptr<SDL_Rect> destination;
  std::shared_ptr<SDL_Rect> clip;

};

#endif
