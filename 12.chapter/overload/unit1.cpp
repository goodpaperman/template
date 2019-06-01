
#include "stdafx.h"


template <typename T1, typename T2>
void f1(T1, T2)
{
  printf("void f1(T1, T2)\n"); 
}

template <typename T>
long f2(T)
{
  printf("long f2(T)\n"); 
  return 1L; 
}

void g()
{
  f1('a', 'b'); 
  f2(1); 
}