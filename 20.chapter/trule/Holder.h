#pragma once

template <typename T>
class Trule; 

template <typename T>
class Holder
{
public:
  Holder(void) : ptr(0) 
  {
  }

  explicit Holder(T* p) : ptr(p)
  {
    printf("holder construct from ptr.\n"); 
  }

  Holder(Trule<T> const& t)
  {
    ptr = t.ptr; 
    const_cast<Trule<T>&>(t).ptr = 0; 
    printf("holder construct from trule.\n"); 
  }

  ~Holder(void)
  {
    delete ptr; 
    printf("holder destruct.\n"); 
  }

  Holder<T>& operator= (T* p)
  {
    delete ptr; 
    ptr = p; 
    printf("holder assigned from ptr.\n"); 
    return *this; 
  }

  Holder<T>& operator= (Trule<T> const& t)
  {
    delete ptr; 
    ptr = t.ptr; 
    const_cast<Trule<T>&>(t).ptr = 0; 
    printf("holder assigned from trule.\n"); 
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
