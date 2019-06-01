// memptr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class B1
{
public:
  void mf1() { b1 = 1; printf("b1 = %d.\n", b1); } 

private:
  int b1; 
}; 

class B2
{
public:
  void mf2() { b2 = 2; printf("b2 = %d.\n", b2); } 

private:
  int b2 ;
}; 

class D : public B1, public B2
{
private:
  int d; 
}; 

void call_memfun(D obj, void (D::*pmf)())
{
  printf("memfun offset: %p.\n", pmf); 
  (obj.*pmf)(); 
}


void call_memfun2(D obj, void (B1::*pmf)())
{
  printf("memfun2 offset: %p.\n", pmf); 
  (obj.*pmf)(); 
}

void call_memfun3(D obj, void (B2::*pmf)())
{
  printf("memfun3 offset: %p.\n", pmf); 
  (obj.*pmf)(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  D obj; 
  obj.mf1(); 
  obj.mf2(); 

  printf("mf1 address: %p.\n", &D::mf1); 
  printf("mf2 address: %p.\n", &D::mf2); 
  call_memfun(obj, &B1::mf1); 
  call_memfun(obj, &B2::mf2); 
  call_memfun(obj, &D::mf1); 
  call_memfun(obj, &D::mf2); 
  call_memfun2(obj, &B1::mf1); 
  call_memfun2(obj, &D::mf1); 
  call_memfun3(obj, &B2::mf2); 
  call_memfun3(obj, &D::mf2); 
	return 0;
}

