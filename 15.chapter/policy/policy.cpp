// policy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "accumtraits.h" 
#include "sumpolicy.h" 

#if 0
template <typename T, typename Policy = SumPolicy, typename Traits = AccumulationTraits<T> >
class Accum
{
public:
  typedef typename Traits::AccT AccT; 
  static AccT accum(T const* beg, T const* end)
  {
    //AccT total = Traits::zero(); 
    AccT total = Policy::zero(); 
    while(beg != end)
      Policy::accumulate(total, *beg++); 
    return total; 
  }
}; 

template <typename T, template <typename, typename> class Policy = SumPolicy, typename Traits = AccumulationTraits<T> >
class Accum
{
public:
  typedef typename Traits::AccT AccT; 
  static AccT accum(T const* beg, T const* end)
  {
    AccT total = Policy<AccT, T>::zero(); 
    while(beg != end)
      Policy<AccT, T>::accumulate(total, *beg++); 
    return total; 
  }
}; 
#endif 

template <typename T
, template <typename, typename> class Policy = SumPolicy
, template <typename> class Traits = AccumulationTraits>
class Accum
{
public:
  typedef typename Traits<T>::AccT AccT; 
  static AccT accum(T const* beg, T const* end)
  {
    AccT total = Policy<AccT, T>::zero(); 
    while(beg != end)
      Policy<AccT, T>::accumulate(total, *beg++); 
    return total; 
  }
}; 


int _tmain(int argc, _TCHAR* argv[])
{
  int num[] = { 1, 2, 3, 4, 5 }; 
  printf("the average value of the integer values is %d\n", Accum<int/*, MultPolicy*/>::accum(num, num+5) / 5); 
  //printf("the average value of the integer values is %d\n", accum<int>(num, num+5) / 5); 
  //printf("the average value of the integer values is %d\n", Accum<int>::accum(num, num+5) / 5); 

  char name[] = "templates"; 
  int length = sizeof(name)-1; 
  printf("the average value of the characters in \"%s\" is %d\n", name, Accum<char/*, MultPolicy*/>::accum(name, name+length) / length);  
  //printf("the average value of the characters in \"%s\" is %d\n", name, accum<int>(name, name+length) / length);  
  //printf("the average value of the characters in \"%s\" is %d\n", name, Accum<char>::accum(name, name+length) / length);  

  float flt[] = { 1.2, 2.3, 3.4, 4.5, 5.6 }; 
  printf("the average value of the float values is %.2f\n", Accum<float/*, MultPolicy*/>::accum(flt, flt+5) / 5); 
  //printf("the average value of the float values is %.2f\n", Accum<float>::accum(flt, flt+5) / 5); 
	return 0;
}