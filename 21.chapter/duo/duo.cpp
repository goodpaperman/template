// duo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Duo.h" 
#include <typeinfo> 


Duo<float, int> foo()
{
  return make_duo(42, 42); 
}

int _tmain(int argc, _TCHAR* argv[])
{
  if(foo() == make_duo(42, 42.0))
    printf("equal\n"); 

  Duo<Duo<int, char>, Duo<bool, double> > q22; 
  q22.v1().v1() = 24; 
  q22.v1().v2() = 'b'; 
  q22.v2().v1() = false; 
  q22.v2().v2() = 3.21; 

  printf("mem %d: v1 = %d, v2 = %c, v3 = %d, v4 = %.2f.\n"
    , Duo<Duo<int, char>, Duo<bool, double> >::N
    , q22.v1().v1()
    , q22.v1().v2()
    , q22.v2().v1()
    , q22.v2().v2()); 

  typedef Duo<int, Duo<char, Duo<bool, double> > > Duo1; 
  Duo1 q4; 
  q4.v2().v2().v2() = 1.23; 
  q4.v2().v2().v1() = true; 
  q4.v2().v1() = 'a'; 
  q4.v1() = 42; 

  printf("mem %d: v1 = %d, v2 = %c, v3 = %d, v4 = %.2f.\n"
    , Duo1::N
    , q4.v1()
    , q4.v2().v1()
    , q4.v2().v2().v1()
    , q4.v2().v2().v2()); 

  typedef Duo<long, Duo<short, Duo<int, float> > > Duo2; 
  Duo2 q42; 
  q42 = q4; 
  printf("mem %d: v1 = %d, v2 = %d, v3 = %d, v4 = %.2f.\n"
    , Duo2::N
    , q42.v1()
    , q42.v2().v1()
    , q42.v2().v2().v1()
    , q42.v2().v2().v2()); 

  printf("Duo1: %s = \n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n"
    , typeid(Duo1).name()
    , typeid(DuoT<1, Duo1>::ResultT).name()
    , typeid(DuoT<2, Duo1>::ResultT).name()
    , typeid(DuoT<3, Duo1>::ResultT).name()
    , typeid(DuoT<4, Duo1>::ResultT).name()
    , typeid(DuoT<5, Duo1>::ResultT).name()
    , typeid(DuoT<0, Duo1>::ResultT).name()); 

  val<1>(q4) = 32; 
  val<2>(q4) = 'z'; 
  val<3>(q4) = true; 
  val<4>(q4) = 3.14; 
  //val<5>(q4) = 0; 
  //void a = 0; 

  printf("mem %d: v1 = %d, v2 = %c, v3 = %d, v4 = %.2f.\n"
    , Duo1::N
    , val<1>(q4)
    , val<2>(q4)
    , val<3>(q4)
    , val<4>(q4)
    /*, val<0>(q4)*/); 


	return 0;
}

