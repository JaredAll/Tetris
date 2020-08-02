#include "SDL_rect.h"
#include "catch.hpp"
#include "catch2/trompeloeil.hpp"
#include "bar_piece.h"
#include "render_component.h"
#include "SDL_render.h"
#include "render_component_mock.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::move;
using trompeloeil::_;

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

  unique_ptr<RenderComponentMock> mock0 = make_unique<RenderComponentMock>();
  REQUIRE_CALL( *mock0, set_x( _ ) );
  REQUIRE_CALL( *mock0, set_y( _ ) );
  piece -> add_render_component( move( mock0 ) );

  unique_ptr<RenderComponentMock> mock1 = make_unique<RenderComponentMock>();
  REQUIRE_CALL( *mock1, set_x( _ ) );
  REQUIRE_CALL( *mock1, set_y( _ ) );
  piece -> add_render_component( move( mock1 ) );

  unique_ptr<RenderComponentMock> mock2 = make_unique<RenderComponentMock>();
  REQUIRE_CALL( *mock2, set_x( _ ) );
  REQUIRE_CALL( *mock2, set_y( _ ) );
  piece -> add_render_component( move( mock2 ) );

  unique_ptr<RenderComponentMock> mock3 = make_unique<RenderComponentMock>();
  REQUIRE_CALL( *mock3, set_x( _ ) );
  REQUIRE_CALL( *mock3, set_y( _ ) );
  piece -> add_render_component( move( mock3 ) );

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
