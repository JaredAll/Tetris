#include "tetris_board_block_visitor.h"
#include "board_block_operation.h"
#include <algorithm>

using std::vector;

TetrisBoardBlockVisitor::TetrisBoardBlockVisitor( TetrisBoard& param_board )
  : board( param_board )
{
  operation = BoardBlockOperation::fall;
}

void TetrisBoardBlockVisitor::visitBlock( Block& block ) 
{
  if( operation == BoardBlockOperation::initialize )
  {
    block.set_column( occupied_x );
    block.set_row( occupied_y );
  }
  else if( operation == BoardBlockOperation::fall )
  {
    for( int row : full_rows )
    {
      if( block.get_row() < row )
      {
        board.occupied_spaces.at( block.get_row() ).at( block.get_column() ) = false;
        block.fall();  
      }
    }
    board.occupied_spaces.at( block.get_row() ).at( block.get_column() ) = true;
  }
  else if( operation == BoardBlockOperation::eliminate )
  {
    vector<int>::iterator iterator = std::find( 
      full_rows.begin(), 
      full_rows.end(), 
      block.get_row() );

    if( iterator == full_rows.end() )
    {
      new_components.push_back( move( component ) );
    }
    else
    {
      board.occupied_spaces.at( block.get_row() ).at( block.get_column() ) = false;
    }
  }
}
