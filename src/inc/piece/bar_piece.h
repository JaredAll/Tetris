#ifndef JARED_ALL_TETRIS_BAR_H
#define JARED_ALL_TETRIS_BAR_H

#include "tetris_piece.h"
#include "point.h"

class BarPiece : public TetrisPiece
{
protected:

  void determine_block_locations() override;
  
};

#endif
