#ifndef COMPONENT_VISITOR_MOCK_H
#define COMPONENT_VISITOR_MOCK_H

#include "catch.hpp"
#include "catch2/trompeloeil.hpp"
#include "component_visitor.h"
#include "tetris_piece.h"

class ComponentVisitorMock : public ComponentVisitor
{
public:
  MAKE_MOCK1( visitTetrisPiece, void( TetrisPiece& ), override );
  MAKE_MOCK1( visitTetrisBoard, void( TetrisBoard& ), override );
};

#endif
