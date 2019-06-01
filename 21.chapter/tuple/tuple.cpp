// tuple.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Tuple.h" 
#include <typeinfo> 

int _tmain(int argc, _TCHAR* argv[])
{
  {
    typedef Tuple<bool, int, float, double> TupleT; 
    typedef TupleT::BaseT BaseT; 
    TupleT t4(true, 42, 3.14, 3.1415926); 
    printf("tuple %d: \n\r%s: %d\n\r%s: %d\n\r%s: %.2f\n\r%s: %f\n"
      , BaseT::N
      , typeid(DuoT<1, BaseT>::ResultT).name()
      , val<1>(t4)
      , typeid(DuoT<2, BaseT>::ResultT).name()
      , val<2>(t4)
      , typeid(DuoT<3, BaseT>::ResultT).name()
      , val<3>(t4)
      , typeid(DuoT<4, BaseT>::ResultT).name()
      , val<4>(t4)); 
  }

  {
    typedef Tuple<int, unsigned short> TupleT; 
    typedef TupleT::BaseT BaseT; 
    TupleT t2(32, 65535); 
    printf("tuple %d: \n\r%s: %d\n\r%s: %d\n"
      , BaseT::N
      , typeid(DuoT<1, BaseT>::ResultT).name()
      , val<1>(t2)
      , typeid(DuoT<2, BaseT>::ResultT).name()
      , val<2>(t2)); 
  }

  //{
  //  typedef Tuple<int, Null> TupleT; 
  //  typedef TupleT::BaseT BaseT; 
  //  TupleT t2(108, Null()); 
  //  printf("mem: \n\r%s: %d\n\r%s: %d\n"
  //    , typeid(DuoT<1, BaseT>::ResultT).name()
  //    , val<1>(t2)
  //    , typeid(DuoT<2, BaseT>::ResultT).name()
  //    , val<2>(t2));  
  //}

  {
    typedef Tuple<int> TupleT; 
    typedef TupleT::BaseT BaseT; 
    TupleT t1(128); 
    printf("tuple %d: \n\r%s: %d\n"
      , BaseT::N
      , typeid(DuoT<1, BaseT>::ResultT).name()
      , val<1>(t1));  
  }

  {
    typedef Tuple<bool, int, double/*float*/> TupleT; 
    typedef TupleT::BaseT BaseT; 
    TupleT t3 = make_tuple(false, 23, 13.13); 
    printf("tuple %d: \n\r%s: %d\n\r%s: %d\n\r%s: %.2f\n"
      , BaseT::N
      , typeid(DuoT<1, BaseT>::ResultT).name()
      , val<1>(t3)
      , typeid(DuoT<2, BaseT>::ResultT).name()
      , val<2>(t3)
      , typeid(DuoT<3, BaseT>::ResultT).name()
      , val<3>(t3)); 
  }

	return 0;
}

