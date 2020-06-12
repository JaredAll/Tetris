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

class TetrisComponentFactory
{
public:
  
  TetrisComponentFactory();

  std::unique_ptr<GameComponent> build_component( PieceType piece_type, GameRenderer& renderer );

  std::unique_ptr<Sprite> initialize_sprite( uint x,
                                             uint y,
                                             std::string resource,
                                             GameRenderer& renderer );
  
};

#endif
