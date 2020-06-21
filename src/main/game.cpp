#include "game.h"
#include "piece_type.h"
#include "tetris_piece.h"
#include "tetris_board.h"
#include <memory>
#include <stdlib.h>
#include <time.h>

using std::make_unique;
using std::unique_ptr;
using std::bad_cast;

Game::Game( int height )
{
  should_update = true;

  types = {
    PieceType::bar,
    PieceType::block,
    PieceType::ell,
    PieceType::ess,
    PieceType::jay,
    PieceType::tee,
    PieceType::zee 
  };

  srand( time( nullptr ) );
  current_piece_index = rand() % types.size();

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
  add_piece();

  while( true )
  {
    engine -> advance( components );
    if( engine -> peek_has_updated() )
    {
      update_components();  
    }
  }
}

void Game::update_components()
{
  for( auto& component : components )
  {
    update_piece( *component );
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
      add_piece();
    }
  }
  catch( bad_cast )
  {
  }
}

void Game::add_piece()
{
  components.push_back(
    move(
      component_factory -> build_component( types.at( current_piece_index ),
                                            engine -> get_renderer() ) )
    );
  current_piece_index = rand() % types.size();
}
