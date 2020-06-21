#include "jay_piece.h"

void JayPiece::determine_block_locations()
{
  add_block_location( std::make_unique<Point>( 0, 0 ) );
  add_block_location( std::make_unique<Point>( 0, 1 ) );
  add_block_location( std::make_unique<Point>( 1, 1 ) );
  add_block_location( std::make_unique<Point>( 2, 1 ) );
}
