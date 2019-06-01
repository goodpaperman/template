// csm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "isclasst.h" 
#include "rparam.h" 
#include <numeric> 

template <typename T, bool Bitwise>
class BitOrClassCSM; 

template <typename T>
class BitOrClassCSM<T, false>
{
public:
  static void copy(typename RParam<T>::Type src, T* dst)
  {
    *dst = src; 
  }

  static void copy_n(T const* src, T* dst, size_t n)
  {
    for(size_t k = 0; k < 0; ++ k)
      dst[k] = src[k]; 
  }

  static void copy_init(typename RParam<T>::Type src, void* dst)
  {
    ::new(dst) T(src); 
  }

  static void copy_init_n(T const* src, void* dst, size_t n)
  {
    for(size_t k = 0; k<n; ++ k)
      ::new((void*)((T*)dst+k)) T(src[k]); 
  }

  static void swap(T* a, T* b)
  {
    T tmp(*a); 
    *a = *b; 
    *b = tmp; 
  }

  static void swap_n(T* a, T* b, size_t n)
  {
    for(size_t k=0; k<n; ++ k)
    {
      T tmp(a[k]); 
      a[k] = b[k]; 
      b[k] = tmp; 
    }
  }

  static void move(T* src, T* dst)
  {
    assert(src != dst); 
    *dst = *src; 
    src->~T(); 
  }

  static void move_n(T* src, T* dst, size_t n)
  {
    assert(src != dst); 
    for(size_t k=0; k<n; ++ k)
    {
      dst[k] = src[k]; 
      src[k].~T(); 
    }
  }

  static void move_init(T* src, void* dst)
  {
    assert(src != dst); 
    ::new(dst) T(*src); 
    src->~T(); 
  }

  static void move_init_n(T const* src, void* dst, size_t n)
  {
    assert(src != dst); 
    for(size_t k=0; k<n; ++k)
    {
      ::new((void*)((T*)dst+k)) T(src[k]); 
      src[k].~T(); 
    }
  }
}; 

template <typename T>
class BitOrClassCSM<T, true> : public BitOrClassCSM<T, false>
{
public:
  static void copy_n(T const* src, T* dst, size_t n)
  {
    std::memcpy((void*)dst, (void*)src, n * sizeof(T)); 
  }

  static void copy_init_n(T const* src, void* dst, size_t n)
  {
    std::memcpy(dst, (void*)src, n * sizeof(T)); 
  }

  static void move_n(T* src, T* dst, size_t n)
  {
    assert(src != dst); 
    std::memcpy((void*)dst, (void*)src, n * sizeof(T)); 
  }

  static void move_init_n(T const* src, void* dst, size_t n)
  {
    assert(src != dst); 
    std::memcpy(dst, (void*)src, n * sizeof(T)); 
  }
}; 

struct MyPODType
{
  char a; 
  short b; 
  int c; 
  long d; 
  long long e; 
  float f; 
  double g; 
  long double h; 
  
  unsigned char z; 
  unsigned short y; 
  unsigned int x; 
  unsigned long w; 
  unsigned long long v;   
  bool u; 
}; 

template <>
class CSMtraits<MyPODType> : public BitOrClassCSM<MyPODType, true>
{
};  


int _tmain(int argc, _TCHAR* argv[])
{
  std::numeric_limits a; 
	return 0;
}

