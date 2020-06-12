#include "tetris_component_factory.h"
#include "configurations.h"
#include "tetris_piece.h"

using namespace std;

TetrisComponentFactory::TetrisComponentFactory()
{}

unique_ptr<GameComponent> TetrisComponentFactory::build_component(
  PieceType piece_type,
  GameRenderer& renderer )
{
  
  SpriteConfig config;
  switch( piece_type )
  {
  case PieceType::jay:
    config = j_config;
    break;
  case PieceType::tee:
    config = t_config;
    break;
  case PieceType::block:
    config = block_config;
    break;
  case PieceType::bar:
    config = bar_config;
    break;
  case PieceType::ell:
    config = l_config;
    break;
  case PieceType::ess:
    config = s_config;
    break;
  case PieceType::zee:
    config = z_config;
    break;
  }

  unique_ptr<RenderComponent> render_component =
    move( initialize_sprite( 0, 0, config.image_path, renderer ) );

  return make_unique<TetrisPiece>( move( render_component ) );
}

unique_ptr<Sprite>TetrisComponentFactory::initialize_sprite( 
  uint x,
  uint y,
  string resource,
  GameRenderer& renderer )
{
  shared_ptr<SDL_Texture> sprite_texture =
    renderer.create_texture( resource );

  return make_unique<Sprite>( x, y, sprite_texture );
}
