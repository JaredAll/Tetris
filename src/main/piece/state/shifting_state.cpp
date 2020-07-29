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
  TetrisPiece& piece = get_piece();
  TetrisBoard& board = get_board();

  int grid_unit_length = piece.get_grid_unit_length();

  for( auto& render_component : piece.get_render_components() )
  {
    int old_y = render_component -> get_y();
    render_component -> set_y( old_y );

    int old_x = render_component -> get_x();
    render_component -> set_x( old_x + direction_unit * grid_unit_length );
  }

  piece.set_current_column( piece.get_current_column() + direction_unit );
  piece.set_current_row( piece.get_current_row() );

  shifted = true;

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
