#include "falling_state.h"
#include <memory>
#include "waiting_state.h"

using std::unique_ptr;
using std::make_unique;

FallingState::FallingState( TetrisPiece& piece )
  : TetrisPieceState( piece )
{
}

unique_ptr<TetrisPieceState> FallingState::update()
{
  TetrisPiece& piece = get_piece();
  if( piece.is_falling() )
  {
    for( size_t i = 0; i < piece.get_render_components().size(); i++ )
    {
      int old_y = piece.get_render_components().at( i ) -> get_y();
      piece.get_render_components().at( i ) -> set_y( old_y + piece.get_grid_unit_length() );
    }
    piece.set_current_row( piece.get_current_row() + 1 );
  }

  return make_unique<WaitingState>( piece, 0 );
}
