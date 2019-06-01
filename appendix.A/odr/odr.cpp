// odr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <typeinfo> 

//#define DYNAMIC
class Decider 
{
#if defined(DYNAMIC)
  virtual ~Decider() {}
#endif 
}; 

extern Decider& d; 
inline int not_so_fast(); 

template <typename T>
int caveman(T const& p); 
extern void increase_counter(); 

int _tmain(int argc, _TCHAR* argv[])
{
  const char* name = typeid(d).name(); 
  printf("Decider: %s\n", name); 

  printf("size = %d\n", sizeof(d)); 
  printf("not so fast = %d\n", not_so_fast()); 
  printf("caveman = %d\n", caveman(100)); 
  increase_counter(); 
	return 0;
}

inline int not_so_fast()
{
  return 'n'; 
}

template <typename T>
int caveman(T const& p)
{
  return p; 
}