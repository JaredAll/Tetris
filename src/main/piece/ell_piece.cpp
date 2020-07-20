#include "ell_piece.h"

using std::vector;
using std::unique_ptr;

EllPiece::EllPiece() : TetrisPiece()
{
  set_block_locations( original_block_locations() );
  set_corners_to_check( original_corners() );
}

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

vector<unique_ptr<Point>> EllPiece::original_corners()
{
  vector<unique_ptr<Point>> corners;
  
  corners.push_back( std::make_unique<Point>( -1, 2 ) );
  corners.push_back( std::make_unique<Point>( 3, 2 ) );

  return corners;
}

vector<unique_ptr<Point>> EllPiece::rotate_corners()
{
  vector<unique_ptr<Point>> corners;
      
  corners.push_back( std::make_unique<Point>( -1, 3 ) );
  corners.push_back( std::make_unique<Point>( 2, 3 ) );

  return corners;
}
