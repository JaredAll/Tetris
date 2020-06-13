#ifndef JARED_ALL_TETRIS_TETRIS_PIECE_H
#define JARED_ALL_TETRIS_TETRIS_PIECE_H

#include "game_component.h"
#include "point.h"
#include <memory>

class TetrisPiece : public GameComponent
{

public:

  TetrisPiece();

  virtual ~TetrisPiece() override;

  void update() override;

  void set_grid_unit_length( int grid_unit_length );

  int get_bottom_x();

  void set_falling( bool falling );

  std::vector<std::unique_ptr<Point>>& get_block_locations();

protected:

  virtual void determine_block_locations() = 0;

  void add_block_location( std::unique_ptr<Point> point );

private:
  
  int grid_unit_length;
  bool falling;
  int pivot_x;
  int pivot_y;
  std::vector<std::unique_ptr<Point>> block_locations;
  
};

#endif
