// tpnm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo>

template <typename T>
class X
{
public:
  class Base
  {
  }; 

  typedef int C;
  typedef double D; 
  //enum { D }; 
}; 

template <typename T>
struct S : /*typename*/ X<T>::Base
{
public:
  S() : /*typename*/ X<T>::Base(/*typename*/ X<T>::Base()) {}
  /*typename*/ X<T> f()
  {
    //typename X<T>::C *p; 
    X<T>::C *p; 
    X<T>::D* q; 
    return X<T>(); 
  }

  /*typename*/ X<int>::C *s; 
}; 

struct U
{
  /*typename*/ X<int>::C *pc; 
}; 

template <typename T>
class Shell
{
public:
  template <int N>
  class In
  {
  public:
    template <int M>
    class Deep
    {
    public:
      virtual void f() { printf("Shell<%s>::In<%d>::Deep<%d>::f() called\n", typeid(T).name(), N, M); } 
    }; 
  }; 
}; 

template <typename T, int N>
class Weird
{
public:
  void case1(typename Shell<T>::/*template*/ In<N>::/*template*/ Deep<N>* p)
  { 
    p->f(); 
  } 

  void case2(typename Shell<T>::/*template*/ In<N>::/*template*/ Deep<N>& p)
  {
    p.f(); 
  }
}; 

class BX
{
public:
  void f(int) { printf("BX::f(int)\n"); } 
  void f(char const*) { printf("BX::f(char const*)\n"); } 
  void g() { printf("BX::g()\n"); } 
}; 

class DX : private BX
{
public:
  using BX::f; 
  BX::g; 
};

template <typename T>
class BXT
{
public:
  typedef T Mystery; 
  template <typename U>
  struct Magic 
  {
    int a; 
  }; 
}; 

template <typename T>
class DXT : private BXT<T>
{
public:
  using typename BXT<T>::Mystery; 
  using typename BXT<T>::/*template*/ Magic; 
  Mystery* p; 
  Magic<T> m; 
}; 

namespace N
{
  class X
  {
  }; 

  template <int I> void select(X*) 
  { printf("N::select(X*)\n"); }
}; 

void g(N::X* xp)
{
  //select<3>(xp); 
  N::select<3>(xp); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  S<int> s; 
  s.f(); 

  Weird<int, 10> w; 
  Shell<int>::In<10>::Deep<10> d; 
  w.case1(&d); 
  w.case2(d); 

  DX dx; 
  dx.f(1); 
  dx.f("hello"); 
  dx.g(); 

  DXT<int> dxt; 
  dxt.p = 0; 
  dxt.m.a = 0; 

  g(0); 
	return 0;
}

