// metaprog.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "pown.h" 

void print(int const& v)
{
  printf("value = %d.\n", v); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  printf("3^7 = %d.\n", pown<3, 7>::result); 
  printf("7^3 = %d.\n", pown<7, 3>::result); 

  printf("2^30 = %d.\n", pown<2, 30>::result); 
  printf("10^9 = %d.\n", pown<10, 9>::result); 
  printf("2^100 = %d.\n", pown<2, 100>::result); 
  print(pown<2, 100>::result); 
  //system("pause"); 
	return 0;
}

