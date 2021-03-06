#ifndef JARED_ALL_TETRIS_TEE_H
#define JARED_ALL_TETRIS_TEE_H

#include "tetris_piece.h"
#include "point.h"

class TeePiece : public TetrisPiece
{
public:

  TeePiece();

protected:

  std::vector<std::unique_ptr<Point>> original_block_locations() override;

};

#endif
