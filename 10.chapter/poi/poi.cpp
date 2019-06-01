// poi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo>

class MyInt
{
public:
  MyInt(int i) : i(i) { }
  int i; 
}; 

MyInt operator- (MyInt const& rhs)
{
  return MyInt(-rhs.i); 
}

bool operator> (MyInt const& lhs, MyInt const& rhs)
{
  return rhs.i < lhs.i; 
}

//typedef MyInt Int; 
typedef int Int; 

template <typename T>
void f(T i)
{
  if(i > 0)
    g(-i); 
}

void g(Int i)
{
  //printf("%d\n", i.i); 
  printf("%d\n", i); 
  f<Int>(i); 
}

template <typename T>
class S
{
public:
  T m; 
}; 

unsigned long h()
{
  return (unsigned long) sizeof(S<int>); 
}

template <typename T>
class U
{
public: 
  typedef int I; 
  U() { printf("U<%s>\n", typeid(T).name()); } 
}; 

template <typename T>
void foo()
{
  printf("foo<%s>()\n", typeid(T).name()); 
  U<char>::I var1 = 41; 
  typename U<T>::I var2 = 42; 
  U<char> var3; 
  U<T> var4; 
}

int _tmain(int argc, _TCHAR* argv[])
{
  g(10); 
  printf("%d\n", h()); 

  foo<double>(); 
	return 0;
}

