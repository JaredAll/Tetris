#include "catch.hpp"
#include "catch2/trompeloeil.hpp"
#include "piece_type.h"
#include "tetris_board.h"
#include "engine.h"
#include "tetris_component_factory.h"

using std::unique_ptr;
using std::make_unique;
using std::vector;

// TEST_CASE("test board piece integration")
// {
//   unique_ptr<TetrisBoard> board = make_unique<TetrisBoard>();
//   int num_rows = 20;
//   int num_columns = 10;

//   int height = 500;
//   int width = height / ( board -> get_rows() / board -> get_columns() );

//   vector<unique_ptr<GameComponent>> empty_vector;
//   unique_ptr<Engine> engine = make_unique<Engine>( empty_vector );
//   engine -> initialize( height, width );

//   GameRenderer& renderer = engine -> get_renderer();

//   unique_ptr<TetrisComponentFactory> piece_factory =
//     make_unique<TetrisComponentFactory>(
//       height,
//       *board );
// }
