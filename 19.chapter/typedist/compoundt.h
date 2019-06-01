#pragma once

#include "functiont.h" 
#include "classt.h" 


template <typename T>
class CompoundT
{
public:
  enum 
  {
    IsPtrT = 0, 
    IsRefT = 0, 
    IsArrayT = 0, 
    IsFuncT = IsFunctionT<T>::Yes, 
    IsPtrMemT = 0, 
  }; 

  typedef T BaseT; 
  typedef T BottomT; 
  typedef CompoundT<void> ClassT; 
};

template <typename T>
class CompoundT<T&>
{
public:
  enum
  {
    IsPtrT = 0, 
    IsRefT = 1, 
    IsArrayT = 0, 
    IsFuncT = 0, 
    IsPtrMemT = 0, 
  }; 

  typedef T BaseT; 
  typedef typename CompoundT<T>::BottomT BottomT; 
  typedef CompoundT<void> ClassT; 
}; 

template <typename T>
class CompoundT<T*>
{
public:
  enum
  {
    IsPtrT = 1, 
    IsRefT = 0, 
    IsArrayT = 0, 
    IsFuncT = 0, 
    IsPtrMemT = 0, 
  }; 

  typedef T BaseT; 
  typedef typename CompoundT<T>::BottomT BottomT; 
  typedef CompoundT<void> ClassT; 
}; 

template <typename T, size_t N>
class CompoundT<T[N]>
{
public:
  enum
  {
    IsPtrT = 0, 
    IsRefT = 0, 
    IsArrayT = 1, 
    IsFuncT = 0, 
    IsPtrMemT = 0, 
  }; 

  typedef T BaseT; 
  typedef typename CompoundT<T>::BottomT BottomT; 
  typedef CompoundT<void> ClassT; 
}; 

template <typename T>
class CompoundT<T[]>
{
public:
  enum
  {
    IsPtrT = 0, 
    IsRefT = 0, 
    IsArrayT = 1, 
    IsFuncT = 0, 
    IsPtrMemT = 0, 
  }; 

  typedef T BaseT; 
  typedef typename CompoundT<T>::BottomT BottomT; 
  typedef CompoundT<void> ClassT; 
}; 

template <typename T, typename C>
class CompoundT<T C::*>
{
public:
  enum
  {
    IsPtrT = 0, 
    IsRefT = 0, 
    IsArrayT = 0, 
    IsFuncT = 0, 
    IsPtrMemT = 1, 
  }; 

  typedef T BaseT; 
  typedef typename CompoundT<T>::BottomT BottomT; 
  typedef C ClassT; 
}; 

//template <typename R>
//class CompoundT<R()>
//{
//public:
//  enum
//  {
//    IsPtrT = 0, 
//    IsRefT = 0, 
//    IsArrayT = 0, 
//    IsFuncT = 1, 
//    IsPtrMemT = 0, 
//  }; 
//
//  typedef R BaseT(); 
//  typedef R BottomT(); 
//  typedef CompoundT<void> ClassT; 
//}; 
//
//template <typename R, typename P1>
//class CompoundT<R(P1)>
//{
//public:
//  enum
//  {
//    IsPtrT = 0, 
//    IsRefT = 0, 
//    IsArrayT = 0, 
//    IsFuncT = 1, 
//    IsPtrMemT = 0, 
//  }; 
//
//  typedef R BaseT(P1); 
//  typedef R BottomT(P1); 
//  typedef CompoundT<void> ClassT; 
//}; 
//
//template <typename R, typename P1>
//class CompoundT<R(P1, ...)>
//{
//public:
//  enum
//  {
//    IsPtrT = 0, 
//    IsRefT = 0, 
//    IsArrayT = 0, 
//    IsFuncT = 1, 
//    IsPtrMemT = 0, 
//  }; 
//
//  typedef R BaseT(P1); 
//  typedef R BottomT(P1); 
//  typedef CompoundT<void> ClassT; 
//}; 

