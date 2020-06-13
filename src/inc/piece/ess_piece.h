#ifndef JARED_ALL_TETRIS_ESS_H
#define JARED_ALL_TETRIS_ESS_H

#include "tetris_piece.h"
#include "point.h"

class EssPiece : public TetrisPiece
{
protected:

  void determine_block_locations() override;
  
};

#endif
