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
