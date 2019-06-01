#pragma once

#define USE_ENUM

template <int B, int E>
class pown
{
public:
#ifdef USE_ENUM
  enum { result = B * pown<B, E-1>::result }; 
#else 
  static int const result = B * pown<B, E-1>::result; 
#endif 
};

template <int B>
class pown<B, 0>
{
public:
#ifdef USE_ENUM
  enum { result = 1 }; 
#else 
  static int const result = 1; 
#endif 
}; 
