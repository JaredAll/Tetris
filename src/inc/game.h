#ifndef JAREDALL_TETRIS_GAME_H
#define JAREDALL_TETRIS_GAME_H

#include <memory>
#include "engine.h"
#include "input_handler.h"
#include "tetris_board.h"
#include "game_state.h"

class ComponentVisitor;

class Engine;

class Game
{
public:

  Game( int height, std::unique_ptr<TetrisBoard> board );

  void play();

private:

  friend class TetrisVisitor;

  void update_components();

  void add_piece();

  void transfer_piece_to_board( TetrisPiece& piece );

  std::unique_ptr<InputHandler> input_handler;
  std::unique_ptr<Engine> engine;
  std::vector<std::unique_ptr<TetrisComponent>> components;
  std::unique_ptr<TetrisComponentFactory> component_factory;
  std::unique_ptr<ComponentVisitor> visitor;
  TetrisBoard& board;
  std::vector<PieceType> types;
  GameState state;
};

#endif
