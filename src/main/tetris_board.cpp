#include "tetris_board.h"
#include "block.h"
#include "game_component.h"
#include "render_component.h"
#include <typeinfo>
#include <algorithm>

using std::vector;
using std::unique_ptr;

void TetrisBoard::update()
{
  current_score = score();
  if( current_score != 0 )
  {
    score_updated = true;
  }
}

void TetrisBoard::update( InputEvent& event )
{
}

void TetrisBoard::accept( ComponentVisitor& visitor )
{
  visitor.visitTetrisBoard( *this );
}

bool TetrisBoard::accepting_input()
{
  return false;
}

void TetrisBoard::accept_renderer( GameRenderer& renderer )
{
  renderer.render_all( components );
}

vector<unique_ptr<Block>>& TetrisBoard::get_render_components()
{
  return components;
}

int TetrisBoard::get_rows()
{
  return rows;
}

int TetrisBoard::get_columns()
{
  return columns;
}

bool TetrisBoard::has_landed( TetrisPiece& piece )
{
  bool landed = false;
  if( impact( piece ) || piece.get_bottom_row() >= rows - 1 )
  {
    landed = true;
  }

  return landed;
}

bool TetrisBoard::full()
{
  bool full { false };
  int col { 0 };
  while( !full && col < columns )
  {
    full = occupied_spaces.at( 0 ).at( col );
    ++col;
  }
  return full;
}

bool TetrisBoard::can_shift( TetrisPiece& piece, int direction_unit )
{
  vector<unique_ptr<Point>>& block_points = piece.get_block_locations();
  
  bool can_shift = true;
  for( auto& point : block_points )
  {
    int x_to_check = point -> get_x() + piece.get_current_column() + direction_unit;
    int y_to_check = point -> get_y() + piece.get_current_row();
    if( x_to_check > -1 && x_to_check < ( columns ) && y_to_check < ( rows ))
    {
      if( occupied_spaces.at( y_to_check ).at( x_to_check ) )
      {
        can_shift = false;
      }
    }
    else
    {
      can_shift = false;
    }
  }

  return can_shift;
}

bool TetrisBoard::can_rotate( TetrisPiece& piece )
{
  vector<unique_ptr<Point>>& rotated_block_points = piece.get_rotated_block_locations();
  bool rotatable = true;
  for( auto& point : rotated_block_points )
  {
    int x_to_check = point -> get_x() + piece.get_current_column();
    int y_to_check = point -> get_y() + piece.get_current_row();
    if(
      !( ( x_to_check >= 0 && x_to_check < columns ) && ( y_to_check >= 0 && y_to_check < rows ) )
      || ( occupied_spaces.at( y_to_check ).at( x_to_check ) )
      )
    {
      rotatable = false;
    }
  }
  return rotatable;
}

void TetrisBoard::add_piece( TetrisPiece& piece )
{
  int piece_current_row = piece.get_current_row();
  int piece_current_column = piece.get_current_column();

  vector<unique_ptr<Point>>& block_locations = piece.get_block_locations();
  vector<unique_ptr<Block>>& blocks = piece.get_render_components();
  for( size_t i = 0; i < block_locations.size(); i++ )
  {
    auto& point = block_locations.at( i );
    
    int occupied_x = point -> get_x() + piece_current_column;
    int occupied_y = point -> get_y() + piece_current_row;

    occupied_spaces
      .at( occupied_y )
      .at( occupied_x ) = true;

    Block& block = *blocks.at( i );
    block.set_column( occupied_x );
    block.set_row( occupied_y );
    components.push_back( move( blocks.at( i ) ) );
  }
}

int TetrisBoard::score()
{
  vector<int> full_rows = determine_full_rows();
  eliminate_full_rows( full_rows );
  update_blocks( full_rows );

  return 10 * full_rows.size();
}

int TetrisBoard::get_score()
{
  score_updated = false;
  return current_score;
}

bool TetrisBoard::new_score()
{
  return score_updated;
}

TetrisBoard::~TetrisBoard()
{  
}

TetrisBoard::TetrisBoard()
{
  score_updated = false;
  rows = 20;
  columns = 10;
  current_score = 0;

  for( size_t row = 0; row < rows; row++ )
  {
    occupied_spaces.push_back( {} );
    for( size_t column = 0; column < columns; column++ )
    {
      occupied_spaces.at( row ).push_back( false );
    }
  }
}

bool TetrisBoard::impact( TetrisPiece& piece )
{
  bool collided = false;
  int point_index = 0;
  auto& points = piece.get_block_locations();
  while( !collided && point_index < points.size() )
  {
    int point_next_row = points.at( point_index ) -> get_y() + piece.get_current_row() + 1;
    int point_column = points.at( point_index ) -> get_x() + piece.get_current_column();

    if( point_next_row < rows )
    {
      collided = occupied_spaces
        .at( point_next_row )
        .at( point_column );
    }
    ++point_index;
  }
  
  return collided;
}

bool TetrisBoard::has_landed( Block& block )
{
  bool landed = false;
  bool impact = false;
  
  int block_next_row = block.get_row() + 1;
  int block_column = block.get_column();
  if( block_next_row < rows )
  {
    impact = occupied_spaces.at( block_next_row ).at( block_column );
  }

  if( impact || block.get_row() >= rows - 1 )
  {
    landed = true;
  }
  return landed;
}

vector<int> TetrisBoard::determine_full_rows()
{
  vector<int> full_rows;
  for( size_t row = 0; row < occupied_spaces.size(); row++ )
  {
    bool full_row = true;
    for( bool square_occupied : occupied_spaces.at( row ) )
    {
      if( !square_occupied )
      {
        full_row = false;
      }
    }
    
    if( full_row )
    {
      full_rows.push_back( row );
    }
  }
  return full_rows;
}

void TetrisBoard::eliminate_full_rows( vector<int> full_rows )
{
  vector<unique_ptr<Block>> new_components;
  for( auto& block : components )
  {
    vector<int>::iterator iterator = std::find( 
      full_rows.begin(), 
      full_rows.end(), 
      block -> get_row() );

    if( iterator == full_rows.end() )
    {
      new_components.push_back( move( block ) );
    }
    else
    {
      occupied_spaces.at( block -> get_row() ).at( block -> get_column() ) = false;
    }
  }
  components = move( new_components );
}

void TetrisBoard::update_blocks( std::vector<int> full_rows )
{  
  for( auto& block : components )
  {
    for( int row : full_rows )
    {
      if( block -> get_row() < row )
      {
        occupied_spaces.at( block -> get_row() ).at( block -> get_column() ) = false;
        block -> fall();  
      }
    }
    occupied_spaces.at( block -> get_row() ).at( block -> get_column() ) = true;
  }
}
