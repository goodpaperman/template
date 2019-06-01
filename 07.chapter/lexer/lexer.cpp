// lexer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory> 
#include <list> 
#include <typeinfo> 

//template <int buf[5]> 
template <int* buf> 
class Lexer
{
public:
  Lexer() { printf("pointer = %p\n", buf); }
}; 

//template <int const length> 
template <int length> 
class Buffer
{
public:
  Buffer() 
  { 
    /*length = 0; */
    printf("length = %d\n", length); 
    //printf("length addr = %p\n", &length); 
  } 
}; 

template <typename T>
class One
{
public:
}; 

template <template <typename X> class C>
//template <template <typename X> struct C>
void f(C<int>* p) { printf("Oh le\n"); } 

template <typename T, template <typename X> class C>
void f2(C<T>* p) { printf("On le 2\n"); } 

template <template <typename T, typename A = std::allocator<T> > class Container>
class Adaptation
{
public:
  Container<int> storage; 

  Adaptation() { printf("Adaptation for \"%s\"\n", typeid(Container).name()); } 
}; 

template <typename T, T* dest>
class LexerBuf
{
public:
  LexerBuf() { dest[2] = 'n'; strcpy(buf, dest); printf("%s\n", buf); } 
  T buf[1024]; 
}; 

extern char _string[10] = { "hello" }; 

template <template <typename T, T* dest> class Buf>
class LexerEx
{
public:
  static char storage[5]; 
  Buf<char, &LexerEx<Buf>::storage[0]> buf; 
}; 

template <template <typename T, typename A = std::allocator<T> > class List>
class Node
{
public:
  //T *buf; 
}; 


template <typename T1, typename T2, typename T3, typename T4 = char, typename T5 = char>
class Quintuple; 

//template <typename T1 = char, typename T2 = char, typename T3 = char, typename T4, typename T5>
//class Quintuple; 

//template <typename T1, typename T2 = char, typename T3, typename T4, typename T5>
//class Quintuple; 

//template <typename T1 = char, typename T2, typename T3, typename T4, typename T5>
//class Quintuple; 

template <typename T1, typename T2 = char, typename T3 = char, typename T4, typename T5>
class Quintuple; 

template <typename T1 = char, typename T2, typename T3, typename T4, typename T5>
class Quintuple
{
public:
  Quintuple() { 
    printf("T1 = %s\nT2 = %s\nT3 = %s\nT4 = %s\nT5 = %s\n"
    , typeid(T1).name()
    , typeid(T2).name()
    , typeid(T3).name()
    , typeid(T4).name()
    , typeid(T5).name()); } 
}; 

template <typename T1 = char, typename T2 = int, typename T3 = long double, typename T4 = unsigned long long>
class tuple
{
public:
  tuple() { 
    printf("T1 = %s\nT2 = %s\nT3 = %s\nT4 = %s\n"
    , typeid(T1).name()
    , typeid(T2).name()
    , typeid(T3).name()
    , typeid(T4).name()); 
  }
}; 

template <typename destT, typename srcT>
inline destT implicit_cast(srcT const& x)
{
  return x; 
}

template <typename Func, typename T>
void apply(Func func_ptr, T x)
{
  func_ptr(x); 
}

template <typename T>
void single(T x) { printf("single(%d)\n", x); } 

template <typename T>
void multi(T x) { printf("multi(%d)\n", x); } 

template <typename T>
void multi(T* p) { printf("multi(%p)\n", p); } 

typedef char RT1; 
typedef struct { char a[2]; } RT2; 

template <typename T>
RT1 test(typename T::X const* p)
{
  printf("test return RT1\n"); 
  return RT1; 
}

template <typename T>
RT2 test(...)
{
  printf("test return RT2\n"); 
  return RT2(); 
}

#define type_has_member_type_X(T) (sizeof(test<T>(0)) == 1) 

class has_x
{
public:
  typedef int X; 
}; 

template <int I>
void foo(int (&)[24/(4-I)])
{
  printf("foo<%d>\n", I); 
}

template <int I>
void foo(int (&)[24/(4+I)])
{
  printf("foo<%d>\n", I); 
}

template <int N>
int g() { return N; } 

template <int* P>
int g() { return *P; } 

int _tmain(int argc, _TCHAR* argv[])
{
  Lexer<0> l; 
  Buffer<1024> b; 

  f<One>(0); 
  f2<int, One>(0); 

  Adaptation<std::list> adapt; 
  LexerBuf<char, _string> buf; 
  //LexerEx<LexerBuf> le; 
  Quintuple<char, char> qt; 
  tuple<> tpl; 

  printf("after cast: %f\n", implicit_cast<double>(-1)); 
  apply(&single<int>, 3); 

  int x = 42; 
  multi(x); 
  multi(&x); 
  //apply(&multi<int>, x); 
  apply<void (*)(int), int>(&multi<int>, x); 

  test<int>(0); 
  //&test<int>; 
  //printf("function addr: %p", (void*)&test<int>); 

  printf("%s has X ? %d\n", typeid(int).name(), type_has_member_type_X(int)); 
  printf("%s has X ? %d\n", typeid(has_x).name(), type_has_member_type_X(has_x)); 

  int buff[3] = { 0 }; 
  foo<4>(buff); 
  //foo<10>(buff); 

  //printf("return %d\n", g<1>()); 
	return 0;
}

