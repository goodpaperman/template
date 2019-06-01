// deducation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo.h> 

template <typename T, typename U>
class X
{
public:
}; 

template <typename T>
class Y
{
public:
}; 

template <typename T>
void f(X< Y<T>, Y<T> >)
{
  printf("void f(X< Y<%s>, Y<%s> >)\n", typeid(T).name(), typeid(T).name()); 
}

template <typename T>
void foo(T, T)
{
  printf("void foo(%s,%s)\n", typeid(T).name(), typeid(T).name()); 
}

void (*pf)(char, char) = &foo; 

class S
{
public:
  //operator int[20]&()
  //{
  //  static int arr[20] = { 0 }; 
  //  return arr; 
  //}

  //template <typename T, int N>
  //operator T[N]&()
  //{
  //  static T[N] arr = { 0 }; 
  //  return arr; 
  //}

  template <typename T>
  operator T()
  {
    printf("S::operator T()\n"); 
    return T(); 
  }
}; 

void g(int)
{
  printf("void g(int)\n"); 
}

template <typename T>
class B
{
}; 

template <typename T>
class D
{
}; 

template <typename T>
void f2(B<T>*)
{
  printf("void f2(B<%s>*)\n", typeid(T).name()); 
}

template <typename T>
class U
{
public:
  U(T b) : a(b) { }
private:
  T a; 
}; 

template <typename T>
void init(T* loc, T const& val = T())
{
  *loc = val; 
}

template <typename T>
void f3(T x = 42)
{
}

int _tmain(int argc, _TCHAR* argv[])
{
  f(X< Y<int>, Y<int> >()); 
  //f(X< Y<int>, Y<char> >()); 
  (*pf)('a', 'b'); 

  S s; 
  g(s); 

  D<long> dl; 
  //f2(&dl); 

  //U u(12); 
  U<int> u(12); 

  init(&u, U<int>(42)); 

  f3<int>(); 
  //f3<S>(); 
  //f3(); 
  f3(42); 
	return 0;
}

