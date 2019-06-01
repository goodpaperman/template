#pragma once

#include "fundat.h" 
#include "classt.h" 
#include "functiont.h" 
#include "enumt.h" 
#include <typeinfo> 

template <typename T>
class CheckT
{
public:
  enum 
  {
    IsFundaT = IsFundaT<T>::Yes, 
    IsPtrT = CompoundT<T>::IsPtrT, 
    IsRefT = CompoundT<T>::IsRefT, 
    IsArrayT = CompoundT<T>::IsArrayT, 
    IsFuncT = CompoundT<T>::IsFuncT, 
    IsPtrMemT = CompoundT<T>::IsPtrMemT, 
    IsEnumT = IsEnumT<T>::Yes, 
    IsClassT = IsClassT<T>::Yes, 
  }; 
}; 

template <typename T>
void check()
{
  if(CheckT<T>::IsFundaT)
    printf(" IsFundaT "); 
  if(CheckT<T>::IsPtrT)
    printf(" IsPtrT "); 
  if(CheckT<T>::IsRefT)
    printf(" IsRefT "); 
  if(CheckT<T>::IsArrayT)
    printf(" IsArrayT "); 
  if(CheckT<T>::IsFuncT)
    printf(" IsFuncT "); 
  if(CheckT<T>::IsPtrMemT)
    printf(" IsPtrMemT "); 
  if(CheckT<T>::IsEnumT)
    printf(" IsEnumT "); 
  if(CheckT<T>::IsClassT)
    printf(" IsClassT "); 
  printf("\n"); 
}

template <typename T>
//void checkT(T)
void check_t()
{
  printf("check type: %s\n", typeid(T).name()); 
  check<T>(); 

  if(CheckT<T>::IsPtrT || CheckT<T>::IsRefT || CheckT<T>::IsPtrMemT || CheckT<T>::IsArrayT)
  {
    // recursive check.
    //printf("check base type: %s\n", typeid(typename CompoundT<T>::BaseT).name()); 
    check_t<typename CompoundT<T>::BaseT>(); 
  }

  printf("\n"); 
}
