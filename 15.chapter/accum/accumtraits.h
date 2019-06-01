
#ifndef _ACCUM_TRAITS_
#define _ACCUM_TRAITS_

template <typename T>
class AccumulationTraits
{
public:
  typedef T AccT; 
  static AccT zero() { return 0; } 
}; 

template <>
class AccumulationTraits<char>
{
public:
  typedef int AccT; 
  //static AccT const zero = 0; 
  static AccT zero() { return 0; }
}; 

template <>
class AccumulationTraits<short>
{
public:
  typedef int AccT; 
  //static AccT const zero = 0; 
  static AccT zero() { return 0; }
}; 

template <>
class AccumulationTraits<int>
{
public:
  typedef long AccT; 
  //static AccT const zero = 0; 
  static AccT zero() { return 0; } 
}; 

template <>
class AccumulationTraits<unsigned int>
{
public:
  typedef unsigned long AccT; 
  //static AccT const zero = 0; 
  static AccT zero() { return 0; }
}; 

template <>
class AccumulationTraits<float>
{
public:
  typedef double AccT; 
  //static AccT const zero/* = 0*/; 
  static AccT zero() { return 0.0; } 
}; 

#endif 