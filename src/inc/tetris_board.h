#ifndef JARED_ALL_TETRIS_TETRIS_BOARD
#define JARED_ALL_TETRIS_TETRIS_BOARD

#include "game_component.h"
#include "tetris_piece.h"
#include <memory>

class TetrisBoard : public GameComponent
{
public:

  void update() override;

  void update( InputEvent& event ) override;

  bool accepting_input() override;

  std::vector<std::unique_ptr<RenderComponent>>& get_render_components() override;

  int get_rows();

  int get_columns();

  bool has_landed( TetrisPiece& piece );

  bool full();

  bool can_shift( TetrisPiece& piece, int direction_unit );

  bool can_rotate( TetrisPiece& piece );

  void add_piece( TetrisPiece& piece );

  ~TetrisBoard();

  TetrisBoard();

private:

  bool impact( TetrisPiece& piece );
  
  std::vector<std::vector<bool>> occupied_spaces;
  std::vector<std::unique_ptr<RenderComponent>> components;
  int rows;
  int columns;

};

#endif
