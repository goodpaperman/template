// ondemand.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

template <typename T> 
class C; 

C<int>* p = 0; 

void g(C<int>& c)
{
  //c.f(); 
}

template <typename T>
class D
{
public:
  D(int) { }
}; 

void candidate(D<double> const&) { printf("candidate(D<double> const&) called\n"); }  
void candidate(int) { printf("candidate(int) called\n"); } 

template <typename T>
class Safe
{
}; 

template <int N>
class Danger
{
public:
  typedef char Block[N];
  Block blocks; 
}; 

template <typename T, int N>
class Tricky
{
public:
  virtual ~Tricky() {}
  void no_body_here(Safe<T> = 3) { }
  void inclass() 
  {
    Danger<N> no_boom_yet; 
  } 

  void error()
  {
    Danger<-2> boom; 
  }

  //void unsafe(T (*p)[N]) 
  //{ 
  //  printf("Tricky::unsafe\n"); 
  //}

  T operator->() { return T(); } 

  //virtual Safe<T> suspect(); 
  struct Nested
  {
    Danger<N> pfew; 
    //Danger<-2> pfew; 
  }; 

  union
  {
    int align; 
    Safe<T> anonymous; 
    //Danger<N> boom; 
  }; 
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  //g(0); 
  //p = new C<int>(); 

  candidate(42); 
  candidate(D<double>(42)); 

  Tricky<int, -2> ok; 
  //ok.error(); 
  //ok.unsafe(0); 

  //Tricky<int, -2>::Nested nest; 
  //nest.pfew.blocks[0] = 'b'; 

  //ok.boom.blocks[0] = 'c'; 

  //ok->hello(); 
  printf("ok->%d\n", ok.operator ->()); 

  //ok.inclass(); 

  //ok.no_body_here(Safe<int>()); 
	return 0;
}

