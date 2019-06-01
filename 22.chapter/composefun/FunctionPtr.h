#pragma once

//#include "rparam.h" 
#include "forwardparam.h" 

template <typename RT
, typename P1 = void
, typename P2 = void 
, typename P3 = void>
class FunctionPtrT
{
public:
  enum { NumParams = 3 }; 
  typedef RT (*Type)(P1, P2, P3); 
}; 

template <typename RT
, typename P1
, typename P2>
class FunctionPtrT<RT, P1, P2, void>
{
public:
  enum { NumParams = 2 }; 
  typedef RT (*Type)(P1, P2); 
}; 

template <typename RT, typename P1>
class FunctionPtrT<RT, P1, void, void>
{
public:
  enum { NumParams = 1 }; 
  typedef RT (*Type)(P1); 
}; 

template <typename RT>
class FunctionPtrT<RT, void, void, void>
{
public:
  enum { NumParams = 0 }; 
  typedef RT (*Type)(); 
}; 


template <typename RT
, typename P1 = void
, typename P2 = void 
, typename P3 = void>
class FunctionPtr
{
private:
  typedef typename FunctionPtrT<RT, P1, P2, P3>::Type FuncPtr; 
  FuncPtr fptr; 

public:
  enum { NumParams = FunctionPtrT<RT, P1, P2, P3>::NumParams }; 
  typedef RT ReturnT; 
  typedef P1 Param1T; 
  typedef P2 Param2T; 
  typedef P3 Param3T; 

  FunctionPtr(FuncPtr ptr) : fptr(ptr) {}
  RT operator() () { return fptr(); } 
  RT operator() (typename ForwardParamT<P1>::Type a1) 
  { return fptr(a1); } 

  RT operator() (typename ForwardParamT<P1>::Type a1, 
    typename ForwardParamT<P2>::Type a2) 
  { return fptr(a1, a2); } 

  RT operator() (typename ForwardParamT<P1>::Type a1, 
    typename ForwardParamT<P2>::Type a2, 
    typename ForwardParamT<P3>::Type a3) 
  { return fptr(a1, a2, a3); } 
};


template <typename RT> 
inline FunctionPtr<RT> func_ptr(RT (*fp)())
{
  return FunctionPtr<RT>(fp); 
}

template <typename RT, typename P1>
inline FunctionPtr<RT, P1> func_ptr(RT (*fp)(P1))
{
  return FunctionPtr<RT, P1>(fp); 
}

template <typename RT, typename P1, typename P2>
inline FunctionPtr<RT, P1, P2> func_ptr(RT (*fp)(P1, P2))
{
  return FunctionPtr<RT, P1, P2>(fp); 
}

template <typename RT, typename P1, typename P2, typename P3>
inline FunctionPtr<RT, P1, P2, P3> func_ptr(RT (*fp)(P1, P2, P3))
{
  return FunctionPtr<RT, P1, P2, P3>(fp); 
}
