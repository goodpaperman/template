// typedist.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "fundat.h" 
#include "compoundt.h" 
#include "classt.h" 
#include "enumt.h" 
#include <typeinfo> 
#include "checkt.h" 

template <typename T>
void test(T const& t)
{
  if(IsFundaT<T>::Yes)
    printf("%s is fundamental type.\n", typeid(T).name()); 
  else 
    printf("%s is not fundamental type.\n", typeid(T).name()); 
}

class MyType
{
//public:
//  int mem1; 
//  float mem2; 
//  double mem3; 
//  char* mem4; 
}; 

enum MyEnum
{
  e1, 
}; 


int f1() { printf("f1 called\n"); return 0; }  
void f2(int) { }
long f3(float, int) { return 0; }  

int _tmain(int argc, _TCHAR* argv[])
{
  test(7); 
  test(MyType()); 

  int a = 0; 
  int* pa = &a; 
  int& ra = a; 

  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsRefT = %d\n\n"
    , typeid(int*).name()
    , typeid(CompoundT<int*>::BaseT).name()
    , typeid(CompoundT<int*>::BottomT).name()
    , CompoundT<int*>::IsPtrT
    , CompoundT<int*>::IsRefT); 

  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsRefT = %d\n\n"
    , typeid(int const*).name()
    , typeid(CompoundT<int const*>::BaseT).name()
    , typeid(CompoundT<int const*>::BottomT).name()
    , CompoundT<int const*>::IsPtrT
    , CompoundT<int const*>::IsRefT); 

  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsRefT = %d\n\n"
    , typeid(int* const).name()
    , typeid(CompoundT<int* const>::BaseT).name()
    , typeid(CompoundT<int* const>::BottomT).name()
    , CompoundT<int* const>::IsPtrT
    , CompoundT<int* const>::IsRefT); 

  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsRefT = %d\n\n"
    , typeid(float***).name()
    , typeid(CompoundT<float***>::BaseT).name()
    , typeid(CompoundT<float***>::BottomT).name()
    , CompoundT<float***>::IsPtrT
    , CompoundT<float***>::IsRefT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsRefT = %d\n\n"
    , typeid(int&).name()
    , typeid(CompoundT<int&>::BaseT).name()
    , typeid(CompoundT<int&>::BottomT).name()
    , CompoundT<int&>::IsPtrT
    , CompoundT<int&>::IsRefT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsRefT = %d\n\n"
    , typeid(int**&).name()
    , typeid(CompoundT<int**&>::BaseT).name()
    , typeid(CompoundT<int**&>::BottomT).name()
    , CompoundT<int**&>::IsPtrT
    , CompoundT<int**&>::IsRefT); 
  
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsArrayT = %d\n\n"
    , typeid(int[4]).name()
    , typeid(CompoundT<int[4]>::BaseT).name()
    , typeid(CompoundT<int[4]>::BottomT).name()
    , CompoundT<int[4]>::IsPtrT
    , CompoundT<int[4]>::IsArrayT); 

  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsArrayT = %d\n\n"
    , typeid(int[]).name()
    , typeid(CompoundT<int[]>::BaseT).name()
    , typeid(CompoundT<int[]>::BottomT).name()
    , CompoundT<int[]>::IsPtrT
    , CompoundT<int[]>::IsArrayT); 

  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsArrayT = %d\n\n"
    , typeid(float*[]).name()
    , typeid(CompoundT<float*[]>::BaseT).name()
    , typeid(CompoundT<float*[]>::BottomT).name()
    , CompoundT<float*[]>::IsPtrT
    , CompoundT<float*[]>::IsArrayT); 

  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsArrayT = %d\n\n"
    , typeid(float**[3]).name()
    , typeid(CompoundT<float**[3]>::BaseT).name()
    , typeid(CompoundT<float**[3]>::BottomT).name()
    , CompoundT<float**[3]>::IsPtrT
    , CompoundT<float**[3]>::IsArrayT); 

  //printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsArrayT = %d\n\n"
  //  , typeid(int&[4]).name()
  //  , typeid(CompoundT<int&[4]>::BaseT).name()
  //  , typeid(CompoundT<int&[4]>::BottomT).name()
  //  , CompoundT<int&[4]>::IsPtrT
  //  , CompoundT<int&[4]>::IsArrayT); 

  //printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsArrayT = %d\n\n"
  //  , typeid(int(&)[4]).name()
  //  , typeid(CompoundT<int(&)[4]>::BaseT).name()
  //  , typeid(CompoundT<int(&)[4]>::BottomT).name()
  //  , CompoundT<int(&)[4]>::IsPtrT
  //  , CompoundT<int(&)[4]>::IsArrayT);

  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsArrayT = %d\n\n"
    , typeid(int(*)[42]).name()
    , typeid(CompoundT<int(*)[42]>::BaseT).name()
    , typeid(CompoundT<int(*)[42]>::BottomT).name()
    , CompoundT<int(*)[42]>::IsPtrT
    , CompoundT<int(*)[42]>::IsArrayT); 

  //int c[42] = { 0 }; 
  //int (*p)[42] = &c; 
  //(*p)[0] = 1; 
  //p[0][41] = 41; 

  printf("type: %s\nbase type: %s\nbottom type: %s\nIsPtrT = %d\nIsArrayT = %d\n\n"
    , typeid(int[4][3]).name()
    , typeid(CompoundT<int[4][3]>::BaseT).name()
    , typeid(CompoundT<int[4][3]>::BottomT).name()
    , CompoundT<int[4][3]>::IsPtrT
    , CompoundT<int[4][3]>::IsArrayT);  

  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsPtrMemT = %d\n\n"
    , typeid(int MyType::*).name()
    , typeid(CompoundT<int MyType::*>::BaseT).name()
    , typeid(CompoundT<int MyType::*>::BottomT).name()
    , typeid(CompoundT<int MyType::*>::ClassT).name()
    , CompoundT<int MyType::*>::IsPtrT
    , CompoundT<int MyType::*>::IsPtrMemT); 

  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsPtrMemT = %d\n\n"
    , typeid(int** MyType::*).name()
    , typeid(CompoundT<int** MyType::*>::BaseT).name()
    , typeid(CompoundT<int** MyType::*>::BottomT).name()
    , typeid(CompoundT<int** MyType::*>::ClassT).name()
    , CompoundT<int** MyType::*>::IsPtrT
    , CompoundT<int** MyType::*>::IsPtrMemT); 

  //printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsPtrMemT = %d\n\n"
  //  , typeid(int& MyType::*).name()
  //  , typeid(CompoundT<int& MyType::*>::BaseT).name()
  //  , typeid(CompoundT<int& MyType::*>::BottomT).name()
  //  , typeid(CompoundT<int& MyType::*>::ClassT).name()
  //  , CompoundT<int& MyType::*>::IsPtrT
  //  , CompoundT<int& MyType::*>::IsPtrMemT); 


  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsPtrMemT = %d\nIsArrayT = %d\n\n"
    , typeid(int MyType::* [4]).name()
    , typeid(CompoundT<int MyType::* [4]>::BaseT).name()
    , typeid(CompoundT<int MyType::* [4]>::BottomT).name()
    , typeid(CompoundT<int MyType::* [4]>::ClassT).name()
    , CompoundT<int MyType::* [4]>::IsPtrT
    , CompoundT<int MyType::* [4]>::IsPtrMemT
    , CompoundT<int MyType::* [4]>::IsArrayT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsPtrMemT = %d\nIsArrayT = %d\n\n"
    , typeid(int (MyType::*) ()).name()
    , typeid(CompoundT<int (MyType::*) ()>::BaseT).name()
    , typeid(CompoundT<int (MyType::*) ()>::BottomT).name()
    , typeid(CompoundT<int (MyType::*) ()>::ClassT).name()
    , CompoundT<int (MyType::*) ()>::IsPtrT
    , CompoundT<int (MyType::*) ()>::IsPtrMemT
    , CompoundT<int (MyType::*) ()>::IsArrayT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsFuncT = %d\n\n"
    , typeid(int()).name()
    , typeid(CompoundT<int()>::BaseT).name()
    , typeid(CompoundT<int()>::BottomT).name()
    , typeid(CompoundT<int()>::ClassT).name()
    , CompoundT<int()>::IsPtrT
    , CompoundT<int()>::IsFuncT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsFuncT = %d\n\n"
    , typeid(int*()).name()
    , typeid(CompoundT<int*()>::BaseT).name()
    , typeid(CompoundT<int*()>::BottomT).name()
    , typeid(CompoundT<int*()>::ClassT).name()
    , CompoundT<int*()>::IsPtrT
    , CompoundT<int*()>::IsFuncT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsFuncT = %d\n\n"
    , typeid(int(*)()).name()
    , typeid(CompoundT<int(*)()>::BaseT).name()
    , typeid(CompoundT<int(*)()>::BottomT).name()
    , typeid(CompoundT<int(*)()>::ClassT).name()
    , CompoundT<int(*)()>::IsPtrT
    , CompoundT<int(*)()>::IsFuncT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsFuncT = %d\n\n"
    , typeid(int(float)).name()
    , typeid(CompoundT<int(float)>::BaseT).name()
    , typeid(CompoundT<int(float)>::BottomT).name()
    , typeid(CompoundT<int(float)>::ClassT).name()
    , CompoundT<int(float)>::IsPtrT
    , CompoundT<int(float)>::IsFuncT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsFuncT = %d\n\n"
    , typeid(int(*)(float)).name()
    , typeid(CompoundT<int(*)(float)>::BaseT).name()
    , typeid(CompoundT<int(*)(float)>::BottomT).name()
    , typeid(CompoundT<int(*)(float)>::ClassT).name()
    , CompoundT<int(*)(float)>::IsPtrT
    , CompoundT<int(*)(float)>::IsFuncT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsFuncT = %d\n\n"
    , typeid(void (int, int)).name()
    , typeid(CompoundT<void (int, int)>::BaseT).name()
    , typeid(CompoundT<void (int, int)>::BottomT).name()
    , typeid(CompoundT<void (int, int)>::ClassT).name()
    , CompoundT<void (int, int)>::IsPtrT
    , CompoundT<void (int, int)>::IsFuncT); 
  
  printf("type: %s\nbase type: %s\nbottom type: %s\nclass type: %s\nIsPtrT = %d\nIsFuncT = %d\nIsArrayT = %d\n\n"
    , typeid(int (*[4])()).name()
    , typeid(CompoundT<int (*[4])()>::BaseT).name()
    , typeid(CompoundT<int (*[4])()>::BottomT).name()
    , typeid(CompoundT<int (*[4])()>::ClassT).name()
    , CompoundT<int (*[4])()>::IsPtrT
    , CompoundT<int (*[4])()>::IsFuncT
    , CompoundT<int (*[4])()>::IsArrayT); 

  printf("%s is function: %d.\n", typeid(int()).name(), IsFunctionT<int()>::Yes); 
  printf("%s is function: %d.\n", typeid(int*()).name(), IsFunctionT<int*()>::Yes); 
  printf("%s is function: %d.\n", typeid(int(void*)).name(), IsFunctionT<int(void*)>::Yes); 
  printf("%s is function: %d.\n", typeid(int(*)()).name(), IsFunctionT<int(*)()>::Yes); 
  printf("%s is function: %d.\n", typeid(int[4]).name(), IsFunctionT<int[4]>::Yes); 
  printf("%s is function: %d.\n", typeid(int(*)[4]).name(), IsFunctionT<int(*)[4]>::Yes); 
  printf("%s is function: %d.\n", typeid(int MyType::*).name(), IsFunctionT<int MyType::*>::Yes); 
  printf("%s is function: %d.\n", typeid(int (MyType::*)()).name(), IsFunctionT<int (MyType::*)()>::Yes); 
  printf("%s is function: %d.\n", typeid(int (*[4])()).name(), IsFunctionT<int(*[4])()>::Yes); 
  printf("%s is function: %d.\n", typeid(void).name(), IsFunctionT<void>::Yes); 
  printf("%s is function: %d.\n", typeid(void const).name(), IsFunctionT<void const>::Yes); 
  printf("%s is function: %d.\n", typeid(int&).name(), IsFunctionT<int&>::Yes); 
  printf("\n"); 

  //int (*x[4])();  
  //x[0] = f1; 
  //(*x[0])(); 

  printf("%s is class: %d.\n", typeid(MyType).name(), IsClassT<MyType>::Yes); 
  printf("%s is class: %d.\n", typeid(MyEnum).name(), IsClassT<MyEnum>::Yes); 
  printf("%s is class: %d.\n", typeid(int).name(), IsClassT<int>::Yes); 
  printf("%s is class: %d.\n", typeid(int*).name(), IsClassT<int*>::Yes); 
  printf("%s is class: %d.\n", typeid(int&).name(), IsClassT<int&>::Yes); 
  printf("%s is class: %d.\n", typeid(int()).name(), IsClassT<int()>::Yes); 
  printf("%s is class: %d.\n", typeid(int(*)()).name(), IsClassT<int(*)()>::Yes); 
  printf("%s is class: %d.\n", typeid(int[4]).name(), IsClassT<int[4]>::Yes); 
  printf("%s is class: %d.\n", typeid(int MyType::*).name(), IsClassT<int MyType::*>::Yes); 
  printf("%s is class: %d.\n", typeid(int (MyType::*)()).name(), IsClassT<int (MyType::*)()>::Yes); 
  printf("%s is class: %d.\n", typeid(int (*[4])()).name(), IsClassT<int (*[4])()>::Yes); 
  printf("\n"); 

  printf("%s is enum: %d.\n", typeid(MyType).name(), IsEnumT<MyType>::Yes); 
  printf("%s is enum: %d.\n", typeid(MyEnum).name(), IsEnumT<MyEnum>::Yes); 
  printf("%s is enum: %d.\n", typeid(int).name(), IsEnumT<int>::Yes); 
  printf("%s is enum: %d.\n", typeid(int*).name(), IsEnumT<int*>::Yes); 
  printf("%s is enum: %d.\n", typeid(int&).name(), IsEnumT<int&>::Yes); 
  printf("%s is enum: %d.\n", typeid(int()).name(), IsEnumT<int()>::Yes); 
  printf("%s is enum: %d.\n", typeid(int(*)()).name(), IsEnumT<int(*)()>::Yes); 
  printf("%s is enum: %d.\n", typeid(int[4]).name(), IsEnumT<int[4]>::Yes); 
  printf("%s is enum: %d.\n", typeid(int MyType::*).name(), IsEnumT<int MyType::*>::Yes); 
  printf("%s is enum: %d.\n", typeid(int (MyType::*)()).name(), IsEnumT<int (MyType::*)()>::Yes); 
  printf("%s is enum: %d.\n", typeid(int (*[4])()).name(), IsEnumT<int (*[4])()>::Yes); 

  check_t<MyType>(); 
  check_t<MyEnum>(); 
  check_t<int>(); 
  check_t<int*>(); 
  check_t<int&>(); 
  check_t<int()>(); 
  check_t<int(*)()>(); 
  check_t<int[4]>(); 
  check_t<int[]>(); 
  check_t<int MyType::*>(); 
  check_t<int (MyType::*)()>(); 
  check_t<int (*[4])()>(); 
  check_t<int (MyType::*) [4]>(); 
  check_t<int MyType::* [4]>(); 
  check_t<int*&>(); 
  check_t<int*[4]>(); 
  check_t<int***>(); 
  check_t<int[4][2][3]>(); 
  check_t<int(*)[42]>(); 
  return 0;
}

