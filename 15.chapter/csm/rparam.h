#pragma once

#include "ifthenelse.h" 

template <typename T>
class RParam
{
public:
  typedef typename IfThenElse<IsClassT<T>::No, T, T const&>::ResultT Type; 
}; 