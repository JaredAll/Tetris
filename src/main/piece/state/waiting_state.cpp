#include "waiting_state.h"
#include <iostream>
#include <memory>
#include "falling_state.h"

using std::unique_ptr;
using std::make_unique;

WaitingState::WaitingState( TetrisPiece& piece, int update_count_param )
  : TetrisPieceState( piece ), update_count( update_count_param )
{
  update_threshold = 30;
}

unique_ptr<TetrisPieceState> WaitingState::update()
{
  update_count += 1;
  return determine_next_state();
}

unique_ptr<TetrisPieceState> WaitingState::determine_next_state()
{
  unique_ptr<TetrisPieceState> next_state;
  if( update_count > update_threshold )
  {
    next_state = make_unique<FallingState>( get_piece() );
  }
  else
  {
    next_state = make_unique<WaitingState>( get_piece(), update_count );
  }

  return next_state;
}
