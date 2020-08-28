#include "bar_piece.h"
#include "jay_piece.h"
#include "tee_piece.h"
#include "block_piece.h"
#include "ell_piece.h"
#include "ess_piece.h"
#include "zee_piece.h"
#include "catch.hpp"
#include "catch2/trompeloeil.hpp"
#include "component_visitor.h"
#include "game_component.h"
#include "engine.h"

using std::unique_ptr;
using std::make_unique;
using std::vector;
using trompeloeil::_;

TEST_CASE( "test tetris component factory" )
{
  unique_ptr<TetrisBoard> board = make_unique<TetrisBoard>();
  int num_rows = 20;
  int num_columns = 10;

  int height = 500;
  int width = height / ( board -> get_rows() / board -> get_columns() );

  vector<unique_ptr<GameComponent>> empty_vector;
  unique_ptr<Engine> engine = make_unique<Engine>( empty_vector );
  engine -> initialize( height, width );

  GameRenderer& renderer = engine -> get_renderer();

  unique_ptr<TetrisComponentFactory> piece_factory =
    make_unique<TetrisComponentFactory>(
      height,
      *board );

  SECTION( "test build jay piece" )
  {
    unique_ptr<TetrisPiece> piece = piece_factory -> 
      build_component( PieceType::jay, renderer );

    REQUIRE( dynamic_cast<JayPiece*>( piece.get() ) != nullptr );
  }

  SECTION( "test build tee piece" )
  {
    unique_ptr<TetrisPiece> piece = piece_factory -> 
      build_component( PieceType::tee, renderer );

    REQUIRE( dynamic_cast<TeePiece*>( piece.get() ) != nullptr );
  }

  SECTION( "test build block piece" )
  {
    unique_ptr<TetrisPiece> piece = piece_factory -> 
      build_component( PieceType::block, renderer );

    REQUIRE( dynamic_cast<BlockPiece*>( piece.get() ) != nullptr );
  }

  SECTION( "test build bar piece" )
  {
    unique_ptr<TetrisPiece> piece = piece_factory -> 
      build_component( PieceType::bar, renderer );

    REQUIRE( dynamic_cast<BarPiece*>( piece.get() ) != nullptr );
  }

  SECTION( "test build ell piece" )
  {
    unique_ptr<TetrisPiece> piece = piece_factory -> 
      build_component( PieceType::ell, renderer );

    REQUIRE( dynamic_cast<EllPiece*>( piece.get() ) != nullptr );
  }

  SECTION( "test build ess piece" )
  {
    unique_ptr<TetrisPiece> piece = piece_factory -> 
      build_component( PieceType::ess, renderer );

    REQUIRE( dynamic_cast<EssPiece*>( piece.get() ) != nullptr );
  }

  SECTION( "test build zee piece" )
  {
    unique_ptr<TetrisPiece> piece = piece_factory -> 
      build_component( PieceType::zee, renderer );

    REQUIRE( dynamic_cast<ZeePiece*>( piece.get() ) != nullptr );
  }
}
