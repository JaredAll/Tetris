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

  void initialize( int height, int width );

  void advance( std::vector<std::unique_ptr<GameComponent>>& components );

  bool peek_has_updated();

  GameRenderer& get_renderer();

private:

  void render( std::vector<std::unique_ptr<GameComponent>>& components );

  void update( std::vector<std::unique_ptr<GameComponent>>& components );

  void maintain_time();

  std::unique_ptr<GameRenderer> renderer;
  bool should_render;
  bool should_update;
  bool has_updated;
  int frame_count;
};

#endif
