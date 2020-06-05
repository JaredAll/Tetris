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

  std::unique_ptr<Engine> engine;

};

#endif
