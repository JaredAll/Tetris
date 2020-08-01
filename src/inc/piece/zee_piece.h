#ifndef JARED_ALL_TETRIS_ZEE_H
#define JARED_ALL_TETRIS_ZEE_H

#include "tetris_piece.h"
#include "point.h"

class ZeePiece : public TetrisPiece
{
public:

  ZeePiece();

protected:

  std::vector<std::unique_ptr<Point>> original_block_locations() override;

  std::vector<std::unique_ptr<Point>> rotate_block_locations() override;

};

#endif
