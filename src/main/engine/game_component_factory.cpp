#include "game_component_factory.h"

using namespace std;

GameComponentFactory::GameComponentFactory()
{}

unique_ptr<Sprite>GameComponentFactory::initialize_sprite(
        uint x,
        uint y,
        std::string resource,
        GameRenderer& renderer )
{
  shared_ptr<SDL_Texture> sprite_texture =
          renderer.create_texture( resource );

  return make_unique<Sprite>( x, y, sprite_texture );
}
