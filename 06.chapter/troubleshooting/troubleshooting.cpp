// troubleshooting.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <list> 
#include <string> 
#include <algorithm> 

template <typename T>
void clear(T const& p)
{
  *p = 0; 
}

template <typename T>
void core(T const& p)
{
  clear(p); 
}

template <typename T>
void middle(typename T::Index p)
{
  core(p); 
}

template <typename T>
inline void ignore(T const&)
{
}

template <typename T>
void shell(T const& env)
{
  class ShallowChecks
  {
    void deref(T::Index ptr)
    { ignore(*ptr); } 
  }; 

  typename T::Index i; 
  middle<T>(i); 
}

class Client
{
public:
  typedef int Index; 
  //typedef int* Index; 
}; 

Client main_client; 


int _tmain(int argc, _TCHAR* argv[])
{
  //std::list<std::string> coll; 
  //std::list<std::string>::iterator pos = 
  //  std::find_if(coll.begin(), coll.end(), 
  //  std::bind2nd(std::greater<int>(), "A")); 

  shell(main_client); 
	return 0;
}

