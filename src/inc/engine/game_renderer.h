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

  void render( const std::vector< std::shared_ptr<GameComponent> > gameComponents );

  std::unique_ptr<SDL_Texture, SDL_Texture_Destroyer> create_texture( std::string image_path );

  std::shared_ptr<SDL_Texture> render_letter_texture( TTF_Font* font,
                                      char letter_singleton[],
                                      SDL_Color color);

private:

  std::unique_ptr<SDL_Window, SDL_Window_Destroyer> window;

  std::unique_ptr<SDL_Renderer, SDL_Renderer_Destroyer> renderer;

  void render( const RenderComponent& renderComponent );
};

#endif
