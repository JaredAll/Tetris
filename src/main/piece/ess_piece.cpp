#include "ess_piece.h"

using std::vector;
using std::unique_ptr;

EssPiece::EssPiece() : TetrisPiece()
{
  set_block_locations( original_block_locations() );
  set_next_block_locations( rotate_block_locations() );
}

vector<unique_ptr<Point>> EssPiece::original_block_locations()
{
  vector<unique_ptr<Point>> locations;
  
  locations.push_back( std::make_unique<Point>( 2, 0 ) );
  locations.push_back( std::make_unique<Point>( 1, 0 ) );
  locations.push_back( std::make_unique<Point>( 1, 1 ) );
  locations.push_back( std::make_unique<Point>( 0, 1 ) );

  return locations;
}
