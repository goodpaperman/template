#pragma once

template <typename T>
class Holder
{
public:
  Holder(void) : ptr(0) 
  {
  }

  explicit Holder(T* p) : ptr(p)
  {
  }

  ~Holder(void)
  {
    delete ptr; 
  }

  Holder<T>& operator= (T* p)
  {
    delete ptr; 
    ptr = p; 
    return *this; 
  }

  T& operator* () const
  {
    return *ptr; 
  }

  T* operator->() const
  {
    return ptr; 
  }

  T* get() const 
  {
    return ptr; 
  }

  //void release()
  //{
  //  ptr = 0; 
  //}

  T* release()
  {
    printf("release pointer.\n"); 
    T* ret = ptr; 
    ptr = 0; 
    return ret; 
  }

  void exchange_with(Holder<T>& h)
  {
    swap(ptr, h.ptr); 
  }

  void exchange_with(T*& p)
  {
    swap(ptr, p); 
  }

private:
  Holder(Holder<T> const&); 
  Holder<T>& operator= (Holder<T> const&); 

  T* ptr; 
};
