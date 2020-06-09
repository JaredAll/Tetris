#ifndef JAREDALL_TETRIS_ENGINE_PIECE_CONFIG_H
#define JAREDALL_TETRIS_ENGINE_PIECE_CONFIG_H

#include <string>
#include <vector>

struct PieceConfig 
{
  std::string image_path;
};

PieceConfig j_config = PieceConfig { "/home/jared/Games/Tetris/resources/j.png" };

PieceConfig t_config = PieceConfig { "/home/jared/Games/Tetris/resources/t.png" };

PieceConfig block_config = PieceConfig { "/home/jared/Games/Tetris/resources/block.png" };

PieceConfig bar_config = PieceConfig { "/home/jared/Games/Tetris/resources/bar.png" };

PieceConfig l_config = PieceConfig { "/home/jared/Games/Tetris/resources/l.png" };

PieceConfig s_config = PieceConfig { "/home/jared/Games/Tetris/resources/s.png" };

PieceConfig z_config = PieceConfig { "/home/jared/Games/Tetris/resources/z.png" };

std::vector<PieceConfig> piece_configurations = { j_config,
                                                  t_config,
                                                  block_config,
                                                  bar_config,
                                                  l_config,
                                                  s_config,
                                                  z_config };
#endif
