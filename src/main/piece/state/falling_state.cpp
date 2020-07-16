#include "falling_state.h"
#include <memory>
#include "waiting_state.h"

using std::unique_ptr;
using std::make_unique;

FallingState::FallingState( TetrisPiece& piece, TetrisBoard& board )
  : TetrisPieceState( piece, board )
{
  fallen = false;
}

unique_ptr<TetrisPieceState> FallingState::update()
{
  TetrisPiece& piece = get_piece();
  if( piece.is_falling() )
  {
    piece.fall();
  }
  fallen = true;

  return determine_next_state();
}

unique_ptr<TetrisPieceState> FallingState::determine_next_state()
{
  unique_ptr<TetrisPieceState> next_state = make_unique<FallingState>( get_piece(), get_board() );
  if( fallen )
  {
    next_state = make_unique<WaitingState>( get_piece(), get_board(), 0 );
  }
  return next_state;
}
