#ifndef JARED_ALL_TETRIS_TETRIS_BOARD
#define JARED_ALL_TETRIS_TETRIS_BOARD

#include "block.h"
#include "tetris_component.h"
#include "tetris_piece.h"
#include <memory>

class TetrisBoard : public TetrisComponent
{
public:

  void update() override;

  void update( InputEvent& event ) override;

  void accept( ComponentVisitor& visitor ) override;

  bool accepting_input() override;

  void accept_renderer( GameRenderer& renderer ) override;

  std::vector<std::unique_ptr<Block>>& get_render_components();

  int get_rows();

  int get_columns();

  bool has_landed( TetrisPiece& piece );

  bool full();

  bool can_shift( TetrisPiece& piece, int direction_unit );

  bool can_rotate( TetrisPiece& piece );

  void add_piece( TetrisPiece& piece );

  int score();

  int get_score();

  bool new_score();

  ~TetrisBoard();

  TetrisBoard();

private:

  bool impact( TetrisPiece& piece );

  bool has_landed( Block& block );

  std::vector<int> determine_full_rows();

  void eliminate_full_rows( std::vector<int> full_rows );

  void update_blocks( std::vector<int> full_rows );

  void sort_blocks_by_row();

  std::vector<std::vector<bool>> occupied_spaces;
  std::vector<std::unique_ptr<Block>> components;
  int rows;
  int columns;
  int current_score;
  bool score_updated;

};

#endif
