#include "tetris_piece.h"
#include "game_component.h"

TetrisPiece::TetrisPiece( std::unique_ptr<RenderComponent> render_component )
  : GameComponent( move( render_component ) )
{
}

TetrisPiece::~TetrisPiece()
{  
}
