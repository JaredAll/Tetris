#include "engine.h"
#include <memory>
#include "game.h"

int main( int argc, char* argv[] )
{
  int height = 500;
  int width = 1000;
  std::unique_ptr<Game> game { std::make_unique<Game>( height, width ) };

  game -> play();
}
