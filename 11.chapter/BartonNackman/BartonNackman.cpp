// BartonNackman.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <typeinfo.h> 

class S
{
}; 

template <typename T>
class Wrapper
{
public:
  Wrapper(T obj) : object(obj)
  {
  }

  friend void f(Wrapper<T> const& a)
  {
    printf("void f(Wrapper<%s> const& a)\n", typeid(T).name()); 
  }

private:
  T object; 
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  S s; 
  Wrapper<S> w(s); 

  f(w); 
  f(s); 
	return 0;
}

