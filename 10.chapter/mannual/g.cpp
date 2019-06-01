
#include "stdafx.h"

//template <typename T>
//void f(); 

template <typename T>
void f()
{
  printf("it is wrong.\n"); 
}

//template <>
//void f<int>(); 

extern template void f<int>(); 

void g()
{ 
  f<int>(); 
}