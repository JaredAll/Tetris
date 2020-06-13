#ifndef JARED_ALL_TETRIS_TEE_H
#define JARED_ALL_TETRIS_TEE_H

#include "tetris_piece.h"
#include "point.h"

class TeePiece : public TetrisPiece
{
protected:

  void determine_block_locations() override;
  
};

#endif
