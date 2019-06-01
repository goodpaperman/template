#pragma once

#include "fundat.h" 
#include "compoundt.h" 

#if defined(EXCLUDE)

#include "classt.h" 

template <typename T>
class IsEnumT
{
public:
  enum
  {
    Yes = IsFundaT<T>::No && 
      IsClassT<T>::No && 
      !CompoundT<T>::IsPtrT && 
      !CompoundT<T>::IsRefT && 
      !CompoundT<T>::IsArrayT && 
      !CompoundT<T>::IsPtrMemT && 
      !CompoundT<T>::IsFuncT, 
    No = !Yes, 
  }; 
};

#else 

#define BOOLEAN_T
struct SizeOverOne { char c[2]; }; 

template <typename T
#if defined(BOOLEAN_T)
, bool convert_possible = !CompoundT<T>::IsFuncT && !CompoundT<T>::IsArrayT>
#else 
>
#endif 
class ConsumeUDC
{
public:
  operator T() const; 
}; 

#if defined(BOOLEAN_T)
template <typename T>
class ConsumeUDC<T, false>
{
}; 

template <bool convert_possible>
class ConsumeUDC<void, convert_possible>
{
}; 
#else 
template <>
class ConsumeUDC<void>
{
}; 
#endif 

char enum_check(bool); 
char enum_check(char); 
char enum_check(signed char); 
char enum_check(unsigned char); 
char enum_check(wchar_t); 
char enum_check(signed short); 
char enum_check(unsigned short); 
char enum_check(signed int); 
char enum_check(unsigned int); 
char enum_check(signed long); 
char enum_check(unsigned long); 
char enum_check(signed long long); 
char enum_check(unsigned long long); 
char enum_check(float); 
char enum_check(double); 
char enum_check(long double); 
SizeOverOne enum_check(...); 

template <typename T>
class IsEnumT
{
public:
  enum 
  {
    Yes = IsFundaT<T>::No && 
      !CompoundT<T>::IsRefT && 
      !CompoundT<T>::IsPtrT && 
      !CompoundT<T>::IsPtrMemT && 
#if !defined(BOOLEAN_T)
      !CompoundT<T>::IsFuncT && 
      !CompoundT<T>::IsArrayT && 
#endif 
      //!CompoundT<T>::IsFuncT && 
      //!CompoundT<T>::IsArrayT && 
      sizeof(enum_check(ConsumeUDC<T>())) == sizeof(char), 

    No = !Yes, 
  }; 
}; 

#endif 
