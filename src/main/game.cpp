#include "game.h"

Game::Game( std::unique_ptr<Engine> param_engine )
{
  engine = std::move( param_engine );
}

void Game::play()
{
  engine -> initialize();
  engine -> loop();
}
