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

  void advance( std::vector<std::unique_ptr<GameComponent>>& components );

  GameRenderer& get_renderer();

private:

  void render( std::vector<std::unique_ptr<GameComponent>>& components );

  void maintain_time();

  std::unique_ptr<GameRenderer> renderer;
  bool should_render;
};

#endif
