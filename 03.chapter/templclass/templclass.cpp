// templclass.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string> 
#include <cstdlib> 
#include "stack.h" 
#include "strstack.h" 
#include "stackex.h" 

template <typename T1, typename T2> 
class MyClass
{
public:
  MyClass() { std::cout << "MyClass<T1,T2>" << std::endl; } 
}; 

template <typename T>
class MyClass<T, T>
{
public:
  MyClass() { std::cout << "MyClass<T,T>" << std::endl; } 
}; 

template <typename T>
class MyClass<T, int>
{
public:
  MyClass() { std::cout << "MyClass<T,int>" << std::endl; }
}; 

template <typename T1, typename T2>
class MyClass<T1*, T2*>
{
public:
  MyClass() { std::cout << "MyClass<T1*,T2*>" << std::endl; } 
}; 

template <typename T> 
class MyClass<T*, T*>
{
public:
  MyClass() { std::cout << "MyClass<T*, T*>" << std::endl; } 
}; 


int _tmain(int argc, _TCHAR* argv[])
{
  MyClass<int, float> mif; 
  MyClass<float, float> mff; 
  MyClass<float, int> mfi; 
  MyClass<int*, float*> mp; 

  //MyClass<int, int> mii; 
  MyClass<int*, int*> mpp; 

  try
  {
    StackEx<int> intStack; 
    StackEx<double, std::deque<double> > dblStack; 
    intStack.push(7); 
    std::cout << intStack.top() << std::endl; 
    intStack.pop(); 

    dblStack.push(42.42); 
    std::cout << dblStack.top() << std::endl; 
    dblStack.pop(); 
    dblStack.pop(); 
  }
  catch(std::exception const& ex)
  {
    std::cerr << "Exception: " << ex.what() << std::endl; 
    return EXIT_FAILURE; 
  }
  

  try
  {
    Stack<int> intStack; 
    Stack<std::string> stringStack; 
    intStack.push(7); 
    std::cout << intStack.top() << std::endl; 

    stringStack.push("hello"); 
    std::cout << stringStack.top() << std::endl; 
    stringStack.pop(); 
    stringStack.pop(); 
  }
  catch(std::exception const& ex)
  {
    std::cerr << "Exception: " << ex.what() << std::endl; 
    return EXIT_FAILURE; 
  }

	return 0;
}

