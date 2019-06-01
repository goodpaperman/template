#pragma once

template <typename T>
class IsClassT
{
private:
  typedef char One; 
  typedef struct { char a[2]; } Two;
  template <typename U> static One test(...); 
  template <typename U> static Two test(int U::*); 

public:
  enum
  {
    Yes = sizeof(test<T>(0)) == sizeof(Two), 
    No = !Yes, 
  }; 
}; 