// rparam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "isclasst.h" 
#include "ifthenelse.h" 
#include <typeinfo> 

#if 0
template <typename T>
class RParam
{
public:
  typedef typename IfThenElse<sizeof(T) <= 2*sizeof(void*), T, T const&>::ResultT Type; 
};

template <typename T1, typename T2>
void foo(typename RParam<T1>::Type p1, typename RParam<T2>::Type p2)
{
  printf("p1 = %d, p2 = %d.\n", sizeof(p1), sizeof(p2)); 
  *(int*)&p1 = 42; 
  *(int*)&p2 = 24; 
  //memset((void*)&p1, 1, sizeof(int)); 
  //memset((void*)&p2, 2, sizeof(int)); 
}

struct Big
{
  int a[4]; 
  float b[5]; 
}; 
#else 
#include "rparam.h" 

class MyClass1
{
public:
  MyClass1() { }
  MyClass1(MyClass1 const&) { printf("MyClass1 copy constructor\n"); } 
}; 

class MyClass2
{
public:
  MyClass2() { }
  MyClass2(MyClass2 const&) { printf("MyClass2 copy constructor\n"); } 
}; 

template <>
class RParam<MyClass2>
{
public:
  typedef MyClass2 Type; 
}; 

template <typename T1, typename T2>
void foo(typename RParam<T1>::Type p1, typename RParam<T2>::Type p2)
{
  
}

template<typename T1, typename T2>
inline void foo_wrapper(T1 const& p1, T2 const& p2)
{
  foo<T1, T2>(p1, p2); 
}


#endif 


int _tmain(int argc, _TCHAR* argv[])
{
#if 0
  int a = 12; 
  Big b = { 0 }; 
  foo<int, Big>(a, b); 

  printf("a = %d, b = %d\n", a, b.a[0]); 
#else 

  MyClass1 mc1; 
  MyClass2 mc2; 
  //foo<MyClass1, MyClass2>(mc1, mc2); 
  foo_wrapper(mc1, mc2); 
#endif 
	return 0;
}

