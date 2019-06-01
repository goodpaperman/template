// toast.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo.h> 

template <typename T>
void f(T) throw(T)
{
  printf("f<%s>(%s) called\n", typeid(T).name(), typeid(T).name()); 
}

template void f<int>(int) throw(int); 
template void f<>(float) throw(float); 
template void f(long) throw(long); 
template void f(char); 

template <typename T>
class S
{
public:
  void f() 
  {
    printf("S<%s>::f() called\n", typeid(T).name()); 
  }
}; 

template void S<int>::f(); 

template <>
class S<void>
{
public:
  void f()
  {
    printf("S<'void'>::f() called\n"); 
  }
}; 

//template class S<void>; 

int _tmain(int argc, _TCHAR* argv[])
{
  f(1); 
  f(1.0f); 
  f(1L); 
  f('a'); 

  S<void> s1; 
  s1.f(); 

  S<int> s2; 
  s2.f(); 
	return 0;
}

