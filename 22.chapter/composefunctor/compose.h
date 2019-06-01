#pragma once

#define EBCO
#ifdef EBCO
//template <typename F1, typename F2>
//class Composer : private F1, private F2
//{
//public:
//  Composer(F1 a, F2 b) : F1(a), F2(b) { }
//  double operator() (double v)
//  { return F2::operator()(F1::operator()(v)); }
//};

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
  Composer(F1 a, F2 b) 
    : BaseMem<F1, 1>(a)
    , BaseMem<F2, 2>(b) { }

  double operator() (double v)
  { return BaseMem<F2, 2>::operator()(BaseMem<F1, 1>::operator()(v)); }
};


#else 
template <typename F1, typename F2>
class Composer
{
public:
  Composer(F1 a, F2 b) : f1(a), f2(b) { }
  double operator() (double v)
  { return f2(f1(v)); }

private:
  F1 f1; 
  F2 f2; 
};
#endif

template <typename F1, typename F2>
inline Composer<F1, F2> compose(F1 f1, F2 f2)
{ return Composer<F1, F2>(f1, f2); } 
