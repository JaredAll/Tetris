#ifndef JARED_ALL_TETRIS_FALLING_STATE
#define JARED_ALL_TETRIS_FALLING_STATE

#include "tetris_piece_state.h"

class FallingState : public TetrisPieceState
{
public:
  
  FallingState( TetrisPiece& piece );

  std::unique_ptr<TetrisPieceState> update() override;

  std::unique_ptr<TetrisPieceState> determine_next_state() override;

private:
  bool fallen;
};

#endif
