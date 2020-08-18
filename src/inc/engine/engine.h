#include "cleanup.h"
#include "game_component.h"
#include "input_event.h"
#include "input_handler.h"
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

  Engine( std::vector<std::unique_ptr<GameComponent>>& components );

  ~Engine();

  void initialize( int height, int width );

  void advance();

  void quit();

  bool peek_has_updated();

  GameRenderer& get_renderer();

private:

  void render_components();

  void update_components( InputEvent& input_event );

  InputEvent& process_input();

  void maintain_time();

  std::unique_ptr<InputHandler> input_handler;
  std::vector<std::unique_ptr<GameComponent>>& components;
  std::unique_ptr<GameRenderer> renderer;
  bool should_render;
  bool should_update;
  bool has_updated;
  bool running;
  int frame_count;
};

#endif
