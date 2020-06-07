#include "engine.h"
#include <memory>
#include "game.h"

int main( int argc, char* argv[] )
{
  std::unique_ptr<Engine> engine { std::make_unique<Engine>() };
  std::unique_ptr<Game> game { std::make_unique<Game>( std::move( engine ) ) };

  game -> play();
}
