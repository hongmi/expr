
all : main

main : main.o
	g++ -o main *.o	
main.o : ExprNode.cpp expr.cpp main.cpp
	g++ -c -g ExprNode.cpp expr.cpp main.cpp
