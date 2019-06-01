// templarg.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Stack.h" 
#include <iostream> 
#include <string> 
#include <algorithm> 

template <typename T, int VAL>
T addValue(T const& x)
{
  return x + VAL; 
}

//template <double VAT>
//double process(double v)
//{
//  return v * VAT; 
//}

//template<std::string NAME> 
//class MyClass
//{
//public:
//  std::string name() { return NAME; } 
//}; 

template <char const* NAME> 
class MyClass
{
public:
  MyClass() { }
  char const* name() { return NAME; } 
}; 


//char const* s = "hello"; 
//extern char const s[] = "hello"; 
//char s[] = { "hello" }; 
char s[100] = "hello"; 

int _tmain(int argc, _TCHAR* argv[])
{
  //MyClass<"hello"> x; 
  MyClass<s> x; 
  std::cout << "x = \"" << x.name() << "\"" << std::endl; 

  int src[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
  int dest[10] = { 0 }; 

  //addValue<int, 8>(src[0]); 
  std::transform(src, src+10, dest, /*(int (*)(int const&))*/addValue<int, 5>); 
  std::cout << "after transform: " << std::endl; 
  for(int i=0; i<10; ++ i)
    std::cout << dest[i] << "  "; 

  std::cout << std::endl; 

  try
  {
    Stack<int, 20> int20Stack; 
    Stack<int, 40> int40Stack; 
    Stack<std::string, 40> str40Stack; 

    int20Stack.push(7); 
    std::cout << int20Stack.top() << std::endl; 
    int20Stack.pop(); 

    str40Stack.push("hello"); 
    std::cout << str40Stack.top() << std::endl; 
    str40Stack.pop(); 
    str40Stack.pop(); 
  }
  catch(std::exception const& ex)
  {
    std::cerr << "Exception: " << ex.what() << std::endl; 
    return EXIT_FAILURE; 
  }

	return 0;
}

