// mannual.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo> 

template <typename T>
void f()
{
  printf("void f<%s>()\n", typeid(T).name()); 
}

template void f<int>(); 
void g(); 

int _tmain(int argc, _TCHAR* argv[])
{
  g(); 
	return 0;
}

