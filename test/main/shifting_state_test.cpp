#include "bar_piece.h"
#include "catch.hpp"
#include "falling_state.h"
#include "shifting_state.h"
#include "tetris_board.h"
#include "catch2/trompeloeil.hpp"
#include "waiting_state.h"
#include "render_component_mock.h"

using std::unique_ptr;
using std::make_unique;
using trompeloeil::_;

TEST_CASE( "test shifting state" )
{
  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  unique_ptr<TetrisBoard> board = make_unique<TetrisBoard>();
  int direction_unit = 1;
  unique_ptr<ShiftingState> shifting_state = make_unique<ShiftingState>( 
    *piece, 
    *board,
    direction_unit );;

  SECTION( "test determine_next_state" )
  {
    unique_ptr<TetrisPieceState> next_state = shifting_state -> determine_next_state();
    REQUIRE( dynamic_cast<ShiftingState*>( next_state.get() ) != nullptr );
  }

  SECTION( "test update piece not landed" )
  {
    piece -> set_grid_unit_length( 1 );
    piece -> set_falling( true );

    unique_ptr<RenderComponentMock> component_mock = make_unique<RenderComponentMock>();
    REQUIRE_CALL( *component_mock, get_x() ).RETURN( 0 );
    REQUIRE_CALL( *component_mock, set_x( _ ) );

    piece -> add_render_component( move( component_mock ) );

    unique_ptr<TetrisPieceState> next_state = shifting_state -> update();

    REQUIRE( dynamic_cast<FallingState*>( next_state.get() ) != nullptr );
    REQUIRE( piece -> is_falling() );
  }

  SECTION( "test update piece landed" )
  {
    piece -> set_grid_unit_length( 1 );
    piece -> set_current_row( board -> get_rows() + 1 );
    piece -> set_falling( true );

    unique_ptr<RenderComponentMock> component_mock = make_unique<RenderComponentMock>();
    REQUIRE_CALL( *component_mock, get_x() ).RETURN( 0 );
    REQUIRE_CALL( *component_mock, set_x( _ ) );

    piece -> add_render_component( move( component_mock ) );

    unique_ptr<TetrisPieceState> next_state = shifting_state -> update();

    REQUIRE( dynamic_cast<WaitingState*>( next_state.get() ) != nullptr );
    REQUIRE_FALSE( piece -> is_falling() );
  }
}
