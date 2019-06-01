#pragma once

#include "typeop.h" 


template <typename T>
class IsVoidT
{
public:
  enum { Result = 0 }; 
}; 

template <>
class IsVoidT<void>
{
public:
  enum { Result = 1 }; 
}; 

template <typename T>
class RParam
{
private:
  class Unused { }; 

public:
  typedef Unused UnusedType; 
  typedef typename IfThenElse<
    IsVoidT<T>::Result, 
    UnusedType,  
    typename TypeOp<T>::RefConstT>::ResultT Type; 
}; 