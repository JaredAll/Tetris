#include "engine.h"
#include <memory>
#include "game.h"
#include "tetris_board.h"

int main( int argc, char* argv[] )
{
  int height = 500;
  std::unique_ptr<TetrisBoard> board = std::make_unique<TetrisBoard>();
  std::unique_ptr<Game> game { std::make_unique<Game>( height, move( board ) ) };

  game -> play();
}
