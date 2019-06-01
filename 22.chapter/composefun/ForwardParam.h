#pragma once

#include "ifthenelse.h" 
#include "isclasst.h" 
#include "typeop.h" 

template <typename T>
class ForwardParamT
{
public:
  typedef typename IfThenElse<
    IsClassT<T>::Yes, 
    typename TypeOp<T>::RefConstT, 
    typename TypeOp<T>::ArgT>::ResultT Type; 
};

template <>
class ForwardParamT<void>
{
private:
  class Unused { }; 

public:
  typedef Unused Type; 
}; 
