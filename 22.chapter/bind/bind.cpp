// bind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Binder.h" 
#include "compose.h" 
#include <string>

using std::string; 

template <typename T>
class Min
{
public:
  enum { NumParams = 2 }; 
  typedef T ReturnT; 
  typedef T Param1T; 
  typedef T Param2T; 
  ReturnT operator() (Param1T a, Param2T b)
  {
    return a < b ? a : b; 
  }
}; 

template <typename T, T b>
class Clamp : private Min<T>
{
public:
  enum { NumParams = 1 }; 
  typedef T ReturnT; 
  typedef T Param1T; 
  ReturnT operator() (Param1T a)
  {
    return Min<T>::operator ()(a, b); 
  }
}; 

bool func(string const& str, double d, float f)
{
  printf("%s: %f %s %f.\n", str.c_str(), d, d<f ? "<" : ">=", f); 
  return d<f; 
}

double binary_func(float a, double b)
{
  return a * b; 
}

bool compare(string debugstr, double v1, float v2)
{
  if(debugstr != "")
    printf("%s: %f %s %f.\n", debugstr.c_str(), v1, v1<v2 ? "<" : ">=", v2); 

  return v1<v2; 
}

void print_name_value(string name, double value)
{
  printf("%s: %f.\n", name.c_str(), value); 
}

double sub(double a, double b)
{
  return a-b; 
}

double twice(double a)
{
  return a*2; 
}

int _tmain(int argc, _TCHAR* argv[])
{
  printf("Min(1, 2) = %d.\n", Min<int>()(1, 2)); 
  printf("Clamp(1, 0) = %d.\n", Clamp<int, 0>()(1)); 

  //bind<2>(Min<int>(), 1)(2); 
  printf("Min(2, b=1) = %d.\n", bind<2>(Min<int>(), 1)(2)); 
  printf("Min(2, b=3) = %d.\n", bind<2>(Min<int>(), 3)(2)); 
  printf("Min(a = 2, 3) = %d.\n", bind<1>(Min<int>(), 2)(3)); 
  printf("Min(a = 4, 3) = %d.\n", bind<1>(Min<int>(), 4)(3)); 
  printf("Min(a = 2, b = 3) = %d.\n", bind<1>(bind<1>(Min<int>(), 2), 3)()); 

  bool result = bind<1>(func_ptr(func), "Comparing")(1.0, 2.0); 
  printf("bound function returned %d.\n", result); 

  double res = bindfp<1>(binary_func, 1.2)(1.1); 
  printf("bound function returned %f.\n", res); 

  result = bind<1>(bind<1>(bind<1>(func_ptr(func), "Comparing"), 1.1), 1.2)(); 
  printf("bound function returned %d.\n", result); 

  printf("Composition result: %f.\n", compose(func_ptr(sub), func_ptr(twice))(3.0, 7.0)); 
  printf("Binding result: %d.\n", bindfp<1>(compare, "main()->compare()")(1.02, 1.03)); 
  bindfp<1>(print_name_value, "the ultimate answer to life")(42); 
  printf("Mixing composition and binding (bind<1>): %f\n", bind<1>(compose(func_ptr(sub), func_ptr(twice)), 7.0)(3.0)); 
  printf("Mixing composition and binding (bind<2>): %f\n", bind<2>(compose(func_ptr(sub), func_ptr(twice)), 7.0)(3.0)); 
	return 0;
}

