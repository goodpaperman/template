// ebco.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BaseMemberPair.h" 


class EmptyClass
{
public:
  typedef int Int; 
  //int i; 
}; 

class EmptyToo : public EmptyClass
{
}; 

class EmptyThree : public EmptyToo
{
}; 

class NonEmpty : public EmptyClass, public EmptyToo
{
}; 

class NonEmptyToo : public EmptyClass, public EmptyToo, public EmptyThree
{
}; 

class MemEmpty
{
public:
  EmptyClass a, b; 
}; 

template <typename CustomClass>
class NonOptimizable
{
public:
  CustomClass info; 
  void* storage; 
}; 

template <typename CustomClass>
class Optimizable
{
public:
  Optimizable() : info_and_storage(CustomClass(), 0) { }
  BaseMemberPair<CustomClass, void*> info_and_storage; 
}; 

int _tmain(int argc, _TCHAR* argv[])
{

  printf("sizeof(EmptyClass) = %d.\n", sizeof(EmptyClass)); 
  printf("sizeof(EmptyToo) = %d.\n", sizeof(EmptyToo)); 
  printf("sizeof(EmptyThree) = %d.\n", sizeof(EmptyThree)); 
  printf("sizeof(NonEmpty) = %d.\n", sizeof(NonEmpty)); 
  printf("sizeof(NonEmptyToo) = %d.\n", sizeof(NonEmptyToo)); 
  printf("sizeof(MemEmpty) = %d.\n", sizeof(MemEmpty)); 
  printf("sizeof(NonOptimizable<EmptyClass>) = %d.\n", sizeof(NonOptimizable<EmptyClass>)); 
  printf("sizeof(Optimizable<EmptyClass>) = %d.\n", sizeof(Optimizable<EmptyClass>)); 

  NonEmpty ne[2]; 
  for(int i=0; i<2; ++ i)
  {
    EmptyClass* p1 = &ne[i]; 
    EmptyToo* p2 = &ne[i]; 
    NonEmpty* p3 = &ne[i]; 
    printf("base1 = %p, base2 = %p, base = %p\n", p1, p2, p3); 
  }

  EmptyClass* p1 = &ne[1]; 
  EmptyToo* p2 = &ne[0]; 
  if(p1 == p2)
    printf("same object, %p == %p.\n", p1, p2); 

  NonEmptyToo net; 
  p1 = &net; 
  p2 = &net; 
  EmptyThree* p3 = &net; 
  printf("base1 = %p, base2 = %p, base = %p\n", p1, p2, p3); 

  //Optimizable<EmptyClass> oe; 
  //oe.info_and_storage.first().i = (int)&oe; 
  //oe.info_and_storage.second() = &oe; 

  //printf("member: i = %d, storage = %p.\n"
  //  , oe.info_and_storage.first().i
  //  , oe.info_and_storage.second()); 

	return 0;
}

