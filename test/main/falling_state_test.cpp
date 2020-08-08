#include "bar_piece.h"
#include "catch.hpp"
#include "falling_state.h"
#include "tetris_board.h"
#include "catch2/trompeloeil.hpp"
#include "waiting_state.h"
#include "render_component_mock.h"
#include <type_traits>

using std::unique_ptr;
using std::make_unique;
using trompeloeil::_;

TEST_CASE( "test falling state" )
{
  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  unique_ptr<TetrisBoard> board = make_unique<TetrisBoard>();
  unique_ptr<FallingState> falling_state = make_unique<FallingState>( *piece, *board );;

  SECTION( "test determine next state")
  {
    unique_ptr<TetrisPieceState> next_state = falling_state -> determine_next_state();
    REQUIRE( dynamic_cast<FallingState*>( next_state.get() ) != nullptr );
  }

  SECTION( "test update piece falling" )
  {
    piece -> set_falling( true );
    piece -> set_grid_unit_length( 1 );
    
    unique_ptr<RenderComponentMock> component_mock = make_unique<RenderComponentMock>();
    REQUIRE_CALL( *component_mock, get_y() ).RETURN( 0 );
    REQUIRE_CALL( *component_mock, set_y( _ ) );

    piece -> add_render_component( move( component_mock ) );

    unique_ptr<TetrisPieceState> next_state = falling_state -> update();

    REQUIRE( dynamic_cast<WaitingState*>( next_state.get() ) != nullptr );
    REQUIRE( piece -> get_current_row() == 1 );
  }

  SECTION( "test update piece not falling" )
  {
    piece -> set_falling( false );
    
    unique_ptr<TetrisPieceState> next_state = falling_state -> update();

    REQUIRE( dynamic_cast<WaitingState*>( next_state.get() ) != nullptr );
    REQUIRE( piece -> get_current_row() == 0 );
  }
}
