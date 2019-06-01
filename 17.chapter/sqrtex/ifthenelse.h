#pragma once

template <bool C, typename TA, typename TB>
class IfThenElse; 

template <typename TA, typename TB>
class IfThenElse<true, TA, TB>
{
public:
  typedef TA ResultT; 
}; 

template <typename TA, typename TB>
class IfThenElse<false, TA, TB>
{
public:
  typedef TB ResultT; 
}; 