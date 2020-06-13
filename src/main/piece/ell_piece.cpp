#include "ell_piece.h"

void EllPiece::determine_block_locations()
{
  add_block_location( std::make_unique<Point>( 0, 2 ) );
  add_block_location( std::make_unique<Point>( 1, 2 ) );
  add_block_location( std::make_unique<Point>( 2, 2 ) );
  add_block_location( std::make_unique<Point>( 2, 1 ) );
}
