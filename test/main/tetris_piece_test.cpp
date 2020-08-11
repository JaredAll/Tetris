#include "SDL_rect.h"
#include "catch.hpp"
#include "catch2/trompeloeil.hpp"
#include "bar_piece.h"
#include "render_component.h"
#include "SDL_render.h"
#include "render_component_mock.h"
#include "tetris_piece.h"
#include <memory>
#include <vector>

using std::unique_ptr;
using std::make_unique;
using std::move;
using std::vector;
using trompeloeil::_;
using trompeloeil::expectation;

vector<unique_ptr<expectation>> set_rotate_expectations( unique_ptr<TetrisPiece>& piece )
{
  vector<unique_ptr<expectation>> expectations;

  unique_ptr<RenderComponentMock> mock0 = make_unique<RenderComponentMock>();
  expectations.push_back( move( NAMED_REQUIRE_CALL( *mock0, set_x( _ ) ) ) );
  expectations.push_back( move( NAMED_REQUIRE_CALL( *mock0, set_y( _ ) ) ) );
  piece -> add_render_component( move( mock0 ) );

  unique_ptr<RenderComponentMock> mock1 = make_unique<RenderComponentMock>();
  expectations.push_back( move( NAMED_REQUIRE_CALL( *mock1, set_x( _ ) ) ) );
  expectations.push_back( move( NAMED_REQUIRE_CALL( *mock1, set_y( _ ) ) ) );
  piece -> add_render_component( move( mock1 ) );

  unique_ptr<RenderComponentMock> mock2 = make_unique<RenderComponentMock>();
  expectations.push_back( move( NAMED_REQUIRE_CALL( *mock2, set_x( _ ) ) ) );
  expectations.push_back( move( NAMED_REQUIRE_CALL( *mock2, set_y( _ ) ) ) );
  piece -> add_render_component( move( mock2 ) );

  unique_ptr<RenderComponentMock> mock3 = make_unique<RenderComponentMock>();
  expectations.push_back( move( NAMED_REQUIRE_CALL( *mock3, set_x( _ ) ) ) );
  expectations.push_back( move( NAMED_REQUIRE_CALL( *mock3, set_y( _ ) ) ) );
  piece -> add_render_component( move( mock3 ) );

  return expectations;
}

TEST_CASE( "test constructor" )
{
  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  REQUIRE( piece -> get_current_row() == 0 );
  REQUIRE( piece -> get_current_column() == 5 );
  REQUIRE( piece -> is_falling() );
  REQUIRE( piece -> get_render_components().empty() );

  int num_bar_blocks = 4;
  REQUIRE( piece -> get_block_locations().size() ==  num_bar_blocks);
}

TEST_CASE( "test accepting_input()" )
{
  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();

  SECTION("accepting_input() true")
  {
    piece -> set_falling( true );
  
    REQUIRE( piece -> accepting_input() );
  }

  SECTION("accepting_input() false")
  {
    piece -> set_falling( false );
  
    REQUIRE_FALSE( piece -> accepting_input() );
  }  
}

TEST_CASE( "determine block locations" )
{
  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  int num_bar_blocks = 4;

  SECTION( "test get_bottom_row" )
  {
    int bar_bottom_row = 0;
    REQUIRE( piece -> get_bottom_row() == bar_bottom_row );
  }

  SECTION( "test get_rightmost_column" )
  {
    int current_column = piece -> get_current_column();

    REQUIRE( piece -> get_rightmost_column() == num_bar_blocks + current_column );
  }
}

TEST_CASE( "determine block locations rotated" )
{
  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  piece -> set_grid_unit_length( 1 );
  int num_bar_blocks = 4;

  vector<unique_ptr<expectation>> expectations = set_rotate_expectations( piece );  

  piece -> rotate();

  SECTION( "test get_bottom_row rotated" )
  {
    REQUIRE( piece -> get_bottom_row() == num_bar_blocks - 1 );
  }

  SECTION( "test get_rightmost_column rotated" )
  {
    REQUIRE( piece -> get_rightmost_column() == piece -> get_current_column() + 1 );
  }
}

TEST_CASE( "test get_rotated_block_locations" )
{
  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();

  SECTION( "piece in original configuration" )
  {
    vector<unique_ptr<Point>>& block_locations = piece -> get_rotated_block_locations();
    for( int i = 0; i < block_locations.size(); i++ )
    {
      REQUIRE(block_locations.at( i ) -> get_x() == 0 );
      REQUIRE(block_locations.at( i ) -> get_y() == i );
    }
  }

  SECTION( "piece in rotated configuration" )
  {
    piece -> set_grid_unit_length( 1 );
    int num_bar_blocks = 4;

    vector<unique_ptr<expectation>> expectations = set_rotate_expectations( piece );

    piece -> rotate();

    vector<unique_ptr<Point>>& block_locations = piece -> get_rotated_block_locations();
    for( int i = 0; i < block_locations.size(); i++ )
    {
      REQUIRE(block_locations.at( num_bar_blocks - i - 1 ) -> get_x() == i );
      REQUIRE(block_locations.at( i ) -> get_y() == 0 );
    }
  }
}

TEST_CASE( "test fall" )
{
  int grid_unit_length = 1;
  int current_component_y = 1;
  unique_ptr<RenderComponentMock> render_component = make_unique<RenderComponentMock>();

  REQUIRE_CALL( *render_component, get_y()).RETURN( 1 );
  REQUIRE_CALL( *render_component, set_y( current_component_y + grid_unit_length ) );

  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  piece -> add_render_component( move( render_component ) );
  piece -> set_grid_unit_length( grid_unit_length );

  int old_row = piece -> get_current_row();

  piece -> fall();
  
  REQUIRE( piece -> get_current_row() == old_row + 1 );
}

TEST_CASE( "test shift" )
{
  int grid_unit_length = 5;
  int current_component_x = 5;
  unique_ptr<RenderComponentMock> render_component = make_unique<RenderComponentMock>();

  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  piece -> set_grid_unit_length( grid_unit_length );
  int old_column = piece -> get_current_column();

  SECTION( "test shift left" )
  {
    int direction_unit = -1;

    REQUIRE_CALL( *render_component, get_x()).RETURN( current_component_x );
    REQUIRE_CALL(
      *render_component,
      set_x( current_component_x + direction_unit * grid_unit_length )
      );

    piece -> add_render_component( move( render_component ) );    
    
    piece -> shift( direction_unit );

    REQUIRE( piece -> get_current_column() == old_column + direction_unit );
  }

  SECTION( "test shift right" )
  {
    int direction_unit = 1;

    REQUIRE_CALL( *render_component, get_x()).RETURN( current_component_x );
    REQUIRE_CALL(
      *render_component,
      set_x( current_component_x + direction_unit * grid_unit_length )
      );

    piece -> add_render_component( move( render_component ) );

    piece -> shift( direction_unit );

    REQUIRE( piece -> get_current_column() == old_column + direction_unit );
  }

}
