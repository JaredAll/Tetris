#ifndef TETRIS_BOARD_BLOCK_VISITOR_H
#define TETRIS_BOARD_BLOCK_VISITOR_H

#include "game.h"
#include "tetris_board.h"
#include "tetris_piece.h"
#include "component_visitor.h"
#include "board_block_operation.h"
#include <memory>

class TetrisBoardBlockVisitor : public RenderComponentVisitor
{
public:

  TetrisBoardBlockVisitor( TetrisBoard& board );

  void visitBlock( Block& block ) override;

  void set_to_initialize( int occupied_x, int occupied_y );

  void set_to_fall( std::vector<int> full_rows );

  void set_to_eliminate( std::vector<std::unique_ptr<RenderComponent>>& new_components,
                         std::unique_ptr<RenderComponent>& component );

private:

  TetrisBoard& board;
  BoardBlockOperation operation;
  int occupied_x;
  int occupied_y;
  std::vector<int> full_rows;
  std::vector<std::unique_ptr<RenderComponent>>& new_components;
  std::unique_ptr<RenderComponent>& component;
  
};

#endif
