#include "cleanup.h"
#include "game_component.h"
#include "render_component.h"
#include "game_renderer.h"
#include "tetris_component_factory.h"
#include <SDL.h>
#include <memory>

#ifndef JAREDALL_TETRIS_ENGINE
#define JAREDALL_TETRIS_ENGINE

class Engine
{
public:

  void initialize();

  void loop();

  void render();

private:

  void maintain_time();

  std::unique_ptr<GameRenderer> renderer;
  
  std::unique_ptr<TetrisComponentFactory> component_factory;

  GameComponent* current_piece;

  std::vector<std::unique_ptr<GameComponent>> pieces;
  int current_piece_index;
  bool should_render;
};

#endif
