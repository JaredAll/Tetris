#include "tetris_piece_state.h"
#include <memory>
#include "falling_state.h"

using std::unique_ptr;
using std::make_unique;
using std::move;

unique_ptr<TetrisPieceState> TetrisPieceState::update( InputEvent& event )
{
  unique_ptr<TetrisPieceState> next_state = determine_next_state();
  if( event.left_up() || event.right_up() )
  {
    int grid_unit_length = piece.get_grid_unit_length();

    int direction_unit = determine_direction( event );
    for( auto& render_component : piece.get_render_components() )
    {
      int old_y = render_component -> get_y();
      render_component -> set_y( old_y + grid_unit_length );

      int old_x = render_component -> get_x();
      render_component -> set_x( old_x + direction_unit * grid_unit_length );
    }

    piece.set_current_column( piece.get_current_column() + direction_unit );
    piece.set_current_row( piece.get_current_row() + 1 );
    
    next_state = make_unique<FallingState>( piece );
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
