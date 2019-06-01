// depend.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo> 

template <typename X>
class Base
{
public:
  int basefield; 
  typedef int T; 
}; 

class D1 : public Base<Base<void> >
{
public:
  void f() { basefield = 3; printf("D1::f()\n"); } 
}; 

template <typename T>
class D2 : public Base<double>
{
public:
  void f() { basefield = 7; printf("D2::f()\n"); } 
  T strange; 
}; 


template <typename T>
class DD : public Base<T>
{
public:
  void f() 
  { basefiled = 0; } 
  //{ this->basefield = 0; } 
  //{ Base<T>::basefield = 0; } 
}; 

//template <>
//class Base<bool>
//{ 
//public:
//  enum BALL { basefield = 42, }; 
//}; 
//
//void gg(DD<bool>& d)
//{
//  d.f(); 
//}

template <typename T>
class B
{
public:
  enum E { e1 = 6, e2 = 28, e3 = 496 }; 
  virtual void zero(E e = e1) { printf("B::zero(E)\n"); } 
  virtual void one(E&) { printf("B::one(E&)\n"); } 
}; 

template <typename T>
class D : public B<T>
{
public:
  void f()
  {
    printf("D::f()\n"); 
    typename D<T>::E e; 
    this->zero(); 
    one(e); 
  }
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  D1 d1; 
  D2<int*> d2; 
  d1.f(); 
  d2.f(); 
  printf("D2::strange: %s\n", typeid(d2.strange).name()); 

  //DD<bool> d; 
  //gg(d); 

  D<float> dd; 
  dd.f(); 
	return 0;
}

