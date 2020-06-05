#include <SDL.h>

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
};

#endif
