#include "block_piece.h"
#include <memory>
#include <vector>

using std::vector;
using std::unique_ptr;

vector<unique_ptr<Point>> BlockPiece::original_block_locations()
{
  vector<unique_ptr<Point>> locations;
  
  locations.push_back( std::make_unique<Point>( 0, 0 ) );
  locations.push_back( std::make_unique<Point>( 0, 1 ) );
  locations.push_back( std::make_unique<Point>( 1, 0 ) );
  locations.push_back( std::make_unique<Point>( 1, 1 ) );

  return locations;
}

vector<unique_ptr<Point>> BlockPiece::rotate_block_locations()
{
  return original_block_locations();
}
