
#include "stdafx.h" 
#include "StackDef.h" 
#include <string.h> 

template Stack<int>; 
template Stack<std::string>::Stack(); 
template void Stack<std::string>::push(std::string const&); 
template void Stack<std::string>::pop(); 
template std::string Stack<std::string>::top() const; 

template void Stack<int>::pop(); 
template Stack<int>; 