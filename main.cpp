#include "expr.h"


int main(int argc, char* argv[])
{

  Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
  std::cout << t << std::endl;
  t = Expr("*", t, t);
  std::cout << t << std::endl;
  return 0;
  

}
