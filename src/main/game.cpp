#include "game.h"
#include "piece_type.h"

Game::Game( std::unique_ptr<Engine> param_engine )
{
  engine = std::move( param_engine );
}

void Game::play()
{
  engine -> initialize();
  initialize();

  while( true )
  {
    engine -> advance( components );  
  }
}

void Game::initialize()
{
  component_factory = std::make_unique<TetrisComponentFactory>();

  engine -> get_renderer();

  components.push_back(
    move(
      component_factory -> build_component( PieceType::jay,
                                            engine -> get_renderer() ) )
    );
}
