#include "game_renderer.h"
#include "SDL_render.h"
#include "easy_sdl.h"
#include "cleanup.h"
#include "render_component.h"

using namespace std;

GameRenderer::GameRenderer( unique_ptr<SDL_Window, SDL_Window_Destroyer> win )
{
  unique_ptr<SDL_Renderer, SDL_Renderer_Destroyer> ren {
    SDL_CreateRenderer(win.get(), -1,
                       SDL_RENDERER_ACCELERATED
                       | SDL_RENDERER_PRESENTVSYNC) };
  if (!ren)
  {
    cout << "CreateRenderer failed" << endl;
    SDL_Quit();
  }
  renderer = move( ren );
  window = move( win );
}

shared_ptr<SDL_Texture> GameRenderer::create_texture( string image_path )
{
  shared_ptr<SDL_Texture> texture {
    loadTexture( image_path, renderer.get() ),
    SDL_Texture_Destroyer()
  };
  return texture;
}

shared_ptr<SDL_Texture> GameRenderer::render_letter_texture( TTF_Font* font,
                                                             char letter_singleton[],
                                                             SDL_Color color )
{
  shared_ptr<SDL_Surface> letter_surface { TTF_RenderText_Solid( font, letter_singleton, color ),
                                           SDL_Surface_Destroyer() };
  
  shared_ptr<SDL_Texture> letter_texture {
    SDL_CreateTextureFromSurface( renderer.get(), letter_surface.get() ),
    SDL_Texture_Destroyer()
  };
  
  return letter_texture;
}

void GameRenderer::render( vector<unique_ptr<GameComponent>>& components )
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

void GameRenderer::render( GameComponent& game_component )
{
  SDL_RenderClear( renderer.get() );

  vector<unique_ptr<RenderComponent>>& renderings = game_component.get_render_components();

  for( size_t i = 0; i < renderings.size(); i++ )
  {
    render( *renderings.at( i ) );
  }

  SDL_RenderPresent( renderer.get() );
}

void GameRenderer::render( const RenderComponent& renderComponent )
{
  renderTexture( renderComponent.getTexture().get(),
                 renderer.get(),
                 renderComponent.getDestination().get(),
                 renderComponent.getClip().get() );  
}
