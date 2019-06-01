// funcparam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "functorparam.h" 
#include "functionptr.h" 
#include <typeinfo> 
#include <string> 
#include <iostream> 

using std::string; 
using std::cout; 
using std::endl; 

class Person
{
public:
  Person() { }
  Person(int age) : age_(age) { } 
  int age() const { return age_; } 
  void age(int val) { age_ = val; } 

private:
  int age_; 
}; 

class PersonSortCriterion
{
public:
  enum { NumParams = 2 }; 
  typedef bool ReturnT; 
  typedef Person const& Param1T; 
  typedef Person const& Param2T; 
  bool operator() (Person const& p1, Person const& p2) const
  {
    return p1.age() < p2.age(); 
  }
}; 

class test
{
private:
  class hidden
  {
  public:
    void print() { printf("test::hidden::print called.\n"); } 
  }; 

public:
  typedef hidden visible; 
}; 

class param
{
public:
  param() : data (0) { }
  param(param const& a) : data(a.data) { printf("param copy constructed.\n"); } 
  param& operator=(param const& a) { printf("param assigned.\n"); data = a.data; return *this; } 

  int data; 
}; 


double seven() { return 7.0; } 
string more() { return string("more"); } 
int f0(void) { printf("f0 called\n"); return 0; } 
int f1(int) { printf("f1 called\n"); return 1; } 
int f2(int const& a) { printf("f2 called\n"); return 2; } 
int f3(int& a) { printf("f3 called\n"); a = 3; return a; } 
int f4(param p) { printf("f4 called\n"); return 4; } 
int f5(param& p) { printf("f5 called\n"); p.data = 5; return 5; } 
int f6(param const& p) { printf("f6 called\n"); return 6; } 

template <typename FunctorT>
void demo(FunctorT func)
{
  printf("Functor %s\nreturn type: %s\n", 
    typeid(func).name(), 
    typeid(typename FunctorT::ReturnT).name()); 
  cout << func() << endl; 
}

int _tmain(int argc, _TCHAR* argv[])
{
  printf("fuctor: %s\nreturn type: %s\nparam1 type: %s\nparam2 type: %s.\n"
    , typeid(PersonSortCriterion).name()
    , typeid(PersonSortCriterion::ReturnT).name()
    , typeid(PersonSortCriterion::Param1T).name()
    , typeid(PersonSortCriterion::Param2T).name()); 

  printf("fuctor: %s\nreturn type: %s\nparam1 type: %s\nparam2 type: %s\nparam3 type: %s\nparam0 type: %s.\n"
    , typeid(PersonSortCriterion).name()
    , typeid(PersonSortCriterion::ReturnT).name()
    , typeid(FunctorParam<PersonSortCriterion, 1>::Type).name()
    , typeid(FunctorParam<PersonSortCriterion, 2>::Type).name()
    , typeid(FunctorParam<PersonSortCriterion, 3>::Type).name()
    , typeid(FunctorParam<PersonSortCriterion, 0>::Type).name()); 

  FunctorParam<PersonSortCriterion, 4>::Type t; 
  memset(&t, 0, sizeof(t)); 
  printf("type: %s.\n", typeid(t).name()); 

  //FunctorParam<PersonSortCriterion, 1>::Unused::Type t2; 
  test::visible v; 
  v.print(); 

  //test::hidden h; 
  //h.print(); 

  demo(func_ptr(seven)); 
  demo(func_ptr(more)); 

  typedef FunctionPtr<void> F1;  
  printf("fuctor: %s\nreturn type: %s\nparam1 type: %s\nparam2 type: %s\nparam3 type: %s\nparam0 type: %s.\n"
    , typeid(F1).name()
    , typeid(F1::ReturnT).name()
    , typeid(FunctorParam<F1, 1>::Type).name()
    , typeid(FunctorParam<F1, 2>::Type).name()
    , typeid(FunctorParam<F1, 3>::Type).name()
    , typeid(FunctorParam<F1, 0>::Type).name()); 
  
  typedef FunctionPtr<int, int, float, double> F2;  
  printf("fuctor: %s\nreturn type: %s\nparam1 type: %s\nparam2 type: %s\nparam3 type: %s\nparam0 type: %s.\n"
    , typeid(F2).name()
    , typeid(F2::ReturnT).name()
    , typeid(FunctorParam<F2, 1>::Type).name()
    , typeid(FunctorParam<F2, 2>::Type).name()
    , typeid(FunctorParam<F2, 3>::Type).name()
    , typeid(FunctorParam<F2, 0>::Type).name()); 

  FunctionPtr<int> fp0(f0); 
  FunctionPtr<int, int> fp1(f1); 
  FunctionPtr<int, int const&> fp2(f2); 
  FunctionPtr<int, int&> fp3(f3); 
  FunctionPtr<int, param> fp4(f4); 
  FunctionPtr<int, param&> fp5(f5); 
  FunctionPtr<int, param const&> fp6(f6); 

  int a = 0; 
  param p; 
  fp0(); 
  fp1(1); 
  fp2(2); 
  fp3(a); 
  printf("a = %d.\n", a); 
  fp4(p); 
  fp5(p); 
  printf("p.data = %d.\n", p.data); 
  fp6(p); 

  //fp0(0); 
  //fp1(); 

	return 0;
}

