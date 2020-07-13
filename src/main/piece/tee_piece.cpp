#include "tee_piece.h"

using std::vector;
using std::unique_ptr;

vector<unique_ptr<Point>> TeePiece::original_block_locations()
{
  vector<unique_ptr<Point>> locations;
  
  locations.push_back( std::make_unique<Point>( 1, 0 ) );
  locations.push_back( std::make_unique<Point>( 0, 1 ) );
  locations.push_back( std::make_unique<Point>( 1, 1 ) );
  locations.push_back( std::make_unique<Point>( 2, 1 ) );

  return locations;
}

vector<unique_ptr<Point>> TeePiece::rotate_block_locations()
{
  vector<unique_ptr<Point>> locations;

  locations.push_back( std::make_unique<Point>( 1, 1 ) );
  locations.push_back( std::make_unique<Point>( 0, 0 ) );
  locations.push_back( std::make_unique<Point>( 0, 1 ) );
  locations.push_back( std::make_unique<Point>( 0, 2 ) );

  return locations;
}
