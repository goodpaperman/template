#pragma once

#include "typeop.h" 

template <typename T1, typename T2>
class Duo
{
public:
  typedef T1 Type1; 
  typedef T2 Type2; 
  enum { N = 2, }; 

  Duo() : value1(), value2()
  {
  }

  Duo(T1 const& a, T2 const& b) : value1(a), value2(b)
  {
  }

  template <typename U1, typename U2>
  Duo(Duo<U1, U2> const& d) : value1(d.v1()), value2(d.v2())
  {
  }

  template <typename U1, typename U2>
  Duo<T1, T2>& operator= (Duo<U1, U2> const& d)
  {
    value1 = d.v1(); //value1; 
    value2 = d.v2(); //value2; 
    return *this; 
  }

  T1& v1() { return value1; } 
  T1 const& v1() const { return value1; } 
  T2& v2() { return value2; } 
  T2 const& v2() const { return value2; } 

  ~Duo(void)
  {
  }

private:
  T1 value1; 
  T2 value2; 
};

template <typename T1, typename T2, typename U1, typename U2>
inline bool operator== (Duo<T1, T2> const& a, Duo<U1, U2> const& b)
{
  return a.v1() == b.v1() && a.v2() == b.v2(); 
}

template <typename T1, typename T2, typename U1, typename U2>
inline bool operator!= (Duo<T1, T2> const& a, Duo<U1, U2> const& b)
{
  return !(a == b); 
}

template <typename T1, typename T2>
inline Duo<T1, T2> make_duo(T1 const& a, T2 const& b)
{
  return Duo<T1, T2>(a, b); 
}


template <typename A, typename B, typename C>
class Duo<A, Duo<B, C> >
{
public:
  typedef A T1; 
  typedef Duo<B, C> T2; 
  enum { N = 1 + Duo<B, C>::N, }; 

  Duo() : value1(), value2()
  {
  }

  Duo(T1 const& a, T2 const& b) : value1(a), value2(b)
  {
  }

  template <typename U1, typename U2>
  Duo(Duo<U1, U2> const& d) : value1(d.v1()), value2(d.v2())
  {
  }

  template <typename U1, typename U2>
  Duo<T1, T2>& operator= (Duo<U1, U2> const& d)
  {
    value1 = d.v1(); //d.value1; 
    value2 = d.v2(); //d.value2; 
    return *this; 
  }

  T1& v1() { return value1; } 
  T1 const& v1() const { return value1; } 
  T2& v2() { return value2; } 
  T2 const& v2() const { return value2; } 

  ~Duo(void)
  {
  }

private:
  T1 value1; 
  T2 value2; 
}; 

template <typename A>
class Duo<A, void>
{
public:
  typedef A T1; 
  typedef void T2; 
  enum { N = 1, }; 

  Duo() : value1() { }
  Duo(T1 const& a) : value1(a) { }

  T1& v1() { return value1; } 
  T1 const& v1() const { return value1; } 
  void v2() { } 
  void v2() const { }

private:
  T1 value1; 
}; 

template <int N, typename T>
class DuoT
{
public:
  typedef void ResultT; 
}; 

template <typename A, typename B>
class DuoT<1, Duo<A, B> >
{
public:
  typedef A ResultT; 
}; 

template <typename A, typename B>
class DuoT<2, Duo<A, B> >
{
public:
  typedef B ResultT; 
}; 

template <int N, typename A, typename B, typename C>
class DuoT<N, Duo<A, Duo<B, C> > >
{
public:
  typedef typename DuoT<N-1, Duo<B, C> >::ResultT ResultT; 
}; 

template <typename A, typename B, typename C>
class DuoT<1, Duo<A, Duo<B, C> > >
{
public:
  typedef A ResultT; 
}; 

template <typename A, typename B, typename C>
class DuoT<2, Duo<A, Duo<B, C> > >
{
public:
  typedef B ResultT; 
}; 



template <int N, typename T>
class DuoValue
{
public:
  static void get(T&) { }
  static void get(T const&) { }
}; 

template <typename A, typename B>
class DuoValue<1, Duo<A, B> >
{
public:
  static A& get(Duo<A, B>& d) { return d.v1(); } 
  static A const& get(Duo<A, B> const& d) { return d.v1(); } 
}; 

template <typename A, typename B>
class DuoValue<2, Duo<A, B> >
{
public:
  static B& get(Duo<A, B>& d) { return d.v2(); } 
  static B const& get(Duo<A, B> const& d) { return d.v2(); } 
}; 

template <int N, typename A, typename B, typename C>
class DuoValue<N, Duo<A, Duo<B, C> > >
{
public:
  typedef typename DuoT<N-1, Duo<B, C> >::ResultT RetT; 
  static typename TypeOp<RetT>::RefT get(Duo<A, Duo<B, C> >& d)
  {
    return DuoValue<N-1, Duo<B, C> >::get(d.v2()); 
  }

  static typename TypeOp<RetT>::RefConstT get(Duo<A, Duo<B, C> > const& d)
  {
    return DuoValue<N-1, Duo<B, C> >::get(d.v2()); 
  }
}; 

template <typename A, typename B, typename C>
class DuoValue<1, Duo<A, Duo<B, C> > >
{
public:
  static A& get(Duo<A, Duo<B, C> >& d)
  {
    return d.v1(); 
  }

  static A const& get(Duo<A, Duo<B, C> > const& d)
  {
    return d.v1(); 
  }
}; 

template <typename A, typename B, typename C>
class DuoValue<2, Duo<A, Duo<B, C> > >
{
public:
  static B& get(Duo<A, Duo<B, C> > &d)
  {
    return d.v2().v1(); 
  }

  static B const& get(Duo<A, Duo<B, C> > const& d)
  {
    return d.v2().v1(); 
  }
}; 


template <int N, typename A, typename B>
inline typename TypeOp<typename DuoT<N, Duo<A, B> >::ResultT>::RefT val(Duo<A, B>& d)
{
  return DuoValue<N, Duo<A, B> >::get(d); 
}

template <int N, typename A, typename B>
inline typename TypeOp<typename DuoT<N, Duo<A, B> >::ResultT>::RefConstT val(Duo<A, B> const& d)
{
  return DuoValue<N, Duo<A, B> >::get(d); 
}