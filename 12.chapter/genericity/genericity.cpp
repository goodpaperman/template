// genericity.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm> 


template <typename T>
class Array
{
public:
  Array() : data(0) { }
  Array(Array<T> const& rhs) : data(rhs.data) { }
  Array<T>& operator=(Array<T> const& rhs)
  {
    data = rhs.data; 
    return *this; 
  }

  void exchange_with(Array<T>* b)
  {
    std::swap(data, b->data); 
  }

  T& operator[](size_t k)
  {
    return data[k]; 
  }

  size_t size() const { return data == 0 ? 0 : 1; } 

  T const* address() const { return data; } 
  void address(T* addr) { data = addr; } 

private:
  T* data; 
}; 

template <typename T>
inline void exchange(T* a, T* b)
{
  std::swap(*a, *b); 
}

template <typename T>
inline void quick_exchange(T* a, T* b)
{
  printf("inline void quick_exchange(T*, T*) called\n"); 
  std::swap(*a, *b); 
}

//template <typename T>
//inline void quick_exchange(Array<T>* a, Array<T>* b)
//{
//  printf("inline void quick_exchange(Array<T>*, Array<T>*) called\n"); 
//  a->exchange_with(b); 
//}

template <typename T>
void quick_exchange(Array<T>* a, Array<T>* b)
{
  printf("void quick_exchange(Array<T>*, Array<T>*) called\n"); 
  T* p = &(*a)[0]; 
  T* q = &(*b)[0]; 
  for(size_t k = a->size(); k-- != 0; )
  {
    quick_exchange(p++, q++); 
  }
}

struct S
{
  int d; 
}s1, s2; 

void demo()
{
  s1.d = 5; 
  s2.d = 8; 

  int x = 24, y = 42; 
  Array<int> a, b; 
  a.address(&x); 
  b.address(&y); 

  int* p = &a[0]; 
  int* q = &s1.d; 
  printf("*p = %p (%d), *q = %p (%d).\n", p, *p, q, *q); 
  quick_exchange(&a, &b); 
  quick_exchange(&s1, &s2); 
  printf("*p = %p (%d), *q = %p (%d).\n", p, *p, q, *q); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  int x = 1, y = 2; 
  printf("x = %d, y = %d.\n", x, y); 
  exchange(&x, &y); 
  printf("x = %d, y = %d.\n", x, y); 

  Array<int> a, b; 
  a.address(&x); 
  b.address(&y); 
  printf("a = %p, b = %p.\n", a.address(), b.address()); 
  exchange(&a, &b); 
  printf("a = %p, b = %p.\n", a.address(), b.address()); 

  quick_exchange(&x, &y); 
  quick_exchange(&a, &b); 
  printf("x = %d, y = %d.\n", x, y); 
  printf("a = %p, b = %p.\n", a.address(), b.address()); 

  demo(); 
	return 0;
}

