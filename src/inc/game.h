#ifndef JAREDALL_TETRIS_GAME_H
#define JAREDALL_TETRIS_GAME_H

#include <memory>
#include "engine.h"

class Game
{
public:

  Game( int height, int width );

  void play();

private:

  void initialize();

  void update_components();

  void update_piece( GameComponent& component );

  void add_piece( PieceType type );

  std::unique_ptr<Engine> engine;
  std::vector<std::unique_ptr<GameComponent>> components;
  int current_piece_index;
  std::unique_ptr<TetrisComponentFactory> component_factory;
  int window_height;
  int window_width;

};

#endif
