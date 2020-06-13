#ifndef JARED_ALL_TETRIS_TETRIS_PIECE_H
#define JARED_ALL_TETRIS_TETRIS_PIECE_H

#include "game_component.h"

class TetrisPiece : public GameComponent
{

public:

  TetrisPiece( std::unique_ptr<RenderComponent> render_component );

  ~TetrisPiece();

  void update();

  void set_grid_unit_length( int grid_unit_length );

  int get_bottom_x();

  void set_falling( bool falling );

private:
  
  int grid_unit_length;

  bool falling;
};

#endif
