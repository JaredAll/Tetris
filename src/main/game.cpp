#include "game.h"
#include "piece_type.h"
#include "tetris_piece.h"
#include "tetris_board.h"
#include <memory>

Game::Game( int height, int width )
{
  engine = std::make_unique<Engine>();
  window_height = height;
  window_width = width;
}

void Game::play()
{
  engine -> initialize( window_height, window_width );
  initialize();

  while( true )
  {
    engine -> advance( components );
    update_components();
  }
}

void Game::initialize()
{
  int grid_unit_length = 50;
  std::unique_ptr<TetrisBoard> board = std::make_unique<TetrisBoard>();
  component_factory = std::make_unique<TetrisComponentFactory>( grid_unit_length );

  add_piece( PieceType::tee );
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
    if( piece.get_bottom_x() >= window_height )
    {
      piece.set_falling( false );
    }
  }
  catch( std::bad_cast )
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
