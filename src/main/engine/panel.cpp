#include "panel.h"

using std::unique_ptr;
using std::vector;

Panel::Panel( unique_ptr<TextBox> param_text_box )
  : text_box( move( param_text_box ) )
{
  x = 0;
  y = 0;
}

Panel::Panel( unique_ptr<TextBox> param_text_box, int param_x, int param_y )
  : text_box( move( param_text_box ) ), x( param_x ), y( param_y )
{
}


void Panel::update()
{
}

void Panel::update( InputEvent& event )
{
}

bool Panel::accepting_input()
{
  return true;
}

void Panel::accept_renderer( GameRenderer& renderer )
{
  vector<unique_ptr<Glyph>>& glyphs = text_box -> get_glyphs();

  for( int i = 0; i < glyphs.size(); i++ )
  {
    glyphs.at( i ) -> set_x( x + ( glyphs.at( i ) -> get_x() ) );
    glyphs.at( i ) -> set_y( y );
  }

  renderer.render_all( glyphs );
}

vector<unique_ptr<Glyph>>& Panel::get_render_components()
{
  return text_box -> get_glyphs();
}

void Panel::accept( ComponentVisitor& visitor )
{
  visitor.visitPanel( *this );
}

TextBox& Panel::get_text_box()
{
  return *text_box;
}
