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
  rotated = false;
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
  for( auto& block : block_locations )
  {
    bottoms.push_back( block -> get_y() + current_row );
  }

  return *std::max_element( bottoms.begin(), bottoms.end() );
}

int TetrisPiece::get_rightmost_column()
{
  std::vector<int> columns;
  for( auto& block : block_locations )
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
  rotated = !rotated;
  block_locations = original_block_locations();
  corners_to_check = original_corners();
  if( rotated )
  {
    block_locations = rotate_block_locations();
    corners_to_check = rotate_corners();
  }

  for( int i = 0; i < block_locations.size(); i++ )
  {
    render_components.at( i ) -> set_x(
      ( current_column + block_locations.at( i ) -> get_x() ) * grid_unit_length );

    render_components.at( i ) -> set_y(
      ( current_row + block_locations.at( i ) -> get_y() ) * grid_unit_length );
  }
}

vector<unique_ptr<Point>> TetrisPiece::get_rotated_block_locations()
{
  vector<unique_ptr<Point>> rotated_block_locations;
  if( rotated )
  {
    rotated_block_locations = original_block_locations();
  }
  else
  {
    rotated_block_locations = rotate_block_locations();
  }
  return rotated_block_locations;
}

vector<unique_ptr<Point>>& TetrisPiece::get_block_locations()
{
  return block_locations;
}

vector<unique_ptr<Point>> TetrisPiece::get_corners_to_check_left()
{
  return get_corners_to_check(
    []( Point& corner, Point& block ) { return corner.get_x() < block.get_x(); }
    );
}

vector<unique_ptr<Point>> TetrisPiece::get_corners_to_check_right()
{
  return get_corners_to_check(
    []( Point& corner, Point& block ) { return corner.get_x() > block.get_x(); }
    );
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

void TetrisPiece::set_block_locations( std::vector<std::unique_ptr<Point>> param_block_locations )
{
  block_locations = move( param_block_locations );
} 

void TetrisPiece::set_corners_to_check( std::vector<std::unique_ptr<Point>> corners )
{
  corners_to_check = move( corners );
} 

void TetrisPiece::add_block_location( std::unique_ptr<Point> point )
{
  block_locations.push_back( move( point ) );
}

template<typename Predicate>
vector<unique_ptr<Point>> TetrisPiece::get_corners_to_check( Predicate corner_qualifies )
{
  vector<unique_ptr<Point>> corners_to_check;
  for( auto& corner : corners_to_check )
  {
    bool corner_to_check = false;
    for( auto& block : block_locations )
    {
      if( corner_qualifies( *corner, *block ) )
      {
        corner_to_check = true;
      }
    }

    if( corner_to_check )
    {
      corners_to_check.push_back(
        make_unique<Point>( corner -> get_x(), corner -> get_y() )
        );
    }
  }
  return corners_to_check;
}
