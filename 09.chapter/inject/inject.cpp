// inject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int C; 

class C
{
private:
  int i[2]; 

public:
  static int f() 
  { return sizeof(C); }
}; 

int f()
{
  return sizeof(C); 
}

template <template <typename> class TT>
class X
{
}; 

template <typename T> 
class D
{
  D* a; 
  D<void>* b; 
  //X<D> c; 
  //X<::D> c; 
  X< ::D> c; 
}; 

template <bool B>
class Invert
{
public:
  static bool const result = !B; 
}; 

void g()
{
  bool test = Invert<(1>0)>::result; 
  //bool test = Invert<1>0>::result; 
  printf("test = %d\n", test); 
}

template <typename T>
class Trap
{
public:
  enum { x }; 
}; 

template <typename T>
class Victim
{
public:
  int y; 
  void poof() 
  //{ printf("value = %d\n", Trap<T>::x *y); } 
  {
    Trap<T>::x *y = 0; 
    printf("value = %p\n", y); 
  }
}; 

template <>
class Trap<void>
{
public:
  typedef int x; 
}; 

void boom(Victim<void>& bomb)
{
  bomb.poof(); 
}


int _tmain(int argc, _TCHAR* argv[])
{
  printf("C::f() = %d, ::f() = %d\n", C::f(), ::f()); 

  D<int> d; 
  D<double> d2; 

  g(); 

  Victim<void> b; 
  boom(b); 
	return 0;
}

