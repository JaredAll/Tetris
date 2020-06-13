#ifndef JARED_ALL_TETRIS_J_H
#define JARED_ALL_TETRIS_J_H

#include "tetris_piece.h"
#include "point.h"

class JayPiece : public TetrisPiece
{
public:

  ~JayPiece() override;

protected:

  void determine_block_locations() override;
  
};

#endif
