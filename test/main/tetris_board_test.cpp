#include "catch.hpp"
#include "catch2/trompeloeil.hpp"
#include "component_visitor.h"
#include "piece_type.h"
#include "tetris_board.h"
#include "engine.h"
#include "tetris_component_factory.h"
#include "component_visitor_mock.h"

using std::unique_ptr;
using std::make_unique;
using std::vector;
using trompeloeil::_;

TEST_CASE( "test tetris board construction" )
{
  unique_ptr<TetrisBoard> board = make_unique<TetrisBoard>();
  int num_rows = 20;
  int num_columns = 10;

  SECTION( "verify constructor" )
  {
    REQUIRE( board -> get_rows() ==  num_rows );
    REQUIRE( board -> get_columns() ==  num_columns );
    REQUIRE( board -> get_score() == 0 );
    REQUIRE_FALSE( board -> full() );
  }

  SECTION( "test update no new score" )
  {
    board -> update();

    REQUIRE_FALSE( board -> new_score() );
  }

  SECTION( "test accepting input" )
  {
    REQUIRE_FALSE( board -> accepting_input() );
  }

  SECTION( "test tetris board accept visitor" )
  {
    unique_ptr<ComponentVisitorMock> visitor = make_unique<ComponentVisitorMock>();
    REQUIRE_CALL( *visitor, visitTetrisBoard( _ ) );

    board -> accept( *visitor );
  }
}

TEST_CASE( "test tetris board" )
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

  SECTION( "test score" )
  {    
    unique_ptr<TetrisPiece> first_piece = piece_factory -> 
      build_component( PieceType::bar, renderer );

    first_piece -> set_current_column( 0 );
    first_piece -> set_current_row( 19 );

    unique_ptr<TetrisPiece> second_piece = piece_factory -> 
      build_component( PieceType::bar, renderer );

    second_piece -> set_current_column( 4 );
    second_piece -> set_current_row( 19 );

    unique_ptr<TetrisPiece> third_piece = piece_factory -> 
      build_component( PieceType::block, renderer );

    third_piece -> set_current_column( 8 );
    third_piece -> set_current_row( 18 );

    board -> add_piece( *first_piece );
    board -> add_piece( *second_piece );
    board -> add_piece( *third_piece );

    board -> update();
    REQUIRE( board -> new_score() );
  }

  SECTION( "test has landed" )
  {
    unique_ptr<TetrisPiece> bar_piece = piece_factory -> 
      build_component( PieceType::bar, renderer );

    REQUIRE_FALSE( board -> has_landed( *bar_piece ) );

    bar_piece -> set_current_column( 0 );
    bar_piece -> set_current_row( 19 );

    REQUIRE( board -> has_landed( *bar_piece ) );

    board -> add_piece( *bar_piece );

    unique_ptr<TetrisPiece> new_bar_piece = piece_factory -> 
      build_component( PieceType::bar, renderer );

    new_bar_piece -> set_current_column( 0 );
    new_bar_piece -> set_current_row( 18 );

    REQUIRE( board -> has_landed( *new_bar_piece ) );
  }

  SECTION( "test full" )
  {
    unique_ptr<TetrisPiece> full_piece = piece_factory -> 
      build_component( PieceType::bar, renderer );

    full_piece -> set_current_column( 5 );
    full_piece -> set_current_row( 0 );

    board -> add_piece( *full_piece );

    REQUIRE( board -> full() );
  }
  
  SECTION( "test can shift true" )
  {
    unique_ptr<TetrisPiece> can_shift_right_piece = piece_factory -> 
      build_component( PieceType::bar, renderer );

    can_shift_right_piece -> set_current_column( 0 );
    can_shift_right_piece -> set_current_row( 10 );

    REQUIRE( board -> can_shift( *can_shift_right_piece, 1 ) );
  }

  SECTION( "test can shift false" )
  {
    unique_ptr<TetrisPiece> can_shift_right_piece = piece_factory -> 
      build_component( PieceType::bar, renderer );

    can_shift_right_piece -> set_current_column( 0 );
    can_shift_right_piece -> set_current_row( 10 );

    REQUIRE_FALSE( board -> can_shift( *can_shift_right_piece, -1 ) );
  }

  SECTION( "test can rotate true" )
  {
    unique_ptr<TetrisPiece> can_rotate_piece = piece_factory -> 
      build_component( PieceType::bar, renderer );

    can_rotate_piece -> set_current_column( 0 );
    can_rotate_piece -> set_current_row( 10 );

    REQUIRE( board -> can_rotate( *can_rotate_piece ) );
  }

  SECTION( "test can rotate false" )
  {
    unique_ptr<TetrisPiece> cannot_rotate_piece = piece_factory -> 
      build_component( PieceType::zee, renderer );

    cannot_rotate_piece -> set_current_column( 9 );
    cannot_rotate_piece -> set_current_row( 10 );

    REQUIRE_FALSE( board -> can_rotate( *cannot_rotate_piece ) );
  }
}
