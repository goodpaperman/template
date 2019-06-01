// sfinae.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "isclasst.h"

class MyClass
{
}; 

struct MyStruct
{
}; 

union MyUnion
{
}; 

void myfunc()
{
}

enum E { e1 } e; 

template <typename T>
void check()
{
  if(IsClassT<T>::Yes)
    printf(" IsClassT\n"); 
  else 
    printf(" !IsClassT\n"); 
}

template <typename T>
void checkT(T)
{
  check<T>(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  printf("int: "); 
  check<int>(); 

  printf("MyClass: "); 
  check<MyClass>(); 

  printf("MyStruct: "); 
  MyStruct s; 
  checkT(s); 

  printf("My Union: "); 
  check<MyUnion>(); 

  printf("enum: "); 
  checkT(e); 

  printf("myfunc(): " ); 
  checkT(myfunc); 

	return 0;
}

