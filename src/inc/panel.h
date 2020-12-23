#ifndef JAREDALL_PANEL_H
#define JAREDALL_PANEL_H

#include "component_visitor.h"
#include "game_component.h"
#include "text_box.h"
#include "tetris_component.h"
#include "game_renderer.h"

class Panel : public TetrisComponent
{
public:
  
  Panel( std::unique_ptr<TextBox> text_box, int x, int y );

  Panel( std::unique_ptr<TextBox> text_box );

  void update() override;

  void update( InputEvent& event ) override;

  bool accepting_input() override;

  void accept_renderer( GameRenderer& renderer ) override;

  std::vector<std::unique_ptr<Glyph>>& get_render_components();

  void accept( ComponentVisitor& visitor ) override;

  TextBox& get_text_box();

private:
  
  std::unique_ptr<TextBox> text_box;
  int x;
  int y;
  
};

#endif
