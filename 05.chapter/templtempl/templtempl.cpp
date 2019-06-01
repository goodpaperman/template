// templtempl.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> 
#include <string> 
#include <vector> 
#include "StackEx.h" 
#include <typeinfo> 

template <typename T>
void foo()
{
  //T x; 
  //T x = 0; 
  T x = T(); 
  std::cout << "x = " << x << std::endl; 
}

template <typename T>
class MyClass
{
public:
  //MyClass() : x(0) 
  MyClass() : x()
  {
    std::cout << "x = " << x << std::endl; 
  }

private:
  T x; 
}; 

template <typename T>
inline T const& max1(T const& a, T const& b)
{
  return a < b ? b : a; 
}

template <typename T>
inline T max2(T a, T b)
{
  return a < b ? b : a; 
}

template <typename T, int N, int M>
T const* max3(T const (&a)[N], T const (&b)[M])
{
  return a < b ? b : a; 
}

template <typename T>
void ref(T const& x)
{
  std::cout << "x in ref(T const&): " << typeid(x).name() << '\n'; 
}

template <typename T>
void nonref(T x)
{
  std::cout << "x in nonref(T): " << typeid(x).name() << '\n'; 
}

int _tmain(int argc, _TCHAR* argv[])
{
  std::cout << "max is : " << ::max3("apple", "peach") << std::endl; 
  std::cout << "max is : " << max3("apple", "tomato") << std::endl; 

  ref("hello"); 
  nonref("hello"); 

  std::string s; 
  std::cout << "max is : " << ::max2("apple", "peach") << std::endl; 
  ::max2("apple", "tomato"); 
  //::max2("apple", s); 

  foo<int>(); 
  foo<double>(); 
  //foo<char const*>(); 

  MyClass<int> mc1; 
  MyClass<double> mc2; 
  //MyClass<char const*> mc3; 

  try
  {
    StackEx<int> intStack; 
    StackEx<float> floatStack; 
    intStack.push(42); 
    intStack.push(7); 

    floatStack.push(7.7); 
    floatStack = intStack; 

    for(int i=0; i<3; ++ i)
    {
      std::cout << floatStack.top() << std::endl; 
      floatStack.pop(); 
    }
  }
  catch(std::exception const& ex)
  {
    std::cerr << "Exception: " << ex.what() << std::endl; 
  }

  StackEx<int, std::vector> vStack; 
  vStack.push(42); 
  vStack.push(7); 
  std::cout << vStack.top() << std::endl; 
  vStack.pop(); 
	return 0;
}

