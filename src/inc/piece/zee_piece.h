#ifndef JARED_ALL_TETRIS_ZEE_H
#define JARED_ALL_TETRIS_ZEE_H

#include "tetris_piece.h"
#include "point.h"

class ZeePiece : public TetrisPiece
{
protected:

  void determine_block_locations() override;
  
};

#endif
