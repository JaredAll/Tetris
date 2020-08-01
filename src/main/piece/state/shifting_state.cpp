#include "shifting_state.h"
#include "tetris_piece.h"
#include "waiting_state.h"
#include "falling_state.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

ShiftingState::ShiftingState( TetrisPiece& piece, TetrisBoard& board, int param_direction_unit )
  : TetrisPieceState( piece, board ), direction_unit( param_direction_unit )
{
  shifted = false;
}

unique_ptr<TetrisPieceState> ShiftingState::update()
{
  shifted = true;
  get_piece().shift( direction_unit );
  return determine_next_state();
}

unique_ptr<TetrisPieceState> ShiftingState::determine_next_state()
{
  unique_ptr<TetrisPieceState> next_state = make_unique<ShiftingState>(
    get_piece(), 
    get_board(),
    direction_unit );
  
  if( shifted )
  {
    if( get_board().has_landed( get_piece() ) )
    {
      get_piece().set_falling( false );
      next_state = make_unique<WaitingState>( get_piece(), get_board(), 0 );
    }
    else
    {
      next_state = make_unique<FallingState>( get_piece(), get_board() );
    }
  }
  
  return next_state;
}
