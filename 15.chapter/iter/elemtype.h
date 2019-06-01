
#ifndef ELEM_TYPE_H
#define ELEM_TYPE_H

#include <vector> 
#include <list> 
#include <stack> 
#include <deque> 
#include <typeinfo> 

template <typename T>
class ElementT
{
public:
  typedef typename T::value_type Type; 
}; 

template <typename T>
class ElementT<std::vector<T> >
{
public:
  typedef T Type; 
}; 

template <typename T>
class ElementT<std::list<T> >
{
public:
  typedef T Type; 
}; 

template <typename T>
class ElementT<std::stack<T> >
{
public:
  typedef T Type; 
}; 

template <typename T>
void print_element_type(T const& c)
{
  printf("%s of %s elements.\n", typeid(T).name(), typeid(typename ElementT<T>::Type).name()); 
}

#endif 