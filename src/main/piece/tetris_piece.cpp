#include "tetris_piece.h"
#include "game_component.h"
#include "input_event.h"
#include "waiting_state.h"
#include <algorithm>
#include <memory>

using std::make_unique;
using std::vector;
using std::unique_ptr;

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
  state = state -> update();
}

void TetrisPiece::update( InputEvent& input_event )
{
  state = state -> update( input_event );
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
  for( auto& block : current_block_locations )
  {
    bottoms.push_back( block -> get_y() + current_row );
  }

  return *std::max_element( bottoms.begin(), bottoms.end() );
}

int TetrisPiece::get_rightmost_column()
{
  std::vector<int> columns;
  for( auto& block : current_block_locations )
  {
    columns.push_back( block -> get_x() + current_column + 1 );
  }
  
  return *std::max_element( columns.begin(), columns.end() );
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

int TetrisPiece::get_max_row()
{
  return max_row;
}

void TetrisPiece::set_max_row( int row )
{
  max_row = row;
}

int TetrisPiece::get_max_column()
{
  return max_column;
}

void TetrisPiece::set_max_column( int column )
{
  max_column = column;
}

void TetrisPiece::set_state( unique_ptr<TetrisPieceState> param_state )
{
  state = move( param_state );
}

void TetrisPiece::rotate()
{
  current_block_locations = move( next_block_locations );

  next_block_locations = move( rotate_block_locations() );

  for( int i = 0; i < current_block_locations.size(); i++ )
  {
    render_components.at( i ) -> set_x(
      ( current_column + current_block_locations.at( i ) -> get_x() ) * grid_unit_length );

    render_components.at( i ) -> set_y(
      ( current_row + current_block_locations.at( i ) -> get_y() ) * grid_unit_length );
  }
}

vector<unique_ptr<Point>>& TetrisPiece::get_rotated_block_locations()
{
  return next_block_locations;
}

vector<unique_ptr<Point>>& TetrisPiece::get_block_locations()
{
  return current_block_locations;
}

void TetrisPiece::fall()
{
  for( auto& render_component : render_components )
  {
    int old_y = render_component -> get_y();
    render_component -> set_y( old_y + grid_unit_length );
  }
  current_row += 1;
}

void TetrisPiece::shift( int direction_unit )
{
  for( auto& render_component : render_components )
  {
    int old_x = render_component -> get_x();
    render_component -> set_x( old_x + direction_unit * grid_unit_length );
  }

  current_column += direction_unit;
}

void TetrisPiece::set_block_locations( std::vector<std::unique_ptr<Point>> param_block_locations )
{
  current_block_locations = move( param_block_locations );
}

void TetrisPiece::set_next_block_locations( vector<unique_ptr<Point>> param_block_locations )
{
  next_block_locations = move( param_block_locations );
} 

void TetrisPiece::add_block_location( std::unique_ptr<Point> point )
{
  current_block_locations.push_back( move( point ) );
}

vector<unique_ptr<Point>> TetrisPiece::rotate_block_locations()
{
  int minimum_x = 0;
  vector<unique_ptr<Point>> rotated_block_locations;
  for( auto& point : current_block_locations )
  {
    int new_x = -1 * point -> get_y();
    int new_y = point -> get_x();
    unique_ptr<Point> new_point = make_unique<Point>( new_x, new_y );

    rotated_block_locations.push_back( move( new_point ) );
    if( new_x < minimum_x )
    {
      minimum_x = new_x;
    }
  }

  if( minimum_x < 0 )
  {
    int right_shift = abs( minimum_x );
    for( auto& point : rotated_block_locations )
    {
      point -> set_x( point -> get_x() + right_shift );
    }
  }

  return move( rotated_block_locations );
}
