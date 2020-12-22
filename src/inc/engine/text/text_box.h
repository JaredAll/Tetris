#ifndef JAREDALL_TETRIS_TEXT_BOX
#define JAREDALL_TETRIS_TEXT_BOX

#include "game_component.h"
#include "game_renderer.h"
#include "glyph.h"
#include "glyph_alphabet.h"

class TextBox : public GameComponent
{
public:

  TextBox( GlyphAlphabet& alphabet, std::string text );

  void update() override;

  void update( InputEvent& event ) override;

  bool accepting_input() override;

  void accept_renderer( GameRenderer& renderer ) override;

  void set_text( std::string text );

  std::vector<std::unique_ptr<Glyph>>& get_glyphs();

private:

  void update_glyphs( std::string text );

  std::string text;
  std::vector<std::unique_ptr<Glyph>> glyphs;
  GlyphAlphabet& alphabet;

};

#endif
