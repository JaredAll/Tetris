#include "tetris_component_factory.h"
#include "configurations.h"
#include "tetris_piece.h"
#include "jay_piece.h"
#include "waiting_state.h"
#include "zee_piece.h"
#include "ess_piece.h"
#include "ell_piece.h"
#include "bar_piece.h"
#include "block_piece.h"
#include "tee_piece.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::vector;
using std::shared_ptr;

TetrisComponentFactory::TetrisComponentFactory( int param_height, TetrisBoard& param_board )
  : board( param_board )
{
  grid_unit_length = param_height / board.get_rows();
  new_piece_x = grid_unit_length * ( board.get_columns() / 2 );
  new_piece_y = 0;
}

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

  for( auto& point : piece -> get_block_locations() )
  {
    piece -> add_render_component(
      move (
        initialize_block( *point, config, renderer )
        )
      );
  }

  piece -> set_grid_unit_length( grid_unit_length );
  piece -> set_max_row( board.get_rows() );
  piece -> set_max_column( board.get_columns() );

  unique_ptr<WaitingState> initial_state = make_unique<WaitingState>( *piece, board, 0 );
  piece -> set_state( move( initial_state ) );

  return piece;
}

unique_ptr<Block> TetrisComponentFactory::initialize_block( Point& point,
                                                            SpriteConfig config,
                                                            GameRenderer& renderer )
{
  return make_unique<Block>( move( initialize_sprite( point, config, renderer ) ) );
}

unique_ptr<Sprite> TetrisComponentFactory::initialize_sprite( Point& point,
                                                              SpriteConfig config,
                                                              GameRenderer& renderer )
{
  shared_ptr<SDL_Texture> sprite_texture =
    renderer.create_texture( config.image_path );

  int sprite_x = new_piece_x + grid_unit_length * point.get_x();
  int sprite_y = new_piece_y + grid_unit_length * point.get_y();
  int sprite_h = grid_unit_length;
  int sprite_w = grid_unit_length;

  return make_unique<Sprite>( sprite_x,
                              sprite_y,
                              sprite_h,
                              sprite_w,
                              sprite_texture );
}
