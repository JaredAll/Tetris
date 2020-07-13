#include "ell_piece.h"

using std::vector;
using std::unique_ptr;

vector<unique_ptr<Point>> EllPiece::original_block_locations()
{
  vector<unique_ptr<Point>> locations;
  
  locations.push_back( std::make_unique<Point>( 0, 1 ) );
  locations.push_back( std::make_unique<Point>( 1, 1 ) );
  locations.push_back( std::make_unique<Point>( 2, 1 ) );
  locations.push_back( std::make_unique<Point>( 2, 0 ) );

  return locations;
}

vector<unique_ptr<Point>> EllPiece::rotate_block_locations()
{
  vector<unique_ptr<Point>> locations;
  
  locations.push_back( std::make_unique<Point>( 0, 0 ) );
  locations.push_back( std::make_unique<Point>( 0, 1 ) );
  locations.push_back( std::make_unique<Point>( 0, 2 ) );
  locations.push_back( std::make_unique<Point>( 1, 2 ) );

  return locations;
}
