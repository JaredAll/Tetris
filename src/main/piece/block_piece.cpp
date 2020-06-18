#include "block_piece.h"

void BlockPiece::determine_block_locations()
{
  add_block_location( std::make_unique<Point>( 0, 1 ) );
  add_block_location( std::make_unique<Point>( 0, 2 ) );
  add_block_location( std::make_unique<Point>( 1, 1 ) );
  add_block_location( std::make_unique<Point>( 1, 2 ) );
}