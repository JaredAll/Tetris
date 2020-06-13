#ifndef JARED_ALL_TETRIS_ELL_H
#define JARED_ALL_TETRIS_ELL_H

#include "tetris_piece.h"
#include "point.h"

class EllPiece : public TetrisPiece
{
protected:

  void determine_block_locations() override;
  
};

#endif
