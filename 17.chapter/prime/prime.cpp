// prime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define TRACE

#ifndef TRACE
#define TRACE \
    a = 10000000000, 
#endif 

template <int p, int i>
class is_prime
{
public:
  enum 
  {
    TRACE
    prime = (p == 2) || (p%i) && is_prime<(i>2?p:0), i-1>::prime, 
  }; 
}; 

template <>
class is_prime<0, 0>
{
public:
  enum 
  { 
    TRACE
    prime = 1, 
  }; 
}; 

template <>
class is_prime<0, 1>
{
public:
  enum 
  {
    TRACE
    prime = 1, 
  }; 
}; 

template <int N>
class D
{
public:
  D(void*) { }
  //D(char a) {}
}; 

template <int N>
class Prime_print
{
public:
  enum
  {
    prime = is_prime<N, N-1>::prime, 
  }; 

  void f()
  {
    D<N> d = prime ? 1 : 0; 
    a.f(); 
  }

private:
  Prime_print<N-1> a; 
}; 

template <>
class Prime_print<1>
{
  enum 
  {
    prime = 0, 
  }; 

  void f()
  {
    D<1> d = prime ? 1 : 0; 
  }
};


int _tmain(int argc, _TCHAR* argv[])
{
  //int const n = 17;
  int const n = 16; 
  printf("%d is prime ? %d\n", n, is_prime<n, n-1>::prime); 

  Prime_print<18> a; 
  a.f(); 
	return 0;
}

