// accum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "accumtraits.h" 

//double const AccumulationTraits<float>::zero = 0.0; 

#if 0
template <typename T>
inline T accum(T const* beg, T const* end)
{
  T total = T(); 
  while(beg != end)
    total += *beg++; 

  return total; 
}

template <typename AccT, typename T>
inline AccT accum(T const* beg, T const* end)
{
  AccT total = AccT(); 
  while(beg != end)
    total += *beg++; 
  return total; 
}

template <typename T>
inline typename AccumulationTraits<T>::AccT
accum (T const* beg, T const* end)
{
  typedef typename AccumulationTraits<T>::AccT AccT; 
  //AccT total = AccT(); 
  //AccT total = AccumulationTraits<T>::zero; 
  AccT total = AccumulationTraits<T>::zero(); 
  while(beg != end)
    total += *beg++; 
  return total; 
}
#endif 

template <typename T, typename AT = AccumulationTraits<T> >
class Accum
{
public:
  static typename AT::AccT accum(T const* beg, T const* end)
  {
    typename AT::AccT total = AT::zero(); 
    while(beg != end)
      total += *beg++; 
    return total; 
  }
}; 

template <typename T>
inline typename AccumulationTraits<T>::AccT accum(T const* beg, T const* end)
{
  return Accum<T>::accum(beg, end); 
}

template <typename AT, typename T>
inline typename AT::AccT accum(T const* beg, T const* end)
{
  return Accum<T, AT>::accum(beg, end); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  int num[] = { 1, 2, 3, 4, 5 }; 
  printf("the average value of the integer values is %d\n", accum(num, num+5) / 5); 
  //printf("the average value of the integer values is %d\n", accum<int>(num, num+5) / 5); 
  //printf("the average value of the integer values is %d\n", Accum<int>::accum(num, num+5) / 5); 

  char name[] = "templates"; 
  int length = sizeof(name)-1; 
  printf("the average value of the characters in \"%s\" is %d\n", name, accum(name, name+length) / length);  
  //printf("the average value of the characters in \"%s\" is %d\n", name, accum<int>(name, name+length) / length);  
  //printf("the average value of the characters in \"%s\" is %d\n", name, Accum<char>::accum(name, name+length) / length);  

  float flt[] = { 1.2, 2.3, 3.4, 4.5, 5.6 }; 
  printf("the average value of the float values is %.2f\n", accum/*<AccumulationTraits<char>, float>*/(flt, flt+5) / 5); 
  //printf("the average value of the float values is %.2f\n", Accum<float>::accum(flt, flt+5) / 5); 
	return 0;
}

