#ifndef JARED_ALL_TETRIS_SHIFTING_STATE
#define JARED_ALL_TETRIS_SHIFTING_STATE

#include "tetris_piece_state.h"

class ShiftingState : public TetrisPieceState
{
public:
  
  ShiftingState( TetrisPiece& piece, TetrisBoard& board, int direction_unit );

  std::unique_ptr<TetrisPieceState> update() override;

  std::unique_ptr<TetrisPieceState> determine_next_state() override;

private:

  int direction_unit;
  bool shifted;

};

#endif
