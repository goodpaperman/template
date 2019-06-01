// funcid.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iso646.h> 

template <typename T>
inline T const& max(T const& a, T const& b)
{
  return a < b ? b : a; 
}

namespace BigMath
{
  class BigNumber
  {
  public:
    int low; 
    int high; 
  }; 

  bool operator<(BigNumber const& lhs, BigNumber const& rhs)
  {
    return lhs.low < rhs.low || lhs.high < rhs.high; 
  }
}; 

using BigMath::BigNumber; 

void g(BigNumber const& a, BigNumber const& b)
{
  //BigNumber x = (max)(a, b); 
  BigNumber x = ::max(a, b); 
  printf("max = %d.%d\n", x.low, x.high); 
}

namespace X
{
  //template <typename T> void f(T) { }
  void f(int) 
  { printf("X::f(int) called\n"); } 
}; 

namespace N
{
  using namespace X; 
  enum E { e1 }; 
  void f(E)
  { printf("N::f(N::E) called\n"); } 
}; 

void f(int)
{ printf("::f(int) called\n"); } 

class D
{
public:
  friend void foo1();
  //friend void foo1() { printf("foo1\n"); } 
  friend void foo3(D const&); 
}; 

void h(D *p)
{
  foo1(); 
  foo3(*p); 
}

//void foo();
template <typename T>
class C
{
public:
  friend void foo1(); 
  friend void foo2(C<int> const&); 
}; 

void g(C<int>* p)
{
  foo1(); 
  foo2(*p); 
}

void foo1() { printf("C friend foo1()\n"); }
void foo2(C<int> const&) 
{ printf("C friend foo2(C<int> const&)\n"); }
void foo3(D const&)
{ printf("D friend foo3(D const&)\n"); } 

int _tmain(int argc, _TCHAR* argv[])
{
  int x = 1 and 2; 
  printf("x = %d\n", x); 

  BigNumber a, b; 
  a.low = 1; 
  a.high = 2; 
  b.low = 2; 
  b.high = 1; 
  g(a, b); 

  ::f(N::e1); 
  f(N::e1); 

  ::f(1); 
  f(1); 

  C<int> cint; 
  g(&cint); 

  D d; 
  h(&d); 
	return 0;
}

