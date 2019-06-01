// templbase.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> 
#include <vector> 
#include <list> 
#include <string> 
#include <bitset> 
#include "Stack.h" 
#include "StackEx.h" 

template <typename T>
void printcoll(T const& coll)
{
  typename T::const_iterator pos; 
  typename T::const_iterator end(coll.end()); 
  for(pos = coll.begin(); pos != end; ++ pos)
    std::cout << *pos << ' '; 

  std::cout << std::endl; 
}

template <int N>
void printBitset(std::bitset<N> const& bs)
{
  std::cout << bs./*template */to_string/*<char, std::char_traits<char>, std::allocator<char> >*/() << std::endl; 
}

template <typename T>
class Base
{
public:
  void exit() { std::cout << "Base::exit" << std::endl; } 
}; 

template <typename T>
class Derived : public Base<T>
{
public:
  void foo() { exit(); } 
  //void foo() { this->exit(); } 
  //void foo() { Base<T>::exit(); } 
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  {
    StackEx<int> intStack1; 
    StackEx<int, std::vector<int> > intStack2; 
    StackEx<float> floatStack; 

    intStack2.push(2); 
    intStack2.push(3); 
    intStack1 = intStack2; 
    std::cout << "intStack1 = " << intStack1.top() << std::endl; 

    floatStack = intStack1;   
    std::cout << "floatStack = " << floatStack.top() << std::endl; 
  }

  {
    Stack<int> intStack1, intStack2; 
    Stack<float> floatStack; 
    Stack<std::string> stringStack; 

    intStack2.push(2); 
    intStack2.push(3); 
    intStack1 = intStack2; 
    std::cout << "intStack1 = " << intStack1.top() << std::endl; 

    floatStack = intStack1;   
    std::cout << "floatStack = " << floatStack.top() << std::endl; 
  }

  //stringStack = floatStack; 

  Derived<int> der; 
  der.exit(); 
  der.foo(); 

  std::bitset<10> bs; 
  std::cout << bs.to_string() << std::endl; 
  printBitset(bs); 

  std::vector<int> intVec; 
  std::list<std::string> strList; 
  for(int i=0; i<10; ++ i)
  {
    intVec.push_back(i); 
    strList.push_back(std::string(i+1, 'a'+i)); 
  }

  printcoll(intVec); 
  printcoll(strList); 
	return 0;
}

