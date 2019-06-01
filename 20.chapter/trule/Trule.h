#pragma once

template <typename T>
class Holder; 

template <typename T>
class Trule
{
public:
  Trule(Holder<T>& h)
  {
    ptr = h.release(); 
    printf("trule construct from holder.\n"); 
  }

  Trule(Trule<T> const& t)
  {
    ptr = t.ptr; 
    const_cast<Trule<T>&>(t).ptr = 0; 
    printf("trule construct from trule.\n"); 
  }

  ~Trule()
  {
    delete ptr; 
    printf("trule destruct.\n"); 
  }

private:
  T* ptr; 

  Trule(Trule<T>&); 
  Trule& operator=(Trule<T>&); 
  friend class Holder<T>; 
};
