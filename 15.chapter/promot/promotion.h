#pragma once


//template <typename T1, typename T2>
//class Promotion
//{
//public:
//  typedef typename IfThenElse<
//    sizeof(T1) > sizeof(T2)
//    , T1
//    , typename IfThenElse<
//    sizeof(T1) < sizeof(T2)
//    , T2
//    , void
//    >::ResultT
//    >::ResultT ResultT; 
//}; 

#define GT(x, y) ((x) > (y))
#define LS(x, y) ((x) < (y)) 

template <typename T1, typename T2>
class Promotion
{
public:
  typedef typename IfThenElse<GT(sizeof(T1), sizeof(T2)), T1
    , typename IfThenElse<LS(sizeof(T1), sizeof(T2)), T2, void>::ResultT >::ResultT ResultT; 
}; 

template <typename T>
class Promotion<T, T>
{
public:
  typedef T ResultT; 
}; 

#define MK_PROMOTION(T1, T2, Tr) \
  template <> \
  class Promotion<T1, T2>{\
    public: \
      typedef Tr ResultT; \
  }; \
  template <> \
  class Promotion<T2, T1>{\
    public: \
      typedef Tr ResultT; \
  }

MK_PROMOTION(float, int, float); 
MK_PROMOTION(float, long long, double); 
MK_PROMOTION(double, long long, double); 
