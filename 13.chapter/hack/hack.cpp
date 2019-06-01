// hack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo>
#include <list> 
#include <vector> 

using std::list; 
using std::vector; 

template <typename T>
void strange()
{
  printf("void strange<%s>()\n", typeid(T).name()); 
}

template <int N>
void strange()
{
  printf("void strange<%d>()\n", N); 
}

template <int N>
class Buf
{
}; 

template <typename T>
class Array
{
public:
  typedef T ElementT; 
}; 

template <typename T>
void clear(typename Array<T>::ElementT& p)
{
}

//template <>
//void clear(/*typename*/ Array<int>::ElementT& p)
//{
//}

template <typename T>
void other(/*typename*/ Array<int>::ElementT& p)
{
}

template <typename T1, typename T2/* = int*/>
T2 count(T1 const x)
{
  printf("%s count(%s const& x)\n", typeid(T2).name(), typeid(T1).name()); 
  return T2(); 
}

class MyInt
{
}; 

//template <typename T1 = int, typename T2>
//class Bad
//{
//};
//
//Bad<int>* b; 

template <typename T/* = double*/>
void f(T const& = T())
{
  printf("void f(%s const& t)\n", typeid(T).name()); 
}

template <char const* str>
class Bracket
{
public:
  static char const* address(); 
  static char const* bytes(); 
}; 

template <char const* str>
char const* Bracket<str>::address()
{
  return str; 
}

template <char const* str>
char const* Bracket<str>::bytes()
{
  return str; 
}

//char* str = "X"; 
//char const* str = "X"; 
char str[] = "X"; 

//template <double Ratio>
//class Converter
//{
//public:
//  static double convert(double val)
//  { return val * Ratio; } 
//}; 
//
//typedef Converter<0.0254> InchToMeter; 

template <typename T1
, typename T2
, template <typename> class Container>
class Relation
{
public:
  Relation() {} 
private:
  Container<T1> dom1; 
  Container<T2> dom2; 
}; 

//template <typename T>
//typedef list<T> MyList; 

//template <typename T>
//typedef vector<list<T> > Table; 

template <typename T>
class Table
{
public:
  typedef vector<list<T> > Type; 
}; 

//template <typename T>
//typedef T Opaque; 
//
//template <typename T>
//typedef void* Opaque<T*>; 
//
//template <>
//typedef bool Opaque<void>; 

template <typename T>
T const& max(T const& a, T const& b)
{
  return a < b ? b : a; 
}

//template <typename T>
//T* const& max<T*>(T* const& a, T* const& b)
//{
//  return *a < *b ? *b : *a; 
//}

int _tmain(int argc, _TCHAR* argv[])
{
  //strange<16>>2>(); 
  strange<(16>>2)>(); 
  strange<Buf<(16>>2)> >(); 

  Buf<16> c; 
  //int i = count(c); 
  int i = count<Buf<16>, int>(c); 
  //MyInt j = count<MyInt>(c); 
  MyInt j = count<Buf<16>, MyInt>(c); 

  f(1); 
  f<long>(2); 
  f<char>(); 
  //f(); 

  Bracket<str> b; 
  printf("address = %s\n", b.address()); 
  (const_cast<char*>(b.address()))[0] = 'Y'; 
  printf("bytes = %s\n", b.bytes()); 

  //Relation<int, double, list> rel; 
  //Relation<int, double, MyList> rel; 

  //Table<int> t; 
  Table<int>::Type t; 

  int x = 42, y = 24; 
  max(x, y); 
  max(&x, &y); 


	return 0;
}

