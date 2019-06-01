
#ifndef SUM_POLICY_H
#define SUM_POLICY_H

#if 0
class SumPolicy
{
public:
  static int zero() { return 0; } 
  template <typename T1, typename T2>
  static void accumulate(T1& total, T2 const& value)
  { total += value; } 
}; 

class MultPolicy
{
public:
  static int zero() { return 1; }
  template <typename T1, typename T2>
  static void accumulate(T1& total, T2 const& value)
  { total *= value; } 
}; 
#endif 

template <typename AT, typename T> 
class SumPolicy
{
public:
  static int zero() { return 0; } 
  static void accumulate(AT& total, T const& value)
  { total += value; }
}; 

template <typename AT, typename T> 
class MultPolicy
{
public:
  static int zero() { return 1; } 
  static void accumulate(AT& total, T const& value)
  { total *= value; }
}; 

//
//template <typename AT, typename T, bool use_compound_op = true> 
//class SumPolicy
//{
//public:
//  static int zero() { return 0; } 
//  static void accumulate(AT& total, T const& value)
//  { total += value; }
//}; 
//
//template <typename AT, typename T> 
//class SumPolicy<AT, T, false>
//{
//public:
//  static int zero() { return 0; } 
//  static void accumulate(AT& total, T const& value)
//  { total = total + value; }
//}; 
//
//template <typename AT, typename T, bool use_compound_op = true> 
//class MultPolicy
//{
//public:
//  static int zero() { return 1; } 
//  static void accumulate(AT& total, T const& value)
//  { total *= value; }
//}; 
//
//template <typename AT, typename T> 
//class MultPolicy<AT, T, false>
//{
//public:
//  static int zero() { return 1; } 
//  static void accumulate(AT& total, T const& value)
//  { total = total * value; }
//}; 

#endif 