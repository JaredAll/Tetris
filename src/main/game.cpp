#include "game.h"
#include "piece_type.h"
#include "tetris_piece.h"
#include "tetris_board.h"
#include <memory>

using std::make_unique;
using std::unique_ptr;
using std::bad_cast;

Game::Game( int height )
{
  current_piece_index = 0;

  types = {
    PieceType::bar,
    PieceType::block,
    PieceType::ell,
    PieceType::ess,
    PieceType::jay,
    PieceType::tee,
    PieceType::zee 
  };

  engine = make_unique<Engine>();

  board = make_unique<TetrisBoard>();

  window_height = height;
  window_width = height / ( board -> get_rows() / board -> get_columns() );

  component_factory = make_unique<TetrisComponentFactory>(
    window_height,
    board -> get_rows(),
    board -> get_columns() );
}

void Game::play()
{
  engine -> initialize( window_height, window_width );
  add_piece( types.at( current_piece_index ) );
  current_piece_index = ( current_piece_index + 1 ) % types.size();

  while( true )
  {
    engine -> advance( components );
    update_components();
  }
}

void Game::update_components()
{
  for( size_t i = 0; i < components.size(); i++ )
  {
    update_piece( *components.at( i ) );
  }  
}

void Game::update_piece( GameComponent& component )
{
  try
  {
    TetrisPiece& piece = dynamic_cast<TetrisPiece&>( component );
    if( board -> has_landed( piece ) && piece.is_falling() )
    {
      piece.set_falling( false );
      board -> add_piece( piece );
      add_piece( types.at( current_piece_index ) );
      current_piece_index = ( current_piece_index + 1 ) % types.size();
    }
  }
  catch( bad_cast )
  {
  }
}

void Game::add_piece( PieceType type )
{
  components.push_back(
    move(
      component_factory -> build_component( type,
                                            engine -> get_renderer() ) )
    );  
}
