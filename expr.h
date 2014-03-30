#ifndef _EXPR_H_
#define _EXPR_H_


#include <string>
#include <iostream>

class ExprNode;
class Expr
{
  friend std::ostream& operator<<(std::ostream& os, const Expr& e);
public:
  Expr(int n);
  Expr(const std::string &op, Expr operand);
  Expr(const std::string &op, Expr left, Expr right);
  Expr(const Expr& e);
  Expr& operator=(const Expr& rhs);
  ~Expr();
  
private:
  ExprNode *p;
  int *use;
};

#endif
