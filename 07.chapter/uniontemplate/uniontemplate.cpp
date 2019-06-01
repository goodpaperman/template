// uniontemplate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

template <typename T>
union AllocChunk
{
  T object; 
  unsigned char bytes[sizeof(T)]; 
}; 

template <typename T>
void fill(T const& val = T())
{
  printf("%d\n", val); 
}

class Value
{
public:
  Value(int) {}
}; 

template <int I>
class CupBoard
{
public:
  void open(); 
  class Shelf; 
  static double total_weight; 
}; 

template <int I>
void CupBoard<I>::open()
{
  printf("cup board %d open\n", I); 
}

template <int I>
class CupBoard<I>::Shelf
{
public:
  Shelf() { printf("cup board %d shelf\n", I); } 
}; 

template <int I>
double CupBoard<I>::total_weight = 0.0; 

template <typename T>
class Dynamic
{
public:
  virtual ~Dynamic() { printf("Dynamic destructed.\n"); }

  template <typename T2> 
  /*virtual*/ void copy(T2 const&) { }
}; 

class C
{
public:
  C() { printf("C goes aways.\n"); } 
}; 
int C; 
int X; 

template <typename T>
class X
{
public:
}; 

struct S
{
}; 

//template <typename T>
//class S
//{
//}; 

extern "C++" template <typename T>
void normal(); 

//extern "C" template <typename T>
//void invalid(); 

//extern "Xroma" template <typename T>
//void xroma_link(); 

template <typename T>
static void internal() { printf("internal link.\n"); } 

//template <typename T, T* Root, template<typename = T> class Buf>
template <typename T, T* Root, template<typename T2 = T*> class Buf> 
//template <typename T, T* Root, template<T*> class Buf> 
class Structure
{
public:

}; 

template <typename Allocator>
class List
{
  typedef Allocator ALLOCATOR; 
  /*class */Allocator allocator; 
  friend class Allocator; 

public:
  void add() { allocator.access(this); } 

//private:
  void forbidden() { printf("you can not access me!\n"); } 
}; 

class ListNode
{
public:
  void access(List<ListNode> *list)
  { list->forbidden(); } 
}; 

template <typename T, typename T::ALLOCATOR* Allocator>
class ListAdaptor
{
public:
}; 

int _tmain(int argc, _TCHAR* argv[])
{
  //SYSTEM_INFO sysinfo = { 0 }; 
  AllocChunk<SYSTEM_INFO> sysinfo; 
  ::GetSystemInfo(&sysinfo.object); 
  sysinfo.object.lpMaximumApplicationAddress; 

  fill(1); 
  fill(2.0); 
  fill<int>(); 
  fill<double>(); 
  fill<char*>(); 
  fill<int*>(); 
  
  Value zero(0); 
  fill(zero); 
  //fill<Value>(); 

  CupBoard<10> cb; 
  cb.open(); 
  cb.total_weight; 
  CupBoard<11>::Shelf s; 

  Dynamic<int> d; 

  C = 1; 
  class C c; 

  S s1; 
  //S<int> s2; 
  X = 2; 
  //X<int> x; 

  //normal<int>(); 
  internal<int>(); 

  int *root = 0; 
  Structure<int, 0, Dynamic> str; 

  List<ListNode> list; 
  list.add(); 

  ListAdaptor<List<ListNode>, 0> listadpt; 
	return 0;
}

