#ifndef JARED_ALL_TETRIS_BAR_H
#define JARED_ALL_TETRIS_BAR_H

#include "tetris_piece.h"
#include "point.h"

class BarPiece : public TetrisPiece
{
public:
  
  BarPiece();

protected:

  std::vector<std::unique_ptr<Point>> original_block_locations() override;

  std::vector<std::unique_ptr<Point>> rotate_block_locations() override;  
};

#endif
