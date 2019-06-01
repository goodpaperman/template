
#include "stdafx.h" 


template <typename T1, typename T2>
void f1(T2, T1)
{
  printf("void f1(T2, T1)\n"); 
}

template <typename T>
char f2(T)
{
  printf("char f2(T)\n"); 
  return 'a'; 
}

void h()
{
  f1('a', 'b'); 
  f2(2); 
}