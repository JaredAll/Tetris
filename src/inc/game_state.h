#ifndef JAREDALL_GAME_STATE
#define JAREDALL_GAME_STATE

struct GameState 
{
  int current_piece_index;
  int window_height;
  int window_width;
  bool should_update;
  int score;
  bool intro;
};

#endif
