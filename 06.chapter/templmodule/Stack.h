#pragma once

#include <deque> 
#include <stdexcept> 

template <typename T>
class Stack
{
public:
  template <typename T2>
  Stack<T>& operator= (Stack<T2> const& op2); 

  void push(T const&); 
  void pop(); 
  T top() const; 
  bool empty() const { return elems.empty(); } 

private:
  std::deque<T> elems; 
};