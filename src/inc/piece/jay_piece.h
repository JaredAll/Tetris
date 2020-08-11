#ifndef JARED_ALL_TETRIS_JAY_H
#define JARED_ALL_TETRIS_JAY_H

#include "tetris_piece.h"
#include "point.h"

class JayPiece : public TetrisPiece
{
public:
  
  JayPiece();

protected:

  std::vector<std::unique_ptr<Point>> original_block_locations() override;

};

#endif
