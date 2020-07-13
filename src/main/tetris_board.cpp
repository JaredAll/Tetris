#include "tetris_board.h"
#include "game_component.h"

using std::vector;
using std::unique_ptr;

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

bool TetrisBoard::full()
{
  bool full { false };
  int col { 0 };
  while( !full && col < columns )
  {
    full = occupied_spaces.at( 0 ).at( col );
    ++col;
  }
  return full;
}

void TetrisBoard::add_piece( TetrisPiece& piece )
{
  int piece_current_row = piece.get_current_row();
  int piece_current_column = piece.get_current_column();

  for( auto& point : piece.get_block_locations() )
  {
    int occupied_x = point -> get_x() + piece_current_column;
    int occupied_y = point -> get_y() + piece_current_row;

    occupied_spaces.at( occupied_y )
      .at( occupied_x ) = true;
  }
}

TetrisBoard::~TetrisBoard()
{  
}

TetrisBoard::TetrisBoard()
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
  int point_index = 0;
  auto& points = piece.get_block_locations();
  while( !collided && point_index < points.size() )
  {
    int point_next_row = points.at( point_index ) -> get_y() + piece.get_current_row() + 1;
    int point_column = points.at( point_index ) -> get_x() + piece.get_current_column();

    if( point_next_row < rows )
    {
      collided = occupied_spaces.at( point_next_row )
        .at( point_column );
    }
    ++point_index;
  }
  
  return collided;
}
