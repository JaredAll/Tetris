#include "game_renderer.h"
#include "SDL_render.h"
#include "easy_sdl.h"
#include "cleanup.h"

using namespace std;

GameRenderer::GameRenderer( unique_ptr<SDL_Window> win )
{
  unique_ptr<SDL_Renderer, SDL_Renderer_Destroyer> ren {
    SDL_CreateRenderer(win.release(), -1,
                       SDL_RENDERER_ACCELERATED
                       | SDL_RENDERER_PRESENTVSYNC) };
  if (!ren)
  {
    logSDLError( cout, "CreateRenderer" );
    SDL_Quit();
  }
  renderer = move( ren );
}

void GameRenderer::render( const vector< shared_ptr<GameComponent> > gameComponents )
{
  SDL_RenderClear( renderer.get() );
  for( uint i = 0; i < gameComponents.size(); i++ )
  {
    RenderComponent& renderComponent = gameComponents.at( i ) -> get_render_component();
    render( renderComponent );
  }
  SDL_RenderPresent( renderer.get() );
}

unique_ptr<SDL_Texture, SDL_Texture_Destroyer> GameRenderer::create_texture( string image_path )
{
  unique_ptr<SDL_Texture, SDL_Texture_Destroyer> texture {
    loadTexture( image_path, renderer.get() )
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

void GameRenderer::render( const RenderComponent& renderComponent )
{
  renderTexture( renderComponent.getTexture().get(),
                 renderer.get(),
                 renderComponent.getDestination().get(),
                 renderComponent.getClip().get() ); 
}
