#ifndef JAREDALL_TETRIS_GAME_H
#define JAREDALL_TETRIS_GAME_H

#include <memory>
#include "engine.h"

class Game
{
public:

  Game( std::unique_ptr<Engine> engine );

  void play();

private:

  void initialize();

  std::unique_ptr<Engine> engine;
  std::vector<std::unique_ptr<GameComponent>> components;
  int current_piece_index;
  std::unique_ptr<TetrisComponentFactory> component_factory;

};

#endif
