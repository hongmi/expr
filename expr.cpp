#include "expr.h"
#include "ExprNode.h"

std::ostream& operator<<(std::ostream& os, const Expr& e) 
{
  e.p->print(os);
  return os;
}


Expr::Expr(int n)
  : use(new int(1))
  , p(new AtomNode(n))
{
}

Expr::Expr(const std::string &op, Expr operand)
  : use(new int(1))
  , p(new UnaryNode(op, operand))
{
}
Expr::Expr(const std::string &op, Expr left, Expr right)
  : use(new int(1))
  , p(new BinaryNode(op, left, right))
{
}
Expr::Expr(const Expr& e)
  : p(e.p), use(e.use)
{
  ++*use;
}
Expr& Expr::operator=(const Expr& rhs)
{
  ++*rhs.use;
  if (--*use == 0) {
    delete p;
    delete use;
  }
  p = rhs.p;
  return *this;
}
Expr::~Expr() {
  if(--*use == 0) {
    delete p;
    delete use;
  }
}
  
