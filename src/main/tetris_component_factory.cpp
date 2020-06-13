#include "tetris_component_factory.h"
#include "configurations.h"
#include "tetris_piece.h"
#include "jay_piece.h"

using namespace std;

TetrisComponentFactory::TetrisComponentFactory( int param_grid_unit_length )
  : grid_unit_length( param_grid_unit_length )
{}

unique_ptr<GameComponent> TetrisComponentFactory::build_component(
  PieceType piece_type,
  GameRenderer& renderer )
{
  
  SpriteConfig config;
  switch( piece_type )
  {
  case PieceType::jay:
    config = j_config;
    break;
  case PieceType::tee:
    config = t_config;
    break;
  case PieceType::block:
    config = block_config;
    break;
  case PieceType::bar:
    config = bar_config;
    break;
  case PieceType::ell:
    config = l_config;
    break;
  case PieceType::ess:
    config = s_config;
    break;
  case PieceType::zee:
    config = z_config;
    break;
  }

  unique_ptr<JayPiece> jay_piece { make_unique<JayPiece>() };

  vector<unique_ptr<Point>>& points = jay_piece -> get_block_locations();
  for( size_t i = 0; i < points.size(); i++ )
  {
    jay_piece -> add_render_component(
      move (
        initialize_sprite( *points.at( i ), config, renderer )
        )
      );
  }

  jay_piece -> set_grid_unit_length( grid_unit_length );

  return jay_piece;
}

unique_ptr<Sprite> TetrisComponentFactory::initialize_sprite( Point& point,
                                                              SpriteConfig config,
                                                              GameRenderer& renderer )
{
  shared_ptr<SDL_Texture> sprite_texture =
    renderer.create_texture( config.image_path );

  int sprite_x = config.x + grid_unit_length * point.get_x();
  int sprite_y = config.y + grid_unit_length * point.get_y();
  int sprite_h = config.h;
  int sprite_w = config.w;

  return make_unique<Sprite>( sprite_x,
                              sprite_y,
                              sprite_h,
                              sprite_w,
                              sprite_texture );
}
