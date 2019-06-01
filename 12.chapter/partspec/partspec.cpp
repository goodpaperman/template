// partspec.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo>

template <typename T>
class List
{
public:
  void append(T const&)
  {
    printf("void List<T>::append(T const&)\n"); 
  }

  inline size_t length() const
  {
    printf("size_t List<T>::length() const\n"); 
    return 0; 
  }
}; 


//template <>
//class List<void*>
//{
//public:
//  void append(void*)
//  {
//    printf("void List<void*>::apend(void*)\n"); 
//  }
//
//  inline size_t length() const 
//  {
//    printf("size_t List<void*>::length() const\n"); 
//    return 0; 
//  }
//}; 

template <typename T>
class List<T*>
{
public:
  void append(T* p)
  {
    printf("void List<T*>::append(T*)\n"); 
    impl_.append(p); 
  }

  inline size_t length() const
  {
    printf("size_t List<T*>::length() const\n"); 
    return impl_.length(); 
  }

private:
  List<void*> impl_; 
}; 

//
//template <typename C>
//class List<void* C::*>
//{
//public:
//  typedef void* C::*ElementType; 
//  void append(ElementType pm)
//  {
//    printf("void List<void* C::*>::append(void* C::*)\n"); 
//  }
//
//  inline size_t length() const
//  {
//    printf("size_t List<void* C::*>::length() const\n"); 
//    return 0; 
//  }
//}; 


template <typename T, typename C>
class List<T* C::*>
{
public:
  typedef T* C::*ElementType; 
  void append(ElementType pm)
  {
    printf("void List<T* C::*>::apend(T* C::*)\n"); 
    //impl.append(pm); 
  }

  inline size_t length() const 
  {
    printf("size_t List<T* C::*>::length() const\n"); 
    //return impl.length(); 
    return 0; 
  }

//private:
//  List<void* C::*> impl; 
}; 


template <typename T, int I = 3> 
class S
{
public:
  void print() const 
  { printf("S<%s, %d>\n", typeid(T).name(), I); } 
}; 

//template <typename T>
//class S<int, T>
//{
//}; 

//template <typename T = int>
//class S<T, 10>
//{
//}; 

//template <int I>
//class S<int, I*2>
//{
//}; 

//template <typename U, int K>
//class S<U, K>
//{
//}; 

template <int I>
class S<int, I>
{
public:
  void print() const
  { printf("S<int, %d>\n", I); } 
};

class Target
{
public:
  int* pi; 
  long* pl; 
  float* pf; 
  double* pd; 
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  List<int> ilist; 
  ilist.append(10); 
  ilist.length(); 

  List<void*> vlist; 
  vlist.append(0); 
  vlist.length(); 

  List<int*> iplist; 
  iplist.append(0); 
  iplist.length(); 

  //List<int* Target::*> tilist; 
  List<int* Target::*> tilist; 
  tilist.append(&Target::pi); 
  tilist.length(); 


  S<bool> sb; 
  sb.print(); 

  S<bool, 10> sb2; 
  sb2.print(); 

  S<int> si; 
  si.print(); 

  S<int, 42> si2; 
  si2.print(); 
	return 0;
}

