#ifndef JARED_ALL_TETRIS_TETRIS_PIECE_STATE
#define JARED_ALL_TETRIS_TETRIS_PIECE_STATE

#include "tetris_piece.h"
#include "tetris_board.h"

class TetrisPieceState
{
  
public:

  TetrisPieceState( TetrisPiece& param_piece, TetrisBoard& param_board )
    : piece( param_piece ), board( param_board )
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

  TetrisBoard& get_board()
  {
    return board;
  }

  bool valid_input( InputEvent& event );

private:

  int determine_direction( InputEvent& event );

  TetrisPiece& piece;

  TetrisBoard& board;
};

#endif
