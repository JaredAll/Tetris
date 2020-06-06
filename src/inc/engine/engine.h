#include "cleanup.h"
#include "render_component.h"
#include "game_renderer.h"
#include <SDL.h>
#include <memory>

#ifndef JAREDALL_TETRIS_ENGINE
#define JAREDALL_TETRIS_ENGINE

class Engine
{
public:

  void initialize();

  void loop();

private:

  void maintain_time();

  void render();

  std::unique_ptr<GameRenderer> renderer;
};

#endif
