#include "tetris_component_factory.h"
#include "configurations.h"
#include "tetris_piece.h"
#include "jay_piece.h"
#include "zee_piece.h"
#include "ess_piece.h"
#include "ell_piece.h"
#include "bar_piece.h"
#include "block_piece.h"
#include "tee_piece.h"
#include <memory>

using namespace std;

TetrisComponentFactory::TetrisComponentFactory( int param_grid_unit_length )
  : grid_unit_length( param_grid_unit_length )
{}

unique_ptr<GameComponent> TetrisComponentFactory::build_component(
  PieceType piece_type,
  GameRenderer& renderer )
{
  
  SpriteConfig config;
  unique_ptr<TetrisPiece> piece;
  switch( piece_type )
  {
  case PieceType::jay:
    config = j_config;
    piece = make_unique<JayPiece>();
    break;
  case PieceType::tee:
    config = t_config;
    piece = make_unique<TeePiece>();
    break;
  case PieceType::block:
    config = block_config;
    piece = make_unique<BlockPiece>();
    break;
  case PieceType::bar:
    config = bar_config;
    piece = make_unique<BarPiece>();
    break;
  case PieceType::ell:
    config = l_config;
    piece = make_unique<EllPiece>();
    break;
  case PieceType::ess:
    config = s_config;
    piece = make_unique<EssPiece>();
    break;
  case PieceType::zee:
    config = z_config;
    piece = make_unique<ZeePiece>();
    break;
  }

  vector<unique_ptr<Point>>& points = piece -> get_block_locations();
  for( size_t i = 0; i < points.size(); i++ )
  {
    piece -> add_render_component(
      move (
        initialize_sprite( *points.at( i ), config, renderer )
        )
      );
  }

  piece -> set_grid_unit_length( grid_unit_length );

  return piece;
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
