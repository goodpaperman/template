// deduce.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo.h> 

template <typename T>
typename T::ElementT at (T const& a, int i)
{
  return a[i]; 
}

void foo(int* p)
{
  //int x = at(p, 7); 
  //int x = at<int*>(p, 7); 
}

template <typename T>
void f(T)
{
  printf("f(%s)\n", typeid(T).name()); 
}

template <typename T>
void g(T&)
{
  printf("g(%s)\n", typeid(T).name()); 
}

template <typename T>
void f1(T*)
{
  printf("f1(%s)\n", typeid(T).name()); 
}

template <typename E, int N>
void f2(E (&) [N])
{
  printf("f2(%s[%d])\n", typeid(E).name(), N); 
}

template <typename R, typename C, typename P>
void f3(R (C::*)(P*))
{
  printf("f3(%s (%s::*)(%s*))\n", typeid(R).name(), typeid(C).name(), typeid(P).name()); 
}

class S
{
public:
  void f(double*) { } 
}; 

void g()
{
  int*** ppp = 0; 
  bool b[42]; 
  f1(ppp); 
  f2(b); 
  f3(&S::f); 
}

template <typename T>
class Q
{
public:
  typedef int X; 
}; 

template <typename T>
void f4(typename Q<T>::X x)
{
}

template <int I>
class R
{
}; 

template <int I>
void f5(R<I/*+1*/> r)
{
  printf("f5(R<%d>)\n", I); 
}

template <typename T>
void f6(int (&) [sizeof(Q<T>)])
{
}

template <int N>
class X
{
public:
  typedef int I; 
  void f(int) { } 
}; 

template <int N>
void fppm(void (X<N>::* p)(typename X<N>::I))
{
  printf("fppm(void (X<%d>::* p)(typename X<%d>::I))\n", N, N); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  int arr[10] = { 1, 2, 3, 4, 5 }; 
  foo(arr); 

  double x[20]; 
  int const seven = 7; 

  printf("x[20]: %s\n", typeid(x).name()); 
  f(x); 
  g(x); 

  printf("seven: %s\n", typeid(seven).name()); 
  f(seven); 
  g(seven); 

  printf("7: %s\n", typeid(7).name()); 
  f(7); 
  //g(7); 

  g(); 
  //f4(5); 
  f5(R<1>()); 
  //f6(arr); 
  fppm(&X<33>::f); 
	return 0;
}

