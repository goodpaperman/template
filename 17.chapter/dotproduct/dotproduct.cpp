// dotproduct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define OPTIMIZE

#ifdef OPTIMIZE

template <typename T, int DIM>
class DotProduct
{
public:
  static T result(T* a, T* b)
  {
    return *a * *b + DotProduct<T, DIM-1>::result(a+1, b+1); 
  }
}; 

template <typename T>
class DotProduct<T, 1>
{
public:
  static T result(T* a, T* b)
  {
    return *a * *b; 
  }
}; 

template <int DIM, typename T>
inline T dot_product(T* a, T* b)
{
  return DotProduct<T, DIM>::result(a, b); 
}

#else

template <typename T>
inline T dot_product(int dim, T* a, T* b)
{
  T result = T(); 
  for(int i=0; i<dim; ++ i)
    result += a[i] * b[i]; 

  return result; 
}

#endif 

int _tmain(int argc, _TCHAR* argv[])
{
  //int a[3] = { 1, 2, 3 }; 
  //int b[3] = { 5, 6, 7 }; 

  LARGE_INTEGER freq = { 0 }, tick1 = { 0 }, tick2 = { 0 }; 
  ::QueryPerformanceFrequency(&freq); 

  //int const n = 1024; 
  int const n = 128; 
  long long a[n] = { 0 }; 
  long long b[n] = { 0 }; 
  for(int i=0; i<n; ++ i)
  {
    a[i] = i; 
    b[i] = n-i-1; 
  }

  ::QueryPerformanceCounter(&tick1); 
#ifdef OPTIMIZE

  printf("dot_product<%d>(a, b) = %d.\n", n, dot_product<n>(a, b)); 
  printf("dot_product<%d>(a, a) = %d.\n", n, dot_product<n>(a, a)); 
  printf("dot_product<%d>(b, b) = %d.\n", n, dot_product<n>(b, b)); 

#else 

  printf("dot_product(%d, a, b) = %d.\n", n, dot_product(n, a, b)); 
  printf("dot_product(%d, a, a) = %d.\n", n, dot_product(n, a, a)); 
  printf("dot_product(%d, b, b) = %d.\n", n, dot_product(n, b, b)); 

#endif 
  QueryPerformanceCounter(&tick2); 

  printf("elapsed %.2f us\n", 1000000.0 * (tick2.QuadPart - tick1.QuadPart) / freq.QuadPart); 

	return 0;
}

