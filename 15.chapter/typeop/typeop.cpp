// typeop.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "typeop.h" 
#include <typeinfo> 

#if 0
template <typename T>
void apply(T& arg, void (*func)(T))
{
  func(arg); 
}
#endif 

template <typename T>
void apply(typename TypeOp<T>::RefT arg, void (*func)(T))
{
  func(arg); 
}

void incr(int& a)
{
  ++ a; 
}

void print(int a)
{
  printf("a = %d\n", a); 
}

//template <typename T>
//class print_type
//{
//public:
//  print_type()
//  {
//    printf("T = %s\nArgT = %s\nBareT = %s\nConstT = %s\nRefT = %s\nRefBareT = %s\nRefConstT = %s\n"
//      , typeid(T).name() 
//      , typeid(typename TypeOp<T>::ArgT).name()
//      , typeid(typename TypeOp<T>::BareT).name()
//      , typeid(typename TypeOp<T>::ConstT).name()
//      , typeid(typename TypeOp<T>::RefT).name()
//      , typeid(typename TypeOp<T>::RefBareT).name()
//      , typeid(typename TypeOp<T>::RefConstT).name()); 
//  }
//}; 

int _tmain(int argc, _TCHAR* argv[])
{
  int x = 7; 
  apply(x, incr); 
  apply(x, print); 

  //int t0 = 0; 
  //int const t1 = 1; 
  //int& t2 = t0; 
  //int const& t3 = t1; 

  //print_type<int> t0; 
  //print_type<int const> t1; 
  //print_type<int&> t2; 
  //print_type<int const&> t3; 

  //printf("\nT = %s\nArgT = %s\nBareT = %s\nConstT = %s\nRefT = %s\nRefBareT = %s\nRefConstT = %s\n"
  //  , typeid(int).name() 
  //  , typeid(TypeOp<int>::ArgT).name()
  //  , typeid(TypeOp<int>::BareT).name()
  //  , typeid(TypeOp<int>::ConstT).name()
  //  , typeid(TypeOp<int>::RefT).name()
  //  , typeid(TypeOp<int>::RefBareT).name()
  //  , typeid(TypeOp<int>::RefConstT).name()); 
  //
  //printf("\nT = %s\nArgT = %s\nBareT = %s\nConstT = %s\nRefT = %s\nRefBareT = %s\nRefConstT = %s\n"
  //  , typeid(int const).name() 
  //  , typeid(TypeOp<int const>::ArgT).name()
  //  , typeid(TypeOp<int const>::BareT).name()
  //  , typeid(TypeOp<int const>::ConstT).name()
  //  , typeid(TypeOp<int const>::RefT).name()
  //  , typeid(TypeOp<int const>::RefBareT).name()
  //  , typeid(TypeOp<int const>::RefConstT).name()); 
  //
  //printf("\nT = %s\nArgT = %s\nBareT = %s\nConstT = %s\nRefT = %s\nRefBareT = %s\nRefConstT = %s\n"
  //  , typeid(int const&).name() 
  //  , typeid(TypeOp<int const&>::ArgT).name()
  //  , typeid(TypeOp<int const&>::BareT).name()
  //  , typeid(TypeOp<int const&>::ConstT).name()
  //  , typeid(TypeOp<int const&>::RefT).name()
  //  , typeid(TypeOp<int const&>::RefBareT).name()
  //  , typeid(TypeOp<int const&>::RefConstT).name()); 
  //
  //printf("\nT = %s\nArgT = %s\nBareT = %s\nConstT = %s\nRefT = %s\nRefBareT = %s\nRefConstT = %s\n"
  //  , typeid(int&).name() 
  //  , typeid(TypeOp<int&>::ArgT).name()
  //  , typeid(TypeOp<int&>::BareT).name()
  //  , typeid(TypeOp<int&>::ConstT).name()
  //  , typeid(TypeOp<int&>::RefT).name()
  //  , typeid(TypeOp<int&>::RefBareT).name()
  //  , typeid(TypeOp<int&>::RefConstT).name()); 
  
  printf("\nT = %s\nArgT = %s\nBareT = %s\nConstT = %s\nRefT = %s\nRefBareT = %s\nRefConstT = %s\n"
    , typeid(void).name() 
    , typeid(TypeOp<void>::ArgT).name()
    , typeid(TypeOp<void>::BareT).name()
    , typeid(TypeOp<void>::ConstT).name()
    , typeid(TypeOp<void>::RefT).name()
    , typeid(TypeOp<void>::RefBareT).name()
    , typeid(TypeOp<void>::RefConstT).name()); 

  return 0;
}

