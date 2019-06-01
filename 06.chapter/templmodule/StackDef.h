
#pragma once
#include "Stack.h" 

template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator =(Stack<T2> const& op2)
{
  std::cout << "Stack template operator =" << std::endl; 
  if(this != (void*)&op2)
  {
    Stack<T2> tmp(op2); 
    elems.clear(); 
    while(!tmp.empty())
    {
      elems.push_front(tmp.top()); 
      tmp.pop(); 
    }

    //elems.assign(op2.elems); 
  }

  return *this; 
}

template <typename T>
void Stack<T>::push(T const& elem)
{
  elems.push_back(elem); 
}

template <typename T>
void Stack<T>::pop()
{
  if(elems.empty())
    throw std::out_of_range("Stack<>::pop() : empty stack"); 

  elems.pop_back(); 
}

template <typename T>
T Stack<T>::top() const
{
  if(elems.empty())
    throw std::out_of_range("Stack<>::top() : empty stack"); 

  return elems.back(); 
}