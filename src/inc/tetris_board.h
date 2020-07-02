#ifndef JARED_ALL_TETRIS_TETRIS_BOARD
#define JARED_ALL_TETRIS_TETRIS_BOARD

#include "game_component.h"
#include "tetris_piece.h"

class TetrisBoard
{
public:

  int get_rows();

  int get_columns();

  bool has_landed( TetrisPiece& piece );

  void add_piece( TetrisPiece& piece );

  ~TetrisBoard();

  TetrisBoard();

private:

  bool impact( TetrisPiece& piece );
  
  std::vector<std::vector<bool>> occupied_spaces;
  std::vector<std::unique_ptr<RenderComponent>> components;
  int rows;
  int columns;

};

#endif
