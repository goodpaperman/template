#pragma once

#include <cstring> 

template <typename T/* = int*/>
inline T const& max(T const& a, T const& b)
{
  printf("template max\n"); 
  return a < b ? b : a; 
}

//template <typename T1, typename T2>
////inline T1 const& max(T1 const& a, T2 const& b)
//inline T1 max(T1 const& a, T2 const& b) 
//{
//  printf("out2::"); 
//  return a < b ? b : a; 
//}

//template <typename T1, typename T2, typename RT>
//inline RT max(T1 const& a, T2 const& b)
//{
//  printf("out3::"); 
//  return a < b ? b : a; 
//}

//template <typename RT, typename T1, typename T2>
//inline RT max(T1 const& a, T2 const& b)
//{
//  printf("our4::"); 
//  return a < b ? b : a; 
//}

template <typename T>
inline T* const& max(T* const& a, T* const& b)
{
  printf("template max T*\n"); 
  return *a < *b ? b : a; 
}

//inline char const* max(char const* a, char const* b)
//{
//  printf("max char const*\n"); 
//  return std::strcmp(a, b) < 0 ? b : a; 
//}

inline char const* const& max(char const* const& a, char const* const& b)
{
  printf("max char const* const&\n"); 
  return std::strcmp(a, b) < 0 ? b : a; 
}

template <typename T> 
inline T const& max(T const& a, T const& b, T const&c )
{
  printf("template max 3\n"); 
  return ::max(::max(a, b), c); 
}

inline int const& max(int const& a, int const& b)
{
  printf("int max\n"); 
  return a < b ? b : a; 
}