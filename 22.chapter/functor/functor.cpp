// functor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo> 
#include <set> 
#include <vector> 
using std::set; 
using std::vector; 

class ConstantIntFunctor
{
public:
  ConstantIntFunctor(int c) : value(c) {}
  int operator()() const { return value; } 
  //operator int() const { return value; } 

private:
  int value; 
}; 

void client(ConstantIntFunctor const& cif)
{
  printf("calling back functor yields %d.\n", cif()); 
  //printf("calling back functor yields %d.\n", (int)cif); 
}

class Person
{
public:
  Person(int age = 0, bool male = true) 
    : age_(age)
    , male_(male) 
  {
  }

  bool operator< (Person const& p) const
  {
    return age() < p.age(); 
  }

  bool operator== (Person const& p) const
  {
    return age() == p.age(); 
  }

  int age() const { return age_; } 
  bool male() const { return male_; } 

private:
  int age_; 
  bool male_; 
}; 

class PersonSortCriterion
{
public:
  bool operator() (Person const& p1, Person const& p2) const
  {
    return p1.male() < p2.male(); 
  }
}; 

class int_compare
{
public:
  bool operator()(int x, int y)
  {
    return x<y; 
  }
}; 

bool my_compare(int x, int y)
{
  return x<y; 
}


template <typename FO>
void my_sort(int a, int b)
{
  FO cmp; 
  if(cmp(a, b))
    printf("%d < %d.\n", a, b); 
  else 
    printf("%d >= %d.\n", a, b); 
}

template <typename F>
void my_sort(int a, int b, F cmp)
{
  printf("F type: %s.\n", typeid(F).name()); 
  if(cmp(a, b))
    printf("%d < %d.\n", a, b); 
  else 
    printf("%d >= %d.\n", a, b); 
}

template <typename F>
void your_sort(int a, int b, F cmp = F())
{
  printf("F type: %s.\n", typeid(F).name()); 
  if(cmp(a, b))
    printf("%d < %d.\n", a, b); 
  else 
    printf("%d >= %d.\n", a, b); 
}

class compare_base
{
public:
  virtual bool operator() (int a, int b) = 0;
}; 

class compare_impl : public compare_base
{
public:
  virtual bool operator() (int a, int b)
  {
    return a < b; 
  }
}; 

//template <compare_impl cmp>
template <compare_base& cmp> 
//template <compare_impl& cmp> 
void our_sort(int a, int b)
{
  printf("cmp type: %s.\n", typeid(cmp).name()); 
  if(cmp(a, b))
    printf("%d < %d.\n", a, b); 
  else 
    printf("%d >= %d.\n", a, b); 
}

compare_impl ci; 

//template <bool (*cmp)(int, int)>
//template <bool (&cmp)(int, int)>
template <bool cmp(int, int)>
void her_sort(int a, int b)
{
  printf("cmp type: %s.\n", typeid(cmp).name()); 
  if(cmp(a, b))
    printf("%d < %d.\n", a, b); 
  else 
    printf("%d >= %d.\n", a, b); 
}

template <int (*FP)()>
class FunctionReturningIntWrapper
{
public:
  int operator() () { return FP(); } 
}; 

int random_int()
{
  return rand(); 
}

template <typename FO>
void initialize(vector<int>& coll)
{
  FO fo; 
  for(int i=0; i<coll.size(); ++ i)
    coll[i] = fo(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  ConstantIntFunctor seven(7); 
  ConstantIntFunctor fortytwo(42); 
  client(seven); 
  client(fortytwo); 

  set<Person> c1, c2; 
  set<Person, PersonSortCriterion> c3, c4; 
  c1 = c2; 
  c3 = c4; 
  if(c1 < c2){}
  else if (c3 > c4){}
  else if(c1 == c2){}
  else if(c3 != c4){}
  else {}

  //c1 = c4; 
  //if(c1 < c4) {}
  //if(c1 == c4) {}
  //if(c1 != c4) {}

  my_sort<std::less<int> >(42, 23); 
  my_sort<int_compare>(32, 90); 
  my_sort(78, 34, std::less<int>()); 
  my_sort(12, 89, int_compare()); 
  my_sort(45, 89, my_compare); 
  
  your_sort<std::less<int> >(42, 23); 
  your_sort<int_compare>(32, 90);
  your_sort(78, 34, std::less<int>()); 
  your_sort(12, 89, int_compare()); 
  your_sort(45, 89, my_compare); 

  int_compare ic; 
  set<int, int_compare> s(ic); //(int_compare()); 
  s.insert(3); 

  
  our_sort<ci>(23, 34); 
  //our_sort<(compare_base&)ci>(23, 34); 
  //our_sort<ci>(23, 34); 

  her_sort<my_compare>(23, 12); 

  vector<int> v(10); 
  //initialize<FunctionReturningIntWrapper<random_int> >(v); 
  initialize<FunctionReturningIntWrapper<rand> >(v); 
  for(int i=0; i<v.size(); ++ i)
    printf("%d  ", v[i]); 
  printf("\n"); 
	return 0;
}

