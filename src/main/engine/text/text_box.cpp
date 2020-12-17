#include "text_box.h"

TextBox::TextBox( std::vector<std::unique_ptr<Glyph>> param_glyphs )
{
  glyphs = move( param_glyphs );
}

void TextBox::update()
{
}

void TextBox::update( InputEvent& event )
{
}

bool TextBox::accepting_input()
{
  return true;
}

void TextBox::accept_renderer( GameRenderer& renderer )
{
  renderer.render_all( glyphs );
}

std::vector<std::unique_ptr<Glyph>>& TextBox::get_glyphs()
{
  return glyphs;
}
