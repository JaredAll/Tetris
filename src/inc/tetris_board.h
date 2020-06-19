#ifndef JARED_ALL_TETRIS_TETRIS_BOARD
#define JARED_ALL_TETRIS_TETRIS_BOARD

#include "game_component.h"

class TetrisBoard : public GameComponent
{
public:
  void update() override;

  std::vector<std::unique_ptr<RenderComponent>>& get_render_components() override;

  ~TetrisBoard();

  TetrisBoard();

private:

  std::vector<std::vector<bool>> occupied_spaces;
  std::vector<std::unique_ptr<RenderComponent>> components;
  int grid_unit_length;
  int rows;
  int columns;

};

#endif
