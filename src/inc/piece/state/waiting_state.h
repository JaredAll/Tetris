#ifndef JARED_ALL_TETRIS_WAITING_STATE
#define JARED_ALL_TETRIS_WAITING_STATE

#include "tetris_piece_state.h"

class WaitingState : public TetrisPieceState
{
public:
  
  WaitingState( TetrisPiece& piece, TetrisBoard& board, int update_count );

  std::unique_ptr<TetrisPieceState> update() override;

  std::unique_ptr<TetrisPieceState> determine_next_state() override;

private:
  
  int update_count;
  int update_threshold;

};

#endif
