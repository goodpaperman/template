// templmodule.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream> 
//#include "Stack.h" 
#include "StackDef.h" 


int _tmain(int argc, _TCHAR* argv[])
{
  Stack<int> intStack; 
  intStack.push(7); 
  std::cout << intStack.top() << std::endl; 
	return 0;
}

