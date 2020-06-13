#include "tetris_piece.h"
#include "game_component.h"

TetrisPiece::TetrisPiece( std::unique_ptr<RenderComponent> render_component )
  : GameComponent( move( render_component ) )
{
  falling = true;
}

TetrisPiece::~TetrisPiece()
{  
}

void TetrisPiece::update()
{
  if( falling )
  {
    int old_y = render_component -> get_y();
    render_component -> set_y( old_y + grid_unit_length ); 
  }
}

void TetrisPiece::set_grid_unit_length( int param_grid_unit_length )
{
  grid_unit_length = param_grid_unit_length;
}

int TetrisPiece::get_bottom_x()
{
  return render_component -> get_y() + render_component -> get_h();
}

void TetrisPiece::set_falling( bool is_falling )
{
  falling = is_falling;
}
