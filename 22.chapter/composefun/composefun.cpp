// composefun.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "compose.h" 
#include "functionptr.h" 
#include <cmath>
#include <cstdlib> 
#include <typeinfo> 

#define FUNCTORT
#ifdef FUNCTORT

template <typename T>
class Abs
{
public:
  enum { NumParams = 1 }; 
  typedef T ReturnT;
  typedef T Param1T; 
  T operator() (T v) const
  {
    return std::abs(v); 
  }
}; 

template <typename T>
class Sine
{
public:
  enum { NumParams = 1 }; 
  typedef T ReturnT; 
  typedef T Param1T; 
  T operator() (T a) const 
  {
    return std::sin(a); 
  }
}; 

#else 

class Abs
{
public:
  enum { NumParams = 1 }; 
  typedef double ReturnT;
  typedef double Param1T; 
  double operator() (double v) const
  {
    return std::abs(v); 
  }
}; 

class Sine
{
public:
  enum { NumParams = 1 }; 
  typedef double ReturnT; 
  typedef double Param1T; 
  double operator() (double a) const 
  {
    return std::sin(a); 
  }
}; 

#endif 

template <typename F>
void print_values(F f)
{
  printf("sizeof(%s) = %d.\n", typeid(F).name(), sizeof(F)); 
  for(int i=-7; i<8; ++ i)
    printf("f(%d) = %f.\n", i, f(i)); 

  printf("\n"); 
}

double add(double a, double b)
{ return a + b; } 

double twice(double a)
{ return a * 2; } 

int _tmain(int argc, _TCHAR* argv[])
{
  printf("abs(sin(0.5)) = %f.\n", std::abs(std::sin(0.5))); 
#ifdef FUNCTORT
  print_values(Abs<double>()); 
  print_values(Sine<double>()); 
  print_values(compose(Abs<double>(), Sine<double>())); 
  print_values(compose(Sine<double>(), Abs<double>())); 
  print_values(compose(compose(Abs<double>(), Sine<double>()), compose(Sine<double>(), Abs<double>()))); 
  print_values(compose(Sine<double>(), Sine<double>())); 
  print_values(compose(compose(Sine<double>(), Sine<double>()), compose(Sine<double>(), Sine<double>()))); 
#else 
  print_values(Abs()); 
  print_values(Sine()); 
  print_values(compose(Abs(), Sine())); 
  print_values(compose(Sine(), Abs())); 
  print_values(compose(compose(Abs(), Sine()), compose(Sine(), Abs()))); 
  print_values(compose(Sine(), Sine())); 
  print_values(compose(compose(Sine(), Sine()), compose(Sine(), Sine()))); 
#endif 

  printf("compute (20+7)*2 = %f.\n", compose(func_ptr(add), func_ptr(twice))(20, 7)); 
#ifdef FUNCTORT
  printf("compute sin((20+7)*2) = %f.\n", compose(compose(func_ptr(add), func_ptr(twice)), Sine<double>())(20, 7)); 
  printf("compute abs(sin((20+7)*2)) = %f.\n", compose(compose(compose(func_ptr(add), func_ptr(twice)), Sine<double>()), Abs<double>())(20, 7)); 
#else 
  printf("compute sin((20+7)*2) = %f.\n", compose(compose(func_ptr(add), func_ptr(twice)), Sine())(20, 7)); 
  printf("compute abs(sin((20+7)*2)) = %f.\n", compose(compose(compose(func_ptr(add), func_ptr(twice)), Sine()), Abs())(20, 7)); 
#endif 
	return 0;
}


