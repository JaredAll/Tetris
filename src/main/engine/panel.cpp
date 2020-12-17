#include "panel.h"

using std::unique_ptr;

Panel::Panel( unique_ptr<TextBox> param_text_box )
  : text_box( move( param_text_box ) )
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
  text_box -> accept_renderer( renderer );
}

std::vector<std::unique_ptr<Glyph>>& Panel::get_render_components()
{
  return text_box -> get_glyphs();
}

void Panel::accept( ComponentVisitor& visitor )
{
}
