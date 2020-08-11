#include "bar_piece.h"
#include "block_piece.h"
#include "catch.hpp"
#include "ell_piece.h"
#include "ess_piece.h"
#include "jay_piece.h"
#include "tee_piece.h"
#include "zee_piece.h"
#include <memory>
#include <vector>
#include <cmath>

using std::unique_ptr;
using std::make_unique;
using std::vector;
using std::move;

TEST_CASE( "test piece block locations" )
{
  unique_ptr<TetrisPiece> piece;

  SECTION( "bar piece original" )
  {
    piece = make_unique<BarPiece>();

    vector<unique_ptr<Point>> original_locations = move( piece -> get_block_locations() );
    for( int i = 0; i < original_locations.size(); i++ )
    {
      REQUIRE( original_locations.at( i ) -> get_x() == i );
      REQUIRE( original_locations.at( i ) -> get_y() == 0 );
    }
  }

  SECTION( "bar piece rotated" )
  {
    piece = make_unique<BarPiece>();

    vector<unique_ptr<Point>> rotated_locations = move( piece -> get_rotated_block_locations() );
    for( int i = 0; i < rotated_locations.size(); i++ )
    {
      REQUIRE( rotated_locations.at( i ) -> get_x() == 0 );
      REQUIRE( rotated_locations.at( i ) -> get_y() == i );
    }
  }

  SECTION( "block piece original" )
  {
    piece = make_unique<BlockPiece>();
    
    vector<unique_ptr<Point>> original_locations = move( piece -> get_block_locations() );
    for( int i = 0; i < original_locations.size(); i++ )
    {
      REQUIRE( original_locations.at( i ) -> get_x() == floor( i / 2 ) );
      REQUIRE( original_locations.at( i ) -> get_y() == i % 2 );
    }    
  }

  SECTION( "block piece rotated" )
  {
    piece = make_unique<BlockPiece>();

    vector<unique_ptr<Point>> rotated_locations = move( piece -> get_rotated_block_locations() );
    for( int i = 0; i < rotated_locations.size(); i++ )
    {
      REQUIRE( rotated_locations.at( 0 ) -> get_x() == 1 );
      REQUIRE( rotated_locations.at( 0 ) -> get_y() == 0 );
      
      REQUIRE( rotated_locations.at( 1 ) -> get_x() == 0 );
      REQUIRE( rotated_locations.at( 1 ) -> get_y() == 0 );

      REQUIRE( rotated_locations.at( 2 ) -> get_x() == 1 );
      REQUIRE( rotated_locations.at( 2 ) -> get_y() == 1 );

      REQUIRE( rotated_locations.at( 3 ) -> get_x() == 0 );
      REQUIRE( rotated_locations.at( 3 ) -> get_y() == 1 );
    }    
  }

  SECTION( "ell piece original" )
  {
    piece = make_unique<EllPiece>();
    
    vector<unique_ptr<Point>> original_locations = move( piece -> get_block_locations() );
    
    REQUIRE( original_locations.at( 0 ) -> get_x() == 0 );
    REQUIRE( original_locations.at( 0 ) -> get_y() == 1 );

    REQUIRE( original_locations.at( 1 ) -> get_x() == 1 );
    REQUIRE( original_locations.at( 1 ) -> get_y() == 1 );

    REQUIRE( original_locations.at( 2 ) -> get_x() == 2 );
    REQUIRE( original_locations.at( 2 ) -> get_y() == 1 );

    REQUIRE( original_locations.at( 3 ) -> get_x() == 2 );
    REQUIRE( original_locations.at( 3 ) -> get_y() == 0 );
  }

  SECTION( "ell piece rotated" )
  {
    piece = make_unique<EllPiece>();
    
    vector<unique_ptr<Point>> rotated_locations = move( piece -> get_rotated_block_locations() );
    
    REQUIRE( rotated_locations.at( 0 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 0 ) -> get_y() == 0 );

    REQUIRE( rotated_locations.at( 1 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 1 ) -> get_y() == 1 );

    REQUIRE( rotated_locations.at( 2 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 2 ) -> get_y() == 2 );

    REQUIRE( rotated_locations.at( 3 ) -> get_x() == 1 );
    REQUIRE( rotated_locations.at( 3 ) -> get_y() == 2 );
  }

  SECTION( "ess piece original" )
  {
    piece = make_unique<EssPiece>();
    
    vector<unique_ptr<Point>> original_locations = move( piece -> get_block_locations() );
    
    REQUIRE( original_locations.at( 0 ) -> get_x() == 2 );
    REQUIRE( original_locations.at( 0 ) -> get_y() == 0 );

    REQUIRE( original_locations.at( 1 ) -> get_x() == 1 );
    REQUIRE( original_locations.at( 1 ) -> get_y() == 0 );

    REQUIRE( original_locations.at( 2 ) -> get_x() == 1 );
    REQUIRE( original_locations.at( 2 ) -> get_y() == 1 );

    REQUIRE( original_locations.at( 3 ) -> get_x() == 0 );
    REQUIRE( original_locations.at( 3 ) -> get_y() == 1 );
  }

  SECTION( "ess piece rotated" )
  {
    piece = make_unique<EssPiece>();
    
    vector<unique_ptr<Point>> rotated_locations = move( piece -> get_rotated_block_locations() );

    REQUIRE( rotated_locations.at( 0 ) -> get_x() == 1 );
    REQUIRE( rotated_locations.at( 0 ) -> get_y() == 2 );

    REQUIRE( rotated_locations.at( 1 ) -> get_x() == 1 );
    REQUIRE( rotated_locations.at( 1 ) -> get_y() == 1 );

    REQUIRE( rotated_locations.at( 2 ) -> get_y() == 1 );
    REQUIRE( rotated_locations.at( 2 ) -> get_x() == 0 );

    REQUIRE( rotated_locations.at( 3 ) -> get_y() == 0 );
    REQUIRE( rotated_locations.at( 3 ) -> get_x() == 0 );
  }

  SECTION( "jay piece original" )
  {
    piece = make_unique<JayPiece>();
    
    vector<unique_ptr<Point>> original_locations = move( piece -> get_block_locations() );
    
    REQUIRE( original_locations.at( 0 ) -> get_x() == 0 );
    REQUIRE( original_locations.at( 0 ) -> get_y() == 0 );

    REQUIRE( original_locations.at( 1 ) -> get_x() == 0 );
    REQUIRE( original_locations.at( 1 ) -> get_y() == 1 );

    REQUIRE( original_locations.at( 2 ) -> get_x() == 1 );
    REQUIRE( original_locations.at( 2 ) -> get_y() == 1 );

    REQUIRE( original_locations.at( 3 ) -> get_x() == 2 );
    REQUIRE( original_locations.at( 3 ) -> get_y() == 1 );
  }

  SECTION( "jay piece rotated" )
  {
    piece = make_unique<JayPiece>();
    
    vector<unique_ptr<Point>> rotated_locations = move( piece -> get_rotated_block_locations() );
    
    REQUIRE( rotated_locations.at( 0 ) -> get_x() == 1 );
    REQUIRE( rotated_locations.at( 0 ) -> get_y() == 0 );

    REQUIRE( rotated_locations.at( 1 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 1 ) -> get_y() == 0 );

    REQUIRE( rotated_locations.at( 2 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 2 ) -> get_y() == 1 );

    REQUIRE( rotated_locations.at( 3 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 3 ) -> get_y() == 2 );
  }

  SECTION( "tee piece original" )
  {
    piece = make_unique<TeePiece>();
    
    vector<unique_ptr<Point>> original_locations = move( piece -> get_block_locations() );
    
    REQUIRE( original_locations.at( 0 ) -> get_x() == 1 );
    REQUIRE( original_locations.at( 0 ) -> get_y() == 0 );

    REQUIRE( original_locations.at( 1 ) -> get_x() == 0 );
    REQUIRE( original_locations.at( 1 ) -> get_y() == 1 );

    REQUIRE( original_locations.at( 2 ) -> get_x() == 1 );
    REQUIRE( original_locations.at( 2 ) -> get_y() == 1 );

    REQUIRE( original_locations.at( 3 ) -> get_x() == 2 );
    REQUIRE( original_locations.at( 3 ) -> get_y() == 1 );
  }

  SECTION( "tee piece rotated" )
  {
    piece = make_unique<TeePiece>();
    
    vector<unique_ptr<Point>> rotated_locations = move( piece -> get_rotated_block_locations() );
    
    REQUIRE( rotated_locations.at( 0 ) -> get_x() == 1 );
    REQUIRE( rotated_locations.at( 0 ) -> get_y() == 1 );

    REQUIRE( rotated_locations.at( 1 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 1 ) -> get_y() == 0 );

    REQUIRE( rotated_locations.at( 2 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 2 ) -> get_y() == 1 );

    REQUIRE( rotated_locations.at( 3 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 3 ) -> get_y() == 2 );
  }

  SECTION( "zee piece original" )
  {
    piece = make_unique<ZeePiece>();
    
    vector<unique_ptr<Point>> original_locations = move( piece -> get_block_locations() );
    
    REQUIRE( original_locations.at( 0 ) -> get_x() == 0 );
    REQUIRE( original_locations.at( 0 ) -> get_y() == 0 );

    REQUIRE( original_locations.at( 1 ) -> get_x() == 1 );
    REQUIRE( original_locations.at( 1 ) -> get_y() == 0 );

    REQUIRE( original_locations.at( 2 ) -> get_x() == 1 );
    REQUIRE( original_locations.at( 2 ) -> get_y() == 1 );

    REQUIRE( original_locations.at( 3 ) -> get_x() == 2 );
    REQUIRE( original_locations.at( 3 ) -> get_y() == 1 );
  }

  SECTION( "zee piece rotated" )
  {
    piece = make_unique<ZeePiece>();
    
    vector<unique_ptr<Point>> rotated_locations = move( piece -> get_rotated_block_locations() );
    
    REQUIRE( rotated_locations.at( 0 ) -> get_x() == 1 );
    REQUIRE( rotated_locations.at( 0 ) -> get_y() == 0 );

    REQUIRE( rotated_locations.at( 1 ) -> get_x() == 1 );
    REQUIRE( rotated_locations.at( 1 ) -> get_y() == 1 );

    REQUIRE( rotated_locations.at( 2 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 2 ) -> get_y() == 1 );

    REQUIRE( rotated_locations.at( 3 ) -> get_x() == 0 );
    REQUIRE( rotated_locations.at( 3 ) -> get_y() == 2 );
  }

}
