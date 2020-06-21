#include "ess_piece.h"

void EssPiece::determine_block_locations()
{
  add_block_location( std::make_unique<Point>( -1, 0 ) );
  add_block_location( std::make_unique<Point>( -2, 0 ) );
  add_block_location( std::make_unique<Point>( -2, 1 ) );
  add_block_location( std::make_unique<Point>( -3, 1 ) );
}
