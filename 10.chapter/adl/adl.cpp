// adl.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "t.h" 

//export template <typename T>
//T const& max(T const&, T const&); 

template <typename T>
void f1(T x)
{
  g1(x); 
}


int _tmain(int argc, _TCHAR* argv[])
{
  //max(7, 42); 
  f1(7); 

  S<int> s; 
  helper(&s); 
  s.f(); 
	return 0;
}


void g1(int)
{ printf("g1 called\n"); }
