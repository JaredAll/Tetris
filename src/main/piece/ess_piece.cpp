#include "ess_piece.h"

using std::vector;
using std::unique_ptr;

vector<unique_ptr<Point>> EssPiece::original_block_locations()
{
  vector<unique_ptr<Point>> locations;
  
  locations.push_back( std::make_unique<Point>( 2, 0 ) );
  locations.push_back( std::make_unique<Point>( 1, 0 ) );
  locations.push_back( std::make_unique<Point>( 1, 1 ) );
  locations.push_back( std::make_unique<Point>( 0, 1 ) );

  return locations;
}

vector<unique_ptr<Point>> EssPiece::rotate_block_locations()
{
  vector<unique_ptr<Point>> locations;
  
  locations.push_back( std::make_unique<Point>( 0, 0 ) );
  locations.push_back( std::make_unique<Point>( 0, 1 ) );
  locations.push_back( std::make_unique<Point>( 1, 1 ) );
  locations.push_back( std::make_unique<Point>( 1, 2 ) );

  return locations;
}

vector<unique_ptr<Point>> EssPiece::original_corners()
{
  vector<unique_ptr<Point>> corners;
  
  corners.push_back( std::make_unique<Point>( -1, 2 ) );
  corners.push_back( std::make_unique<Point>( 2, 2 ) );
  corners.push_back( std::make_unique<Point>( 3, 1 ) );

  return corners;
}

vector<unique_ptr<Point>> EssPiece::rotate_corners()
{
  vector<unique_ptr<Point>> corners;
      
  corners.push_back( std::make_unique<Point>( -1, 2 ) );
  corners.push_back( std::make_unique<Point>( 0, 3 ) );
  corners.push_back( std::make_unique<Point>( 2, 3 ) );

  return corners;
}
