// templfun.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> 
#include <string> 
#include "max.h" 



int _tmain(int argc, _TCHAR* argv[])
{
  //int i = 42; 
  //std::cout << "max(7, i) : " << ::max(7, i) << std::endl; 

  //double f1 = 3.4; 
  //double f2 = -6.7; 
  //std::cout << "max(f1, f2) : " << ::max(f1, f2) << std::endl; 

  //std::string s1 = "mathematics"; 
  //std::string s2 = "math"; 
  //std::cout << "max(s1, s2) : " << ::max(s1, s2) << std::endl; 
  //std::cout << "max(s1, s2) : " << std::max(s1, s2) << std::endl; 

  //std::cout << "max(4, 4.2) : " << ::max(4, 4.2) << std::endl; 
  ////std::cout << "max(4, 4.2) : " << ::max(static_cast<double>(4), 4.2) << std::endl; 
  ////std::cout << "max(4, 4.2) : " << ::max<double>(4, 4.2) << std::endl; 

  //std::cout << "max(4, 4.2) : " << ::max<int, double, double>(4,4.2) << std::endl; 
  //std::cout << "max(4,4.2) : " << ::max<double>(4, 4.2) << std::endl; 

  //std::cout << "max(7, 42, 68) : " << ::max(7, 42, 68) << std::endl; 
  //std::cout << "max(7.0, 42.0) : " << ::max(7.0, 42.0) << std::endl; 
  //std::cout << "max('a', 'b') : " << ::max('a', 'b') << std::endl; 
  //std::cout << "max(7, 42) : " << ::max(7, 42) << std::endl; 
  //std::cout << "max<>(7, 42) : " << ::max<>(7, 42) << std::endl; 
  //std::cout << "max<double>(7, 42) : " << ::max<double>(7, 42) << std::endl; 
  //std::cout << "max('a', 42.7) : " << ::max('a', 42.7) << std::endl; 

  int a = 7, b = 42; 
  std::cout << "max(a, b) : " << ::max(a, b) << std::endl; 

  std::string s = "hey"; 
  std::string t = "you"; 
  std::cout << "max(s, t) : " << ::max(s, t) << std::endl; 

  int* p1 = &b, *p2 = &a; 
  std::cout << "max(p1, p2) : " << *::max(p1, p2) << std::endl; 

  char const* s1 = "David"; 
  char const* s2 = "Nico"; 
  std::cout << "max(s1, s2) : " << ::max(s1, s2) << std::endl; 

  char const* s3 = "Hai"; 
  std::cout << "max(s1, s2, s3) : " << ::max(s1, s2, s3) << std::endl; 

  char const* c1 = "David", * c2 = "Nico", * c3 = "Yun"; 
  std::cout << "max(c1, c2, c3) : " << ::max(c1, c2, c3) << std::endl; 
	return 0;
}

