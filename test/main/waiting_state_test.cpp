#include "bar_piece.h"
#include "catch.hpp"
#include "falling_state.h"
#include "tetris_board.h"
#include "catch2/trompeloeil.hpp"
#include "waiting_state.h"

using std::unique_ptr;
using std::make_unique;
using trompeloeil::_;

TEST_CASE( "test waiting state" )
{
  unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();
  unique_ptr<TetrisBoard> board = make_unique<TetrisBoard>();
  unique_ptr<WaitingState> waiting_state = make_unique<WaitingState>(
    *piece,
    *board,
    0);

  SECTION( "test determine next state" )
  {
    unique_ptr<TetrisPieceState> next_state = waiting_state -> determine_next_state();
    REQUIRE( dynamic_cast<WaitingState*>( next_state.get() ) != nullptr );
  }

  SECTION( "test update" )
  {
    for( int update_count = 0; update_count < 29; update_count++ )
    {
      waiting_state -> update();
    }
    unique_ptr<TetrisPieceState> next_state = waiting_state -> determine_next_state();
    REQUIRE( dynamic_cast<WaitingState*>( next_state.get() ) != nullptr );
    
    next_state = waiting_state -> update();
    REQUIRE( dynamic_cast<FallingState*>( next_state.get() ) != nullptr );
  }
}
