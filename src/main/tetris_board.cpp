#include "tetris_board.h"
#include "game_component.h"

using std::vector;
using std::unique_ptr;

void TetrisBoard::update()
{
  
}

vector<unique_ptr<RenderComponent>>& TetrisBoard::get_render_components()
{
  return components;
}

int TetrisBoard::get_rows()
{
  return rows;
}

int TetrisBoard::get_columns()
{
  return columns;
}

bool TetrisBoard::has_landed( TetrisPiece& piece )
{
  bool landed = false;
  if( impact( piece ) || piece.get_bottom_row() >= rows - 1 )
  {
    landed = true;
  }

  return landed;
}

void TetrisBoard::add_piece( TetrisPiece& piece )
{
  int piece_current_row = piece.get_current_row();
  int piece_current_column = piece.get_current_column();

  for( auto& point : piece.get_block_locations() )
  {
    occupied_spaces.at( point -> get_y() + piece_current_row - 1 )
      .at( point -> get_x() + piece_current_column ) = true;
  }
}

TetrisBoard::~TetrisBoard()
{  
}

TetrisBoard::TetrisBoard()
  : GameComponent{}
{
  rows = 20;
  columns = 10;

  for( size_t row = 0; row < rows; row++ )
  {
    occupied_spaces.push_back( {} );
    for( size_t column = 0; column < columns; column++ )
    {
      occupied_spaces.at( row ).push_back( false );
    }
  }
}

bool TetrisBoard::impact( TetrisPiece& piece )
{
  bool collided = false;
  for( auto& point : piece.get_block_locations() )
  {
    int point_next_row = point -> get_y() + piece.get_current_row() + 1;
    int point_column = point -> get_x() + piece.get_current_column();

    if( point_next_row < rows )
    {
      collided = occupied_spaces.at( point_next_row )
      .at( point_column );
    }
  }

  return collided;
}
