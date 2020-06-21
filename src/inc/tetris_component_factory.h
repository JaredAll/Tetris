#ifndef GAME_COMPONENT_FACTORY_H
#define GAME_COMPONENT_FACTORY_H

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "cleanup.h"
#include <iostream>
#include <vector>
#include "game_renderer.h"
#include "game_component.h"
#include "sprite.h"
#include <unistd.h>
#include <memory>
#include "sprite_config.h"
#include "piece_type.h"
#include "sprite_config.h"
#include "point.h"
#include "block.h"
#include "tetris_board.h"

class TetrisComponentFactory
{
public:
  
  TetrisComponentFactory( int height, int rows, int columns );

  std::unique_ptr<GameComponent> build_component( PieceType piece_type, GameRenderer& renderer );

private:

  std::unique_ptr<Block> initialize_block( Point& point,
                                           SpriteConfig config,
                                           GameRenderer& renderer );

  std::unique_ptr<Sprite> initialize_sprite( Point& point,
                                             SpriteConfig config,
                                             GameRenderer& renderer );

  int grid_unit_length;
  int new_piece_x;
  int new_piece_y;

};

#endif
