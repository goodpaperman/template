// recurtempl.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo> 

template <typename T, typename U>
struct Doublify
{
  typedef T FirstT; 
  typedef U SecondT; 
}; 

template <int N>
class Trouble
{
public:
  typedef Doublify<Trouble<N-1>, Trouble<N-1> > LongType; 
}; 

template <>
class Trouble<0>
{
public:
  typedef double LongType; 
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  printf("%s::%s = %d\n"
    , typeid(Trouble<10>).name()
    , typeid(Trouble<10>::LongType).name()
    , sizeof(Trouble<10>::LongType)); 

  Trouble<10>::LongType::FirstT::LongType::FirstT::LongType::FirstT::LongType::FirstT::LongType::FirstT::LongType::FirstT::LongType::FirstT::LongType::FirstT::LongType::FirstT::LongType::FirstT::LongType value;
  value = 1.1; 

	return 0;
}

