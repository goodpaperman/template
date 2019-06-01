// overload.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

extern void combine(int, double); 
extern void combine(long, int); 

class X
{
public:
  X(int) {}
}; 

void f1(int) { printf("f1(int)\n"); }
void f1(double) { printf("f1(double)\n"); }
void f1(char) { printf("f1(char)\n"); } 

void f2(X) { printf("f2(X)\n"); }
void f2(...) { printf("f2(...)\n"); } 
//void f2(float) { printf("f2(float)\n"); } 

void f3(int *) { printf("f3(int*)\n"); } 
void f3(int const*) { printf("f3(int const*)\n"); } 

template <typename T>
class MyString
{
public:
  MyString(T const* = 0){}
}; 

template <typename T>
void truncate(MyString<T> const&, int) 
{ printf("truncate\n"); }

void report(int& val)
{
  printf("report(int&)\n"); 
}

void report(int const& val)
{
  printf("report(int const&)\n"); 
}

//void report(int val)
//{
//  printf("report(int)\n"); 
//}

class Wonder
{
public:
  void tick() { printf("tick()\n"); } 
  void tick() const { printf("tick() const\n"); } 
  void tack() const { printf("tack() const\n"); }
}; 

template <typename T>
int f(T) { printf("template int f(T)\n"); return 0; }
Wonder f(int) { printf("void f(int)\n"); return Wonder(); } 

class Base
{
public:
  operator short() const { printf("Base to short\n"); return 0; } 
}; 

class Derived : public Base
{
}; 

void count(int) { printf("void count(int)\n"); } 

void check(Base *) { printf("void check(Base*)\n"); } 
void check(void *) { printf("void check(void*)\n"); } 
void check(bool) { printf("void check(bool)\n"); } 

class Son : public Derived
{
}; 

void serialize(Base*) { printf("serialize(Base*)\n"); } 
void serialize(Derived*) { printf("serialize(Derived*)\n"); } 

typedef void FuncType(double, int); 
void FuncTypeImpl(double, int)  { printf("void FuncType(double, int)\n"); }
class IndirectFunctor
{
public:
  void operator()(double, double) { printf("operator()(double, double)\n"); } 
  operator FuncType* () { printf("operator FuncType* () const\n"); return FuncTypeImpl; }
}; 

class Matrix
{
}; 

class Vector
{
}; 

int n_elements(Matrix const&) { printf("n_elements(Maxtrix const&)\n"); return 0; } 
int n_elements(Vector const&) { printf("n_elements(Vector const&)\n"); return 0; } 

int _tmain(int argc, _TCHAR* argv[])
{
  //combine(1, 2); 

  f1(4); 
  f1(true); 

  f2(7); 

  int /*const */a = 3; 
  f3(&a); 

  MyString<char> str1, str2; 
  truncate<char>("Hello World", 5); 
  //truncate("Hello World", 4); 

  int k = 0; 
  const int l = 0; 
  report(k); 
  report(l); 
  report(42);

  Wonder /*const*/ device; 
  device.tick(); 
  device.tack(); 

	//return f(7);
  //return f<int>(7); 

  const Derived object; 
  count(object); 

  Derived m; 
  check(&m); 

  Son s; 
  serialize(&s); 

  IndirectFunctor funcObj; 
  //funcObj(3, 5); 

  Vector vec; 
  int (*funcPtr)(Vector const&) = n_elements; 
  (*funcPtr)(vec); 
  return 0; 
}

