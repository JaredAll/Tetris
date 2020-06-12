#ifndef JARED_ALL_TETRIS_TETRIS_PIECE_H
#define JARED_ALL_TETRIS_TETRIS_PIECE_H

#include "game_component.h"

class TetrisPiece : public GameComponent
{

public:

  TetrisPiece( std::unique_ptr<RenderComponent> render_component );

  ~TetrisPiece();

};

#endif
