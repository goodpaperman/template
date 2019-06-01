// composefunctor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "compose.h" 
#include <cmath>
#include <cstdlib> 
#include <typeinfo> 

class Abs
{
public:
  double operator() (double v) const
  {
    return std::abs(v); 
  }

  //int a; 
}; 

class Sine
{
public:
  double operator() (double a) const 
  {
    return std::sin(a); 
  }

  //int s; 
}; 

template <typename F>
void print_values(F f)
{
  printf("sizeof(%s) = %d.\n", typeid(F).name(), sizeof(F)); 
  for(int i=-7; i<8; ++ i)
    printf("f(%d) = %f.\n", i, f(i)); 

  printf("\n"); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  printf("abs(sin(0.5)) = %f.\n", std::abs(std::sin(0.5))); 
  print_values(Abs()); 
  print_values(Sine()); 
  //print_values(Composer<Abs, Sine>(Abs(), Sine())); 
  //print_values(Composer<Sine, Abs>(Sine(), Abs())); 
  print_values(compose(Abs(), Sine())); 
  print_values(compose(Sine(), Abs())); 
  print_values(compose(compose(Abs(), Sine()), compose(Sine(), Abs()))); 
//#ifndef EBCO
  print_values(compose(Sine(), Sine())); 
  print_values(compose(compose(Sine(), Sine()), compose(Sine(), Sine()))); 
//#endif 
	return 0;
}

