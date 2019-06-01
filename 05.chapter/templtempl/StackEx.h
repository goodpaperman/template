#pragma once

#include <deque> 
#include <stdexcept> 

template <typename T, template <typename E, typename A = std::allocator<E> > class CONT = std::deque>
class StackEx
{
public:
  template <typename T2, template <typename E2, typename A2 = std::allocator<E2> > class CONT2>
  StackEx<T, CONT>& operator =(StackEx<T2, CONT2> const& op2); 

  void push(T const&); 
  void pop(); 
  T top() const; 
  bool empty() const { return elems.empty(); }

private:
  CONT<T> elems; 
};

template <typename T, template <typename, typename> class CONT>
template <typename T2, template <typename, typename> class CONT2>
StackEx<T, CONT>& StackEx<T, CONT>::operator =(StackEx<T2, CONT2> const& op2)
{
  if(this != (void*)&op2)
  {
    StackEx<T2, CONT2> tmp(op2); 
    elems.clear(); 
    while(!tmp.empty())
    {
      elems.push_front(tmp.top()); 
      tmp.pop(); 
    }
  }

  return *this; 
}

template <typename T, template <typename, typename> class CONT>
void StackEx<T, CONT>::push(T const& elem)
{
  elems.push_back(elem); 
}

template <typename T, template <typename, typename> class CONT>
void StackEx<T, CONT>::pop()
{
  if(elems.empty())
    throw std::out_of_range("Stack<>::pop() : empty stack"); 

  elems.pop_back(); 
}

template <typename T, template <typename, typename> class CONT>
T StackEx<T, CONT>::top() const
{
  if(elems.empty())
    throw std::out_of_range("Stack<>::top() : empty stack"); 

  return elems.back(); 
}
