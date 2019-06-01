// iter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector> 
#include <iterator>
#include "elemtype.h" 
using std::vector; 
using std::iterator_traits; 

template <typename Iter>
inline typename iterator_traits<Iter>::value_type 
accum(Iter beg, Iter end)
{
  typedef typename iterator_traits<Iter>::value_type VT; 
  VT total = VT(); 
  while(beg != end)
    total += *beg++; 
  return total; 
}

template <typename T>
class TypeSize
{
public:
  static size_t const value = sizeof(T); 
}; 

template <typename C>
typename ElementT<C>::Type sum_of_elements(C const& c)
{
  typedef typename ElementT<C>::Type elem_type; 
  elem_type total = elem_type(); 
  for(typename C::const_iterator it(c.begin()); it != c.end(); ++ it)
    total += *it; 
  return total; 
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
  printf("the average value of the float values is %.2f\n", accum(flt, flt+5) / 5); 
  //printf("the average value of the float values is %.2f\n", Accum<float>::accum(flt, flt+5) / 5); 

  vector<int> ivec(num, num+5); 
  printf("the average value of the integer values is %d\n", accum(ivec.begin(), ivec.end()) / 5); 
  printf("Typesize<int>::value = %d\n", TypeSize<int>::value); 

  std::stack<bool> s; 
  print_element_type(s); 
  std::deque<short> d; 
  print_element_type(d); 

  printf("sum = %d.\n", sum_of_elements(ivec)); 
	return 0;
}
