// promot.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ifthenelse.h" 
#include "promotion.h" 
#include <typeinfo> 

template <typename T>
class Array
{
public:
}; 

//template <typename T>
//Array<T> operator+ (Array<T> const&, Array<T> const&)
//{
//  return Array<T>(); 
//}

template <typename T1, typename T2>
Array<typename Promotion<T1, T2>::ResultT>
operator+ (Array<T1> const&, Array<T2> const&)
{
  printf("T1 = %s, T2 = %s\n", typeid(T1).name(), typeid(T2).name()); 
  Array<typename Promotion<T1, T2>::ResultT> obj; 
  return obj; 
}


int _tmain(int argc, _TCHAR* argv[])
{
  Array<char> carr; 
  Array<short> sarr; 
  Array<int> iarr, iarr2; 
  Array<long> larr; 
  Array<float> farr, farr2; 
  Array<double> darr;  
  Array<long long> llarr; 
  printf("Array<char> + Array<short> = %s.\n", typeid(carr+sarr).name()); 
  printf("Array<int> + Array<short> = %s.\n", typeid(iarr+sarr).name()); 
  printf("Array<int> + Array<double> = %s.\n", typeid(iarr+darr).name());  
  printf("Array<int> + Array<float> = %s.\n", typeid(iarr+farr).name());   
  printf("Array<int> + Array<long> = %s.\n", typeid(iarr+larr).name()); 
  printf("Array<float> + Array<long long> = %s.\n", typeid(farr+llarr).name()); 
  printf("Array<double> + Array<long long> = %s.\n", typeid(darr+llarr).name()); 
  printf("Array<long> + Array<long long> = %s.\n", typeid(larr+llarr).name()); 
  printf("Array<int> + Array<int> = %s.\n", typeid(iarr+iarr2).name()); 
  printf("Array<float> + Array<float> = %s.\n", typeid(farr+farr2).name()); 

  //iarr = iarr + iarr2; 
  //farr = farr + farr2; 
  printf("result = %s.\n", typeid(IfThenElse<LS(sizeof(float), sizeof(float)), float, void>::ResultT).name());  


	return 0;
}

