#ifndef JAREDALL_TETRIS_TEXT_BOX
#define JAREDALL_TETRIS_TEXT_BOX

#include "game_component.h"
#include "game_renderer.h"
#include "glyph.h"

class TextBox : public GameComponent
{
public:

  TextBox( std::vector<std::unique_ptr<Glyph>> glyphs );

  void update() override;

  void update( InputEvent& event ) override;

  bool accepting_input() override;

  void accept_renderer( GameRenderer& renderer ) override;

  std::vector<std::unique_ptr<Glyph>>& get_glyphs();

private:

  std::vector<std::unique_ptr<Glyph>> glyphs;

};

#endif
