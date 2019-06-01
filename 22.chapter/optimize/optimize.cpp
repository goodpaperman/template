// optimize.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo> 

inline int f1(int const& r)
{
  return ++ (int&)r; 
}

inline int f2(int const& r)
{
  return r; 
}

inline int f3()
{
  return 42; 
}

int foo()
{
  int param = 0, answer = 0; 
  answer = f1(param); 
  f2(param); 
  f3(); 
  return answer + param; 
}

void goo()
{
  printf("goo() called.\n"); 
}

class MyType
{
public:
  void g() { printf("MyType::g() called.\n"); } 
}; 

typedef void GooT(); 

int _tmain(int argc, _TCHAR* argv[])
{
  printf("foo() = %d.\n", foo()); 

  goo(); 
  printf("goo type: %s.\n", typeid(goo).name()); 
  printf("GooT type: %s.\n", typeid(GooT).name()); 

  GooT* pg = goo; 
  pg(); 
  (*pg)(); 

  printf("pg type: %s.\n", typeid(pg).name()); 

  void (*pg2)() = &goo; 
  pg2(); 

  printf("pg2 type: %s.\n", typeid(pg2).name()); 

  GooT& rg = goo; 
  rg(); 

  printf("rg type: %s.\n", typeid(rg).name()); 

  void (&rg2)() = goo; 
  rg2(); 

  printf("rg2 type: %s.\n", typeid(rg2).name()); 

  void (MyType::*mfr)() = &MyType::g; 
  MyType mt; 
  (mt.*mfr)(); 

  //void (MyType::&mfr)() = MyType::g; 
	return 0;
}

