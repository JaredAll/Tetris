#ifndef VISITOR_COMPONENT_VISITOR_H
#define VISITOR_COMPONENT_VISITOR_H

class Block;

class RenderComponentVisitor
{
public:

  virtual ~RenderComponentVisitor() = default;

  virtual void visitBlock( Block& block ) = 0;

};

#endif
