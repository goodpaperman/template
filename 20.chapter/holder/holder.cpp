// holder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <memory> 
#include <stdexcept> 
#include "Holder.h" 

#define USE_HOLDER

class Something
{
public:
  Something() { printf("Construct Something.\n"); }
  ~Something() { printf("Destruct Something.\n"); } 
  void perform() { printf("Perform Something.\n"); throw std::bad_alloc(); } 
}; 

void do_something()
{
#ifdef USE_HOLDER
  //Holder<Something> ptr = new Something(); 
  Holder<Something> ptr(new Something()); 
  try
  {
    ptr->perform(); 
  }
  catch(...)
  {
  }
#else
  Something* ptr = new Something(); 

  try
  {
    ptr->perform(); 
  }
  catch(...)
  {
    delete ptr; 
    throw; 
  }

  delete ptr; 
#endif 
}

class A
{
public:
  A() { printf("A constructed.\n"); } 
  ~A() { printf("A destructed.\n"); } 
}; 

class B
{
public:
  B() { printf("B constructed.\n"); throw std::bad_exception(); } 
  ~B() { printf("B destructed.\n"); } 
}; 


class Compound
{
public: 
  Compound() 
    : a(new A())
    , b(new B())
  { printf("Compound constructed.\n"); } 
  
  ~Compound() 
  { 
    printf("Compound destructed.\n"); 
#ifndef USE_HOLDER
    delete a; 
    delete b; 
#endif 
  } 

private:
#ifdef USE_HOLDER
  Holder<A> a; 
  Holder<B> b; 
#else 
  A *a; 
  B *b; 
#endif 
}; 

void read_something(Something* ptr)
{
  throw std::invalid_argument("无效的参数"); 
}

Something* load_something()
{
  Holder<Something> result(new Something()); 
  read_something(result.get()); 
  //Something* ret = result.get(); 
  //result.release(); 
  //return ret; 
  return result.release() ;
}

class MyClass 
{
public:
  MyClass() { printf("MyClass construct.\n"); }
  MyClass(MyClass const& a) { printf("MyClass copy construct.\n"); throw std::out_of_range("超出范围"); } 
  ~MyClass() { printf("MyClass destruct.\n"); }
}; 

void callee(MyClass a, Something* ptr)
{
  printf("callee called.\n"); 
  //delete ptr; 
}

class BadClass
{
public:
  BadClass() { printf("BadClass Construct.\n"); } 
  ~BadClass() { printf("BadClass Destruct.\n"); throw std::exception(); } 
}; 

Something* creator()
{
  Holder<Something> h(new Something()); 
  BadClass b; 
  return h.release(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  //do_something(); 
  try
  {
    Compound c; 
  }
  catch(...)
  {
  }

  try
  {
    Something* ptr = load_something(); 
    delete ptr; 
  }
  catch(...)
  {
    //throw; 
  }


  try
  {
    Holder<Something> ptr(new Something()); 
    //Holder<Something> ptr2(ptr.release()); 
    ////Holder<Something> ptr3 = ptr2.release(); 
    //ptr = ptr2.release(); 
    MyClass x; 
    //callee(x, ptr.release()); 
    callee(x, ptr.get()); 
  }
  catch(...)
  {
  }

  try
  {
    Something* ptr = creator(); 
    delete ptr; 
  }
  catch(...)
  {
  }

	return 0;
}

