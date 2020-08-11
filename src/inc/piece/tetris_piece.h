#ifndef JARED_ALL_TETRIS_TETRIS_PIECE_H
#define JARED_ALL_TETRIS_TETRIS_PIECE_H

#include "game_component.h"
#include "point.h"
#include "render_component.h"
#include <memory>

class TetrisPieceState;

class TetrisPiece : public GameComponent
{

public:

  TetrisPiece();

  virtual ~TetrisPiece() override;

  void update() override;

  void update( InputEvent& event ) override;

  bool accepting_input() override;

  std::vector<std::unique_ptr<RenderComponent>>& get_render_components() override;

  void add_render_component( std::unique_ptr<RenderComponent> render_component );

  void set_grid_unit_length( int grid_unit_length );

  int get_grid_unit_length();

  int get_bottom_row();

  int get_rightmost_column();

  bool is_falling();

  void set_falling( bool falling );

  int get_current_row();

  void set_current_row( int row );

  int get_current_column();

  void set_current_column( int column );

  int get_max_row();

  void set_max_row( int max_row );

  int get_max_column();

  void set_max_column( int max_column );

  void set_state( std::unique_ptr<TetrisPieceState> state );

  void rotate();

  std::vector<std::unique_ptr<Point>>& get_rotated_block_locations();

  std::vector<std::unique_ptr<Point>>& get_block_locations();

  void fall();

  void shift( int direction_unit );

protected:

  void set_block_locations( std::vector<std::unique_ptr<Point>> block_locations );

  void set_next_block_locations( std::vector<std::unique_ptr<Point>> block_locations );

  virtual std::vector<std::unique_ptr<Point>> original_block_locations() = 0;

  void add_block_location( std::unique_ptr<Point> point );

  std::vector<std::unique_ptr<Point>> rotate_block_locations();

private:

  int grid_unit_length;
  bool falling;
  int current_row;
  int current_column;
  int max_row;
  int max_column;
  std::vector<std::unique_ptr<Point>> current_block_locations;
  std::vector<std::unique_ptr<Point>> next_block_locations;
  std::vector<std::unique_ptr<RenderComponent>> render_components;
  std::unique_ptr<TetrisPieceState> state;
};

#endif
