#ifndef JARED_ALL_TETRIS_ELL_H
#define JARED_ALL_TETRIS_ELL_H

#include "tetris_piece.h"
#include "point.h"

class EllPiece : public TetrisPiece
{
public:

  EllPiece();

protected:

  std::vector<std::unique_ptr<Point>> original_block_locations() override;

  std::vector<std::unique_ptr<Point>> rotate_block_locations() override;

  std::vector<std::unique_ptr<Point>> original_corners() override;

  std::vector<std::unique_ptr<Point>> rotate_corners() override;
  
};

#endif
