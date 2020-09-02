#include "SDL_rect.h"
#include "catch.hpp"
#include "catch2/trompeloeil.hpp"
#include "bar_piece.h"
#include "component_visitor_mock.h"
#include "render_component.h"
#include "SDL_render.h"
#include "tetris_piece.h"
#include <memory>
#include <vector>
#include "tetris_board.h"
#include "engine.h"

using std::unique_ptr;
using std::make_unique;
using std::move;
using std::vector;
using trompeloeil::_;
using trompeloeil::expectation;

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

TEST_CASE( "test accept visitor" )
{
  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  unique_ptr<ComponentVisitorMock> visitor = make_unique<ComponentVisitorMock>();
  
  REQUIRE_CALL( *visitor, visitTetrisPiece( _ ) );

  piece -> accept( *visitor );
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
  unique_ptr<TetrisBoard> board = make_unique<TetrisBoard>();
  int num_rows = 20;
  int num_columns = 10;

  int height = 500;
  int width = height / ( board -> get_rows() / board -> get_columns() );

  unique_ptr<Engine> engine = make_unique<Engine>();
  engine -> initialize( height, width );

  GameRenderer& renderer = engine -> get_renderer();

  unique_ptr<TetrisComponentFactory> piece_factory =
    make_unique<TetrisComponentFactory>(
      height,
      *board );

  unique_ptr<TetrisPiece> piece = piece_factory -> build_component( PieceType::bar, renderer );
    
  piece -> set_grid_unit_length( 1 );
  int num_bar_blocks = 4;

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
  unique_ptr<TetrisBoard> board = make_unique<TetrisBoard>();
  int num_rows = 20;
  int num_columns = 10;

  int height = 500;
  int width = height / ( board -> get_rows() / board -> get_columns() );

  unique_ptr<Engine> engine = make_unique<Engine>();
  engine -> initialize( height, width );

  GameRenderer& renderer = engine -> get_renderer();

  unique_ptr<TetrisComponentFactory> piece_factory =
    make_unique<TetrisComponentFactory>(
      height,
      *board );

  unique_ptr<TetrisPiece> piece = piece_factory -> build_component( PieceType::bar, renderer );

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

  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  piece -> set_grid_unit_length( grid_unit_length );

  int old_row = piece -> get_current_row();

  piece -> fall();
  
  REQUIRE( piece -> get_current_row() == old_row + 1 );
}

TEST_CASE( "test shift" )
{
  int grid_unit_length = 5;
  int current_component_x = 5;

  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  piece -> set_grid_unit_length( grid_unit_length );
  int old_column = piece -> get_current_column();

  SECTION( "test shift left" )
  {
    int direction_unit = -1;

    piece -> shift( direction_unit );

    REQUIRE( piece -> get_current_column() == old_column + direction_unit );
  }

  SECTION( "test shift right" )
  {
    int direction_unit = 1;

    piece -> shift( direction_unit );

    REQUIRE( piece -> get_current_column() == old_column + direction_unit );
  }

}
