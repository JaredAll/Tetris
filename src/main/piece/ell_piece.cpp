#include "ell_piece.h"

void EllPiece::determine_block_locations()
{
  add_block_location( std::make_unique<Point>( 0, 1 ) );
  add_block_location( std::make_unique<Point>( 1, 1 ) );
  add_block_location( std::make_unique<Point>( 2, 1 ) );
  add_block_location( std::make_unique<Point>( 2, 0 ) );
}
