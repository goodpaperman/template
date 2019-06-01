// sqrtex.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ifthenelse.h" 

#define OPTIMIZE
//#define TRACE

#ifdef OPTIMIZE

template <int N>
class Value
{
public:
  enum { result = N }; 
}; 

template <int N, int I=0>
class Sqrt
{
public:
  typedef typename IfThenElse<(long long)I*I < N
    , Sqrt<N, I+1>
    , Value<I> >::ResultT SubT; 

  enum 
  {
#  ifdef TRACE
    a = 1000000000000, 
#  endif 
    result = SubT::result, 
  }; 
}; 

#else

template <int N, int I=0>
class Sqrt
{
public:
  enum
  {
#  ifdef TRACE
    a = 1000000000000,  
#  endif 
    result = ((long long)I*I<N) 
    ? Sqrt<N, I+1>::result
    : I, 
  }; 
}; 

template <int N>
class Sqrt<N, N>
{
public:
  enum
  { 
#  ifdef TRACE
    a = 1000000000000, 
#  endif 
    result = N, 
  }; 
}; 

#endif 


int _tmain(int argc, _TCHAR* argv[])
{
  printf("Sqrt<16>::result = %d.\n", Sqrt<16>::result); 
#ifndef TRACE
  printf("Sqrt<25>::result = %d.\n", Sqrt<25>::result); 
  printf("Sqrt<42>::result = %d.\n", Sqrt<42>::result); 
  printf("Sqrt<1>::result = %d.\n", Sqrt<1>::result); 
#  ifdef OPTIMIZE
  printf("Sqrt<1024>::result = %d.\n", Sqrt<1024>::result); 
  //printf("Sqrt<1000000000>::result = %d.\n", Sqrt<1000000000>::result); 
  //printf("Sqrt<1050625>::result = %d.\n", Sqrt<1050625>::result); 
  //printf("Sqrt<1048576>::result = %d.\n", Sqrt<1048576>::result); 
  printf("Sqrt<16384>::result = %d.\n", Sqrt<16384>::result); 
  printf("Sqrt<4096>::result = %d.\n", Sqrt<4096>::result); 
#  endif 
#endif 
	return 0;
}

