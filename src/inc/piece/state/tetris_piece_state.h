#ifndef JARED_ALL_TETRIS_TETRIS_PIECE_STATE
#define JARED_ALL_TETRIS_TETRIS_PIECE_STATE

#include "tetris_piece.h"

class TetrisPieceState
{
  
public:

  TetrisPieceState( TetrisPiece& param_piece )
    : piece( param_piece )
  {
  }

  virtual ~TetrisPieceState()
  {
  }

  virtual std::unique_ptr<TetrisPieceState> update() = 0;

  virtual std::unique_ptr<TetrisPieceState> determine_next_state() = 0;

  std::unique_ptr<TetrisPieceState> update( InputEvent& event );

  TetrisPiece& get_piece()
  {
    return piece;
  }

private:

  int determine_direction( InputEvent& event );

  TetrisPiece& piece;
  
};

#endif
