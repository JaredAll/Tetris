#include "text_box.h"
#include "glyph_alphabet.h"

using std::move;

TextBox::TextBox( GlyphAlphabet& param_alphabet, std::string param_text )
  : alphabet( param_alphabet ), text( param_text )
{
  update_glyphs( text );
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

void TextBox::set_text( std::string param_text )
{
  text = param_text;
  update_glyphs( text );
}

void TextBox::update_glyphs( std::string text )
{
  glyphs.clear();

  int padding = 50;

  for( int i = 0; i < text.size(); i++ )
  {
    std::unique_ptr<Glyph> glyph = alphabet.get_char_as_glyph( text.at( i ) );

    glyph -> set_x( padding * i );

    glyphs.push_back( move( glyph ) );
  }
}
