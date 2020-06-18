#include "tetris_piece.h"
#include "game_component.h"
#include <algorithm>
#include <memory>

TetrisPiece::TetrisPiece()
  : GameComponent()
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
    for( size_t i = 0; i < render_components.size(); i++ )
    {
      int old_y = render_components.at( i ) -> get_y();
      render_components.at( i ) -> set_y( old_y + grid_unit_length );
    }
  }
}

void TetrisPiece::add_render_component( std::unique_ptr<RenderComponent> render_component )
{
  render_components.push_back( move( render_component ) );
}

std::vector<std::unique_ptr<RenderComponent>>& TetrisPiece::get_render_components()
{
  return render_components;
}

void TetrisPiece::set_grid_unit_length( int param_grid_unit_length )
{
  grid_unit_length = param_grid_unit_length;
}

int TetrisPiece::get_bottom_x()
{
  std::vector<int> bottoms;
  for( size_t i = 0; i < render_components.size(); i++ )
  {
    RenderComponent& component = *render_components.at( i );
    bottoms.push_back( component.get_y() + component.get_h() );
  }

  return *std::max_element( bottoms.begin(), bottoms.end() );
}

void TetrisPiece::set_falling( bool is_falling )
{
  falling = is_falling;
}

std::vector<std::unique_ptr<Point>>& TetrisPiece::get_block_locations()
{
  determine_block_locations();
  return block_locations;
}

void TetrisPiece::add_block_location( std::unique_ptr<Point> point )
{
  block_locations.push_back( move( point ) );
}
