// scalar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cassert>
#include <valarray> 

//#define OPTIMIZE1
#define OPTIMIZE2 
#define EXTEND

#if defined(OPTIMIZE2)

template <typename T>
class OpTraits
{
public:
  typedef T const& ExprRef; 
}; 

template <typename T> 
class ScalarOp; 

template <typename T>
class OpTraits<ScalarOp<T> >
{
public:
  typedef ScalarOp<T> ExprRef; 
}; 

template <typename T, typename OP1, typename OP2>
class AddOp
{
public:
  AddOp(OP1 const& a, OP2 const& b)
    : op1(a)
    , op2(b)
  {
  }

  T operator[] (size_t idx) const
  {
    return op1[idx] + op2[idx]; 
  }

  size_t size() const
  {
    assert(op1.size() == 0 || op2.size() == 0 ||
      op1.size() == op2.size()); 
    return op1.size() != 0 ? op1.size() : op2.size(); 
  }

private:
  typename OpTraits<OP1>::ExprRef op1; 
  typename OpTraits<OP2>::ExprRef op2; 
}; 

template <typename T, typename OP1, typename OP2>
class MultOp
{
public:
  MultOp(OP1 const& a, OP2 const& b)
    : op1(a)
    , op2(b)
  {
  }

  T operator[] (size_t idx) const
  {
    return op1[idx] * op2[idx]; 
  }

  size_t size() const
  {
    assert(op1.size() == 0 || op2.size() == 0 || 
      op1.size() == op2.size()); 
    return op1.size() != 0 ? op1.size() : op2.size(); 
  }

private:
  typename OpTraits<OP1>::ExprRef op1; 
  typename OpTraits<OP2>::ExprRef op2; 
}; 

template <typename T>
class ScalarOp
{
public:
  ScalarOp(T const& v)
    : s(v) 
  {
  }

  T operator[] (size_t idx) const
  {
    return s; 
  }

  size_t size() const 
  {
    return 0; 
  }

private:
  T const& s; 
}; 

#  if defined(EXTEND)
template <typename T, typename A1, typename A2>
class SubscriptOp
{
public:
  SubscriptOp(A1& a, A2 const& b)
    : a1(a)
    , a2(b)
  {
  }

  T operator[] (size_t idx) const
  {
    return a1[a2[idx]]; 
  }

  T& operator[] (size_t idx)
  {
    return a1[a2[idx]]; 
  }

  size_t size() const
  {
    return a2.size(); 
  }

private:
  //typename OpTraits<A1>::ExprRef a1; 
  //typename OpTraits<A2>::ExprRef a2; 
  A1& a1; 
  A2 const& a2; 
}; 

#  endif 
#endif 

template <typename T>
class SArray
{
public:
  explicit SArray(size_t s)
    : storage(new T[s]())
    , storage_size(s) 
  {
    init(); 
  }

  SArray(SArray<T> const& orig)
    : storage(new T[orig.size()]())
    , storage_size(orig.size())
  {
    copy(orig); 
  }

  ~SArray()
  {
    delete []storage; 
  }

  SArray<T>& operator= (SArray<T> const& orig)
  {
    if(&orig != this)
      copy(orig); 

    return *this; 
  }

  size_t size() const
  {
    return storage_size; 
  }

  T operator[] (size_t idx) const
  {
    return storage[idx]; 
  }

  T& operator[] (size_t idx)
  {
    return storage[idx]; 
  }

#if defined(OPTIMIZE1)

  SArray<T>& operator+= (SArray<T> const& b)
  {
    for(size_t k=0; k<size(); ++ k)
      storage[k] += b[k]; 

    return *this; 
  }

  SArray<T>& operator*= (SArray<T> const& b)
  {
    for(size_t k=0; k<size(); ++ k)
      storage[k] *= b[k]; 

    return *this; 
  }

  SArray<T>& operator*= (T const& s)
  {
    for(size_t k=0; k<size(); ++ k)
      storage[k] *= s; 

    return *this; 
  }

#endif 

protected:
  void init()
  {
    for(size_t idx=0; idx<size(); ++ idx)
      storage[idx] = T(); 
  }

  void copy(SArray<T> const& orig)
  {
    assert(size() == orig.size()); 
    for(size_t idx=0; idx<size(); ++ idx)
      storage[idx] = orig.storage[idx]; 
  }

private:
  T* storage; 
  size_t storage_size; 
}; 

#if !defined(OPTIMIZE1) && !defined(OPTIMIZE2)

template <typename T>
SArray<T> operator+ (SArray<T> const& a, SArray<T> const& b)
{
  SArray<T> result(a.size()); 
  for(size_t k=0; k<a.size(); ++ k)
    result[k] = a[k]+b[k]; 

  return result; 
}

template <typename T>
SArray<T> operator* (SArray<T> const& a, SArray<T> const& b)
{
  SArray<T> result(a.size()); 
  for(size_t k=0; k<a.size(); ++ k)
    result[k] = a[k]*b[k]; 

  return result; 
}

template <typename T>
SArray<T> operator* (T const& s, SArray<T> const& a)
{
  SArray<T> result(a.size()); 
  for(size_t k=0; k<a.size(); ++ k)
    result[k] = s*a[k]; 

  return result; 
}

#endif 


#if defined(OPTIMIZE2)

template <typename T, typename Rep = SArray<T> >
class Array
{
public:
  explicit Array(size_t s)
    : expr_rep(s)
  {
  }

  Array(Rep const& rb)
    : expr_rep(rb)
  {
  }

  Array& operator= (Array const& b)
  {
    assert(size() == b.size()); 
    for(size_t idx=0; idx<b.size(); ++ idx)
      expr_rep[idx] = b[idx]; 

    return *this; 
  }

  template <typename T2, typename Rep2>
  Array& operator= (Array<T2, Rep2> const& b)
  {
    assert(size() == b.size()); 
    for(size_t idx=0; idx<b.size(); ++ idx)
      expr_rep[idx] = b[idx]; 

    return *this; 
  }

  size_t size() const 
  {
    return expr_rep.size(); 
  }

  T operator[] (size_t idx) const
  {
    assert(idx < size()); 
    return expr_rep[idx]; 
  }

  T& operator[] (size_t idx)
  {
    assert(idx < size()); 
    return expr_rep[idx]; 
  }

#  if defined(EXTEND)

  template <typename R2>
  Array<T, SubscriptOp<T, Rep, R2> > operator[] (Array<T, R2> const& b)
  {
    return Array<T, SubscriptOp<T, Rep, R2> >(SubscriptOp<T, Rep, R2>(this->rep(), b.rep())); 
  }

#  endif 

  Rep const& rep() const
  {
    return expr_rep; 
  }

  Rep& rep()
  {
    return expr_rep; 
  }

private:
  Rep expr_rep; 
}; 

template <typename T, typename R1, typename R2>
Array<T, AddOp<T, R1, R2> >
operator+ (Array<T, R1> const& a, Array<T, R2> const& b)
{
  return Array<T, AddOp<T, R1, R2> >(AddOp<T, R1, R2>(a.rep(), b.rep())); 
}

template <typename T, typename R1, typename R2>
Array<T, MultOp<T, R1, R2> >
operator* (Array<T, R1> const& a, Array<T, R2> const& b)
{
  return Array<T, MultOp<T, R1, R2> >(MultOp<T, R1, R2>(a.rep(), b.rep())); 
}

template <typename T, typename R2>
Array<T, MultOp<T, ScalarOp<T>, R2> >
operator* (T const& s, Array<T, R2> const& b)
{
  return Array<T, MultOp<T, ScalarOp<T>, R2> >(MultOp<T, ScalarOp<T>, R2>(ScalarOp<T>(s), b.rep())); 
}

#endif 

int print_elem(int e)
{
  printf("%d\n", e); 
  return e == 3 ? 0 : 1; 
}

int _tmain(int argc, _TCHAR* argv[])
{
#if defined(OPTIMIZE2)
  Array<double>
#else 
  SArray<double>
#endif 
    x(1000), y(x), z(1000); 
  z = y; 

  for(size_t i=0; i<x.size(); ++ i)
  {
    x[i] = i; 
    y[i] = x.size()-i-1; 
  }

  LARGE_INTEGER freq = { 0 }, cnt1 = { 0 }, cnt2 = { 0 }; 
  ::QueryPerformanceFrequency(&freq); 
  ::QueryPerformanceCounter(&cnt1); 

#if !defined(OPTIMIZE1)/* && !defined(OPTIMIZE2)*/
  // OPTIMIZE2 has same expression with no OPTIMIZE*
  x = 1.2*x+x*y; 
  //x = 1.2 * x + x * y + 2.1 * y + x * x + y * y; 
#elif defined(OPTIMIZE1)
  SArray<double> tmp(x); 
  tmp *= y; 
  x *= 1.2; 
  x += tmp; 
#endif 

  ::QueryPerformanceCounter(&cnt2); 

  for(size_t i=0; i<x.size(); ++ i)
  {
    printf("x[%d] = %.2f\n", i, x[i]); 
  }

  printf("elapsed %.2f us\n", 1000000.0 * (cnt2.QuadPart - cnt1.QuadPart) / freq.QuadPart); 

#if defined(EXTEND)

  Array<double> idx(1000); 
  for(size_t i=0; i<idx.size(); ++ i)
    idx[i] = 1000-1-i; 

  //x = 2.0 * x; 
  x[idx] = 2.0 * x[idx]; 
  //for(size_t i=0; i<x.size(); ++ i)
  //  x[idx[i]] + y[idx[i]] = 2*x[idx[i]]; 

  for(size_t i=0; i<x.size(); ++ i)
    printf("x[%d] = %.2f\n", i, x[i]); 

#endif 

  int arr[] = { 1, 3, 5, 7, 9 }; 
  std::valarray<int> iva(arr, sizeof(arr)/sizeof(int)); 

  printf("iva: \n"); 
  for(size_t i=0; i<iva.size(); ++ i)
    printf("iva[%d] = %d\n", i, iva[i]); 


  //iva = iva.shift(3); 
  iva = iva.cshift(3); 
  printf("iva: \n"); 
  for(size_t i=0; i<iva.size(); ++ i)
    printf("iva[%d] = %d\n", i, iva[i]); 

#ifdef min
#  undef min
#endif 

#ifdef max
#  undef max
#endif 
  printf("min: %d, max = %d, sum = %d.\n", iva.min(), iva.max(), iva.sum()); 
  iva.apply(print_elem); 


	return 0;
}

