#pragma once

#include "typeop.h" 
#include "ifthenelse.h" 
#include "functorparam.h" 
#include "forwardparam.h" 
#include "functionptr.h" 

template <typename T>
class BoundVal
{
public:
  typedef T ValueT; 
  BoundVal(T v) : value(v) { }
  typename TypeOp<T>::RefT get() { return value; } 

private:
  T value; 
}; 

template <typename F, int P>
class BinderParams
{
public:
  enum { NumParams = F::NumParams - 1 }; 

#define ComposeParamT(N) \
  typedef typename IfThenElse<(N<P) \
  , FunctorParam<F, N> \
  , FunctorParam<F, N+1> >::ResultT::Type Param##N##T

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
}; 

//#define LESS_THAN(a, b) ((a) < (b))
//#define GREATER_THAN(a, b) ((a) > (b))
template <int S, typename NegT, typename ZeroT, typename PosT>
struct SignSelect
{
  typedef typename IfThenElse<(S<0)
    , NegT
    , typename IfThenElse<(S>0)
      , PosT
      , ZeroT>::ResultT
  >::ResultT ResultT; 
}; 

template <typename F, int P, typename V>
class Binder : private F, private V
{
public:
  enum { NumParams = F::NumParams-1 }; 
  typedef typename F::ReturnT ReturnT; 

  typedef BinderParams<F, P> Params; 

#define ComposeParamT(N) \
  typedef typename ForwardParamT<typename Params::Param##N##T>::Type Param##N##T; 

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

private:
  template <int A>
  class ArgSelect
  {
  public:
    typedef typename TypeOp<typename IfThenElse<(A<=Params::NumParams)
    , FunctorParam<Params, A>
    , FunctorParam<Params, A-1> >::ResultT::Type>::RefT NoSkipT; 

    typedef typename TypeOp<typename IfThenElse<(A>1)
      , FunctorParam<Params, A-1>
      , FunctorParam<Params, A> >::ResultT::Type>::RefT SkipT; 

    typedef typename TypeOp<typename V::ValueT>::RefT BindT; 
    

    class NoSkip
    {
    public:
      static NoSkipT select(SkipT prev_arg, NoSkipT arg, BindT bound_val)
      { return arg; } 
    }; 

    class Skip
    {
    public:
      static SkipT select(SkipT prev_arg, NoSkipT arg, BindT bound_val)
      { return prev_arg; }
    }; 

    class Bind
    {
    public:
      static BindT select(SkipT prev_arg, NoSkipT arg, BindT bound_val)
      { return bound_val; } 
    }; 

    typedef typename SignSelect<A-P, NoSkipT, BindT, SkipT>::ResultT ReturnT; 
    typedef typename SignSelect<A-P, NoSkip, Bind, Skip>::ResultT SelectT; 
    static ReturnT from(SkipT prev_arg, NoSkipT arg, BindT bound_val)
    { return SelectT::select(prev_arg, arg, bound_val); } 
  }; 

public:
  Binder(F& f) : F(f) { } 
  Binder(F& f, V& v) : F(f), V(v) { } 
  Binder(F& f, V const& v) : F(f), V(v) { }
  Binder(F const& f) : F(f) { }
  Binder(F const& f, V& v) : F(f), V(v) { }
  Binder(F const& f, V const& v) : F(f), V(v) { }
  template <typename T>
  Binder(F& f, T& v) : F(f), V(BoundVal<T>(v)) { }
  template <typename T>
  Binder(F& f, T const& v) : F(f), V(BoundVal<T const>(v)) { }

  ReturnT operator()()
  {
    return F::operator()(V::get()); 
  }

  ReturnT operator() (Param1T v1)
  {
    return F::operator()(ArgSelect<1>::from(v1, v1, V::get())
      , ArgSelect<2>::from(v1, v1, V::get())); 
  }

  ReturnT operator() (Param1T v1, Param2T v2)
  {
    return F::operator()(ArgSelect<1>::from(v1, v1, V::get())
      , ArgSelect<2>::from(v1, v2, V::get())
      , ArgSelect<3>::from(v2, v2, V::get())); 
  }

  ReturnT operator() (Param1T v1, Param2T v2, Param3T v3)
  {
    return F::operator()(ArgSelect<1>::from(v1, v1, V::get())
      , ArgSelect<2>::from(v1, v2, V::get())
      , ArgSelect<3>::from(v2, v3, V::get())
      , ArgSelect<4>::from(v3, v3, V::get())); 
  }
};

template <int P, typename F>
inline Binder<F, P, BoundVal<typename FunctorParam<F, P>::Type> >
bind(F const& f, typename ForwardParamT<typename FunctorParam<F, P>::Type>::Type val)
{
  //return Binder<F, P, BoundVal<typename FunctorParam<F, P>::Type> >(f, BoundVal<typename FunctorParam<F, P>::Type>(val)); 
  return Binder<F, P, BoundVal<typename FunctorParam<F, P>::Type> >(f, val); 
}

template <int P, typename RT, typename P1, typename P2>
inline Binder<FunctionPtr<RT, P1, P2>, P, BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2>, P>::Type> >
bindfp(RT (*fp)(P1, P2), typename ForwardParamT<typename FunctorParam<FunctionPtr<RT, P1, P2>, P>::Type>::Type val)
{
  //return Binder<FunctionPtr<RT, P1, P2>, P, BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2>, P>::Type> >(func_ptr(fp), BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2>, P>::Type>(val)); 
  return Binder<FunctionPtr<RT, P1, P2>, P, BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2>, P>::Type> >(func_ptr(fp), val); 
}

template <int P, typename RT, typename P1, typename P2, typename P3>
inline Binder<FunctionPtr<RT, P1, P2, P3>, P, BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2, P3>, P>::Type> >
bindfp(RT (*fp)(P1, P2, P3), typename ForwardParamT<typename FunctorParam<FunctionPtr<RT, P1, P2, P3>, P>::Type>::Type val)
{
  //return Binder<FunctionPtr<RT, P1, P2, P3>, P, BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2, P3>, P>::Type> >(func_ptr(fp), BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2, P3>, P>::Type>(val)); 
  return Binder<FunctionPtr<RT, P1, P2, P3>, P, BoundVal<typename FunctorParam<FunctionPtr<RT, P1, P2, P3>, P>::Type> >(func_ptr(fp), val); 
}
