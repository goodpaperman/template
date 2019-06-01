// meta.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo> 

template <typename T>
class Array
{
}; 

//template <typename T1, typename T2>
//Array<typeof(T1()+T2())> operator+ (Array<T1> const& x, Array<T2> const& y); 

template <typename T>
T makeT(); 

//template <typename T1, typename T2>
//Array<typeof(makeT<T1>(), makeT<T2>())> operator+ (Array<T1> const& x, Array<T2> const& y); 


template <typename T>
class Tuple
{
}; 

//template <typename T1, typename T2>
//class Tuple
//{
//}; 
//
//template <typename T1, typename T2, typename T3>
//class Tuple
//{
//}; 

template <typename T1, typename T2>
class Pair
{
}; 

//template <int I1, int I2>
//class Pair
//{
//}; 

template <typename T>
inline T const& max (T const& a, T const& b)
{
  return a < b ? b : a; 
}

//template <typename T, ... list>
//inline T const& max(T const& a, T const& b, list const& x)
//{
//  return max(a, max(b, x)); 
//}

template <typename T>
class ListProps
{
public:
  enum { length = 1 }; 
}; 

//template <... list>
//class ListProps
//{
//public:
//  enum { length = 1 + ListProps<list[1 ...]>::length }; 
//}; 

//template <... list> 
//class Collection
//{
//  list; 
//}; 

template <typename T>
void align()
{
  printf("alignof (%s) = %d.\n", typeid(T).name(), __alignof(T)); 
  printf("sizeof (%s) = %d.\n", typeid(T).name(), sizeof(T)); 
}

class state
{
  char a; 
  short b; 
  int c; 
  long double d; 
}; 

template <typename T>
class Alignment
{
public:
  enum { max = __alignof(T) }; 
}; 

//template <...list>
//class Alignment
//{
//public:
//  enum { max = __alignof(list[0]) > Alignment<list[1...]>::max
//    ? __alignof(list[0])
//    : Alignment<list[1...]>::max }; 
//}; 

int _tmain(int argc, _TCHAR* argv[])
{
  printf("sizeof (%s) = %d.\n", typeid(makeT<Array<int> >()).name(), sizeof(makeT<Array<int> >())); 

  //std::type<int>::is_bit_copyable; 
  //std::type<int>::is_union; 

  //__alignof__(int); 

  align<char>(); 
  align<short>(); 
  align<int>(); 
  align<long>(); 
  align<long long>(); 
  align<float>(); 
  align<double>(); 
  align<int*>(); 
  align<state>(); 
  //__alignof(16); 

	return 0;
}

