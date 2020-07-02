#include "tetris_piece.h"
#include "game_component.h"
#include "input_event.h"
#include "waiting_state.h"
#include <algorithm>
#include <memory>

using std::make_unique;

TetrisPiece::TetrisPiece()
  : GameComponent()
{
  current_row = 0;
  current_column = 5;
  falling = true;
  state = make_unique<WaitingState>( *this, 0 );
}

TetrisPiece::~TetrisPiece()
{  
}

void TetrisPiece::update()
{
  state = state -> update();
}

void TetrisPiece::update( InputEvent& input_event )
{
  int delta_x = determine_delta_x( input_event );
  for( size_t i = 0; i < render_components.size(); i++ )
  {
    int old_y = render_components.at( i ) -> get_y();
    render_components.at( i ) -> set_y( old_y + grid_unit_length );

    int old_x = render_components.at( i ) -> get_x();
    render_components.at( i ) -> set_x( old_x + delta_x );
  }

  if( delta_x > 0 )
  {
    current_column += 1;
  }
  else if( delta_x < 0 )
  {
    current_column -= 1;
  }
  
  current_row += 1;  
}

bool TetrisPiece::accepting_input()
{
  return falling;
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

int TetrisPiece::get_frames_per_input()
{
  return 15;
}

void TetrisPiece::set_grid_unit_length( int param_grid_unit_length )
{
  grid_unit_length = param_grid_unit_length;
}

int TetrisPiece::get_grid_unit_length()
{
  return grid_unit_length;
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

void TetrisPiece::set_current_row( int param_row )
{
  current_row = param_row;
}

int TetrisPiece::get_current_column()
{
  return current_column;
}

void TetrisPiece::set_current_column( int column )
{
  current_column = column;
}

std::vector<std::unique_ptr<Point>>& TetrisPiece::get_block_locations()
{
  if( block_locations.empty() )
  {
    determine_block_locations();    
  }
  return block_locations;
}

int TetrisPiece::determine_delta_x( InputEvent& input_event )
{
  int delta_x = 0;
  if( input_event.get_input() == InputType::right )
  {
    delta_x = grid_unit_length;
  }
  else if( input_event.get_input() == InputType::left )
  {
    delta_x = -1 * grid_unit_length;
  }
  return delta_x;
}

void TetrisPiece::add_block_location( std::unique_ptr<Point> point )
{
  block_locations.push_back( move( point ) );
}
