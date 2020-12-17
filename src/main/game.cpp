#include "game.h"
#include "piece_type.h"
#include "tetris_piece.h"
#include "tetris_board.h"
#include "tetris_visitor.h"
#include <memory>
#include <stdlib.h>
#include <time.h>

using std::make_unique;
using std::unique_ptr;
using std::bad_cast;
using std::vector;
using std::move;

Game::Game( int height, unique_ptr<TetrisBoard> param_board )
  : board( *param_board )
{
  score = 0;
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

  components.push_back( move( param_board ) );

  window_height = height;
  window_width = height / ( board.get_rows() / board.get_columns() );

  component_factory = make_unique<TetrisComponentFactory>(
    window_height,
    board );

  visitor = make_unique<TetrisVisitor>( board, *this );
}

void Game::play()
{
  engine -> initialize( window_height, window_width );

  std::shared_ptr<TTF_Font> font = engine -> initialize_font( "/home/jared/Games/Tetris/resources/OpenSans-Bold.ttf", 112 );

  unique_ptr<Panel> panel = component_factory -> build_panel(
    "Tetris",
    font,
    engine -> get_renderer() );

  components.push_back( move( panel ) );

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
    component -> accept( *visitor );
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

void Game::transfer_piece_to_board( TetrisPiece& piece )
{
  board.add_piece( piece );
  
  vector<unique_ptr<TetrisComponent>> new_components;
  for( auto& component : components )
  {
    if( component.get() != &piece )
    {
      new_components.push_back( move( component ) );
    }
  }

  components = move( new_components );
}
