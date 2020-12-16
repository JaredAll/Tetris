#ifndef GAME_COMPONENT_FACTORY_H
#define GAME_COMPONENT_FACTORY_H

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "cleanup.h"
#include <iostream>
#include <vector>
#include "game_renderer.h"
#include "panel.h"
#include "sprite.h"
#include <unistd.h>
#include <memory>
#include "sprite_config.h"
#include "piece_type.h"
#include "sprite_config.h"
#include "point.h"
#include "block.h"
#include "tetris_board.h"
#include "tetris_piece.h"

class TetrisComponentFactory
{
public:
  
  TetrisComponentFactory( int height, TetrisBoard& board );

  std::unique_ptr<TetrisPiece> build_component( PieceType piece_type, GameRenderer& renderer );

  std::unique_ptr<Panel> build_panel( std::string text,
                                      std::shared_ptr<TTF_Font> font,
                                      GameRenderer& renderer );

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
  TetrisBoard& board;
};

#endif
