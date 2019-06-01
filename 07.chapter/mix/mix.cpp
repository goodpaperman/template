// mix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo> 

template <typename T>
class List
{
public:
  void clear() { printf("clear list\n"); } 
  T *buf; 
};

typedef struct
{
  double x, y, z; 
} Point; 

typedef enum { red, green, blue } *ColorPtr; 

template <typename T, T nontype_param> 
class C 
{ 
public: 
  C() { printf("%s\n", typeid(T).name()); } 
}; 

//static int a; 
int a; 

void f() { }
void f(int) { }

class X
{
public:
  int n; 
  static bool b; 
}; 

template <typename T>
void templ_func() { printf("this is a templ func.\n"); } 

template <char const* str> 
class Message
{
public:
  Message() { printf("str: %s\n", str); } 
}; 

extern char const hello[] = "Hello World!"; 

class Base
{
public:
  int i; 
} base; 

class Derived : public Base 
{
} derived_obj; 

//int ab[10]; 

template <typename T, int I>
class Mix
{
public:
  Mix() { printf("type: %s\n", typeid(*this).name()); } 
}; 

template <typename T>
class Node; 

template <typename T>
class Tree
{
  friend class Node<T>; 

  template <typename T2>
  friend class Node; 

  friend class Factory; 
}; 

//template <typename T>
//class Node
//{
//public:
//}; 

template <typename T1, typename T2>
void combine(T1 a, T2 b)
{
  printf("%d %d\n", a.i, b.i); 
}

class Mixer 
{
  friend void combine<>(int&, int&); 
  friend void combine<int, int>(int, int); 
  friend void combine<char>(char, int); 
  friend void combine<char>(char&, int); 
  //friend void combine<>(long, long) {}

  //friend void combine<Mixer&>(Mixer&, int); 

  template <typename T1, typename T2>
  friend void combine(T1, T2); 
public:
  Mixer() : i(-1) {}

private:
  int i; 
}; 

void multiply(void *)
{
  printf("multiply(void *)\n"); 
}

template <typename T>
void multiply(T a)
{
  printf("template <typename T> multiply(T): %d\n", a.i); 
}

class Comrades
{
  friend void multiply(int) { }
  friend void ::multiply(void *); 
  friend void ::multiply(Comrades com); 
  friend void ::multiply<double*>(double *); 
  //friend void ::error() { } 
  //friend void ::multiply(double) { }

public:
  Comrades() : i(-2) {}

private:
  int i; 
}; 


template <typename T>
class Creator
{
  friend void appear(){ printf("appear %s.\n", typeid(T).name()); } 
public:
  Creator() { appear();} 
}; 

template <typename T>
class Generator
{
  friend void feed(Generator<T> *const p) { printf("feed %s.\n", typeid(p).name()); } 

public:
  Generator() { feed(this); } 
}; 

class Manager
{
  template <typename T>
  friend class Task; 
  //template <typename T>
  //friend void Schedule<T>::dispatch(Task<T>*); 
  template <typename T>
  friend int ticket()
  {
    return ++ Manager::counter; 
  }

  static int counter; 
}; 

int Manager::counter = 0; 

int _tmain(int argc, _TCHAR* argv[])
{
  //template <typename T>
  //class error_templ
  //{
  //}; 

  struct Association
  {
    int* p; 
    int* q; 
  }; 

  List<Association*> list1; 
  list1.clear(); 

  printf("enum name: %s\n", typeid(ColorPtr).name()); 
  List<ColorPtr> list2; 
  list2.clear(); 

  List<Point> list3; 
  list3.clear(); 

  C<int, 33> c1; 
  C<int, 32>* c2; 

  //int a; 
  //static int a; 
  C<int*, &a> c3; 
  C<int*, &a>* c4; 
  
  C<void (*)(int), f> c5; 
  C<void (*)(), f>* c6; 

  C<bool&, X::b> c7; 
  C<bool&, X::b>* c8; 

  C<int X::*, &X::n> c9; 
  //C<int X::*, X::n>* c10; 

  C<void (*)(), &templ_func<double> > c11;   
  C<void (*)(), templ_func<float> >* c12;   

  Message<hello> hello_msg; 

  //C<Base*, &derived_obj> c13; 
  //C<int&, base.i> c14; 
  //C<int*, &ab[0]> c15; 

  typedef int Int; 
  Mix<int, 3*3> p1;
  Mix<Int, 4+5> p2; 
  p2 = p1; 

  Tree<int> tree; 
  Mixer mx; 

  combine(mx, mx); 

  Comrades com; 
  //multiply(com); 
  multiply(com); 

  //Creator<void> miracle; 
  Creator<double> oops; 

  Generator<void> one; 
  Generator<double> two; 

  Manager man; 
	return 0;
}

