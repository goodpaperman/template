// mannual.cpp : �������̨Ӧ�ó������ڵ㡣
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

