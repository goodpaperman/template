#pragma once


template <typename T>
class S
{
public:
  void f(); 
}; 

template <typename T>
void S<T>::f()
{
  printf("S::f() called\n"); 
}


void helper(S<int>* s); 
