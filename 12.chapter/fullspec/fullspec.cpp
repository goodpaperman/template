// fullspec.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

template <typename T>
int f(T)
{ 
  printf("int f(T)\n"); 
  return 1; 
} 

template <typename T>
int f(T*)
{
  printf("int f(T*)\n"); 
  return 2; 
}

template <>
int f(int)
{
  printf("int f<int>(int)\n"); 
  return 3; 
}

template <>
int f(int*)
{
  printf("int f<int>(int*)\n"); 
  return 4; 
}

template <typename T>
int g(T, T x = 42)
{
  printf("int g(T, T=42)\n"); 
  return x; 
}

template <>
int g(int, int y/* = 35*/)
{
  printf("int g(int, int)\n"); 
  return y/2; 
}


template <typename T>
class Outer
{
public:
  template <typename U>
  class Inner
  {
  private:
    static int count; 
  }; 

  static int code; 
  void print() const 
  { printf("void Outer<T>::print code = %d\n", code); } 
}; 

template <typename T>
int Outer<T>::code = 6; 

template <typename T>
template <typename U>
int Outer<T>::Inner<U>::count = 7; 

template <>
class Outer<bool>
{
public:
  template <typename U>
  class Inner
  {
  private:
    static int count; 
  }; 

  static int code; 
  void print() const 
  { printf("void Outer<bool>::print code = %d\n", code); } 
}; 

int Outer<bool>::code = 8; 

template <>
int Outer<void>::code = 9; 

template <>
void Outer<float>::print() const
{ printf("void Outer<float>::print code = %d\n", code); } 

//template <>
//class Outer<void>
//{
//}; 

template class Outer<float>; 

//template <>
//int Outer<double>::code; 

template <>
void Outer<long>::print() const; 



class DefaultInitOnly
{
public:
  DefaultInitOnly() { }

private:
  DefaultInitOnly(DefaultInitOnly const&); 
}; 

template <typename T>
class Statics
{
private:
  static T sm; 
}; 

template <>
DefaultInitOnly Statics<DefaultInitOnly>::sm; 


template <>
template <typename X>
class Outer<char>::Inner
{
public:
  static long count; 
  void print() const 
  { printf("void Outer<char>::Inner<T>::print() count = %d.\n", count); } 
}; 

template <>
template <typename X>
long Outer<char>::Inner<X>::count = 11; 

template <>
template <>
class Outer<char>::Inner<char>
{
public:
  enum { count = 1 }; 
  void print() const 
  { printf("void Outer<char>::Inner<char>::print() count = %d.\n", count); }
};

//template <>
template <>
class Outer<bool>::Inner<char>
{
public:
  enum { count = 2 }; 
  void print() const
  { printf("void Outer<bool>::Inner<char>::print() count = %d.\n", count); }
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  double d = 1.2, *pd = &d; 
  f(d); 
  f(pd); 

  int i = 42, *pi = &i; 
  f(i); 
  f(pi); 

  printf("g(0) = %d\n", g(0)); 
  printf("g(0.0) = %d\n", g(0.0)); 

  Outer<int> oi; 
  oi.print(); 

  Outer<bool> ob; 
  ob.print(); 

  Outer<void> ov; 
  ov.print(); 

  Outer<float> of; 
  of.print(); 

  Outer<double> od; 
  od.print(); 

  Outer<long> ol; 
  ol.print(); 

  Statics<DefaultInitOnly> sd; 
  //sd.sm; 

  Outer<char>::Inner<int> oii; 
  oii.print(); 

  Outer<char>::Inner<char> oic; 
  oic.print(); 

  Outer<bool>::Inner<char> oib; 
  oib.print(); 
	return 0;
}

template <>
int Outer<double>::code = 10; 

template <>
void Outer<long>::print() const 
{ printf("void Outer<long>::print code = %d.\n", code); } 