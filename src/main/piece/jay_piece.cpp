#include "jay_piece.h"
#include "tetris_piece.h"
#include <memory>

JayPiece::~JayPiece()
{
}

void JayPiece::determine_block_locations()
{
  add_block_location( std::make_unique<Point>( 0, 1 ) );
  add_block_location( std::make_unique<Point>( 0, 2 ) );
  add_block_location( std::make_unique<Point>( 1, 2 ) );
  add_block_location( std::make_unique<Point>( 2, 2 ) );
}
