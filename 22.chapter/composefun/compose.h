#pragma once

#include "forwardparam.h" 
#include "functorparam.h" 

template <typename C, int N>
class BaseMem : public C
{
public:
  BaseMem(C& c) : C(c) { }
  BaseMem(C const& c) : C(c) { } 
};

template <typename F1, typename F2>
class Composer 
  : private BaseMem<F1, 1>
  , private BaseMem<F2, 2>
{
public:
  enum { NumParams = F1::NumParams }; 
  typedef typename F2::ReturnT ReturnT; 
  //typedef typename F1::Param1T Param1T; 
  //typedef typename FunctorParam<F1, 1>::Type Param1T; 

#define ComposeParamT(N) \
  typedef typename FunctorParam<F1, N>::Type Param##N##T

  ComposeParamT(1); 
  ComposeParamT(2); 
  ComposeParamT(3); 
  ComposeParamT(4); 
  ComposeParamT(5); 
  ComposeParamT(6); 
  ComposeParamT(7); 
  ComposeParamT(8); 
  ComposeParamT(9); 
  ComposeParamT(10); 
  ComposeParamT(11); 
  ComposeParamT(12); 
  ComposeParamT(13); 
  ComposeParamT(14); 
  ComposeParamT(15); 
  ComposeParamT(16); 
  ComposeParamT(17); 
  ComposeParamT(18); 
  ComposeParamT(19); 
  ComposeParamT(20); 
#undef ComposeParamT

  Composer(F1 const& a, F2 const& b)
    : BaseMem<F1, 1>(a)
    , BaseMem<F2, 2>(b) { }
  Composer(F1 const& a, F2 &b)
    : BaseMem<F1, 1>(a)
    , BaseMem<F2, 2>(b) { }
  Composer(F1 &a, F2 const& b)
    : BaseMem<F1, 1>(a)
    , BaseMem<F2, 2>(b) { } 
  Composer(F1 &a, F2 &b) 
    : BaseMem<F1, 1>(a)
    , BaseMem<F2, 2>(b) { }

  ReturnT operator() ()
  { return BaseMem<F2, 2>::operator()(BaseMem<F1, 1>::operator()()); }
  ReturnT operator() (typename ForwardParamT<Param1T>::Type v1)
  { return BaseMem<F2, 2>::operator()(BaseMem<F1, 1>::operator()(v1)); }
  ReturnT operator() (typename ForwardParamT<Param1T>::Type v1
    , typename ForwardParamT<Param2T>::Type v2)
  { return BaseMem<F2, 2>::operator()(BaseMem<F1, 1>::operator()(v1, v2)); }
};


template <typename F1, typename F2>
inline Composer<F1, F2> compose(F1 f1, F2 f2)
{ return Composer<F1, F2>(f1, f2); } 
