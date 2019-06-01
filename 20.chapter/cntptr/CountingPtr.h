#pragma once

class SimpleReferenceCount
{
public:
  SimpleReferenceCount() : counter(0) { }

  template <typename T>
  void init(T*)
  {
    printf("create counter.\n"); 
    counter = new size_t(1); 
  }

  template <typename T>
  void dispose(T*)
  {
    printf("dispose counter.\n"); 
    delete counter; 
    counter = 0; 
  }

  template <typename T>
  void increment(T*)
  {
    ++ *counter; 
    printf("increase counter to %d.\n", *counter); 
  }

  template <typename T>
  void decrement(T*)
  {
    -- *counter; 
    printf("decrease counter to %d.\n", *counter); 
  }

  template <typename T>
  bool is_zero(T*)
  {
    return *counter == 0; 
  }

private:
  size_t* counter; 
}; 

template <typename T
, typename SizeT
, SizeT T::* mem>
class MemberReferenceCount
{
public:
  void init(T* p)
  {
    p->*mem = 1; 
    printf("init invasion counter to %d.\n", p->*mem); 
  }

  void dispose(T* p)
  {
    printf("dispose invasion counter nothing to do.\n"); 
  }

  void increment(T* p)
  {
    ++ (p->*mem); 
    printf("increase invasion counter to %d.\n", p->*mem); 
  }

  void decrement(T* p)
  {
    -- (p->*mem); 
    printf("decrease invasion counter to %d.\n", p->*mem); 
  }

  bool is_zero(T* p)
  {
    return p->*mem == 0; 
  }
}; 


class StandardObjectPolicy
{
public:
  template <typename T>
  void dispose(T* ptr)
  {
    printf("dispose object.\n"); 
    delete ptr; 
  }
}; 

class StandardArrayPolicy
{
public:
  template <typename T>
  void dispose(T* arr)
  {
    printf("dispose array.\n"); 
    delete[] arr; 
  }
}; 

template <typename T
, typename CounterPolicy = SimpleReferenceCount
, typename ObjectPolicy = StandardObjectPolicy>
class CountingPtr : private CounterPolicy, private ObjectPolicy
{
  typedef CounterPolicy CP; 
  typedef ObjectPolicy OP; 

public:
  CountingPtr() : ptr_(0) { }
  
  explicit CountingPtr(T* p) 
  { 
    printf("construct from ptr.\n"); 
    this->init(p); 
  } 

  CountingPtr(CountingPtr<T, CP, OP> const& p)
    : CP((CP const&)p)
    , OP((OP const&)p)
  { 
    printf("construct from counting ptr.\n"); 
    this->attach(p); 
  } 

  template <typename S, typename U, typename V>
  friend class CountingPtr; 

  template <typename S>
  CountingPtr(CountingPtr<S, CP, OP> const& p)
    : CP((CP const&)p)
    , OP((OP const&)p)
    , ptr_(p.ptr_)
  {
    printf("construct from ptr convertion.\n"); 
    if(p.ptr_)
      CP::increment(p.ptr_); 
  }

  ~CountingPtr(void)
  {
    printf("destruct.\n"); 
    this->detach(); 
  }

  CountingPtr<T, CP, OP>& operator= (T* p)
  {
    printf("assign from ptr.\n"); 
    if(p != ptr_)
    {
      this->detach(); 
      this->init(p); 
      return *this; 
    }

    return *this; 
  }

  CountingPtr<T, CP, OP>& operator= (CountingPtr<T, CP, OP> const& p)
  {
    printf("assign from counting ptr.\n"); 
    if(ptr_ != p.ptr_)
    {
      this->detach(); 
      CP::operator=((CP const&)p); 
      OP::operator=((OP const&)p); 
      this->attach(p); 
    }

    return *this; 
  }

  T* operator->() const
  {
    return ptr_; 
  }

  T& operator*() const
  {
    return *ptr_; 
  }

#ifdef BOOL_PTR
  operator bool() const
  {
    return ptr_; 
  }
#elif defined(VOID_PTR)
  operator void*() const
  {
    return ptr_; 
  }
#else 
private:
  class BoolConversionSupport { public: int dummy; }; 
  //typedef int BoolConversionSupport::*MEM_PTR; 

public:
  //operator void*() const
  operator int BoolConversionSupport::*() const
  {
    return ptr_ ? &BoolConversionSupport::dummy : 0; 
  }
#endif 


  friend bool operator== (CountingPtr<T, CP, OP> const& cp, T const* p)
  {
    return cp.operator->() == p; 
  }

  friend bool operator== (T const* p, CountingPtr<T, CP, OP> const& cp)
  {
    return p == cp.operator->(); 
  }


private:
  void init(T* p)
  {
    printf("init\n"); 
    if(p)
      CounterPolicy::init(p); 

    ptr_ = p; 
  }

  void attach(CountingPtr<T, CP, OP> const& cp)
  {
    printf("attach\n"); 
    ptr_ = cp.ptr_; 
    if(cp.ptr_)
      CounterPolicy::increment(cp.ptr_); 
  }

  void detach()
  {
    printf("detach\n"); 
    if(ptr_)
    {
      CounterPolicy::decrement(ptr_); 
      if(CounterPolicy::is_zero(ptr_))
      {
        //printf("dispose object.\n"); 
        CounterPolicy::dispose(ptr_); 
        ObjectPolicy::dispose(ptr_); 
      }
    }
  }

private:
  T* ptr_; 
};

template <typename T1, typename T2, typename CP, typename OP>
inline bool operator== (CountingPtr<T1, CP, OP> const& cp1, CountingPtr<T2, CP, OP> const& cp2)
{
  return cp1.operator->() == cp2.operator->(); 
}

 

template <typename CounterPolicy, typename ObjectPolicy>
class CountingPtr<void, CounterPolicy, ObjectPolicy> : private CounterPolicy, private ObjectPolicy
{
  typedef CounterPolicy CP; 
  typedef ObjectPolicy OP; 

public:
  CountingPtr() : ptr_(0) { }
  
  explicit CountingPtr(void* p) 
  { 
    printf("construct from ptr.\n"); 
    this->init(p); 
  } 

  CountingPtr(CountingPtr<void, CP, OP> const& p)
    : CP((CP const&)p)
    , OP((OP const&)p)
  { 
    printf("construct from counting ptr.\n"); 
    this->attach(p); 
  } 

  template <typename S, typename U, typename V>
  friend class CountingPtr; 

  template <typename S>
  CountingPtr(CountingPtr<S, CP, OP> const& p)
    : CP((CP const&)p)
    , OP((OP const&)p)
    , ptr_(p.ptr_)
  {
    printf("construct from ptr convertion.\n"); 
    if(p.ptr_)
      CP::increment(p.ptr_); 
  }

  ~CountingPtr(void)
  {
    printf("destruct.\n"); 
    this->detach(); 
  }

  CountingPtr<void, CP, OP>& operator= (void* p)
  {
    printf("assign from ptr.\n"); 
    if(p != ptr_)
    {
      this->detach(); 
      this->init(p); 
      return *this; 
    }

    return *this; 
  }

  CountingPtr<void, CP, OP>& operator= (CountingPtr<void, CP, OP> const& p)
  {
    printf("assign from counting ptr.\n"); 
    if(ptr_ != p.ptr_)
    {
      this->detach(); 
      CP::operator=((CP const&)p); 
      OP::operator=((OP const&)p); 
      this->attach(p); 
    }

    return *this; 
  }

  void* operator->() const
  {
    return ptr_; 
  }

  //void& operator*() const
  //{
  //  return *ptr_; 
  //}

private:
  void init(void* p)
  {
    printf("init\n"); 
    if(p)
      CounterPolicy::init(p); 

    ptr_ = p; 
  }

  void attach(CountingPtr<void, CP, OP> const& cp)
  {
    printf("attach\n"); 
    ptr_ = cp.ptr_; 
    if(cp.ptr_)
      CounterPolicy::increment(cp.ptr_); 
  }

  void detach()
  {
    printf("detach\n"); 
    if(ptr_)
    {
      CounterPolicy::decrement(ptr_); 
      if(CounterPolicy::is_zero(ptr_))
      {
        //printf("dispose object.\n"); 
        CounterPolicy::dispose(ptr_); 
        ObjectPolicy::dispose(ptr_); 
      }
    }
  }

private:
  void* ptr_; 
};
