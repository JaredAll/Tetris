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

  template< typename T, typename = typename std::enable_if_t<
                          std::is_base_of<GameComponent, T>::value>>
  void render( std::vector<std::unique_ptr<T>>& components )
  {
    SDL_RenderClear( renderer.get() );

    for( auto& component : components )
    {
      for( auto& render_component : component -> get_render_components() )
      {
        render( *render_component );
      }
    }

    SDL_RenderPresent( renderer.get() );
  }

  template< typename T, typename = typename std::enable_if_t<
                          std::is_base_of<GameComponent, T>::value>>
  void render( T& game_component )
  {
    SDL_RenderClear( renderer.get() );

    std::vector<std::unique_ptr<RenderComponent>>& renderings =
      game_component.get_render_components();

    for( size_t i = 0; i < renderings.size(); i++ )
    {
      render( *renderings.at( i ) );
    }

    SDL_RenderPresent( renderer.get() );
  }

private:

  void render( const RenderComponent& renderComponent );

  std::unique_ptr<SDL_Window, SDL_Window_Destroyer> window;

  std::unique_ptr<SDL_Renderer, SDL_Renderer_Destroyer> renderer;
};

#endif
