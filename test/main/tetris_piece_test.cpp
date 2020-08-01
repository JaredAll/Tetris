#define CATCH_CONFIG_MAIN
#include <memory>
#include "catch2.h"
#include "bar_piece.h"

using std::unique_ptr;
using std::make_unique;

unique_ptr<TetrisPiece> piece = make_unique<BarPiece>();

TEST_CASE( "test accepting_input() true when falling" )
{
  piece -> set_falling( true );
  
  REQUIRE( piece -> accepting_input() );
}

TEST_CASE( "test accepting_input() false when not falling" )
{
  piece -> set_falling( false );
  
  REQUIRE( !piece -> accepting_input() );
}
