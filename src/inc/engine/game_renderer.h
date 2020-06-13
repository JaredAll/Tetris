#ifndef JAREDALL_TETRIS_GAME_RENDERER_H
#define JAREDALL_TETRIS_GAME_RENDERER_H

#include "cleanup.h"
#include "game_component.h"
#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <SDL_image.h>

class GameRenderer
{
public:
  
  GameRenderer( std::unique_ptr<SDL_Window, SDL_Window_Destroyer> win );

  std::shared_ptr<SDL_Texture> create_texture( std::string image_path );

  std::shared_ptr<SDL_Texture> render_letter_texture( TTF_Font* font,
                                      char letter_singleton[],
                                      SDL_Color color);
  
  void render( GameComponent& renderComponent );


private:

  void render( const RenderComponent& renderComponent );

  std::unique_ptr<SDL_Window, SDL_Window_Destroyer> window;

  std::unique_ptr<SDL_Renderer, SDL_Renderer_Destroyer> renderer;
};

#endif
