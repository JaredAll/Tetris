#ifndef JAREDALL_TETRIS_GAME_H
#define JAREDALL_TETRIS_GAME_H

#include <memory>
#include "engine.h"
#include "tetris_board.h"

class Engine;

class Game
{
public:

  Game( int height );

  void play();

private:

  void update_components();

  void update_piece( GameComponent& component );

  void add_piece();

  std::unique_ptr<Engine> engine;
  std::vector<std::unique_ptr<GameComponent>> components;
  std::unique_ptr<TetrisComponentFactory> component_factory;
  std::unique_ptr<TetrisBoard> board;
  int current_piece_index;
  int window_height;
  int window_width;
  std::vector<PieceType> types;
  bool should_update;
};

#endif
