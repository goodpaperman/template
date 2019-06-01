// virt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class NonVirtual
{
public:
  void foo()
  {
    printf("NonVirtual::foo\n"); 
  }
};

class Virtual
{
public:
  virtual void foo()
  {
    printf("Virtual::foo\n"); 
  }
}; 

template <typename VB>
class B : /*private*/public VB
{
public:
  void foo()
  {
    printf("B::foo\n"); 
  }
}; 

template <typename V>
class D : public B<V>
{
public:
  void foo()
  {
    printf("D::foo\n"); 
  }
}; 


int _tmain(int argc, _TCHAR* argv[])
{
  B<NonVirtual>* pb = new D<NonVirtual>(); 
  pb->foo(); 
  //pb->NonVirtual::foo(); 
  delete pb; 

  B<Virtual>* pv = new D<Virtual>(); 
  pv->foo(); 
  //pv->Virtual::foo(); 
  delete pv; 
	return 0;
}

