#include "tetris_board.h"
#include "game_component.h"

using std::vector;
using std::unique_ptr;

void TetrisBoard::update()
{
  
}

vector<unique_ptr<RenderComponent>>& TetrisBoard::get_render_components()
{
  return components;
}

TetrisBoard::~TetrisBoard()
{  
}

TetrisBoard::TetrisBoard()
  : GameComponent{}
{
  rows = 20;
  columns = 10;
  grid_unit_length = 50;

  for( size_t row = 0; row < rows; row++ )
  {
    occupied_spaces.push_back( {} );
    for( size_t column = 0; column < columns; column++ )
    {
      occupied_spaces.at( row ).push_back( false );
    }
  }
}
