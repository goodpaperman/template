
#include "stdafx.h" 

template <typename T>
class Danger; 

template <>
class Danger<void>
{
public:
  enum { max = 100 }; 
}; 

void clear(char const* buf)
{
  printf("max = %d.\n", Danger<void>::max); 
}