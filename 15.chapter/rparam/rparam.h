#pragma once



template <typename T>
class RParam
{
public:
  typedef typename IfThenElse<IsClassT<T>::No, T, T const&>::ResultT Type; 
}; 