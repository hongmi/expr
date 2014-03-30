#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

#include "expr.h"

class ExprNode
{
  friend std::ostream& operator<<(std::ostream&, const Expr&);
  friend class Expr;
protected:
  virtual ~ExprNode(){}
  virtual void print(std::ostream&) const = 0;
};


class AtomNode : public ExprNode
{
  friend class Expr;
public:
  AtomNode(int n) : v(n){}

protected:
  void print(std::ostream& os) const {
    os << v;
  }
  
private:
  int v;
};

class UnaryNode : public ExprNode
{
  friend class Expr;
public:
  UnaryNode(const std::string& oper, Expr node) : op(oper), operand(node){}
protected:
  void print(std::ostream& os) const {
    os << "(" << op << operand << ")";
  }
  
private:
  std::string op;
  Expr operand;
};


class BinaryNode : public ExprNode
{
  friend class Expr;
public:
  BinaryNode(const std::string &oper, Expr l, Expr r) : op(oper), left(l), right(r){}

protected:
  void print(std::ostream &os) const {
    os << "(" << left << op << right << ")";
  }
  
private:
  Expr left;
  Expr right;
  std::string op;
};


#endif
