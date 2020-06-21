#include "bar_piece.h"

void BarPiece::determine_block_locations()
{
  add_block_location( std::make_unique<Point>( 0, 0 ) );
  add_block_location( std::make_unique<Point>( 1, 0 ) );
  add_block_location( std::make_unique<Point>( 2, 0 ) );
  add_block_location( std::make_unique<Point>( 3, 0 ) );
}
