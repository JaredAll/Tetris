#ifndef COMPONENT_VISITOR_H
#define COMPONENT_VISITOR_H

class TetrisPiece;

class TetrisBoard;

class ComponentVisitor
{
public:

  virtual ~ComponentVisitor() = default;

  virtual void visitTetrisPiece( TetrisPiece& piece ) = 0;

  virtual void visitTetrisBoard( TetrisBoard& board ) = 0;

};

#endif
