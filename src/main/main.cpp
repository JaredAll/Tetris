#include "engine.h"
#include <memory>
#include "game.h"

int main( int argc, char* argv[] )
{
  std::unique_ptr<Engine> engine{ new Engine() };
  std::unique_ptr<Game> game { new Game( std::move( engine ) ) };

  game -> play();
}
