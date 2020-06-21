#include "tetris_piece.h"
#include "game_component.h"
#include <algorithm>
#include <memory>

TetrisPiece::TetrisPiece()
  : GameComponent()
{
  current_row = 0;
  current_column = 5;
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
    current_row += 1;
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

int TetrisPiece::get_frames_per_update()
{
  return 30;
}

void TetrisPiece::set_grid_unit_length( int param_grid_unit_length )
{
  grid_unit_length = param_grid_unit_length;
}

int TetrisPiece::get_bottom_row()
{
  std::vector<int> bottoms;
  for( size_t i = 0; i < block_locations.size(); i++ )
  {
    bottoms.push_back( block_locations.at( i ) -> get_y() + current_row );
  }

  return *std::max_element( bottoms.begin(), bottoms.end() );
}

bool TetrisPiece::is_falling()
{
  return falling;
}

void TetrisPiece::set_falling( bool is_falling )
{
  falling = is_falling;
}

int TetrisPiece::get_current_row()
{
  return current_row;
}

int TetrisPiece::get_current_column()
{
  return current_column;
}

std::vector<std::unique_ptr<Point>>& TetrisPiece::get_block_locations()
{
  if( block_locations.empty() )
  {
    determine_block_locations();    
  }
  return block_locations;
}

void TetrisPiece::add_block_location( std::unique_ptr<Point> point )
{
  block_locations.push_back( move( point ) );
}
