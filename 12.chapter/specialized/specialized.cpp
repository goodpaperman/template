// specialized.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

template <typename T>
class S
{
public:
  void info()
  {
    printf("generic (S<T>::info())\n"); 
  }
}; 

template <>
class S<void>
{
public:
  void msg()
  {
    printf("fully specialized (S<void>::msg())\n"); 
  }
}; 


template <typename T>
class Types
{
public:
  typedef int I; 
}; 

template <typename T, typename U = typename Types<T>::I>
class X; 

template <>
class X<void>
{
public:
  void f(); 
}; 

template <>
class X<char, char>; 

//template <>
//class X<char, 0>; 

template <typename T>
class Y; 

template <> 
class Y<char**>
{
public:
  void print() const; 
}; 

//template <>
void Y<char**>::print() const
{
  printf("pointer to pointer to char\n"); 
}

template <typename T>
class Outside
{
public:
  template <typename U>
  class Inside
  {
  }; 
}; 

template <>
class Outside<void>
{
  template<typename U>
  class Inside
  {
  private:
    static int count; 
  }; 
}; 

//template <>
template <typename U>
int Outside<void>::Inside<U>::count = 1; 

template <typename T>
class Invalid
{
}; 

//Invalid<double> x1; 
//template Invalid<double>; 

template <>
class Invalid<double>; 

template <typename T>
class Danger
{
public:
  enum { max = 10 }; 
}; 

char buffer[Danger<void>::max]; 
extern void clear(char const*); 

int _tmain(int argc, _TCHAR* argv[])
{
  S<int> s1; 
  S<void> s2; 
  s1.info(); 
  //s2.info(); 
  s2.msg(); 

  X<int>* pi; 
  //X<int> e1; 
  X<void>* pv; 
  X<void, int> sv; 
  //X<void, char> e2; 
  //X<char, char> e3; 

  //Y<char*> ypc; 
  Y<char**> yppc; 
  yppc.print(); 

  clear(buffer); 
	return 0;
}

template <>
class X<char, char>
{
}; 

