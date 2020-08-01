#include "tetris_piece_state.h"
#include "falling_state.h"
#include "shifting_state.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;
using std::move;

unique_ptr<TetrisPieceState> TetrisPieceState::update( InputEvent& event )
{
  unique_ptr<TetrisPieceState> next_state = determine_next_state();
  if( valid_input( event ) )
  {
    int direction_unit = determine_direction( event );
    next_state = make_unique<ShiftingState>( piece, board, direction_unit );
  }
  else if( event.down_up() )
  {
    next_state = make_unique<FallingState>( piece, board );
  }
  else if( event.enter_up() )
  {
    piece.set_falling( false );
  }
  else if( event.romeo_up() )
  {
    if( board.can_rotate( piece ) )
    {
      piece.rotate();
    }
  }
  
  return next_state;
}

int TetrisPieceState::determine_direction( InputEvent& event )
{
  int direction_unit {0};
  if( event.left_up() )
  {
    direction_unit = -1;
  }
  else if( event.right_up() )
  {
    direction_unit = 1;
  }
  return direction_unit;
}

bool TetrisPieceState::valid_input( InputEvent& event )
{
  return ( event.left_up() &&
           piece.get_current_column() > 0 &&
           board.can_shift( piece, determine_direction( event ) ) )
    || ( event.right_up() &&
         piece.get_rightmost_column() < piece.get_max_column() &&
         board.can_shift( piece, determine_direction( event ) ) );
}
