// trule.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <memory> 
#include <stdexcept> 
#include "Holder.h" 
#include "Trule.h" 

class Something
{
public:
  Something() { printf("Construct Something.\n"); }
  ~Something() { printf("Destruct Something.\n"); } 
  void perform() { printf("Perform Something.\n"); throw std::bad_alloc(); } 
}; 

class BadClass
{
public:
  BadClass() { printf("BadClass Construct.\n"); } 
  ~BadClass() { printf("BadClass Destruct.\n"); throw std::exception(); } 
}; 

//Something* creator()
//{
//  Holder<Something> h(new Something()); 
//  BadClass b; 
//  return h.release(); 
//}

Trule<Something> creator()
{
  Holder<Something> h(new Something()); 
  BadClass b; 
  return h; 
}

int _tmain(int argc, _TCHAR* argv[])
{
  try
  {
    Holder<Something> ptr = creator(); 
  }
  catch(...)
  {
  }

	return 0;
}

