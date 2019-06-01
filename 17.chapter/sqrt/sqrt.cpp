// sqrt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ifthenelse.h" 

#define OPTIMIZE
//#define TRACE

template <int N, int LO=0, int HI=N>
class Sqrt
{
public:

#ifdef OPTIMIZE
  enum
  {
    mid = (LO+HI+1)/2, 
#ifdef TRACE
    a = 1000000000000,  
#endif 
  }; 

  typedef typename IfThenElse<(N<(long long)mid*mid) 
    , Sqrt<N, LO, mid-1>
    , Sqrt<N, mid, HI> >::ResultT SubT; 

  enum { result = SubT::result, }; 
#else 
  enum
  {
    mid = (LO+HI+1)/2, 
    result = (N<(long long)mid*mid) 
    ? Sqrt<N, LO, mid-1>::result
    : Sqrt<N, mid, HI>::result, 
  }; 
#endif 
}; 

template <int N, int M>
class Sqrt<N, M, M>
{
public:
  enum
  {
    result = M, 
#ifdef TRACE
    a = 1000000000000, 
#endif 
  }; 
}; 



int _tmain(int argc, _TCHAR* argv[])
{
  printf("Sqrt<16>::result = %d.\n", Sqrt<16>::result); 
#ifndef TRACE
  printf("Sqrt<25>::result = %d.\n", Sqrt<25>::result); 
  printf("Sqrt<42>::result = %d.\n", Sqrt<42>::result); 
  printf("Sqrt<1>::result = %d.\n", Sqrt<1>::result); 
  printf("Sqrt<1024>::result = %d.\n", Sqrt<1024>::result); 
#  ifdef OPTIMIZE
  printf("Sqrt<1000000000>::result = %d.\n", Sqrt<1000000000>::result); 
  printf("Sqrt<1050625>::result = %d.\n", Sqrt<1050625>::result); 
  printf("Sqrt<1048576>::result = %d.\n", Sqrt<1048576>::result); 
  printf("Sqrt<16384>::result = %d.\n", Sqrt<16384>::result); 
  printf("Sqrt<4096>::result = %d.\n", Sqrt<4096>::result); 
#  endif 
#endif 
	return 0;
}

